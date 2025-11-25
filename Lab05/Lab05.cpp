// TASK 1: constexpr Power Function
// Write a constexpr function called 'power' that calculates base^exponent.
// Requirements:
// - Function signature: constexpr long int power(const int base, const int exponent)
// - Use iterative approach (loop)
// - Handle exponent = 0 (return 1)
// - Test with: power(2, 10), power(5, 3), power(3, 0)
// - Declare an array with size power(2, 4) to verify compile-time evaluation

// TASK 2: consteval Fibonacci
// Write a consteval function called 'fibonacci' that returns the nth Fibonacci number.
// Requirements:
// - Function signature: consteval long int fibonacci(const int n)
// - Use recursive approach
// - Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21...
// - Test with compile-time constants: fibonacci(0), fibonacci(10), fibonacci(15)
// - Try calling it with a runtime variable and observe the compilation error

// TASK 3: Static Counter with Reset
// Write a function called 'counter' with a static variable that counts calls.
// Then write a second function called 'reset_counter' that resets the count to 0.
// Requirements:
// - Function signatures: 
//   int counter()
//   void reset_counter()
// - counter() increments and returns the current count
// - Test by calling counter() 5 times, then reset_counter(), then counter() 3 more times
// - Print all returned values to verify the reset works

// TASK 4: Function with Multiple Default Parameters
// Write a function called 'print_grade' that prints student information.
// Requirements:
// - Function signature: void print_grade(const std::string name, const int score, 
//                                        const std::string course = "Programming", 
//                                        const std::string semester = "Fall 2025")
// - Print format: "[name] scored [score] in [course] ([semester])"
// - Test with: 
//   - All 4 parameters provided
//   - Only name and score (use defaults for course and semester)
//   - Name, score, and course (use default for semester)

// TASK 5: Array Statistics Functions
// Write three functions to work with double arrays:
// Requirements:
// - double find_max(const double array[], const int length) - returns maximum value
// - double find_min(const double array[], const int length) - returns minimum value
// - double calculate_average(const double array[], const int length) - returns average
// - Test with an array: {23.5, 67.8, 12.3, 89.1, 45.6, 34.2}
// - Print all three statistics

// TASK 6: Vector Manipulation
// Write two functions that work with std::vector<int>:
// Requirements:
// - void remove_negatives(std::vector<int> & vec) - removes all negative numbers
// - int sum_elements(const std::vector<int> & vec) - returns sum of all elements
// - Test with vector: {10, -5, 20, -15, 30, -25, 40}
// - Print vector before and after removing negatives
// - Print sum before and after removing negatives
// Hint: To remove elements, create a new vector with only positive values, 
//       then use vec = new_vector

// TASK 7: String Vector Operations
// Write two functions for working with std::vector<std::string>:
// Requirements:
// - void print_strings(const std::vector<std::string> & vec) - prints all strings
//   with their index: "0: first_string\n1: second_string\n..."
// - std::string find_longest(const std::vector<std::string> & vec) - returns the longest string
//   (if multiple strings have same max length, return the first one)
// - Test with: {"C++", "Python", "JavaScript", "Go", "Rust", "Assembly"}
// - Print all strings and identify the longest one

// TASK 8: Combined Challenge
// Create a program that:
// Requirements:
// - Declares a std::vector<double> to store temperatures
// - Write function: void add_temperature(std::vector<double> & temps, double temp)
// - Write function: void print_statistics(const std::vector<double> & temps) that prints:
//   - Number of readings
//   - Highest temperature
//   - Lowest temperature
//   - Average temperature
// - In main: Add at least 7 temperature readings (use push_back or your add_temperature function)
// - Call print_statistics to display the results
// - Test with temperatures like: {20.5, 22.3, 19.8, 23.1, 21.7, 18.9, 24.2}

// INSTRUCTIONS:
// - Implement each task in order
// - Test your functions in the main() function
// - Use std::cout for output
// - Add comments to explain your logic
// - Make sure your code compiles without errors

#include <iostream>
#include <string>
#include <vector>

