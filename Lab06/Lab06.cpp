// TASK 1: constexpr Factorial Function
// Write a constexpr function called 'factorial' that calculates n!.
// Requirements:
// - Function signature: constexpr long long factorial(const int n)
// - Use iterative approach (loop)
// - Handle n = 0 and n = 1 (return 1)
// - Test with: factorial(5), factorial(7), factorial(0)
// - Create a constexpr variable storing factorial(6) and use it as array size
// - Print: "Array size determined at compile-time: [size]"

// TASK 2: consteval Prime Checker
// Write a consteval function called 'is_prime' that checks if a number is prime.
// Requirements:
// - Function signature: consteval bool is_prime(const int n)
// - Return true if n is prime, false otherwise
// - Numbers less than 2 are not prime
// - Test with compile-time constants: is_prime(2), is_prime(17), is_prime(20), is_prime(97)
// - Use if constexpr to conditionally compile different messages based on results
// - Try calling with a runtime variable and observe the compilation error

// TASK 3: Static Sum Accumulator with Query
// Write two functions: 'accumulate' adds a value to a running total, 'get_total' returns current total.
// Requirements:
// - Function signatures:
//   void accumulate(const int value)
//   int get_total()
// - accumulate() adds the value to a static variable
// - get_total() returns the current total without modifying it
// - Test by: accumulate(10), accumulate(25), get_total(), accumulate(-5), get_total()
// - Print the total after each get_total() call

// TASK 4: Function with Multiple Default Parameters for Formatting
// Write a function called 'format_price' that formats and prints a price.
// Requirements:
// - Function signature: void format_price(const double price, 
//                                          const std::string currency = "USD",
//                                          const bool show_symbol = true,
//                                          const int decimal_places = 2)
// - Currency symbols: USD=$, EUR=€, GBP=£, JPY=¥
// - Format: "[symbol][price]" if show_symbol is true, "[price] [currency]" if false
// - Use std::fixed and std::setprecision for decimal places (include <iomanip>)
// - Test with:
//   - format_price(49.99) - all defaults
//   - format_price(29.50, "EUR") - custom currency
//   - format_price(99.95, "GBP", false) - no symbol
//   - format_price(1234.5, "JPY", true, 0) - zero decimals

// TASK 5: Array Sorting and Median
// Write three functions to work with integer arrays:
// Requirements:
// - void sort_array(int array[], const int length) - sorts array in ascending order
//   (implement bubble sort or selection sort)
// - double find_median(const int array[], const int length) - returns median value
//   (median is middle element if length is odd, average of two middle elements if even)
// - void print_array(const int array[], const int length) - prints array elements
// - Test with array: {45, 23, 67, 12, 89, 34, 56}
// - Print original array, sorted array, and median

// TASK 6: Vector Filtering and Transformation
// Write three functions that work with std::vector<int>:
// Requirements:
// - void keep_evens(std::vector<int> & vec) - removes all odd numbers
// - void multiply_by(std::vector<int> & vec, const int multiplier) - multiplies each element
// - int product_of_elements(const std::vector<int> & vec) - returns product of all elements
// - Test with vector: {3, 8, 15, 22, 9, 16, 5}
// - Print original vector
// - Keep only even numbers and print result
// - Multiply all elements by 3 and print result
// - Calculate and print product of final vector

// TASK 7: String Vector Search and Count
// Write three functions for working with std::vector<std::string>:
// Requirements:
// - int count_starting_with(const std::vector<std::string> & vec, const char letter)
//   - counts strings starting with specified letter (case-insensitive)
// - std::vector<std::string> filter_by_length(const std::vector<std::string> & vec, const int min_length)
//   - returns new vector containing only strings with length >= min_length
// - void print_with_length(const std::vector<std::string> & vec)
//   - prints each string with its length: "word (4 chars)"
// - Test with: {"apple", "Banana", "apricot", "Cherry", "avocado", "blueberry"}
// - Count strings starting with 'a' or 'A'
// - Filter strings with minimum length 6
// - Print all strings with their lengths

// TASK 8: Grade Management System
// Create a comprehensive grade management program:
// Requirements:
// - Create struct: struct Student { std::string name; std::vector<double> grades; };
// - Write function: void add_grade(Student & student, const double grade)
//   - adds grade to student's grade vector
// - Write function: double calculate_gpa(const Student & student)
//   - returns average of all grades (GPA)
// - Write function: char get_letter_grade(const double gpa)
//   - returns: 'A' (>=90), 'B' (>=80), 'C' (>=70), 'D' (>=60), 'F' (<60)
// - Write function: void print_student_report(const Student & student)
//   - prints: name, all grades, GPA, letter grade
// - In main: Create 2-3 students, add multiple grades to each, print reports

