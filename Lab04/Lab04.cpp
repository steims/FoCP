/**
 *
 * FUNDAMENTALS OF COMPUTER PROGRAMMING
 * Lecture 4: Functions — PRACTICE TASKS
 *
 * Instructions:
 *   - Complete the following 5 tasks.
 *   - Each task focuses on understanding and applying functions, parameters, and recursion.
 *   - Use the examples from lecture code as inspiration.
 *   - You can compile and run after each task to test your work.
 *
 * Estimated total time: ~1.5 hours
 */

#include <iostream>
#include <cmath>
#include <random>
#include <chrono>
#include <numbers>

using namespace std;

/* ----------------------------------------------------------
   TASK 1: Simple Function — Sum of Three Numbers
   ----------------------------------------------------------
   Create a function called `sum3` that takes THREE numbers
   (double a, double b, double c) and returns their sum.

   Example:
      sum3(1.0, 2.0, 3.0) → 6.0

   Hints:
   - You can use the style of `f_sum` from the lecture.
   - Then, call it from main() and print the result.
*/

double sum3(double a, double b, double c) {
    double result;
    result = a + b + c;
    return result;
}




/* ----------------------------------------------------------
   TASK 2: Stars with a Twist — print_stars_advanced
   ----------------------------------------------------------
   Create a function `print_stars_advanced(int s, char symbol)`
   that prints a line of s symbols (for example, '*', '#', or '$')
   between square brackets.

   Example:
      print_stars_advanced(5, '#') → [#####]

   Hints:
   - Similar to `print_stars(int s)` from the lecture.
   - Use a while or for loop.
*/

void print_stars_advanced(int s, char symbol) {
    cout << '[';
    while (s > 0)
    {
        cout << symbol;
        --s;
    }
    cout << ']' << endl;

}



/* ----------------------------------------------------------
   TASK 3: Recursion Practice — Factorial
   ----------------------------------------------------------
   Write a recursive function `factorial(int n)` that returns n!.

   Example:
      factorial(5) → 120

   Rules:
   - Use recursion (function calls itself).
   - Use 1 as the base case: factorial(1) = 1.
   - No loops allowed.

   Bonus:
   - Try printing the intermediate values to see recursion in action.
*/

 int factorial(int n) {
    if (n < 2)
        return 1;
    else
        return n * factorial(n - 1);

}



/* ----------------------------------------------------------
   TASK 4: Monte Carlo π Approximation (simplified)
   ----------------------------------------------------------
   Using the lecture’s `pi_monte_carlo` as inspiration,
   write a simpler version: `estimate_pi(int shots)`.

   Requirements:
   - Randomly generate x and y between -1 and 1.
   - Count how many points fall inside the unit circle (x*x + y*y < 1).
   - Return the estimate 4.0 * inside / shots.
   - Test it with 10,000 samples and print the result.

   Hints:
   - Use <random> and <chrono> for generating random numbers.
   - You can copy parts of `pi_monte_carlo()` and simplify them.
*/

double estimate_pi(int shots)
{
    default_random_engine engine(chrono::system_clock::now().time_since_epoch().count());
    uniform_real_distribution<double> distro(-1, 1);

    int circle{ 0 };
    for (int i = 0; i < shots; ++i)
    {
        double x = distro(engine);
        double y = distro(engine);

        if (x * x + y * y < 1)
        {
            circle++;
        }
    }
    return 4.0 * circle / shots;
}





/* ----------------------------------------------------------
   TASK 5: Inline Function — Minimum of Two Numbers
   ----------------------------------------------------------
   Create an inline function `minimum(double a, double b)`
   that returns the smaller of the two values.

   Example:
      minimum(5.3, 2.1) → 2.1

   Hints:
   - Use the conditional (ternary) operator ? :
   - Then, test it in main() with several examples.
*/

double minimum(double a, double b) {
    return (a < b) ? a : b;
}



/* ----------------------------------------------------------
   MAIN FUNCTION
   ----------------------------------------------------------
   Test all your functions here.
   Uncomment and modify the test calls after completing each task.
*/

int main()
{
   cout << "=== Function Practice Tasks ===" << endl;

    // TASK 1 test
   cout << "Sum of three: " << sum3(1.1, 2.2, 3.3) << endl;
   cout << "Sum of three: " << sum3(1.0, 2.0, 3.0) << endl;
    
   // TASK 2 test
   
   print_stars_advanced(5, '#');
   print_stars_advanced(8, '*');
   print_stars_advanced(2, '$');
   
   // TASK 3 test
    
   cout << "Factorial of 5: " << factorial(5) << endl;
   cout << "Factorial of 1: " << factorial(1) << endl;
   cout << "Factorial of 0: " << factorial(0) << endl;
   cout << "Factorial of 7: " << factorial(7) << endl;
    
   // TASK 4 test
    
   cout << "Estimated π: " << estimate_pi(10000) << endl;
   
   // TASK 5 test
   
   cout << "Minimum of 10 and 3.14: " << minimum(10, 3.14) << endl;
   cout << "Minimum of 3.14 and 10: " << minimum(3.14, 10) << endl;
   cout << "Minimum of 11 and 5: " << minimum(11, 5) << endl;
   cout << "Minimum of 1 and 7.22: " << minimum(1, 7.22) << endl;
   cout << "Minimum of 5.3 and 2.1: " << minimum(5.3, 2.1) << endl;
   cout << "Minimum of 4.5 and 8.14: " << minimum(4.5, 8.14) << endl;
   cout << "Minimum of 76 and 34: " << minimum(76, 34) << endl;
   cout << "Minimum of 45.78 and 87.98: " << minimum(45.78, 87.98) << endl;
   
   return 0;
}

/*
  End of file.
  Practice makes progress — not perfection.

*/
