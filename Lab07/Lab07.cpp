// TASK 1: Function Overloading - Absolute Value
// Write three overloaded functions called 'absolute' that return absolute values.
// Requirements:
// - int absolute(const int value) - returns absolute value of integer
// - double absolute(const double value) - returns absolute value of double
// - void absolute(std::vector<int> & vec) - converts all elements to absolute values in-place
// - Test all three versions with different inputs
// - For vector version, print before and after
// - Test with: absolute(-42), absolute(-3.14), absolute(vector{-5, 10, -15, 20})

// TASK 2: File Writing - Student Records
// Write a function that writes student records to a file.
// Requirements:
// - Function signature: bool write_students(const std::string & filename, 
//                                           const std::vector<std::string> & names,
//                                           const std::vector<int> & scores)
// - Each line format: "Name: [name], Score: [score]"
// - Return true if successful, false if vectors have different sizes or file fails
// - Test with at least 5 students
// - Print success/failure message and verify file contents

// TASK 3: File Reading - Number Statistics
// Write functions to read numbers from a file and analyze them.
// Requirements:
// - std::vector<double> read_numbers(const std::string & filename)
//   - reads all numbers from file (one per line or space-separated)
//   - returns vector of numbers
// - int count_positive(const std::vector<double> & numbers)
//   - counts how many numbers are positive
// - int count_negative(const std::vector<double> & numbers)
//   - counts how many numbers are negative
// - First create a file with numbers, then read and analyze it
// - Print: total count, positive count, negative count, zero count

// TASK 4: Reference Parameters - Sort Three Values
// Write functions that work with references to sort and manipulate values.
// Requirements:
// - void sort_three(int & a, int & b, int & c) - sorts three integers in ascending order
//   (a will be smallest, c will be largest)
// - void increment_all(int & a, int & b, int & c, const int value) - adds value to all three
// - void make_equal(int & a, int & b, int & c) - sets all three to their average
// - Test with three variables initialized to: 45, 12, 33
// - Show values after each function call

// TASK 5: String Stream Processing
// Write functions that use std::stringstream for string manipulation.
// Requirements:
// - std::vector<int> parse_integers(const std::string & text)
//   - extracts all integers from a string (use stringstream)
//   - example: "The year 2024 has 366 days" -> {2024, 366}
// - std::string join_strings(const std::vector<std::string> & words, const std::string & delimiter)
//   - joins vector of strings with delimiter between them
//   - example: {"Hello", "World", "!"} with ", " -> "Hello, World, !"
// - int count_tokens(const std::string & text)
//   - counts space-separated tokens using stringstream
// - Test with various strings and print results

// TASK 6: Recursive Array Operations
// Write recursive functions to work with arrays.
// Requirements:
// - int array_sum_recursive(const int array[], const int length, const int index = 0)
//   - recursively calculates sum of array elements
//   - base case: index >= length returns 0
// - int find_max_recursive(const int array[], const int length, const int index = 0)
//   - recursively finds maximum value in array
//   - base case: index == length-1 returns array[index]
//   - hint: return max of current element and max of rest
// - Test with array: {34, 67, 12, 89, 45, 23, 78}
// - Compare with iterative results to verify correctness

// TASK 7: Multi-File Data Processing
// Create a program that processes multiple data files.
// Requirements:
// - Create struct: struct DataSummary { 
//     std::string filename; 
//     int line_count;
//     int word_count;
//     int char_count;
//   };
// - Write function: DataSummary analyze_file(const std::string & filename)
//   - counts lines, words (space-separated), and characters in file
//   - returns DataSummary with all statistics
// - Write function: void print_summary(const DataSummary & summary)
//   - prints all statistics in readable format
// - Write function: void compare_files(const std::string & file1, const std::string & file2)
//   - analyzes both files and prints which has more lines/words/chars
// - Create 2-3 test files with different content and analyze them



#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>



// TASK 1: Function Overloading - Absolute Value

int absolute(const int value) {
    return (value < 0) ? -value : value;
}

double absolute(const double value) {
    return (value < 0.0) ? -value : value;
}

void absolute(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] < 0) {
            vec[i] = -vec[i];
        }
    }
}

void printVector(const std::vector<int>& vec) {
    std::cout << "{ ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " }";
}

// TASK 2: File Writing - Student Records