// TASK 9: Vector Statistics with Outlier Detection
// Create advanced statistics functions:
// Requirements:
// - double calculate_std_deviation(const std::vector<double> & vec)
//   - calculates standard deviation: sqrt(sum((x - mean)^2) / n)
//   - use <cmath> for sqrt function
// - std::vector<double> remove_outliers(const std::vector<double> & vec, const double threshold)
//   - removes values more than threshold standard deviations from mean
//   - returns new vector with outliers removed
// - void print_detailed_stats(const std::vector<double> & vec)
//   - prints: count, min, max, mean, standard deviation
// - Test with: {12.5, 15.3, 14.8, 13.9, 45.2, 14.1, 15.7, 13.2, 90.5, 14.5}
// - Print stats for original data
// - Remove outliers (threshold = 2.0) and print stats again

// TASK 10: Combined Challenge - Inventory System
// Create a simple inventory management system:
// Requirements:
// - Create struct: struct Item { std::string name; int quantity; double price; };
// - Write function: void add_item(std::vector<Item> & inventory, const Item & item)
// - Write function: double calculate_total_value(const std::vector<Item> & inventory)
//   - returns sum of (quantity * price) for all items
// - Write function: Item find_most_expensive(const std::vector<Item> & inventory)
//   - returns item with highest price
// - Write function: void print_inventory(const std::vector<Item> & inventory)
//   - prints table: "Name | Quantity | Price | Value"
// - Write function: void restock(std::vector<Item> & inventory, const std::string & name, const int amount)
//   - finds item by name and increases its quantity
// - In main: Create inventory with 5+ items, demonstrate all functions

// INSTRUCTIONS:
// - Implement each task in order
// - Test your functions thoroughly in the main() function
// - Use std::cout for output and format output clearly
// - Add meaningful comments to explain your logic
// - Pay attention to const correctness and pass-by-reference vs pass-by-value
// - Make sure your code compiles without errors or warnings

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <numeric> 

// TODO: TASK 1 - Write your factorial function here

constexpr long long factorial(const int n) {
    // Handle n = 0 and n = 1 (return 1)
    if (n <= 1) {
        return 1;
    }

    // Use iterative approach (loop)
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}


// TODO: TASK 2 - Write your is_prime function here

