#include <iostream>     
#include <fstream>      
#include <vector>       
#include <list>         
#include <forward_list> 
#include <string>       
#include <utility>     
#include <tuple>        
#include <algorithm>    
#include <sstream>      
#include <format>
#include <iomanip>

/* TASK 1: Binary File Writer
   Write a function that takes a filename and a vector of doubles,
   then writes them to a binary file. Return true if successful.

   Example: write_binary("data.bin", {1.5, 2.5, 3.5}) writes 3 doubles
*/
bool write_binary_doubles(const std::string& filename, const std::vector<double>& data) {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) return false;

    outFile.write(reinterpret_cast<const char*>(data.data()), data.size() * sizeof(double));
    return outFile.good();
}

/* TASK 2: Binary File Reader
   Write a function that reads all doubles from a binary file and returns
   them in a vector. The file was written using write_binary_doubles.

   Example: read_binary("data.bin") returns vector {1.5, 2.5, 3.5}
*/
std::vector<double> read_binary_doubles(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary | std::ios::ate); 
    if (!inFile) return {};

    std::streamsize size = inFile.tellg();
    inFile.seekg(0, std::ios::beg);

    std::vector<double> result(size / sizeof(double));
    if (inFile.read(reinterpret_cast<char*>(result.data()), size)) {
        return result;
    }
    return {};
}

/* TASK 3: List Manipulation - Remove Duplicates
   Write a function that takes a std::list<int> by reference and removes
   all consecutive duplicate elements, keeping only the first occurrence.

   Example: {1, 1, 2, 3, 3, 3, 4, 1} becomes {1, 2, 3, 4, 1}
*/
void remove_consecutive_duplicates(std::list<int>& numbers) {
    numbers.unique();
}

/* TASK 4: Forward List - Insert Sorted
   Write a function that inserts a value into a sorted std::forward_list<int>
   maintaining the sorted order (ascending). The list is already sorted.

   Example: Insert 5 into {1, 3, 7, 9} results in {1, 3, 5, 7, 9}
*/
void insert_sorted(std::forward_list<int>& list, int value) {
    auto prev = list.before_begin();
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (*it >= value) break;
        prev = it;
    }
    list.insert_after(prev, value);
}

/* TASK 5: Pair Statistics
   Write a function that takes a vector of pairs (student name, grade)
   and returns a pair containing: the name of the best student and
   the average grade of all students.

   Example: {{"Alice", 85}, {"Bob", 92}, {"Eve", 78}}
            returns {"Bob", 85.0}
*/
std::pair<std::string, double> analyze_grades(
    const std::vector<std::pair<std::string, int>>& students) {
    if (students.empty()) return { "", 0.0 };
    auto best = students[0];
    double sum = 0;
    for (const auto& s : students) {
        if (s.second > best.second) best = s;
        sum += s.second;
    }
    return { best.first, sum / students.size() };
}

/* TASK 6: Tuple Unpacking and Processing
   Write a function that takes a vector of tuples (name, age, height)
   and returns a new vector containing only tuples where age is between
   18 and 30 (inclusive), sorted by height in descending order.

   Example: {{"Alice", 25, 1.65}, {"Bob", 17, 1.80}, {"Eve", 22, 1.70}}
            returns {{"Eve", 22, 1.70}, {"Alice", 25, 1.65}}
*/
std::vector<std::tuple<std::string, int, double>> filter_and_sort_people(
    const std::vector<std::tuple<std::string, int, double>>& people) {
    std::vector<std::tuple<std::string, int, double>> result;

    for (const auto& p : people) {
        if (std::get<1>(p) >= 18 && std::get<1>(p) <= 30) {
            result.push_back(p);
        }
    }

    std::sort(result.begin(), result.end(), [](const auto& a, const auto& b) {
        return std::get<2>(a) > std::get<2>(b);
        });

    return result;
}

/* TASK 7: Text File Processing - Count Lines and Words
   Write a function that reads a text file and returns a pair containing:
   the number of lines and the total number of words in the file.
   Words are separated by whitespace.

   Example: File with "Hello World\nC++ Programming" returns {2, 4}
*/
std::pair<int, int> count_lines_and_words(const std::string& filename) {
    std::ifstream file(filename);
    std::string line, word;
    int lines = 0, words = 0;
    while (std::getline(file, line)) {
        lines++;
        std::stringstream ss(line);
        while (ss >> word) words++;
    }
    return { lines, words };
}

