// Standard libraries
#include <iostream>   // input / output operations
#include <iomanip>    // number precision
#include <cmath>      // maths library
#include <string>     // std::string

/*
===========================================
LABORATORY TASKS — FUNDAMENTALS OF C++
===========================================

Task 1 — Hello, You!
--------------------
Goal: Practice basic input/output and strings.

1. Ask the user to enter their name and age.
2. Store the input in variables (std::string and int).
3. Print a message:
      Hello, Alice! You are 20 years old.
4. (Optional) Print the size (in bytes) of both variables using sizeof().


Task 2 — Simple Math
--------------------
Goal: Practice arithmetic operations and formatted output.

1. Declare two variables 'a' and 'b' as double.
2. Assign them values or read them from the user.
3. Calculate and print:
      sum = a + b
      difference = a - b
      product = a * b
      quotient = a / b
4. Use std::setprecision(3) to format the results (3 decimal places).


Task 3 — Solve a Linear Equation
--------------------------------
Goal: Practice if-else conditions and logic.

1. The equation is: a * x + b = 0
2. Ask the user to input 'a' and 'b'.
3. If a == 0:
      - If b == 0 → print "Equation always true"
      - Else → print "No solution"
4. Otherwise compute:
      x = -b / a
   and print the result.


Task 4 — True or False
----------------------
Goal: Practice boolean variables and conditional statements.

1. Declare a bool variable 'lightOn'.
2. Ask the user to type 1 for "light on" or 0 for "light off".
3. If lightOn is true → print "The room is bright!"
   Else → print "It's dark in here."
4. Try assigning other values like -1 or 3 and observe what happens.

===========================================
End of Tasks
===========================================
*/

int main()
{
        //task1

    std::string name;
    int age;
    std::cin >> name >> age;
    
    std::cout << "Hello, " << name << "! You are " << age << " years old.\n";
    std::cout << "It's " << sizeof(name) + sizeof(age) << " bits";


        //task2

    double a, b;
    double sum, difference, product, quotient;
    std::cin >> a >> b;
    sum =a + b;
    difference = a - b;
    product = a * b;
    quotient = a / b;
    std::cout << std::fixed << std::setprecision(3);
    std::cout << sum << std::endl;
    std::cout << difference << std::endl;
    std::cout << product << std::endl;
    std::cout << quotient << std::endl; 


        //task3
    double a, b, x;
    std::cin >> a >> b;
    if (a == 0) {
        if (b == 0)
        {
            std::cout << "Equation always true";
        }
        else {
            std::cout << "No solution";
        }
    }
    else{
        x = -b / a;
        std::cout << x;
    }


            //task4
     bool lightOn;
     std::cout << "type 1 for light on or for light off\n";
     std::cin >> lightOn;
     if (lightOn) {
         if (true)
             std::cout << "The room is bright!" << std::endl;

     }
     else {
             std::cout << "It's dark in here." << std::endl;
         }
     


    return 0;
}