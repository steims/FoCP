#include <iostream>

// ============================================================================
// TASK 1: Pointer Basics (10 minutes)
// ============================================================================
// Create a function swap_values that takes two integer pointers and swaps
// the values they point to.
// Example: if a=5 and b=10, after calling swap_values(&a, &b), a=10 and b=5
//
// Requirements:
// - Use pointers (not references)
// - Function signature: void swap_values(int* a, int* b)
// ============================================================================

void swap_values(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


// ============================================================================
// TASK 2: Pointer Arithmetic (10 minutes)
// ============================================================================
// Create a function find_max that finds the maximum value in an array using
// pointer arithmetic (no array indexing []).
//
// Requirements:
// - Use only pointer arithmetic (no array[i] notation)
// - Function signature: int find_max(int* array, int size)
// - Return the maximum value found
// ============================================================================

int find_max(int* array, int size)
{
    int max_val = *array;
    for (int* ptr = array + 1; ptr < array + size; ptr++)
    {
        if (*ptr > max_val)
        {
            max_val = *ptr;
        }
    }
    return max_val;
}


// ============================================================================
// TASK 3: Pointer to Pointer (12 minutes)
// ============================================================================
// Create a function that takes a pointer to a pointer and changes where
// the original pointer points to.
// 
// Given: int a = 10, b = 20; int* p = &a;
// After calling: redirect_pointer(&p, &b);
// Result: p now points to b (so *p == 20)
//
// Requirements:
// - Function signature: void redirect_pointer(int** ptr, int* new_target)
// ============================================================================

void redirect_pointer(int** ptr, int* new_target)
{
    *ptr = new_target;
}


// ============================================================================
// TASK 4: Const Pointers (10 minutes)
// ============================================================================
// Create three functions demonstrating different const pointer types:
// 
// a) print_value: pointer to const int - can change where it points,
//    cannot change the value
// b) increment_value: const pointer to int - cannot change where it points,
//    can change the value
// c) display_value: const pointer to const int - cannot change either
//
// Requirements:
// - void print_value(const int* ptr)
// - void increment_value(int* const ptr)
// - void display_value(const int* const ptr)
// ============================================================================

void print_value(const int* ptr)
{
    if (ptr != nullptr)
    {
        std::cout << "Value: " << *ptr << std::endl;
    }
}

void increment_value(int* const ptr)
{
    if (ptr != nullptr)
    {
        (*ptr)++;
    }
}

void display_value(const int* const ptr)
{
    if (ptr != nullptr)
    {
        std::cout << "Display: " << *ptr << std::endl;
    }
}


// ============================================================================
// TASK 5: Array Reversal (15 minutes)
// ============================================================================
// Create a function reverse_array that reverses an array in-place using
// pointers.
//
// Example: {1, 2, 3, 4, 5} becomes {5, 4, 3, 2, 1}
//
// Requirements:
// - Use two pointers (one from start, one from end)
// - Function signature: void reverse_array(int* array, int size)
// - Modify the array in-place
// ============================================================================

void reverse_array(int* array, int size)
{
    int* start = array;
    int* end = array + size - 1;
    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}


// ============================================================================
// TASK 6: Pointer Range Functions (12 minutes)
// ============================================================================
// Create a function sum_range that calculates the sum of elements in a range
// defined by two pointers [begin, end).
//
// Requirements:
// - Use pointer arithmetic
// - Function signature: int sum_range(int* begin, int* end)
// - end points one past the last element (like STL iterators)
// ============================================================================

int sum_range(int* begin, int* end)
{
    int total = 0;
    for (int* ptr = begin; ptr < end; ptr++)
    {
        total += *ptr;
    }
    return total;
}


// ============================================================================
// TASK 7: Structure Pointers (12 minutes)
// ============================================================================
// Create a structure Point with x and y coordinates.
// Create a function move_point that takes a pointer to Point and dx, dy values
// and moves the point by adding dx to x and dy to y.
// Create a function print_point that prints a point using -> operator.
//
// Requirements:
// - struct Point { double x, y; };
// - void move_point(Point* p, double dx, double dy)
// - void print_point(const Point* p)
// ============================================================================

struct Point
{
    double x, y;
};

void move_point(Point* p, double dx, double dy)
{
    p->x += dx;
    p->y += dy;
}

void print_point(const Point* p)
{
    if (p != nullptr)
    {
        std::cout << "Point(" << p->x << ", " << p->y << ")" << std::endl;
    }
}


// ============================================================================
// TASK 8: Multiple Output Parameters (15 minutes)
// ============================================================================
// Create a function analyze_array that takes an array and returns multiple
// statistics through output parameters (using pointers):
// - minimum value
// - maximum value
// - sum of all elements
// - average value
//
// Requirements:
// - Function signature: 
//   void analyze_array(int* array, int size, int* min, int* max, 
//                      int* sum, double* avg)
// - Use pointers for all output parameters
// ============================================================================

void analyze_array(int* array, int size, int* min, int* max,
    int* sum, double* avg)
{
    if (size <= 0) return;
    int current_min = array[0];
    int current_max = array[0];
    int current_sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] < current_min)
            current_min = array[i];
        if (array[i] > current_max)
            current_max = array[i];
        current_sum += array[i];
    }

    *min = current_min;
    *max = current_max;
    *sum = current_sum;
    *avg = static_cast<double>(current_sum) / size;
}


