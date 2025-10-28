// Fundamentals of Computer Programming
// Laboratory 02 Tasks

// Included standard libraries
#include <iostream>
#include <cmath>
#include <iomanip>


// --------------------------------------------------------------
// TASK 1: Numerical Precision and Type Casting
// --------------------------------------------------------------
// 1. Print the value of 0.1 with default precision and with setprecision(30).
// 2. Print results of integer division and floating-point division of two numbers (e.g., 7 and 3).
// 3. Explain the difference in output and why it happens.
// 4. Demonstrate casting int to double before division.


// --------------------------------------------------------------
// TASK 2: Conditional Statements and Operators
// --------------------------------------------------------------
// 1. Ask the user for an integer number.
// 2. Check whether the number is even or odd using modulo (%).
// 3. Use the ternary operator to compute the absolute value of the number (without using std::abs).
// 4. Print both results (even/odd and absolute value).


// --------------------------------------------------------------
// TASK 3: Loops and Increment Operators
// --------------------------------------------------------------
// 1. Using a while loop, print numbers from 5 down to 1.
// 2. Using a do-while loop, print numbers from 1 to 5.
// 3. Using a for loop, print even numbers from 0 to 10.
// 4. In each loop, demonstrate difference between pre-increment (++i) and post-increment (i++).


// --------------------------------------------------------------
// TASK 4: Working with Loops
// --------------------------------------------------------------
// 1. Write a program that sums numbers from 1 to 100 using a for loop.
// 2. Write a while loop that reads numbers from the user until the user enters 0.
//    For each number, print whether it is positive or negative.
// 3. Write a for loop that prints the first 10 squares (1, 4, 9, ...).
// 4. Use nested loops to print a simple rectangle made of '*' characters
//    (for example, 4 rows and 6 columns).


// --------------------------------------------------------------
// Note: Each task should be implemented in a separate code block
// within the main() function. Use clear output formatting
// (e.g., "TASK 1 OUTPUT:" before each task’s results).
// --------------------------------------------------------------

int main()
{
    //task1
    double x = 0.1;
    std::cout << std::setprecision(30) << x << std::endl;

    int a = 7;
    float b = 3;
    std::cout << a / b << std::endl;

    std::cout << "When we use intigers, the solution always be intiger. \nBut when we divided intiger with floating - point numbers the result will be floating - point number. " << std::endl;

    int c = 5; 
    double d = 3;
    std::cout << c / d << std::endl;




    //task2
    int x;
    std::cout << "Enter number: \n";
    std::cin >> x;
    if (x%2 == 0)
    {
        std::cout << "The number is even \n";
    }
    else
    {
        std::cout << "The number is odd \n";
    }
    int absx = (x < 0) ? -x : x;
    std::cout << "The absolute value is: " << absx << std::endl;



    //task3
    std::cout << "While loop: " << std::endl;

    int x = 5;
    while (x >= 1)
    {
        std::cout << x << " ";
        --x;
    }
    std::cout << std::endl;
    std::cout << "Do-while loop: " << std::endl;
    
    int y = 1;
    do
    {
        std::cout << y << " ";
        ++y;
    } while (y <= 5);
    std::cout << std::endl;
    std::cout << "For loop: " << std::endl;

    int z = 0;
    for (int i = 0; i <= 10; i++)
    {
        if (i % 2 == 0)
        {
            std::cout << i << " ";
        }   
    }



    //task4
    int x = 0;
    for (int i = 1; i <= 100; i++)
    {
        x += i;
        std::cout << x << std::endl;
    }


    int n;
    std::cin >> n;
    while (n != 0)
    {
        if (n > 0)
        {
            std::cout << "positive " << n << std::endl;
        }
        else
        {
            std::cout << "negative " << n << std::endl;
        }
        std::cin >> n;
    }
    std::cout << "You enter 0" << std::endl;




    int a;
    for (int i = 1; i <= 10; i++)
    {
        std::cout << i * i << std::endl;
    }


    int row, col;
    std::cout << "Row:" << std::endl;
    std::cin >> row;
    std::cout << "Column:" << std::endl;
    std::cin >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }


    return 0;
}


