#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <cctype>
#include <algorithm>
#include <random>
#include <ctime>
#include <chrono>

struct SudokuBoard {
    static const int SIZE = 9;
    std::vector<std::vector<int>> grid;

    SudokuBoard() {
        grid.resize(SIZE, std::vector<int>(SIZE, 0));
    }
};

enum class Difficulty {
    EASY,
    MEDIUM,
    HARD
};

void printBoard(const SudokuBoard& board) {
    std::cout << "-------------------------\n";
    for (int row = 0; row < SudokuBoard::SIZE; ++row) {
        std::cout << "| ";
        for (int col = 0; col < SudokuBoard::SIZE; ++col) {
            if (board.grid[row][col] == 0) {
                std::cout << ". ";
            }
            else {
                std::cout << board.grid[row][col] << " ";
            }
            if ((col + 1) % 3 == 0) std::cout << "| ";
        }
        std::cout << "\n";
        if ((row + 1) % 3 == 0) std::cout << "-------------------------\n";
    }
}

bool isValidMove(const SudokuBoard& board, int row, int col, int num) {
    for (int c = 0; c < SudokuBoard::SIZE; ++c) {
        if (board.grid[row][c] == num && c != col) {
            return false;
        }
    }

    for (int r = 0; r < SudokuBoard::SIZE; ++r) {
        if (board.grid[r][col] == num && r != row) {
            return false;
        }
    }

    int startRow = row - (row % 3);
    int startCol = col - (col % 3);
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            int curRow = startRow + r;
            int curCol = startCol + c;
            if (board.grid[curRow][curCol] == num && (curRow != row || curCol != col)) {
                return false;
            }
        }
    }

    return true;
}

bool isSolved(const SudokuBoard& board) {
    for (int r = 0; r < SudokuBoard::SIZE; ++r) {
        for (int c = 0; c < SudokuBoard::SIZE; ++c) {
            int num = board.grid[r][c];
            if (num == 0) return false;
            if (!isValidMove(board, r, c, num)) return false;
        }
    }
    return true;
}

void fill3x3Box(SudokuBoard& board, int startRow, int startCol) {
    std::vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(nums.begin(), nums.end(), std::default_random_engine(seed));

    int idx = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board.grid[startRow + i][startCol + j] = nums[idx++];
        }
    }
}

bool solveSudoku(SudokuBoard& board) {
    int row = -1;
    int col = -1;
    bool isEmpty = false;

    for (int r = 0; r < SudokuBoard::SIZE; ++r) {
        for (int c = 0; c < SudokuBoard::SIZE; ++c) {
            if (board.grid[r][c] == 0) {
                row = r;
                col = c;
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) break;
    }

    if (!isEmpty) return true;

    for (int num = 1; num <= 9; ++num) {
        if (isValidMove(board, row, col, num)) {
            board.grid[row][col] = num;
            if (solveSudoku(board)) return true;
            board.grid[row][col] = 0;
        }
    }

    return false;
}

void generateSudoku(SudokuBoard& board, Difficulty level) {
    for (int i = 0; i < 9; ++i) std::fill(board.grid[i].begin(), board.grid[i].end(), 0);

    fill3x3Box(board, 0, 0);
    fill3x3Box(board, 3, 3);
    fill3x3Box(board, 6, 6);

    solveSudoku(board);

    int attempts = 0;
    switch (level) {
    case Difficulty::EASY: attempts = 30; break;
    case Difficulty::MEDIUM: attempts = 40; break;
    case Difficulty::HARD: attempts = 50; break;
    }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, 8);

    while (attempts > 0) {
        int r = distribution(generator);
        int c = distribution(generator);

        if (board.grid[r][c] != 0) {
            board.grid[r][c] = 0;
            attempts--;
        }
    }
}

void playManual(SudokuBoard& board) {
    std::vector<std::vector<bool>> fixed(SudokuBoard::SIZE, std::vector<bool>(SudokuBoard::SIZE, false));
    for (int r = 0; r < SudokuBoard::SIZE; ++r) {
        for (int c = 0; c < SudokuBoard::SIZE; ++c) {
            if (board.grid[r][c] != 0) fixed[r][c] = true;
        }
    }

    while (true) {
        std::cout << "\n--- Manual Play Mode ---\n";
        printBoard(board);

        if (isSolved(board)) {
            std::cout << "\n*** CONGRATULATIONS! YOU SOLVED IT! ***\n";
            std::cout << "Press Enter to return to menu...";
            std::cin.ignore();
            std::cin.get();
            break;
        }

        std::cout << "Enter move as: Row Col Value (e.g., '1 1 5')\n";
        std::cout << "To remove a number, enter 0 as the value (e.g., '1 1 0')\n";
        std::cout << "Enter '0 0 0' to stop playing and return to menu.\n";
        std::cout << "Move: ";

        int r, c, val;
        if (!(std::cin >> r >> c >> val)) {
            std::cout << "Invalid input format. Please enter numbers.\n";
            std::cin.clear();
            while (std::cin.get() != '\n');
            continue;
        }

        if (r == 0 && c == 0 && val == 0) {
            break;
        }

        int rIdx = r - 1;
        int cIdx = c - 1;

        if (rIdx < 0 || rIdx >= SudokuBoard::SIZE || cIdx < 0 || cIdx >= SudokuBoard::SIZE || val < 0 || val > 9) {
            std::cout << "Error: Coordinates must be 1-9, Value must be 0-9.\n";
            continue;
        }

        if (fixed[rIdx][cIdx]) {
            std::cout << "Error: Cannot change a fixed starting number!\n";
            continue;
        }

        if (val == 0) {
            board.grid[rIdx][cIdx] = 0;
            std::cout << "Cell (" << r << "," << c << ") cleared.\n";
            continue;
        }

        if (isValidMove(board, rIdx, cIdx, val)) {
            board.grid[rIdx][cIdx] = val;
            std::cout << "Placed " << val << " at (" << r << "," << c << ").\n";
        }
        else {
            std::cout << "Invalid move! " << val << " violates Sudoku rules in that position.\n";
        }
    }
}