// ============================================================================
// MAIN FUNCTION - Test your implementations here
// ============================================================================

int main()
{
    std::cout << "POINTER TASKS - PRACTICE SESSION\n";
    std::cout << "=================================\n\n";

    // Test TASK 1: swap_values
    {
        std::cout << "TASK 1: Swap Values\n";
        std::cout << "-------------------\n";
        int a = 5, b = 10;
        std::cout << "Before: a = " << a << ", b = " << b << "\n";
        swap_values(&a, &b);
        std::cout << "After:  a = " << a << ", b = " << b << "\n";
        std::cout << "Expected: a = 10, b = 5\n\n";
    }

    // Test TASK 2: find_max
    {
        std::cout << "TASK 2: Find Maximum\n";
        std::cout << "--------------------\n";
        int arr[] = { 3, 7, 2, 9, 1, 5 };
        int size = 6;
        int max = find_max(arr, size);
        std::cout << "Array: {3, 7, 2, 9, 1, 5}\n";
        std::cout << "Maximum: " << max << "\n";
        std::cout << "Expected: 9\n\n";
    }

    // Test TASK 3: redirect_pointer
    {
        std::cout << "TASK 3: Redirect Pointer\n";
        std::cout << "------------------------\n";
        int a = 10, b = 20;
        int* p = &a;
        std::cout << "Before: *p = " << *p << " (pointing to a)\n";
        redirect_pointer(&p, &b);
        std::cout << "After:  *p = " << *p << " (pointing to b)\n";
        std::cout << "Expected: *p = 20\n\n";
    }

    // Test TASK 4: const pointers
    {
        std::cout << "TASK 4: Const Pointers\n";
        std::cout << "----------------------\n";
        int value = 42;
        std::cout << "Original value: " << value << "\n";
        print_value(&value);
        increment_value(&value);
        std::cout << "After increment: " << value << "\n";
        display_value(&value);
        std::cout << "\n";
    }

    // Test TASK 5: reverse_array
    {
        std::cout << "TASK 5: Reverse Array\n";
        std::cout << "---------------------\n";
        int arr[] = { 1, 2, 3, 4, 5 };
        int size = 5;
        std::cout << "Before: ";
        for (int i = 0; i < size; ++i)
            std::cout << arr[i] << " ";
        std::cout << "\n";

        reverse_array(arr, size);

        std::cout << "After:  ";
        for (int i = 0; i < size; ++i)
            std::cout << arr[i] << " ";
        std::cout << "\n";
        std::cout << "Expected: 5 4 3 2 1\n\n";
    }

    // Test TASK 6: sum_range
    {
        std::cout << "TASK 6: Sum Range\n";
        std::cout << "-----------------\n";
        int arr[] = { 10, 20, 30, 40, 50 };
        int sum = sum_range(arr, arr + 5);
        std::cout << "Array: {10, 20, 30, 40, 50}\n";
        std::cout << "Sum: " << sum << "\n";
        std::cout << "Expected: 150\n\n";
    }

    // Test TASK 7: Point structure
    {
        std::cout << "TASK 7: Point Structure\n";
        std::cout << "-----------------------\n";
        Point p = { 3.0, 4.0 };
        std::cout << "Initial point: ";
        print_point(&p);
        move_point(&p, 2.5, -1.5);
        std::cout << "After moving by (2.5, -1.5): ";
        print_point(&p);
        std::cout << "Expected: (5.5, 2.5)\n\n";
    }

    // Test TASK 8: analyze_array
    {
        std::cout << "TASK 8: Analyze Array\n";
        std::cout << "---------------------\n";
        int arr[] = { 5, 2, 8, 1, 9, 3 };
        int size = 6;
        int min, max, sum;
        double avg;

        analyze_array(arr, size, &min, &max, &sum, &avg);

        std::cout << "Array: {5, 2, 8, 1, 9, 3}\n";
        std::cout << "Minimum: " << min << "\n";
        std::cout << "Maximum: " << max << "\n";
        std::cout << "Sum: " << sum << "\n";
        std::cout << "Average: " << avg << "\n";
        std::cout << "Expected: min=1, max=9, sum=28, avg=4.666...\n\n";
    }

    std::cout << "=================================\n";
    std::cout << "All tasks completed!\n";

    return 0;
}