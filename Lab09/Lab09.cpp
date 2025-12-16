/** @file */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <array>
#include <utility>

// Task 1: Create a struct called 'book' with fields for title, author, year of publication, 
// and number of pages. Then create a vector of at least 3 books and print out the author 
// of the second book in your collection.

struct book {
    std::string title;
    std::string author;
    int year;
    int pages;
};

// Task 2: Write a function that takes a vector of integers and returns a pair containing 
// the sum and the average of all numbers. Test it with the vector {12, 45, 67, 23, 89, 34}.

std::pair<int, double> calculateStats(const std::vector<int>&numbers) {
    if (numbers.empty()) return{ 0,0.0 };

    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    double average = static_cast<double>(sum)/numbers.size();
        return std::make_pair(sum, average);
}

// Task 3: Create a std::array of 5 doubles representing temperatures in Celsius. 
// Write code to find and display both the highest and lowest temperature from the array 
// without using any additional functions.



// Task 4: Build a simple phone book using std::map where the key is a person's name 
// and the value is their phone number. Add at least 4 entries, then write code to 
// look up and display a specific person's number. Also print all entries in the phone book.



// Task 5: Define a struct called 'student' that contains name, student ID number, 
// and a vector of grades. Create two students, add several grades to each, 
// then calculate and print the average grade for both students.

struct student {
    std::string name;
    int studentID;
    std::vector<double> grades;
};

// Task 6: Create a nested structure for a 'computer' that has fields for brand and model, 
// plus a nested struct for 'processor' containing manufacturer, model, and speed in GHz. 
// Initialize one computer object and print all its details.

struct processor {
    std::string manufacturer;
    std::string model;
    double speedGHz;
};
struct computer {
    std::string brand;
    std::string model;
    processor cpu;
};


// Task 7: Use std::map to count how many times each character appears in the string 
// "programming is fun and challenging". Display the results showing each character 
// and its count, but skip spaces in your counting.

int main()
{
    // Write your solutions here
    //task1
    std::cout << "--- Task 1 ---" << std::endl;
    std::vector<book> library;
    library.push_back({ "firtsB", "J.Lad", 2019, 409 });
    library.push_back({ "secendB", "Kasder", 2006, 523 });
    library.push_back({ "thirdB", "Oprerg", 1999, 478 });

    if (library.size() >= 2)
    {
        std::cout << "Author: " << library[1].author << std::endl;
    }
    std::cout << std::endl;


    //task2
    std::cout << "--- Task 2 ---" << std::endl;
    std::vector<int> numbers = { 12, 45, 67, 23, 89, 34 };
    std::pair<int, double> result = calculateStats(numbers);
    std::cout << "Sum: " << result.first << std::endl;
    std::cout << "Average: " << result.second << std::endl;
    std::cout << std::endl;

    //task3
    std::cout << "--- Task 3 ---" << std::endl;
    std::array<double, 5> temps = { 22.5, 18.0, 31.4, 15.2, 26.8 };
    double maxTemp = temps[0];
    double minTemp = temps[0];
    for (const auto& t : temps) {
        if (t > maxTemp) maxTemp = t;
        if (t < minTemp) minTemp = t;
    }
    std::cout << "Max tempo: " << maxTemp << " C" << std::endl;
    std::cout << "Min tempo: " << minTemp << " C" << std::endl;
    std::cout << std::endl;

    //task4
    std::cout << "--- Task 4 ---" << std::endl;
    std::map<std::string, std::string> phoneBook;
    phoneBook["Alice"] = "555-090-323";
    phoneBook["Bob"] = "443-567-090";
    phoneBook["Chris"] = "123-321-574";
    phoneBook["Diana"] = "675-764-034";

    std::string target = "Chris";
    if (phoneBook.find(target) != phoneBook.end())
    {
        std::cout << target << ": " << phoneBook[target] << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Full phoneBook: " << std::endl;
    for (const auto& entry : phoneBook)
    {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }
    std::cout << std::endl;


    //task5
    std::cout << "--- Task 5 ---" << std::endl;
    student s1 = { "John Doe", 1001, {85.5, 90.0, 94.0, 78.5} };
    student s2 = { "Jane Smith", 1002, {92.0, 88.5, 95.0, 91.0} };

    auto printAvg = [](const student& s) {
        double sum = 0;
        for (double g : s.grades) sum += g;
        double avg = s.grades.empty() ? 0.0 : sum / s.grades.size();
        std::cout << s.name << "Average: " << avg << std::endl;
        };
    printAvg(s1);
    printAvg(s2);
    std::cout << std::endl;



    return 0;
}