// TODO: TASK 1 - Write your power function here

constexpr long int power(const int base, const int exponent) {
    // Handle exponent = 0 (and initialization for loop)
    long int result = 1;

    // Iterative approach
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }

    return result;
}


// TODO: TASK 2 - Write your fibonacci function here

long int fibonacci(const int n) {
    // Recursive approach
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}


// TODO: TASK 3 - Write your counter and reset_counter functions here

static int call_count = 0;

int counter() {
    return ++call_count;
}

void reset_counter() {
    call_count = 0;
}



// TODO: TASK 4 - Write your print_grade function here

void print_grade(const std::string name, const int score,
    const std::string course = "Programming",
    const std::string semester = "Fall 2025") {
    std::cout << name << " scored " << score
        << " in " << course
        << " (" << semester << ")" << std::endl;
}


// TODO: TASK 5 - Write your array statistics functions here

double find_max(const double array[], const int length) {
    if (length <= 0) return 0.0; 

    double maxVal = array[0];
    for (int i = 1; i < length; ++i) {
        if (array[i] > maxVal) {
            maxVal = array[i];
        }
    }
    return maxVal;
}

double find_min(const double array[], const int length) {
    if (length <= 0) return 0.0;

    double minVal = array[0];
    for (int i = 1; i < length; ++i) {
        if (array[i] < minVal) {
            minVal = array[i];
        }
    }
    return minVal;
}

double calculate_average(const double array[], const int length) {
    if (length <= 0) return 0.0; 

    double sum = 0.0;
    for (int i = 0; i < length; ++i) {
        sum += array[i];
    }
    return sum / length;
}

// TODO: TASK 6 - Write your vector manipulation functions here

int sum_elements(const std::vector<int>& vec) {
    int sum = 0;
    for (int num : vec) {
        sum += num;
    }
    return sum;
}

void remove_negatives(std::vector<int>& vec) {
    std::vector<int> positives;

    for (int num : vec) {
        if (num >= 0) {
            positives.push_back(num);
        }
    }

    vec = positives;
}

void print_vector(const std::vector<int>& vec) {
    std::cout << "{ ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << (i < vec.size() - 1 ? ", " : " ");
    }
    std::cout << " }" << std::endl;
}


// TODO: TASK 7 - Write your string vector functions here

void print_strings(const std::vector<std::string>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << i << ": " << vec[i] << std::endl;
    }
}

std::string find_longest(const std::vector<std::string>& vec) {
    if (vec.empty()) return "";

    std::string longest = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i].length() > longest.length()) {
            longest = vec[i];
        }
    }
    return longest;
}


// TODO: TASK 8 - Write your temperature functions here

void add_temperature(std::vector<double>& temps, double temp) {
    temps.push_back(temp);
}

void print_statistics(const std::vector<double>& temps) {
    std::cout << "--- Temperature Statistics ---" << std::endl;

    if (temps.empty()) {
        std::cout << "No readings available." << std::endl;
        return;
    }

    double max_temp = temps[0];
    double min_temp = temps[0];
    double sum = 0.0;

    for (double t : temps) {
        if (t > max_temp) max_temp = t;
        if (t < min_temp) min_temp = t;
        sum += t;
    }

    double average = sum / temps.size();

    std::cout << "Number of readings: " << temps.size() << std::endl;
    std::cout << "Highest temperature: " << max_temp << " C" << std::endl;
    std::cout << "Lowest temperature:  " << min_temp << " C" << std::endl;
    std::cout << "Average temperature: " << average << " C" << std::endl;
    std::cout << "------------------------------" << std::endl;
}


