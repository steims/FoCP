#include <iostream>
using namespace std;
int main()
{
    int sudoku[10][10];
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			sudoku[i][j] = rand() %9 + 1;
			cout << sudoku[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
