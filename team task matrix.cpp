/*
Program: operation on 2 matrix
Purpose: Demonstrate use of struct and operator
		  overloading to create matrix and
		  functions to operation on matrix
 Author:  Mina Emad Lotfy & Mina Botros
 ID's  :  20170309 , 20170307
 Date  :  8/10/82018
 Version: 1.0
*/
#include "pch.h"
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

struct matrix
{
	int** data;
	int row, col;
};

void menu();

void createMatrix(int row, int col, matrix& mat);   //done
matrix operator+  (matrix mat1, matrix mat2);   // done
matrix operator-  (matrix mat1, matrix mat2);   //done
matrix operator*  (matrix mat1, matrix mat2);   //done
matrix operator+  (matrix mat1, int scalar);    //done
matrix operator-  (matrix mat1, int scalar);    //done
matrix operator*  (matrix mat1, int scalar);    //done

matrix operator+= (matrix& mat1, matrix mat2);  //done
matrix operator-= (matrix& mat1, matrix mat2);  //done
matrix operator+= (matrix& mat, int scalar);    //done
matrix operator-= (matrix& mat, int scalar);    //done
void   operator++ (matrix& mat);    //done
void   operator-- (matrix& mat);    //done
istream& operator>> (istream& in, matrix& mat);	// done
ostream& operator<< (ostream& out, matrix mat);	// done

bool   operator== (matrix mat1, matrix mat2);    //done
bool   operator!= (matrix mat1, matrix mat2);    //done
bool   isSquare(matrix mat); //done
bool   isSymetric(matrix mat);  // done
bool   isIdentity(matrix mat);  // done
matrix transpose(matrix mat);   //done