SudokuBoard loadBoard(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) throw std::runtime_error("Error: Could not open file " + filename);

    SudokuBoard board;
    std::string line;
    int row = 0;

    while (std::getline(file, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();

        if (row >= SudokuBoard::SIZE) continue;

        if (line.length() < SudokuBoard::SIZE) {
            file.close();
            throw std::runtime_error("Error: Line " + std::to_string(row + 1) + " is too short.");
        }

        for (int col = 0; col < SudokuBoard::SIZE; ++col) {
            char c = line[col];
            if (c >= '0' && c <= '9') {
                board.grid[row][col] = c - '0';
            }
        }
        row++;
    }
    file.close();
    std::cout << "Board successfully loaded from " << filename << "\n";
    return board;
}

void saveBoard(const SudokuBoard& board, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open file for writing: " + filename);
    }

    for (const auto& row : board.grid) {
        for (int val : row) {
            file << val;
        }
        file << "\n";
    }
    file.close();
    std::cout << "Board successfully saved to " << filename << "\n";
}

int main() {
    std::srand(std::time(0));

    try {
        SudokuBoard gameBoard;
        int mainChoice = 0;

        std::cout << "=== SUDOKU MASTER ===\n";
        std::cout << "1. Generate New Puzzle\n";
        std::cout << "2. Load Puzzle from File\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter choice: ";

        while (!(std::cin >> mainChoice) || mainChoice < 1 || mainChoice > 3) {
            std::cout << "Invalid input. Please enter 1, 2, or 3: ";
            std::cin.clear();
            while (std::cin.get() != '\n');
        }

        if (mainChoice == 3) {
            return 0;
        }

        if (mainChoice == 1) {
            int diffChoice = 0;
            Difficulty level = Difficulty::MEDIUM;
            std::cout << "\nSelect Difficulty:\n1. Easy\n2. Medium\n3. Hard\nChoice: ";
            while (!(std::cin >> diffChoice) || diffChoice < 1 || diffChoice > 3) {
                std::cout << "Invalid. Enter 1-3: ";
                std::cin.clear(); while (std::cin.get() != '\n');
            }
            if (diffChoice == 1) level = Difficulty::EASY;
            else if (diffChoice == 2) level = Difficulty::MEDIUM;
            else level = Difficulty::HARD;

            std::cout << "\nGenerating new puzzle...\n";
            generateSudoku(gameBoard, level);
        }
        else {
            std::string filename;
            std::cout << "\nEnter filename to load (e.g. puzzle.txt): ";
            std::cin >> filename;
            gameBoard = loadBoard(filename);
        }

        std::cout << "\n--- Current Board ---\n";
        printBoard(gameBoard);

        bool keepRunning = true;
        while (keepRunning) {
            int action = 0;
            std::cout << "\nOptions:\n";
            std::cout << "1. Play Manual (Self Solve)\n";
            std::cout << "2. Auto Solve (Computer)\n";
            std::cout << "3. Save Board to File\n";
            std::cout << "4. Exit Game\n";
            std::cout << "Choice: ";

            while (!(std::cin >> action) || action < 1 || action > 4) {
                std::cout << "Invalid. Enter 1-4: ";
                std::cin.clear(); while (std::cin.get() != '\n');
            }

            switch (action) {
            case 1: 
                playManual(gameBoard);
                break;

            case 2:
                std::cout << "\nSolving...\n";
                if (solveSudoku(gameBoard)) {
                    std::cout << "\n--- Solved Board ---\n";
                    printBoard(gameBoard);
                    if (isSolved(gameBoard)) std::cout << "Status: Verified Valid Solution.\n";
                }
                else {
                    std::cout << "\nNo solution exists for this board.\n";
                }
                break;

            case 3:
            {
                std::string saveName;
                std::cout << "Enter filename to save as (e.g. saved_puzzle.txt): ";
                std::cin >> saveName;
                saveBoard(gameBoard, saveName);
            }
            break;

            case 4:
                keepRunning = false;
                break;
            }
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}