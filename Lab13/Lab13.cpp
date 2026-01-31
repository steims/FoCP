#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>

/* TASK 1: Create and Use unique_ptr
   Write a function that creates a unique_ptr to an integer, sets its value
   to the given parameter, and returns the unique_ptr.

   Example: create_unique(42) should return a unique_ptr containing 42
*/
std::unique_ptr<int> create_unique(int value) {
    // TODO: Create a unique_ptr using std::make_unique and set the value
    return std::make_unique<int>(value); // Replace with actual unique_ptr
}

/* TASK 2: Transfer Ownership with unique_ptr
   Write a function that takes a unique_ptr by move, adds 100 to its value,
   and returns the modified unique_ptr.

   Example: If input unique_ptr contains 50, output should contain 150
*/
std::unique_ptr<int> add_hundred(std::unique_ptr<int> ptr) {
    if (ptr) {
        *ptr += 100;
    }
    return ptr;
}

/* TASK 3: Create Dynamic Array with unique_ptr
   Write a function that creates a unique_ptr to a dynamic array of doubles
   of given size, initializes all elements to their index * 2.5, and returns it.

   Example: create_array(4) should return array {0.0, 2.5, 5.0, 7.5}
*/
std::unique_ptr<double[]> create_array(std::size_t size) {
    auto arr = std::make_unique<double[]>(size);
    for (std::size_t i = 0; i < size; ++i)
    {
        arr[i] = i * 2.5;
    }
    return arr;
}

/* TASK 4: Shared Ownership with shared_ptr
   Write a function that creates a shared_ptr to an integer with given value
   and returns a vector containing 3 copies of that shared_ptr.
   All should point to the same value.

   Example: create_shared(99) returns vector with 3 shared_ptrs,
            all pointing to 99, use_count should be 3
*/
std::vector<std::shared_ptr<int>> create_shared(int value) {
    std::vector<std::shared_ptr<int>> ptrs;
    auto shared = std::make_shared<int>(value);
    ptrs.push_back(shared);
    ptrs.push_back(shared);
    ptrs.push_back(shared);
    return ptrs;
}

/* TASK 5: Custom strlen Implementation
   Write a function that calculates the length of a C-style string
   without using strlen. Use pointer arithmetic.

   Example: my_string_length("Hello") should return 5
*/
int my_string_length(const char* str) {
    const char* start = str;
    while (*str != '\0') {
        str++;
    }
    return static_cast<int>(str - start);
}

/* TASK 6: Custom strcpy Implementation
   Write a function that copies a C-style string from source to destination.
   Assume destination has enough space. Use pointer arithmetic.

   Example: my_string_copy(dest, "Copy") copies "Copy" to dest
*/
void my_string_copy(char* destination, const char* source) {
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
}

/* TASK 7: Custom strcat Implementation
   Write a function that concatenates (appends) source string to the end
   of destination string. Assume destination has enough space.

   Example: If dest = "Hello" and src = " World",
            result should be "Hello World" in dest
*/
void my_string_concat(char* destination, const char* source) {
    while (*destination != '\0') {
        destination++;
    }
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
}

/* TASK 8: Count Words in C-String
   Write a function that counts the number of words in a C-style string.
   Words are separated by spaces. Multiple spaces count as one separator.

   Example: count_words("Hello  World  C++") should return 3
*/
int count_words(const char* str) {
    int count = 0;
    bool in_word = false;
    while (*str != '\0') {
        if (*str != ' ') {
            if (!in_word) {
                count++;
                in_word = true;
            }
        }
        else {
            in_word = false;
        }
        str++;
    }
    return count;
}

/* MAIN FUNCTION - Test Your Solutions */
int main() {
    // Test TASK 1
    std::cout << "TASK 1: Create unique_ptr\n";
    std::unique_ptr<int> uPtr = create_unique(42);
    if (uPtr)
    {
        std::cout << "Value: " << *uPtr << std::endl;
    }
    std::cout << "\n";

    // Test TASK 2
    std::cout << "TASK 2: Transfer Ownership\n";
    std::unique_ptr<int> ptr = create_unique(50);
    ptr = add_hundred(std::move(ptr));
    std::cout << "Value: " << *ptr << std::endl;

    std::cout << "\n";

    // Test TASK 3
    std::cout << "TASK 3: Create Dynamic Array\n";
    std::size_t size = 4.0;
    auto arrPtr = create_array(size);
    std::cout << "Array valuse : ";
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << arrPtr[i] << " ";
    }
    std::cout << "\n";
    std::cout << "\n";

    // Test TASK 4
    std::cout << "TASK 4: Shared Ownership\n";
    auto sharedVec = create_shared(99);
    if (!sharedVec.empty()) {
        std::cout << "Value: " << *sharedVec[0] << "\n";
        std::cout << "Use count: " << sharedVec[0].use_count() << "\n";
    }
    std::cout << "\n";

    // Test TASK 5
    std::cout << "TASK 5: Custom strlen\n";
    std::cout << "Length: " << my_string_length("Hello") << "\n";

    std::cout << "\n";

    // Test TASK 6
    std::cout << "TASK 6: Custom strcpy\n";
    char destBuffer[50];
    my_string_copy(destBuffer, "Copy");
    std::cout << destBuffer << "\n\n";


    // Test TASK 7
    std::cout << "TASK 7: Custom strcat\n";
    my_string_copy(destBuffer, "Hello");
    my_string_concat(destBuffer, " World");
    std::cout << destBuffer << "\n\n";


    // Test TASK 8
    std::cout << "TASK 8: Count Words\n";
    std::cout << "Words: " << count_words("Hello  World  C++") << "\n";

    return 0;
}