bool write_students(const std::string& filename,
    const std::vector<std::string>& names,
    const std::vector<int>& scores) {

    if (names.size() != scores.size()) {
        std::cerr << "Error: Vectors must have the same size." << std::endl;
        return false;
    }

    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for writing." << std::endl;
        return false;
    }

    for (size_t i = 0; i < names.size(); ++i) {
        outFile << "Name: " << names[i] << ", Score: " << scores[i] << "\n";
    }

    outFile.close();
    return true;
}

void verify_file_contents(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file for verification." << std::endl;
        return;
    }

    std::cout << "\n--- Verifying File Contents (" << filename << ") ---\n";
    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }
    std::cout << "-------------------------------------------\n";
    inFile.close();
}

// TASK 3: File Reading - Number Statistics

std::vector<double> read_numbers(const std::string& filename) {
    std::vector<double> numbers;
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return numbers;
    }

    double num;
    while (inFile >> num) {
        numbers.push_back(num);
    }

    inFile.close();
    return numbers;
}

int count_positive(const std::vector<double>& numbers) {
    int count = 0;
    for (double num : numbers) {
        if (num > 0) {
            count++;
        }
    }
    return count;
}

int count_negative(const std::vector<double>& numbers) {
    int count = 0;
    for (double num : numbers) {
        if (num < 0) {
            count++;
        }
    }
    return count;
}

// TASK 4: Reference Parameters - Sort Three Values

void sort_three(int& a, int& b, int& c) {
    if (a > b) std::swap(a, b);
    if (a > c) std::swap(a, c);
    if (b > c) std::swap(b, c);
}

void increment_all(int& a, int& b, int& c, const int value) {
    a += value;
    b += value;
    c += value;
}

void make_equal(int& a, int& b, int& c) {
    int average = (a + b + c) / 3;
    a = average;
    b = average;
    c = average;
}

void print_values(const std::string& label, int a, int b, int c) {
    std::cout << label << ": " << a << ", " << b << ", " << c << std::endl;
}

// TASK 5: String Stream Processing


std::vector<int> parse_integers(const std::string& text) {
    std::vector<int> numbers;
    std::stringstream ss(text);

    int num;
    while (!ss.eof()) {
        if (ss >> num) {
            numbers.push_back(num);
        }
        else {
            ss.clear();
            ss.ignore();
        }
    }
    return numbers;
}

std::string join_strings(const std::vector<std::string>& words, const std::string& delimiter) {
    std::stringstream ss;
    for (size_t i = 0; i < words.size(); ++i) {
        ss << words[i];
        if (i < words.size() - 1) {
            ss << delimiter;
        }
    }
    return ss.str();
}

int count_tokens(const std::string& text) {
    std::stringstream ss(text);
    std::string token;
    int count = 0;

    while (ss >> token) {
        count++;
    }
    return count;
}

// TASK 6: Recursive Array Operations

int array_sum_recursive(const int array[], const int length, const int index = 0) {
    if (index >= length) {
        return 0;
    }
    return array[index] + array_sum_recursive(array, length, index + 1);
}

int find_max_recursive(const int array[], const int length, const int index = 0) {
    if (index == length - 1) {
        return array[index];
    }

    int max_of_rest = find_max_recursive(array, length, index + 1);

    return (array[index] > max_of_rest) ? array[index] : max_of_rest;
}


int array_sum_iterative(const int array[], const int length) {
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += array[i];
    }
    return sum;
}

int find_max_iterative(const int array[], const int length) {
    int max_val = array[0];
    for (int i = 1; i < length; ++i) {
        if (array[i] > max_val) {
            max_val = array[i];
        }
    }
    return max_val;
}

// TASK 7: Multi-File Data Processing

struct DataSummary {
    std::string filename;
    int line_count;
    int word_count;
    int char_count;
};

void create_test_file(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
    }
    else {
        std::cerr << "Error creating " << filename << std::endl;
    }
}

DataSummary analyze_file(const std::string& filename) {
    DataSummary summary = { filename, 0, 0, 0 };
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return summary;
    }

    std::string line;
    while (std::getline(file, line)) {
        summary.line_count++;
        summary.char_count += line.length() + 1;

        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            summary.word_count++;
        }
    }

    file.close();
    return summary;
}