int main()
{
	matrix mat1, mat2;
	int choice, num_matrix;
	cout << "						ahlan ya user ya 7abibi XD XD "<< endl;
	while (true) {
		menu();
		cout << "\n\n";
		cout << "Enter your Choice : ";
		cin >> choice;

		if (choice == 1) {
			int row, col;
			cout << "Enter number of rows : ";
			cin >> row;
			cout << "Enter number of columns : ";
			cin >> col;
			cout << "Enter the number of the matrix (1 or 2) : ";
			cin >> num_matrix;
			if (num_matrix == 1) {
				createMatrix(row, col, mat1);
			}
			if (num_matrix == 2) {
				createMatrix(row, col, mat2);
			}
		}

		if (choice == 2) {
			cout << "Enter the number of the matrix (1 or 2) : ";
			cin >> num_matrix;
			if (num_matrix == 1) {
				cin >> mat1;
			}
			if (num_matrix == 2) {
				cin >> mat2;
			}
		}

		if (choice == 3) {
			int row, col;
			cout << "Enter number of rows : ";
			cin >> row;
			cout << "Enter number of coloms : ";
			cin >> col;
			createMatrix(row, col, mat2);
			cout << "Enter the value of matrix 2 : ";
			cin >> mat2;
			if (mat1.row == mat2.row && mat1.col == mat2.col) {
				cout << "The Summation of the two Matrices is : \n" << mat1 + mat2 << endl;
			}
			else {
				cout << "The Dimensions of the two matrices are not equal" << endl;
			}
		}

		if (choice == 4) {
			int row, col;
			cout << "Enter number of rows : ";
			cin >> row;
			cout << "Enter number of coloms : ";
			cin >> col;
			createMatrix(row, col, mat2);
			cout << "Enter the value of matrix 2 : ";
			cin >> mat2;
			if (mat1.row == mat2.row && mat1.col == mat2.col) {
				cout << "The Subtraction of the two Matrices is : \n" << mat1 - mat2 << endl;
			}
			else {
				cout << "The Dimensions of the two matrices are not equal" << endl;
			}
		}

		if (choice == 5) {
			int row, col;
			cout << "Enter number of rows : ";
			cin >> row;
			cout << "Enter number of coloms : ";
			cin >> col;
			createMatrix(row, col, mat2);
			cout << "Enter the value of matrix 2 : ";
			cin >> mat2;
			if (mat1.col == mat2.row) {
				cout << "The Multiplication of the two Matrices is : \n" << mat1 * mat2 << endl;
			}
			else {
				cout << "The Dimensions of the two matrices are not equal" << endl;
			}
		}

		if (choice == 6) {
			int scalar;
			cout << "Enter the Scalar number : ";
			cin >> scalar;


			cout << "The Result is : \n" << mat1 + scalar << endl;


		}

		if (choice == 7) {
			int scalar;
			cout << "Enter the Scalar number : ";
			cin >> scalar;



			cout << "The Result is : \n " << mat1 - scalar << endl;


		}

		if (choice == 8) {
			int scalar;
			cout << "Enter the Scalar number : ";
			cin >> scalar;

			cout << "The Result is : \n " << mat1 * scalar << endl;

		}

		if (choice == 9) {
			int row, col;
			cout << "Enter number of rows : ";
			cin >> row;
			cout << "Enter number of coloms : ";
			cin >> col;
			createMatrix(row, col, mat2);
			cout << "Enter the value of matrix 2 : ";
			cin >> mat2;
			if (mat1.row == mat2.row && mat1.col == mat2.col) {
				cout << "1. Add second Matrix to the first one " << endl;
				cout << "2. Add first Matrix to the second one " << endl;
				cout << "Enter your choice : ";
				cin >> num_matrix;
				if (num_matrix == 1) {
					mat1 += mat2;
					cout << mat1 << endl;
				}
				else if (num_matrix == 2) {
					mat2 += mat1;
					cout << mat2 << endl;
				}
			}
			else {
				cout << "The Dimensions of the two Matrices are not equal" << endl;
			}
		}

		if (choice == 10) {
			int row, col;
			cout << "Enter number of rows : ";
			cin >> row;
			cout << "Enter number of coloms : ";
			cin >> col;
			createMatrix(row, col, mat2);
			cout << "Enter the value of matrix 2 : ";
			cin >> mat2;
			if (mat1.row == mat2.row && mat1.col == mat2.col) {
				cout << "1. Subtract second Matrix from the first one " << endl;
				cout << "2. Subtract first Matrix from the second one " << endl;
				cout << "Enter your choice : ";
				cin >> num_matrix;
				if (num_matrix == 1) {
					mat1 -= mat2;
					cout << mat1 << endl;
				}
				else if (num_matrix == 2) {
					mat2 -= mat1;
					cout << mat2 << endl;
				}
			}
			else {
				cout << "The Dimensions are not equal" << endl;
			}
		}

		if (choice == 11) {
			int scalar;
			cout << "Enter the Scalar number : ";
			cin >> scalar;

			mat1 += scalar;
			cout << mat1;

		}

		if (choice == 12) {
			int scalar;
			cout << "Enter the Scalar number : ";
			cin >> scalar;

			mat1 -= scalar;
			cout << mat1 << endl;
		}

		if (choice == 13) {


			mat1 += 1;
			cout << mat1 << endl;
		}

		if (choice == 14) {

			mat1 -= 1;
			cout << mat1 << endl;
		}

		if (choice == 15) {

			cout << "Enter the number of the matrix (1 or 2) : ";
			cin >> num_matrix;
			if (num_matrix == 1) {
				cout << "The Matrix after the transpose is : \n" << transpose(mat1) << endl;
			}
			else if (num_matrix == 2) {
				int row, col;
				cout << "Enter number of rows : ";
				cin >> row;
				cout << "Enter number of coloms : ";
				cin >> col;
				createMatrix(row, col, mat2);
				cout << "Enter the value of matrix 2 : ";
				cin >> mat2;
				cout << "The Matrix after the transpose is : \n" << transpose(mat2) << endl;
			}
		}

		if (choice == 16) {
			int row, col;
			cout << "Enter number of rows : ";
			cin >> row;
			cout << "Enter number of coloms : ";
			cin >> col;
			createMatrix(row, col, mat2);
			cout << "Enter the value of matrix 2 : ";
			cin >> mat2;
			if (mat1.row == mat2.row && mat1.col == mat2.col) {
				if (mat1 == mat2) {
					cout << "The two Matrices are equal" << endl;
				}
				else {
					cout << "The two Matrices are not equal" << endl;
				}
			}
			else {
				cout << "The Dimensions are not equal" << endl;
			}
		}

		if (choice == 17) {
			int row, col;
			cout << "Enter number of rows : ";
			cin >> row;
			cout << "Enter number of coloms : ";
			cin >> col;
			createMatrix(row, col, mat2);
			cout << "Enter the value of matrix 2 : ";
			cin >> mat2;
			if (mat1.row == mat2.row && mat1.col == mat2.col) {
				if (mat1 != mat2) {
					cout << "The two Matrices are not equal" << endl;
				}
				else {
					cout << "The two Matrices are equal" << endl;
				}
			}
			else {
				cout << "The Dimensions are not equal" << endl;
			}
		}

		if (choice == 18) {
			bool found = false;
			cout << "Enter the number of the matrix (1 or 2) : ";
			cin >> num_matrix;
			if (num_matrix == 1) {
				found = isSquare(mat1);
			}
			else if (num_matrix == 2) {
				int row, col;
				cout << "Enter number of rows : ";
				cin >> row;
				cout << "Enter number of coloms : ";
				cin >> col;
				createMatrix(row, col, mat2);
				cout << "Enter the value of matrix 2 : ";
				cin >> mat2;
				found = isSquare(mat2);
			}

			if (found) {
				cout << "The Matrix is a Square one" << endl;
			}
			else {
				cout << "The Matrix is not a Square one" << endl;
			}
		}

		if (choice == 19) {
			bool found = false;
			cout << "Enter the number of the matrix (1 or 2) : ";
			cin >> num_matrix;
			if (num_matrix == 1) {
				found = isSymetric(mat1);
			}
			else if (num_matrix == 2) {
				int row, col;
				cout << "Enter number of rows : ";
				cin >> row;
				cout << "Enter number of coloms : ";
				cin >> col;
				createMatrix(row, col, mat2);
				cout << "Enter the value of matrix 2 : ";
				cin >> mat2;
				found = isSymetric(mat2);
			}

			if (found) {
				cout << "The Matrix is a Summetric one" << endl;
			}
			else {
				cout << "The Matrix is not a Symmetric one" << endl;
			}
		}

		if (choice == 20) {
			bool found = false;
			cout << "Enter the number of the matrix (1 or 2) : ";
			cin >> num_matrix;
			if (num_matrix == 1) {
				found = isIdentity(mat1);
			}
			else if (num_matrix == 2) {
				int row, col;
				cout << "Enter number of rows : ";
				cin >> row;
				cout << "Enter number of coloms : ";
				cin >> col;
				createMatrix(row, col, mat2);
				cout << "Enter the value of matrix 2 : ";
				cin >> mat2;
				found = isIdentity(mat2);
			}

			if (found) {
				cout << "The Matrix is an Identity one" << endl;
			}
			else {
				cout << "The Matrix is not an Identity one" << endl;
			}
		}

		if (choice == 21) {
			cout << "Enter the number of the matrix (1 or 2) : ";
			cin >> num_matrix;
			if (num_matrix == 1) {
				cout << mat1 << endl;
			}
			else if (num_matrix == 2) {
				cout << mat2 << endl;
			}
		}

		if (choice == 22) {
			return 0;
		}

	}
	return 0;
}

