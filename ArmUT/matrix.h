#include <iostream>
#include <iomanip>

using namespace std;

void transMult(double t1[][4], double t2[][4], double result[][4]){			// Matrix Multiplication Function

	int row, column, ptr, sum_count = 0;
	double sum[16];

	for (row = 0; row < 4; row++)											// To be able to pass a matrix a both result and input matrix
		for (column = 0; column < 4; column++){								// instead of setting every element in each step,
																			// this function sets values after all the values calculated,
			sum[sum_count] = 0.0;											// to prevent result to be affected by itself when in multiplication.

			for (ptr = 0; ptr < 4; ptr++){

				sum[sum_count] = sum[sum_count] + (t1[row][ptr] * t2[ptr][column]);

			}

			sum_count++;
		}
			
	sum_count = 0;

	for (row = 0; row < 4; row++)
		for (column = 0; column < 4; column++)
			result[row][column] = sum[sum_count++];

}

void displayMatrix(double t1[][4]){											// Displaying Matrix Aligned

	for (int row = 0; row < 4; row++){

		cout << "\t";

		for (int column = 0; column < 4; column++){

			cout << internal << setw(6) << fixed << setprecision(3) << t1[row][column] << "\t\t";
		}

		cout << endl;

	}

}