void print_summary(const DataSummary& summary) {
    std::cout << "--- Summary for " << summary.filename << " ---" << std::endl;
    std::cout << "Lines:      " << summary.line_count << std::endl;
    std::cout << "Words:      " << summary.word_count << std::endl;
    std::cout << "Characters: " << summary.char_count << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

void compare_files(const std::string& file1, const std::string& file2) {
    DataSummary s1 = analyze_file(file1);
    DataSummary s2 = analyze_file(file2);

    std::cout << "\nComparison: " << file1 << " vs " << file2 << std::endl;

    if (s1.line_count > s2.line_count)
        std::cout << "Lines: " << s1.filename << " has more (" << s1.line_count << " vs " << s2.line_count << ")" << std::endl;
    else if (s2.line_count > s1.line_count)
        std::cout << "Lines: " << s2.filename << " has more (" << s2.line_count << " vs " << s1.line_count << ")" << std::endl;
    else
        std::cout << "Lines: Both have equal lines (" << s1.line_count << ")" << std::endl;

    if (s1.word_count > s2.word_count)
        std::cout << "Words: " << s1.filename << " has more (" << s1.word_count << " vs " << s2.word_count << ")" << std::endl;
    else if (s2.word_count > s1.word_count)
        std::cout << "Words: " << s2.filename << " has more (" << s2.word_count << " vs " << s1.word_count << ")" << std::endl;
    else
        std::cout << "Words: Both have equal words (" << s1.word_count << ")" << std::endl;

    if (s1.char_count > s2.char_count)
        std::cout << "Chars: " << s1.filename << " has more (" << s1.char_count << " vs " << s2.char_count << ")" << std::endl;
    else if (s2.char_count > s1.char_count)
        std::cout << "Chars: " << s2.filename << " has more (" << s2.char_count << " vs " << s1.char_count << ")" << std::endl;
    else
        std::cout << "Chars: Both have equal chars (" << s1.char_count << ")" << std::endl;
}

int main()
{
    // Task 1

    std::cout << "=== Task 1: Function Overloading Tests ===\n" << std::endl;

    int intInput = -42;
    int intResult = absolute(intInput);

    std::cout << "1. Integer Test:" << std::endl;
    std::cout << "   Input: " << intInput << std::endl;
    std::cout << "   Result: " << intResult << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    double doubleInput = -3.14;
    double doubleResult = absolute(doubleInput);

    std::cout << "2. Double Test:" << std::endl;
    std::cout << "   Input: " << doubleInput << std::endl;
    std::cout << "   Result: " << doubleResult << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    std::vector<int> vecInput = { -5, 10, -15, 20 };

    std::cout << "3. Vector Test (In-Place modification):" << std::endl;
    std::cout << "   Before absolute(): ";
    printVector(vecInput);
    std::cout << std::endl;

    absolute(vecInput);

    std::cout << "   After absolute():  ";
    printVector(vecInput);
    std::cout << std::endl;

    // Task 2

    std::cout << "=== Task 2: Student Records File Writing ===\n" << std::endl;

    std::string outputFilename = "student_records.txt";
    std::vector<std::string> names = { "Alice", "Bob", "Charlie", "Diana", "Evan" };
    std::vector<int> scores = { 85, 92, 78, 95, 88 };

    std::cout << "Attempting to write " << names.size() << " records to " << outputFilename << "..." << std::endl;

    if (write_students(outputFilename, names, scores)) {
        std::cout << "Success: Data written to file." << std::endl;

        verify_file_contents(outputFilename);
    }
    else {
        std::cout << "Failure: Could not write data." << std::endl;
    }

    std::cout << "\nTesting Error Case (Mismatched Sizes):" << std::endl;
    std::vector<std::string> mismatchNames = { "One", "Two" };
    std::vector<int> mismatchScores = { 10, 20, 30 };

    std::string errorFilename = "error_test.txt";

    if (!write_students(errorFilename, mismatchNames, mismatchScores)) {
        std::cout << "Correctly handled mismatched vector sizes (function returned false)." << std::endl;
    }


    // Task 3

    std::cout << "=== Task 3: Number Statistics ===\n" << std::endl;

    std::string filename = "numbers.txt";

    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << "10.5 -2.5 0\n";
        outFile << "42.0     -100.1\n";
        outFile << "0 7.7\n-5.5 3.14\n";
        outFile.close();
        std::cout << "Created sample file '" << filename << "' with test data." << std::endl;
    }
    else {
        std::cerr << "Error: Could not create sample file." << std::endl;
        return 1;
    }

    std::vector<double> data = read_numbers(filename);

    if (data.empty()) {
        std::cout << "No data read or file empty." << std::endl;
        return 0;
    }

    int total_count = data.size();
    int pos_count = count_positive(data);
    int neg_count = count_negative(data);
    int zero_count = total_count - pos_count - neg_count;

    std::cout << "\nAnalysis Results:" << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "Total numbers read: " << total_count << std::endl;
    std::cout << "Positive count:     " << pos_count << std::endl;
    std::cout << "Negative count:     " << neg_count << std::endl;
    std::cout << "Zero count:         " << zero_count << std::endl;

    std::cout << "\nRaw Data Loaded: { ";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i];
        if (i < data.size() - 1) std::cout << ", ";
    }
    std::cout << " }" << std::endl;

    // Task 4

    std::cout << "=== Task 4: Reference Parameters ===\n" << std::endl;

    int x = 45;
    int y = 12;
    int z = 33;

    print_values("Initial values", x, y, z);
    std::cout << "----------------------------------------" << std::endl;

    sort_three(x, y, z);
    print_values("After sort_three()", x, y, z);

    increment_all(x, y, z, 5);
    print_values("After increment_all(..., 5)", x, y, z);

    make_equal(x, y, z);
    print_values("After make_equal()", x, y, z);

    // Task 5

    std::cout << "=== Task 5: String Stream Processing ===\n" << std::endl;

    std::string textWithNums = "The year 2024 has 366 days (leap year).";
    std::cout << "1. Parsing Integers:" << std::endl;
    std::cout << "   Input: \"" << textWithNums << "\"" << std::endl;

    std::vector<int> nums = parse_integers(textWithNums);
    std::cout << "   Found: { ";
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << (i < nums.size() - 1 ? ", " : "");
    }
    std::cout << " }" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    std::vector<std::string> words = { "Hello", "World", "from", "C++" };
    std::string delimiter = " | ";

    std::cout << "2. Joining Strings:" << std::endl;
    std::cout << "   Input Vector: {Hello, World, from, C++}" << std::endl;
    std::cout << "   Delimiter: \"" << delimiter << "\"" << std::endl;

    std::string joined = join_strings(words, delimiter);
    std::cout << "   Result: \"" << joined << "\"" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    std::string sentence = "   This   string   has   irregular   spacing   ";

    std::cout << "3. Counting Tokens:" << std::endl;
    std::cout << "   Input: \"" << sentence << "\"" << std::endl;

    int count = count_tokens(sentence);
    std::cout << "   Token Count: " << count << std::endl;

    // Task 6

    std::cout << "=== Task 6: Recursive Array Operations ===\n" << std::endl;

    int testArray[] = { 34, 67, 12, 89, 45, 23, 78 };
    int length = sizeof(testArray) / sizeof(testArray[0]);

    std::cout << "Test Array: { ";
    for (int i = 0; i < length; ++i) {
        std::cout << testArray[i] << (i < length - 1 ? ", " : "");
    }
    std::cout << " }\n" << std::endl;

    std::cout << "1. Testing Summation:" << std::endl;

    int recSum = array_sum_recursive(testArray, length);
    int iterSum = array_sum_iterative(testArray, length);

    std::cout << "   Recursive Sum: " << recSum << std::endl;
    std::cout << "   Iterative Sum: " << iterSum << std::endl;

    if (recSum == iterSum) {
        std::cout << "   [PASS] Results match." << std::endl;
    }
    else {
        std::cout << "   [FAIL] Results do not match." << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl;

    std::cout << "2. Testing Find Max:" << std::endl;

    int recMax = find_max_recursive(testArray, length);
    int iterMax = find_max_iterative(testArray, length);

    std::cout << "   Recursive Max: " << recMax << std::endl;
    std::cout << "   Iterative Max: " << iterMax << std::endl;

    if (recMax == iterMax) {
        std::cout << "   [PASS] Results match." << std::endl;
    }
    else {
        std::cout << "   [FAIL] Results do not match." << std::endl;
    }


    // Task 7
    std::cout << "=== Task 7: Multi-File Data Processing ===\n" << std::endl;

    std::string file1 = "short_story.txt";
    std::string content1 = "The quick brown fox.\nJumps over the lazy dog.\nEnd of story.\n";
    create_test_file(file1, content1);

    std::string file2 = "poem.txt";
    std::string content2 = "Roses are red,\nViolets are blue,\nC++ is fun,\nAnd so are you.\nExtra line here.\n";
    create_test_file(file2, content2);

    std::cout << "Analyzing files..." << std::endl;
    DataSummary s1 = analyze_file(file1);
    print_summary(s1);

    DataSummary s2 = analyze_file(file2);
    print_summary(s2);

    compare_files(file1, file2);

    return 0;
}