void menu() {
	cout << "\t 1. Create Matrix" << endl;
	cout << "\t 2. Enter the values of the matrix" << endl;
	cout << "\t 3. Add two Matrices" << endl;
	cout << "\t 4. Subtract two Matrices" << endl;
	cout << "\t 5. Multiply two Matrices" << endl;
	cout << "\t 6. Add a Scalar to a Matrix" << endl;
	cout << "\t 7. Subtract a Scalar from a Matrix" << endl;
	cout << "\t 8. Multiply a Scalar and a Matrix" << endl;
	cout << "\t 9. Add Matrix to another matrix" << endl;
	cout << "\t10. Subtract Matrix from another matrix" << endl;
	cout << "\t11. Add a Scalar to the Matrix" << endl;
	cout << "\t12. Subtract a Scalar from the Matrix" << endl;
	cout << "\t13. Increase the Matrix by 1" << endl;
	cout << "\t14. Decrease the Matrix by 1" << endl;
	cout << "\t15. Transpose the Matrix" << endl;
	cout << "\t16. Check if the Two Matrices are equal" << endl;
	cout << "\t17. Check if the Two Matrices are not equal" << endl;
	cout << "\t18. Check if the Matrix is a Square one" << endl;
	cout << "\t19. Check if the Matrix is Symmetric" << endl;
	cout << "\t20. Check if the Matrix is Identity" << endl;
	cout << "\t21. Print the Matrix" << endl;
	cout << "\t22. End the Program" << endl;
}//display all operators to choice 