/* TASK 8: Format Student Report
   Write a function that takes a tuple (name, surname, age, grade)
   and returns a formatted string using std::format:
   "Name: [name, 15 chars left-aligned] | Age: [age, 3 chars] | Grade: [grade, 5.2f]"

   Example: ("John", "Smith", 20, 87.5) returns
            "Name: John Smith      | Age:  20 | Grade: 87.50"
*/
std::string format_student_report(const std::tuple<std::string, std::string, int, double>& student) {
    std::string name = std::get<0>(student);
    std::string surname = std::get<1>(student);
    int age = std::get<2>(student);
    double grade = std::get<3>(student);

    std::ostringstream oss;
    // Name: [15 chars left], Age: [3 chars right], Grade: [5.2f]
    oss << "Name: " << std::left << std::setw(15) << (name + " " + surname)
        << " | Age: " << std::right << std::setw(3) << age
        << " | Grade: " << std::fixed << std::setprecision(2) << std::setw(5) << grade;
    return oss.str();
}

/* MAIN FUNCTION - Test Your Solutions */
int main() {
    // Test TASK 1 & 2
    std::cout << "TASK 1 & 2: Binary File I/O\n";
    std::string bin_file = "test_data.bin";
    std::vector<double> original_doubles = { 1.5, 2.5, 3.5 };
    write_binary_doubles("data.bin", original_doubles);
    auto loaded = read_binary_doubles("data.bin");
    std::cout << loaded.size() << " doubles\n";
    if (write_binary_doubles(bin_file, original_doubles)) {
        std::vector<double> read_doubles = read_binary_doubles(bin_file);
        for (double d : read_doubles) std::cout << d << " ";
    }
    std::cout << "\n";
    std::cout << "\n";

    // Test TASK 3
    std::cout << "TASK 3: Remove Consecutive Duplicates\n";
    std::list<int> numbers = { 1, 1, 2, 3, 3, 3, 4, 1 };
    remove_consecutive_duplicates(numbers);
    for (int n : numbers) std::cout << n << " ";

    std::cout << "\n";
    std::cout << "\n";

    // Test TASK 4
    std::cout << "TASK 4: Insert Sorted in Forward List\n";
    std::forward_list<int> flist = { 1, 3, 7, 9 };
    insert_sorted(flist, 5);
    for (int n : flist) std::cout << n << " ";

    std::cout << "\n";
    std::cout << "\n";

    // Test TASK 5
    std::cout << "TASK 5: Pair Statistics\n";
    std::vector<std::pair<std::string, int>> students = { {"Alice", 85}, {"Bob", 92}, {"Eve", 78} };
    auto stats = analyze_grades(students);
    std::cout << stats.first << " ";
    std::cout << std::fixed << std::setprecision(1) << stats.second << "\n";

    std::cout << "\n";

    // Test TASK 6
    std::cout << "TASK 6: Filter and Sort Tuples\n";
    std::vector<std::tuple<std::string, int, double>> people = {
    {"Alice", 25, 1.65},
    {"Bob", 17, 1.80},   
    {"Eve", 22, 1.70},
    };
    auto filtered = filter_and_sort_people(people);

    for (const auto& p : filtered) {
        std::cout << std::get<0>(p) << " " << std::get<1>(p) << " " << std::fixed << std::setprecision(2) << std::get<2>(p) << std::endl;
    }

    std::cout << "\n";

    // Test TASK 7
    std::cout << "TASK 7: Count Lines and Words\n";
    std::string txt_file = "test.txt";
    std::ofstream out_txt(txt_file);
    out_txt << "Hello World\nC++ Programming\n";
    out_txt.close();

    auto counts = count_lines_and_words(txt_file);
    std::cout <<  counts.first << ", " << counts.second << "\n";

    std::cout << "\n";

    // Test TASK 8
    std::cout << "TASK 8: Format Student Report\n";
    auto student = std::make_tuple("John", "Smith", 20, 87.50);
    std::cout << format_student_report(student) << "\n";

    return 0;
}