int main()
{
    std::cout << "=== FUNDAMENTALS OF COMPUTER PROGRAMMING - PRACTICE TASKS ===\n\n";

    // TODO: TASK 1 - Test power function
    std::cout << "TASK 1: constexpr Power Function\n";
    std::cout << "--------------------------------\n";

    std::cout << "power(2, 10) = " << power(2, 10) << std::endl;
    std::cout << "power(5, 3)  = " << power(5, 3) << std::endl;
    std::cout << "power(3, 0)  = " << power(3, 0) << std::endl;

    const int arraySize = power(2, 4);
    int verificationArray[arraySize];

    verificationArray[0] = 1;

    std::cout << "Array size determined at compile-time: " << sizeof(verificationArray) / sizeof(int) << std::endl;
    std::cout << "\n";

    // TODO: TASK 2 - Test fibonacci function
    std::cout << "TASK 2: consteval Fibonacci\n";
    std::cout << "----------------------------\n";
    
    std::cout << "Fibonacci(0)  = " << fibonacci(0) << std::endl;
    std::cout << "Fibonacci(10) = " << fibonacci(10) << std::endl;
    std::cout << "Fibonacci(15) = " << fibonacci(15) << std::endl;
    std::cout << "\n";

    // TODO: TASK 3 - Test counter functions
    std::cout << "TASK 3: Static Counter with Reset\n";
    std::cout << "----------------------------------\n";
    
    for (int i = 0; i < 5; ++i) {
        std::cout << counter() << " ";
    }
    std::cout << std::endl;

    reset_counter();

    for (int i = 0; i < 3; ++i) {
        std::cout << counter() << " ";
    }
    std::cout << std::endl;

    std::cout << "\n";

    // TODO: TASK 4 - Test print_grade function
    std::cout << "TASK 4: Function with Default Parameters\n";
    std::cout << "-----------------------------------------\n";
    
    print_grade("Alice", 95, "Data Structures", "Spring 2026");

    print_grade("Bob", 88);

    print_grade("Charlie", 92, "Calculus");
    std::cout << "\n";

    // TODO: TASK 5 - Test array statistics
    std::cout << "TASK 5: Array Statistics\n";
    std::cout << "------------------------\n";
    
    const double data[] = { 23.5, 67.8, 12.3, 89.1, 45.6, 34.2 };
    const int length = sizeof(data) / sizeof(data[0]);

    std::cout << "Data Set: { ";
    for (int i = 0; i < length; ++i) std::cout << data[i] << (i < length - 1 ? ", " : " ");
    std::cout << "}" << std::endl;

    std::cout << "Maximum Value: " << find_max(data, length) << std::endl;
    std::cout << "Minimum Value: " << find_min(data, length) << std::endl;
    std::cout << "Average Value: " << calculate_average(data, length) << std::endl;
    std::cout << "\n";

    // TODO: TASK 6 - Test vector manipulation
    std::cout << "TASK 6: Vector Manipulation\n";
    std::cout << "---------------------------\n";
    
    std::vector<int> numbers = { 10, -5, 20, -15, 30, -25, 40 };

    print_vector(numbers);
    std::cout << "Original Sum:    " << sum_elements(numbers) << std::endl;

    remove_negatives(numbers);

    print_vector(numbers);
    std::cout << "Modified Sum:    " << sum_elements(numbers) << std::endl;
    std::cout << "\n";

    // TODO: TASK 7 - Test string vector operations
    std::cout << "TASK 7: String Vector Operations\n";
    std::cout << "---------------------------------\n";

    std::vector<std::string> languages = { "C++", "Python", "JavaScript", "Go", "Rust", "Assembly" };

    std::cout << "Language List:" << std::endl;
    print_strings(languages);

    std::cout << "Longest String: " << find_longest(languages) << std::endl;
    std::cout << "\n";

    // TODO: TASK 8 - Test temperature statistics
    std::cout << "TASK 8: Temperature Statistics\n";
    std::cout << "------------------------------\n";
    
    std::vector<double> temperatures;

    add_temperature(temperatures, 20.5);
    add_temperature(temperatures, 22.3);
    add_temperature(temperatures, 19.8);
    add_temperature(temperatures, 23.1);
    add_temperature(temperatures, 21.7);
    add_temperature(temperatures, 18.9);
    add_temperature(temperatures, 24.2);

    print_statistics(temperatures);

    std::cout << "\n";

    return 0;
}