void createMatrix(int row, int col, matrix& mat)// this fun to creat and input matrix 
{
	mat.row = row;
	mat.col = col;
	mat.data = new int*[row];

	for (int i = 0; i < row; i++)
		mat.data[i] = new int[col];
}

matrix operator+ (matrix mat1, matrix mat2)//Add if same dimensions 
{
	matrix sum;
	sum.row = mat1.row;
	sum.col = mat1.col;

	sum.data = new int*[mat1.row];

	for (int i = 0; i < mat1.row; i++)
		sum.data[i] = new int[mat1.col];

	for (int i = 0; i < mat1.row; i++)
	{
		for (int j = 0; j < mat1.col; j++)
		{
			sum.data[i][j] = mat1.data[i][j] + mat1.data[i][j];
		}
	}

	return sum;
}


matrix operator-  (matrix mat1, matrix mat2) // Sub if same dimensions 
{
	matrix sum;
	sum.row = mat1.row;
	sum.col = mat1.col;

	sum.data = new int*[mat1.row];

	for (int i = 0; i < mat1.row; i++)
		sum.data[i] = new int[mat1.col];

	for (int i = 0; i < mat1.row; i++)
	{
		for (int j = 0; j < mat1.col; j++)
		{
			sum.data[i][j] = mat1.data[i][j] - mat1.data[i][j];
		}
	}

	return sum;


}

matrix operator+  (matrix mat1, int scalar) // Add a scalar to matrix
{
	matrix sum;
	sum.row = mat1.row;
	sum.col = mat1.col;
	sum.data = new int*[mat1.row];

	for (int i = 0; i < mat1.row; i++)
		sum.data[i] = new int[mat1.col];

	for (int i = 0; i < mat1.row; i++)
	{
		for (int j = 0; j < mat1.col; j++)
		{
			sum.data[i][j] = mat1.data[i][j] + scalar;
		}
	}

	return sum;
}

matrix operator-  (matrix mat1, int scalar) // sub a scalar from matrix 
{
	matrix sum;
	sum.row = mat1.row;
	sum.col = mat1.col;
	sum.data = new int*[mat1.row];

	for (int i = 0; i < mat1.row; i++)
		sum.data[i] = new int[mat1.col];

	for (int i = 0; i < mat1.row; i++)
	{
		for (int j = 0; j < mat1.col; j++)
		{
			sum.data[i][j] = mat1.data[i][j] - scalar;
		}
	}

	return sum;
}

matrix operator*  (matrix mat1, int scalar) // Multiple by scalar 
{
	matrix sum;
	sum.row = mat1.row;
	sum.col = mat1.col;
	sum.data = new int*[mat1.row];

	for (int i = 0; i < mat1.row; i++)
		sum.data[i] = new int[mat1.col];

	for (int i = 0; i < mat1.row; i++)
	{
		for (int j = 0; j < mat1.col; j++)
		{
			sum.data[i][j] = mat1.data[i][j] * scalar;
		}
	}

	return sum;
}

matrix operator*  (matrix mat1, matrix mat2) // Multi if col1 == row2
{
	matrix sum;
	sum.row = mat2.row;
	sum.col = mat1.col;
	sum.data = new int*[mat2.row];

	for (int i = 0; i < mat2.row; i++)
		sum.data[i] = new int[mat1.col];

	for (int i = 0; i < mat2.row; i++)
	{
		for (int j = 0; j < mat1.col; j++)
		{
			sum.data[i][j] += mat1.data[i][j] * mat2.data[j][i];
		}
	}
	return sum;
}

matrix operator+= (matrix& mat1, matrix mat2)// mat1 changes & return and new matrix with the sum 
{
	for (int i = 0; i < mat1.row; i++)
	{
		for (int j = 0; j < mat1.col; j++)
		{
			mat1.data[i][j] += mat2.data[i][j];
		}
	}
	return mat1;
}

matrix operator-= (matrix& mat1, matrix mat2)// mat1 changes + return new and matrix with difference  
{
	for (int i = 0; i < mat1.row; i++)
	{
		for (int j = 0; j < mat1.col; j++)
		{
			mat1.data[i][j] -= mat2.data[i][j];
		}
	}
	return mat1;
}

