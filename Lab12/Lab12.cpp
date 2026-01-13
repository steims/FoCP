#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

double add(const double l, const double p);
double subtract(const double l, const double p);
double multiply(const double l, const double p);
bool greater_than(double a, double b);
double double_val(double x);

/* TASK 1: Apply Operation Using Function Pointer
   Write a function that takes two doubles and a pointer to a function,
   then applies that function to the two numbers and returns the result.
   The function should work with add, subtract, and multiply functions.

   Example: apply_operation(10.0, 5.0, add) should return 15.0
*/
double apply_operation(double a, double b, double (*op)(const double, const double)) {
    return op(a, b);
}


/* TASK 2: Array of Function Pointers
   Write a function that creates an array of function pointers (add, subtract, multiply)
   and applies all three operations to two given numbers. Store the results in a
   vector and return it.

   Example: all_operations(8.0, 2.0) should return {10.0, 6.0, 16.0}
*/
std::vector<double> all_operations(double a, double b) {
    std::vector<double> results;
    double (*operations[])(const double, const double) = { add, subtract, multiply };
    for (int i = 0; i < 3; ++i) {
        results.push_back(operations[i](a, b));
    }
    return results; // Replace with actual results
}


/* TASK 3: Transform Array Using Function Pointer
   Write a function that takes a pointer to the beginning of an array,
   a pointer past the last element, and a function pointer that transforms
   each double value. Apply the transformation to all elements.

   Example: transform_array with a function that doubles values:
            {1.0, 2.0, 3.0} becomes {2.0, 4.0, 6.0}
*/
void transform_array(double* begin, double* past_the_last,
    double (*transform_func)(double)) {
    for (double* ptr = begin; ptr != past_the_last; ++ptr) {
        *ptr = transform_func(*ptr);
    }
}


/* TASK 4: Custom Operation with Lambda
   Write a function that takes two integers and performs a custom operation
   using std::function and a lambda. The lambda should calculate:
   (a * b) + (a - b)

   Example: custom_calc(5, 3) should return 5*3 + 5-3 = 15 + 2 = 17
*/
int custom_calc(int a, int b) {
    std::function<int(int, int)> operation = [](int x, int y) -> int {return (x * y) + (x - y);
        };
    return operation(a, b);
}


/* TASK 5: Filter Array Using Pointer Arithmetic
   Write a function that takes a pointer to an array of doubles, its size,
   and a threshold value. Count how many elements are greater than the threshold
   using pointer arithmetic (no array indexing with []).

   Example: count_above_threshold({1.5, 3.7, 2.1, 4.9}, 4, 2.5) should return 2
*/
int count_above_threshold(double* arr, int size, double threshold) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (*(arr + i) > threshold) {
            count++;
        }
    }
    return count; 
}


/* TASK 6: Typedef for Function Pointer
   Create a typedef for a function pointer that takes two doubles and returns a double.
   Then write a function that accepts this typedef as a parameter and applies it
   to calculate the result of: operation(a, b) * 2

   Example: Using add function: double_operation(4.0, 6.0, add) should return 20.0
*/

typedef double (*operation_func)(const double, const double);

double double_operation(double a, double b, operation_func op) {
    return op(a, b) * 2.0; 
}


/* TASK 7: Find Maximum Using Custom Comparator
   Write a function that finds the maximum value in an array of doubles
   using pointer arithmetic and a comparison function pointer. The comparison
   function should return true if first argument is greater than second.

   Example: find_max_with_compare({2.5, 7.1, 3.9, 5.2}, 4, greater_than)
            should return 7.1
*/
double find_max_with_compare(double* arr, int size,
    bool (*compare)(double, double)) {
    if (size <= 0) return 0.0;
    double current_max = *arr;
    for (int i = 1; i < size; ++i) {
        double val = *(arr + i);
        if (compare(val, current_max)) {
            current_max = val;
        }
    }
    return current_max; 
}


/* HELPER FUNCTIONS - Implement these as well */

// Helper for TASK 1, 2, 6
double add(const double l, const double p) {
    return l + p;
}

double subtract(const double l, const double p) {
    return l - p;
}

double multiply(const double l, const double p) {
    return l * p;
}

// Helper for TASK 7
bool greater_than(double a, double b) {
    return a > b;
}
double double_val(double x) {
    return x * 2.0;
}


/* MAIN FUNCTION - Test Your Solutions */
int main() {
    
    // Test TASK 1
    std::cout << "TASK 1: Apply Operation\n";
    std::cout << "Add: " << apply_operation(10.0, 5.0, add) << std::endl;
    std::cout << "Sub: " << apply_operation(10.0, 5.0, subtract) << std::endl;
    std::cout << "Multi: " << apply_operation(10.0, 5.0, multiply) << std::endl;
    std::cout << std::endl;

    // Test TASK 2
    std::cout << "\nTASK 2: All Operations\n";
    std::vector<double> ops = all_operations(8.0, 2.0);
    std::cout << "Results: " << std::endl;
    for (double d : ops) std::cout << d << std::endl;
    std::cout << std::endl;

    // Test TASK 3
    std::cout << "\nTASK 3: Transform Array\n";
    double data[] = { 1.0, 2.0, 3.0 };
    std::cout << "Before: 1 2 3" << std::endl;
    transform_array(data, data + 4, double_val);
    std::cout << "After: ";
    for(double d : data) std::cout << d << " ";
    std::cout << std::endl;
    

    // Test TASK 4
    std::cout << "\nTASK 4: Custom Calculation\n";
    std::cout << "Result: " << custom_calc(5, 3) << std::endl;


    // Test TASK 5
    std::cout << "\nTASK 5: Count Above Threshold\n";
    double threshold_arr[] = { 1.5, 3.7, 2.1, 4.9, 0.5 };
    int count = count_above_threshold(threshold_arr, 4, 2.5);
    std::cout << "Count: " << count << std::endl;

    // Test TASK 6
    std::cout << "\nTASK 6: Double Operation\n";
    std::cout << "Result: " << double_operation(4.0, 6.0, add) << std::endl;

    // Test TASK 7
    std::cout << "\nTASK 7: Find Maximum\n";
    double max_arr[] = { 2.5, 7.1, 3.9, 5.2 };
    double max_val = find_max_with_compare(max_arr, 4, greater_than);
    std::cout << "Max value: " << max_val << std::endl;

    return 0;
}