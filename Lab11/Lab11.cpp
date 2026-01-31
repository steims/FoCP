#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <deque>

/* TASK 1: Reverse Print Using Iterator

   Write a function that prints all elements of a vector in reverse order
   using a reverse iterator. Each element should be printed on a new line.

   Example output for vector {1, 2, 3}:
   3
   2
   1
*/
void reverse_print(const std::vector<int>& vec)
{
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        std::cout << *it << std::endl;
    }
}


/* TASK 2: Multiply All Elements

   Write a function that multiplies all elements in a vector by a given
   factor. Use std::for_each with a lambda function that captures the
   factor by value.

   Example: multiply_all({1, 2, 3}, 5) should change vector to {5, 10, 15}
*/
void multiply_all(std::vector<int>& vec, int factor)
{
    std::for_each(vec.begin(), vec.end(), [factor](int& n) {
        n *= factor;
        });
}


/* TASK 3: Sort Strings by Length

   Write a function that sorts a vector of strings by their length
   (shortest first). Use std::sort with a lambda function.

   Example: {"apple", "dog", "elephant", "cat"} becomes {"dog", "cat", "apple", "elephant"}
*/
void sort_by_length(std::vector<std::string>& vec)
{
    std::sort(vec.begin(), vec.end(), [](const std::string& a, const std::string& b) {
        return a.length() < b.length();
        });
}


/* TASK 4: Find Maximum Value

   Write a function that finds and returns the maximum value in a vector.
   Use std::for_each with a lambda function and capture the maximum
   value by reference.

   Example: find_maximum({3, 7, 2, 9, 1}) should return 9
*/
int find_maximum(const std::vector<int>& vec)
{
    if (vec.empty()) return 0; // Safety check

    int max_val = vec[0];

    std::for_each(vec.begin(), vec.end(), [&max_val](int n) {
        if (n > max_val) {
            max_val = n;
        }
        });

    return max_val;
}


/* TASK 5: Calculate Average

   Write a function that calculates the average of all elements in a
   vector of doubles. Use std::for_each with a lambda function.

   Example: calculate_average({2.0, 4.0, 6.0, 8.0}) should return 5.0
*/
double calculate_average(const std::vector<double>& vec)
{
    if (vec.empty()) return 0.0;

    double sum = 0.0;

    std::for_each(vec.begin(), vec.end(), [&sum](double n) {
        sum += n;
        });

    return sum / vec.size();
}



/* TASK 6: Erase All Negative Numbers

   Write a function that removes all negative numbers from a vector.
   Use an iterator and the erase method in a loop.

   Example: erase_negatives({1, -2, 3, -4, 5}) should result in {1, 3, 5}
*/
void erase_negatives(std::vector<int>& vec)
{
    for (auto it = vec.begin(); it != vec.end(); ) {
        if (*it < 0) {
            it = vec.erase(it);
        }
        else {
            ++it;
        }
    }
}


/* TASK 7: Merge Two Sorted Vectors

   Write a function that takes two sorted vectors and merges them into
   the first vector, maintaining sorted order. Use vector::insert with
   iterators, then sort the result.

   Example: merge_sorted({1, 3, 5}, {2, 4, 6})
            should result in first vector being {1, 2, 3, 4, 5, 6}
*/
void merge_sorted(std::vector<int>& first, const std::vector<int>& second)
{
    first.insert(first.end(), second.begin(), second.end());
    std::sort(first.begin(), first.end());
}


/* TASK 8: Count Strings Starting With Letter

   Write a function that counts how many strings in a vector start with
   a given letter (case-sensitive). Use std::for_each with a lambda
   function.

   Example: count_starting_with({"apple", "ant", "bear", "Alice"}, 'a')
            should return 2
*/
int count_starting_with(const std::vector<std::string>& vec, char letter)
{
    int count = 0;
    std::for_each(vec.begin(), vec.end(), [&count, letter](const std::string& s) {
        if (!s.empty() && s[0] == letter) {
            count++;
        }
        });

    return count;
}


/* MAIN FUNCTION - Test Your Solutions */

int main()
{
    std::cout << "--- TASK 1 ---" << std::endl;
    std::vector<int> v1 = { 1, 2, 3 };
    reverse_print(v1);

    std::cout << "\n--- TASK 2 ---" << std::endl;
    std::vector<int> v2 = { 1, 2, 3 };
    multiply_all(v2, 5);
    for (int i : v2) std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "\n--- TASK 3 ---" << std::endl;
    std::vector<std::string> v3 = { "apple", "dog", "elephant", "cat" };
    sort_by_length(v3);
    for (const auto& s : v3) std::cout << s << " ";
    std::cout << std::endl;

    std::cout << "\n--- TASK 4 ---" << std::endl;
    std::vector<int> v4 = { 3, 7, 2, 9, 1 };
    std::cout << find_maximum(v4) << std::endl;

    std::cout << "\n--- TASK 5 ---" << std::endl;
    std::vector<double> v5 = { 2.0, 4.0, 6.0, 8.0 };
    std::cout << calculate_average(v5) << std::endl;

    std::cout << "\n--- TASK 6 ---" << std::endl;
    std::vector<int> v6 = { 1, -2, 3, -4, 5 };
    erase_negatives(v6);
    for (int i : v6) std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "\n--- TASK 7 ---" << std::endl;
    std::vector<int> v7a = { 1, 3, 5 };
    std::vector<int> v7b = { 2, 4, 6 };
    merge_sorted(v7a, v7b);
    for (int i : v7a) std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "\n--- TASK 8 ---" << std::endl;
    std::vector<std::string> v8 = { "apple", "ant", "bear", "Alice" };
    std::cout << count_starting_with(v8, 'a') << std::endl;

    return 0;
}