constexpr bool is_prime(const int n) {
    if (n < 2) {
        return false;
    }
    // Check for divisibility from 2 up to the square root of n
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// TODO: TASK 3 - Write your accumulate and get_total functions here

static int internal_total = 0;

void accumulate(const int value) {
    internal_total += value;
    std::cout << "Accumulating: " << value << std::endl;
}

int get_total() {
    return internal_total;
}

// TODO: TASK 4 - Write your format_price function here

void format_price(const double price,
    const std::string currency = "USD",
    const bool show_symbol = true,
    const int decimal_places = 2) {

    // Determine the symbol based on currency code
    std::string symbol = "";
    if (currency == "USD") symbol = "$";
    else if (currency == "EUR") symbol = "€";
    else if (currency == "GBP") symbol = "£";
    else if (currency == "JPY") symbol = "¥";
    else symbol = currency; // Fallback

    // Configure the output format for floating point numbers
    std::cout << std::fixed << std::setprecision(decimal_places);

    if (show_symbol) {
        std::cout << "Formatted: " << symbol << price << std::endl;
    }
    else {
        std::cout << "Formatted: " << price << " " << currency << std::endl;
    }

    // Reset formatting to default
    std::cout.unsetf(std::ios_base::floatfield);
}

// TODO: TASK 5 - Write your array sorting and median functions here

void print_array(const int array[], const int length) {
    std::cout << "{ ";
    for (int i = 0; i < length; ++i) {
        std::cout << array[i];
        if (i < length - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " }" << std::endl;
}

void sort_array(int array[], const int length) {
    for (int i = 0; i < length - 1; ++i) {
        for (int j = 0; j < length - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

double find_median(const int array[], const int length) {
    if (length == 0) return 0.0;

    if (length % 2 != 0) {
        return static_cast<double>(array[length / 2]);
    }
    else {
        int mid1 = array[(length / 2) - 1];
        int mid2 = array[length / 2];
        return (mid1 + mid2) / 2.0;
    }
}

// TODO: TASK 6 - Write your vector filtering functions here

void print_vector(const std::vector<int>& vec) {
    std::cout << "{ ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " }" << std::endl;
}

void keep_evens(std::vector<int>& vec) {
    auto it = vec.begin();
    while (it != vec.end()) {
        if (*it % 2 != 0) {
            it = vec.erase(it);
        }
        else {
            ++it;
        }
    }
}

void multiply_by(std::vector<int>& vec, const int multiplier) {
    for (int& val : vec) {
        val *= multiplier;
    }
}

long long product_of_elements(const std::vector<int>& vec) {
    if (vec.empty()) return 0;

    long long product = 1;
    for (const int val : vec) {
        product *= val;
    }
    return product;
}

// TODO: TASK 7 - Write your string vector search functions here

int count_starting_with(const std::vector<std::string>& vec, const char letter) {
    int count = 0;
    char target = std::tolower(static_cast<unsigned char>(letter));

    for (const std::string& str : vec) {
        if (!str.empty()) {
            char first = std::tolower(static_cast<unsigned char>(str[0]));
            if (first == target) {
                count++;
            }
        }
    }
    return count;
}

std::vector<std::string> filter_by_length(const std::vector<std::string>& vec, const int min_length) {
    std::vector<std::string> result;
    // Reserve memory to avoid reallocations 
    result.reserve(vec.size());

    for (const std::string& str : vec) {
        if (static_cast<int>(str.length()) >= min_length) {
            result.push_back(str);
        }
    }
    return result;
}

void print_with_length(const std::vector<std::string>& vec) {
    std::cout << "--- List Contents ---" << std::endl;
    for (const std::string& str : vec) {
        std::cout << str << " (" << str.length() << " chars)" << std::endl;
    }
    std::cout << "---------------------" << std::endl;
}

// TODO: TASK 8 - Write your Student struct and grade management functions here

struct Student {
    std::string name;
    std::vector<double> grades;
};

void add_grade(Student& student, const double grade) {
    if (grade >= 0.0 && grade <= 100.0) {
        student.grades.push_back(grade);
    }
    else {
        std::cout << "Warning: Invalid grade " << grade << " ignored for " << student.name << std::endl;
    }
}

double calculate_gpa(const Student& student) {
    if (student.grades.empty()) {
        return 0.0;
    }

    double sum = 0.0;
    for (const double grade : student.grades) {
        sum += grade;
    }
    return sum / student.grades.size();
}

char get_letter_grade(const double gpa) {
    if (gpa >= 90.0) return 'A';
    else if (gpa >= 80.0) return 'B';
    else if (gpa >= 70.0) return 'C';
    else if (gpa >= 60.0) return 'D';
    else return 'F';
}

void print_student_report(const Student& student) {
    std::cout << "\n--- Student Report ---" << std::endl;
    std::cout << "Name: " << student.name << std::endl;

    std::cout << "Grades: ";
    if (student.grades.empty()) {
        std::cout << "No grades recorded.";
    }
    else {
        std::cout << "[ ";
        for (size_t i = 0; i < student.grades.size(); ++i) {
            std::cout << std::fixed << std::setprecision(1) << student.grades[i];
            if (i < student.grades.size() - 1) std::cout << ", ";
        }
        std::cout << " ]";
    }
    std::cout << std::endl;

    double gpa = calculate_gpa(student);
    char letter = get_letter_grade(gpa);

    std::cout << "GPA: " << std::fixed << std::setprecision(2) << gpa << std::endl;
    std::cout << "Letter Grade: " << letter << std::endl;
    std::cout << "----------------------" << std::endl;
}

// TODO: TASK 9 - Write your advanced statistics functions here

double calculate_mean(const std::vector<double>& vec) {
    if (vec.empty()) return 0.0;
    double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
    return sum / vec.size();
}

double calculate_std_deviation(const std::vector<double>& vec) {
    if (vec.empty()) return 0.0;

    double mean = calculate_mean(vec);
    double sq_sum = 0.0;

    for (const double val : vec) {
        sq_sum += (val - mean) * (val - mean);
    }

    // Variance = sum of squared differences / n
    double variance = sq_sum / vec.size();

    return std::sqrt(variance);
}

std::vector<double> remove_outliers(const std::vector<double>& vec, const double threshold) {
    std::vector<double> filtered_vec;
    if (vec.empty()) return filtered_vec;

    double mean = calculate_mean(vec);
    double std_dev = calculate_std_deviation(vec);

    for (const double val : vec) {
        // Check if value is within [mean - cuttoff, mean + cutoff]
        // Equivalently: abs(val - mean) <= threshold * std_dev
        if (std::abs(val - mean) <= threshold * std_dev) {
            filtered_vec.push_back(val);
        }
    }
    return filtered_vec;
}

void print_detailed_stats(const std::vector<double>& vec) {
    std::cout << "--- Data Statistics ---" << std::endl;
    if (vec.empty()) {
        std::cout << "Dataset is empty." << std::endl;
        return;
    }

    double mean = calculate_mean(vec);
    double std_dev = calculate_std_deviation(vec);

    // Find min and max elements using iterators
    auto min_it = std::min_element(vec.begin(), vec.end());
    auto max_it = std::max_element(vec.begin(), vec.end());

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Count:   " << vec.size() << std::endl;
    std::cout << "Min:     " << *min_it << std::endl;
    std::cout << "Max:     " << *max_it << std::endl;
    std::cout << "Mean:    " << mean << std::endl;
    std::cout << "Std Dev: " << std_dev << std::endl;

    std::cout << "Values:  { ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) std::cout << ", ";
    }
    std::cout << " }" << std::endl;
    std::cout << "-----------------------" << std::endl;
}

// TODO: TASK 10 - Write your Item struct and inventory functions here

// Define the Item structure
struct Item {
    std::string name;
    int quantity;
    double price;
};

void add_item(std::vector<Item>& inventory, const Item& item) {
    inventory.push_back(item);
}

double calculate_total_value(const std::vector<Item>& inventory) {
    double total = 0.0;
    for (const auto& item : inventory) {
        total += item.quantity * item.price;
    }
    return total;
}

Item find_most_expensive(const std::vector<Item>& inventory) {
    if (inventory.empty()) {
        return { "", 0, 0.0 };
    }

    // Assume first item is most expensive initially
    Item most_expensive = inventory[0];

    for (size_t i = 1; i < inventory.size(); ++i) {
        if (inventory[i].price > most_expensive.price) {
            most_expensive = inventory[i];
        }
    }
    return most_expensive;
}

void restock(std::vector<Item>& inventory, const std::string& name, const int amount) {
    bool found = false;
    for (auto& item : inventory) {
        if (item.name == name) {
            item.quantity += amount;
            std::cout << "Restocked " << name << ": +" << amount << " (New Qty: " << item.quantity << ")" << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Error: Could not restock. Item '" << name << "' not found." << std::endl;
    }
}

void print_inventory(const std::vector<Item>& inventory) {
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(20) << "Name"
        << std::right << std::setw(10) << "Quantity"
        << std::right << std::setw(12) << "Price ($)"
        << std::right << std::setw(15) << "Value ($)" << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;

    std::cout << std::fixed << std::setprecision(2);

    for (const auto& item : inventory) {
        double item_total_value = item.quantity * item.price;
        std::cout << std::left << std::setw(20) << item.name
            << std::right << std::setw(10) << item.quantity
            << std::right << std::setw(12) << item.price
            << std::right << std::setw(15) << item_total_value << std::endl;
    }
    std::cout << "------------------------------------------------------------" << std::endl;
}

int main()
{
    std::cout << "=== FUNDAMENTALS OF COMPUTER PROGRAMMING - LABORATORY 2 ===\n\n";

    // TODO: TASK 1 - Test factorial function
    std::cout << "TASK 1: constexpr Factorial Function\n";
    std::cout << "-------------------------------------\n";
    
    std::cout << "Runtime tests:" << std::endl;
    std::cout << "factorial(5) = " << factorial(5) << std::endl;
    std::cout << "factorial(7) = " << factorial(7) << std::endl; 
    std::cout << "factorial(0) = " << factorial(0) << std::endl; 

    std::cout << "-----------------------------------" << std::endl;

    constexpr long long size = factorial(6);

    int staticArray[size];

    std::cout << "Array size determined at compile-time: " << size << std::endl;

    std::cout << "Size of array in bytes: " << sizeof(staticArray) << std::endl;
    std::cout << "\n";

    // TODO: TASK 2 - Test is_prime function
    std::cout << "TASK 2: consteval Prime Checker\n";
    std::cout << "--------------------------------\n";
    
    std::cout << "Checking primes at compile-time..." << std::endl;

    if constexpr (is_prime(2)) {
        std::cout << "2 is prime (Validated at compile-time)" << std::endl;
    }
    else {
        std::cout << "2 is NOT prime" << std::endl;
    }

    if constexpr (is_prime(17)) {
        std::cout << "17 is prime (Validated at compile-time)" << std::endl;
    }
    else {
        std::cout << "17 is NOT prime" << std::endl;
    }

    if constexpr (is_prime(20)) {
        std::cout << "20 is prime" << std::endl;
    }
    else {
        std::cout << "20 is NOT prime (Validated at compile-time)" << std::endl;
    }

    if constexpr (is_prime(97)) {
        std::cout << "97 is prime (Validated at compile-time)" << std::endl;
    }
    else {
        std::cout << "97 is NOT prime" << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    int runtime_val = 13;
    std::cout << "Runtime variable value: " << runtime_val << std::endl;


    std::cout << "Call with 'runtime_val' commented out to allow compilation." << std::endl;
    std::cout << "Uncommenting it would trigger: error: call to consteval function with non-constant argument" << std::endl;

    std::cout << "\n";

    // TODO: TASK 3 - Test accumulate functions
    std::cout << "TASK 3: Static Sum Accumulator\n";
    std::cout << "-------------------------------\n";
    
    std::cout << "--- Static Sum Accumulator Test ---" << std::endl;

    std::cout << "Initial Total: " << get_total() << std::endl;

    accumulate(10);
    accumulate(25);

    std::cout << "Total after adding 10 and 25: " << get_total() << std::endl;

    accumulate(-5);

    std::cout << "Total after adding -5: " << get_total() << std::endl;

    std::cout << "\n";

    // TODO: TASK 4 - Test format_price function
    std::cout << "TASK 4: Price Formatting with Defaults\n";
    std::cout << "---------------------------------------\n";
    
    std::cout << "--- Default Parameter Tests ---" << std::endl;

    // 1. All defaults used
    std::cout << "Call: format_price(49.99)" << std::endl;
    format_price(49.99);

    // 2. Custom currency, keeping show_symbol=true and decimal_places=2 defaults
    std::cout << "\nCall: format_price(29.50, \"EUR\")" << std::endl;
    format_price(29.50, "EUR");

    // 3. Custom currency and symbol flag, keeping decimal_places=2 default
    std::cout << "\nCall: format_price(99.95, \"GBP\", false)" << std::endl;
    format_price(99.95, "GBP", false);

    // 4. All parameters overridden
    std::cout << "\nCall: format_price(1234.5, \"JPY\", true, 0)" << std::endl;
    format_price(1234.5, "JPY", true, 0);
    std::cout << "\n";

    // TODO: TASK 5 - Test array sorting and median
    std::cout << "TASK 5: Array Sorting and Median\n";
    std::cout << "---------------------------------\n";
    
    int data[] = { 45, 23, 67, 12, 89, 34, 56 };
    const int length = sizeof(data) / sizeof(data[0]);

    std::cout << "--- Array Statistics ---" << std::endl;

    // 1. Print original array
    std::cout << "Original Array: ";
    print_array(data, length);

    // 2. Sort the array
    sort_array(data, length);

    // 3. Print sorted array
    std::cout << "Sorted Array:   ";
    print_array(data, length);

    // 4. Calculate and print median
    double median = find_median(data, length);
    std::cout << "Median: " << median << std::endl;
    std::cout << "\n";

    // TODO: TASK 6 - Test vector filtering
    std::cout << "TASK 6: Vector Filtering and Transformation\n";
    std::cout << "--------------------------------------------\n";
    
    std::vector<int> numbers = { 3, 8, 15, 22, 9, 16, 5 };

    std::cout << "--- Vector Operations Test ---" << std::endl;

    // 1. Print original vector
    std::cout << "Original Vector: ";
    print_vector(numbers);

    // 2. Keep only even numbers
    keep_evens(numbers);
    std::cout << "After keeping evens: ";
    print_vector(numbers);

    // 3. Multiply all elements by 3
    multiply_by(numbers, 3);
    std::cout << "After multiplying by 3: ";
    print_vector(numbers);

    // 4. Calculate and print product
    long long total_product = product_of_elements(numbers);
    std::cout << "Product of final elements: " << total_product << std::endl;
    std::cout << "\n";

    // TODO: TASK 7 - Test string vector search
    std::cout << "TASK 7: String Vector Search and Count\n";
    std::cout << "---------------------------------------\n";
    
    std::vector<std::string> words = {
       "apple", "Banana", "apricot", "Cherry", "avocado", "blueberry"
    };

    // 1. Print all strings with their lengths (Test of print_with_length)
    std::cout << "Original List:" << std::endl;
    print_with_length(words);

    // 2. Count strings starting with 'a' or 'A'
    char search_char = 'a';
    int count = count_starting_with(words, search_char);
    std::cout << "Strings starting with '" << search_char << "' (case-insensitive): "
        << count << std::endl;

    // 3. Filter strings with minimum length 6
    int min_len = 6;
    std::vector<std::string> long_words = filter_by_length(words, min_len);

    std::cout << "\nStrings with length >= " << min_len << ":" << std::endl;
    print_with_length(long_words);
    std::cout << "\n";

    // TODO: TASK 8 - Test grade management
    std::cout << "TASK 8: Grade Management System\n";
    std::cout << "--------------------------------\n";
    
    // Create Student 1: Alice
    Student s1;
    s1.name = "Alice Smith";
    add_grade(s1, 92.5);
    add_grade(s1, 88.0);
    add_grade(s1, 95.0);
    add_grade(s1, 100.0); 

    // Create Student 2: Bob
    Student s2;
    s2.name = "Bob Jones";
    add_grade(s2, 75.0);
    add_grade(s2, 68.5);
    add_grade(s2, 82.0);
    add_grade(s2, 79.0);

    // Create Student 3: Charlie
    Student s3;
    s3.name = "Charlie Brown";
    add_grade(s3, 55.0);
    add_grade(s3, 62.0);
    add_grade(s3, 48.0);

    // Print reports
    print_student_report(s1); 
    print_student_report(s2); 
    print_student_report(s3); 

    std::cout << "\n";

    // TODO: TASK 9 - Test statistics with outliers
    std::cout << "TASK 9: Statistics with Outlier Detection\n";
    std::cout << "------------------------------------------\n";
    
    // Test dataset with obvious outliers (45.2 and 90.5)
    std::vector<double> datas = { 12.5, 15.3, 14.8, 13.9, 45.2, 14.1, 15.7, 13.2, 90.5, 14.5 };

    // 1. Print stats for original data
    std::cout << "Original Dataset Analysis:" << std::endl;
    print_detailed_stats(datas);

    // 2. Remove outliers (threshold = 2.0 sigma)
    double threshold = 2.0;
    std::cout << "\nRemoving outliers (> " << threshold << " standard deviations from mean)..." << std::endl;

    std::vector<double> clean_data = remove_outliers(datas, threshold);

    // 3. Print stats for cleaned data
    std::cout << "\nCleaned Dataset Analysis:" << std::endl;
    print_detailed_stats(clean_data);
    std::cout << "\n";

    // TODO: TASK 10 - Test inventory system
    std::cout << "TASK 10: Inventory Management System\n";
    std::cout << "-------------------------------------\n";
    std::vector<Item> warehouse;

    std::cout << "--- Initializing Inventory System ---" << std::endl;

    // 1. Add items
    add_item(warehouse, { "Smartphone", 10, 699.00 });
    add_item(warehouse, { "Wireless Headset", 25, 149.99 });
    add_item(warehouse, { "Tablet", 12, 450.00 });
    add_item(warehouse, { "Smart Watch", 15, 299.50 });
    add_item(warehouse, { "Power Bank", 40, 49.99 });
    add_item(warehouse, { "Office Desk", 4, 350.00 });

    // 2. Print initial inventory
    std::cout << "\nCurrent Stock:";
    print_inventory(warehouse);

    // 3. Calculate total value
    double total_value = calculate_total_value(warehouse);
    std::cout << "\nTotal Inventory Value: $" << std::fixed << std::setprecision(2) << total_value << std::endl;

    // 4. Find most expensive item
    Item expensive_item = find_most_expensive(warehouse);
    std::cout << "Most Expensive Item:   " << expensive_item.name << " ($" << expensive_item.price << ")" << std::endl;

    // 5. Restock items
    std::cout << "\n--- Restocking Process ---" << std::endl;
    restock(warehouse, "Wireless Headset", 10);
    restock(warehouse, "Smartphone", 2);
    restock(warehouse, "Webcam", 5);

    // 6. Print final inventory and value
    std::cout << "\nFinal Stock:";
    print_inventory(warehouse);

    std::cout << "\nUpdated Total Value:   $" << calculate_total_value(warehouse) << std::endl;

    std::cout << "\n";

    std::cout << "=== ALL TASKS COMPLETED ===\n";
    return 0;
}