matrix operator+= (matrix& mat, int scalar) // change mat & return new 
{
	for (int i = 0; i < mat.row; i++)
	{
		for (int j = 0; j < mat.col; j++)
		{
			mat.data[i][j] += scalar;
		}
	}
	return mat;
}

matrix operator-= (matrix& mat, int scalar) // change mat & return new 
{
	for (int i = 0; i < mat.row; i++)
	{
		for (int j = 0; j < mat.col; j++)
		{
			mat.data[i][j] -= scalar;
		}
	}
	return mat;
}

void   operator++ (matrix& mat)// Add 1 to each element ++mat 
{
	for (int i = 0; i < mat.row; i++)
	{
		for (int j = 0; j < mat.col; j++)
		{
			mat.data[i][j] += 1;
		}
	}
}

void operator-- (matrix& mat) // Sub 1 from each element --mat
{
	for (int i = 0; i < mat.row; i++)
	{
		for (int j = 0; j < mat.col; j++)
		{
			mat.data[i][j] -= 1;
		}
	}
}

istream & operator>>(istream & in, matrix & mat)// input matrix
{
	for (int i = 0; i < mat.row; i++)
	{
		for (int j = 0; j < mat.col; j++)
		{
			in >> mat.data[i][j];
		}
	}
	return in;
}

ostream & operator<<(ostream & out, matrix mat)// display matrix
{
	for (int i = 0; i < mat.row; i++)
	{
		for (int j = 0; j < mat.col; j++)
		{
			out << mat.data[i][j];
		}
		out << endl;
	}
	return out;
}

bool   operator== (matrix mat1, matrix mat2) // True if identical 
{
	bool found = true;
	for (int i = 0; i < mat2.row; i++)
	{
		for (int j = 0; j < mat1.col; j++)
		{
			if (mat1.data[i][j] == mat2.data[i][j])
			{
				continue;
			}
			else
			{
				found = false;
				break;
			}
		}
		if (!found)
		{
			return false;
			break;
		}
	}
	return true;
}

bool   operator!= (matrix mat1, matrix mat2) // True if not same 
{
	bool found = true;
	for (int i = 0; i < mat2.row; i++)
	{
		for (int j = 0; j < mat1.col; j++)
		{
			if (mat1.data[i][j] != mat2.data[i][j])
			{
				continue;
			}
			else
			{
				found = false;
				break;
			}
		}
		if (!found)
		{
			return false;
			break;
		}
	}
	return true;
}

bool   isSquare(matrix mat)// True if square matrix 
{
	if (mat.col == mat.row)
	{
		return true;
	}
	else
	{
		return false;
	}
}

matrix transpose(matrix mat) // Return new matrix with the transpose 
{
	matrix m;
	m.row = mat.col;
	m.col = mat.row;
	m.data = new int*[mat.col];

	for (int i = 0; i < mat.col; i++)
		m.data[i] = new int[mat.row];

	for (int i = 0; i < mat.col; i++)
	{
		for (int j = 0; j < mat.row; j++)
		{
			m.data[i][j] = mat.data[j][i];
		}
	}
	return m;
}


bool   isSymetric(matrix mat) // True if square and symmetric 
{
	matrix m;
	m.row = mat.col;
	m.col = mat.row;
	m.data = new int*[mat.col];

	for (int i = 0; i < mat.col; i++)
		m.data[i] = new int[mat.row];

	for (int i = 0; i < mat.col; i++)
	{
		for (int j = 0; j < mat.row; j++)
		{
			m.data[i][j] = mat.data[j][i];
		}
	}

	bool found = true;
	for (int i = 0; i < mat.row; i++)
	{
		for (int j = 0; j < mat.col; j++)
		{
			if (m.data[i][j] == mat.data[i][j])
			{
				continue;
			}
			else
			{
				found = false;
				break;
			}
			if (!found)
			{
				return false;
				break;
			}
		}
	}
	return true;
}

bool   isIdentity(matrix mat) // True if square and identity
{
	for (int i = 0; i < mat.row; i++)
	{
		for (int j = 0; j < mat.col; j++)
		{
			if (mat.data[i][j] != 1 && i == j) {
				return false;
			}
			if (i != j && mat.data[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}