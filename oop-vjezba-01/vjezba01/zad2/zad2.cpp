/*
	OP - VJEZBA 1 - ZADATAK 2
	@file zad2.cpp
	@author Anamarija Papic
*/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Matrix {
	int rows;
	int cols;
	float** data;
};

void inputMatrix(Matrix* matrix, int n, int m)
{

	matrix->rows = n;
	matrix->cols = m;
	matrix->data = new float* [n];
	for (int i = 0; i < n; i++)
		matrix->data[i] = new float[m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "matrix[" << i << "][" << j << "] = ";
			cin >> matrix->data[i][j];
		}
	}
}

void generateMatrix(Matrix* matrix, int n, int m)
{
	float randNum, a, b;

	matrix->rows = n;
	matrix->cols = m;
	matrix->data = new float* [n];
	for (int i = 0; i < n; i++)
		matrix->data[i] = new float[m];

	srand((unsigned)time(0));
	cout << "Enter interval [a, b] - random generated number range:" << endl;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			randNum = a > b ? (a + (rand() / (RAND_MAX / (b - a)))) : (b + (rand() / (RAND_MAX / (a - b))));
			matrix->data[i][j] = randNum;
		}
	}
}

int calculateSum(Matrix* matrix1, Matrix* matrix2, Matrix* matrixSum)
{
	if ((matrix1->rows == matrix2->rows) && (matrix1->cols == matrix2->cols)) {
		matrixSum->rows = matrix1->rows;
		matrixSum->cols = matrix1->cols;
		matrixSum->data = new float* [matrixSum->rows];
		for (int i = 0; i < matrixSum->rows; i++)
			matrixSum->data[i] = new float[matrixSum->cols];

		for (int i = 0; i < matrix1->cols; i++)
			for (int j = 0; j < matrix1->rows; j++)
				matrixSum->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];

		return 1;
	}
	return 0;
}

int calculateDiff(Matrix* matrix1, Matrix* matrix2, Matrix* matrixDiff)
{
	if ((matrix1->rows == matrix2->rows) && (matrix1->cols == matrix2->cols)) {
		matrixDiff->rows = matrix1->rows;
		matrixDiff->cols = matrix1->cols;
		matrixDiff->data = new float* [matrixDiff->rows];
		for (int i = 0; i < matrixDiff->rows; i++)
			matrixDiff->data[i] = new float[matrixDiff->cols];

		for (int i = 0; i < matrix1->cols; i++)
			for (int j = 0; j < matrix1->rows; j++)
				matrixDiff->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];

		return 1;
	}
	return 0;
}

int calculateProd(Matrix* matrix1, Matrix* matrix2, Matrix* matrixProd)
{
	if (matrix1->cols == matrix2->rows) {
		matrixProd->rows = matrix1->rows;
		matrixProd->cols = matrix2->cols;
		matrixProd->data = new float* [matrixProd->rows];
		for (int i = 0; i < matrixProd->rows; i++)
			matrixProd->data[i] = new float[matrixProd->cols];

		for (int i = 0; i < matrix1->rows; i++) {
			for (int j = 0; j < matrix2->cols; j++) {
				matrixProd->data[i][j] = 0;
				for (int k = 0; k < matrix2->rows; k++) {
					matrixProd->data[i][j] += (matrix1->data[i][k] * matrix2->data[k][j]);
				}
			}
		}

		return 1;
	}
	return 0;
}

void transposeMatrix(Matrix* matrix, Matrix* matrixT)
{
	matrixT->rows = matrix->cols;
	matrixT->cols = matrix->rows;
	matrixT->data = new float* [matrixT->rows];
	for (int i = 0; i < matrixT->rows; i++)
		matrixT->data[i] = new float[matrixT->cols];

	for (int i = 0; i < matrixT->cols; ++i) {
		for (int j = 0; j < matrixT->rows; ++j) {
			matrixT->data[j][i] = matrix->data[i][j];
		}
	}
}

void freeMatrix(Matrix* matrix)
{
	for (int i = 0; i < matrix->rows; i++)
		delete[] matrix->data[i];
	delete[] matrix->data;
}

void printMatrix(Matrix* matrix)
{
	int i, j;
	for (i = 0; i < matrix->rows; i++) {
		for (j = 0; j < matrix->cols; j++)
			cout << setw(10) << fixed << setprecision(4) << right << matrix->data[i][j];
		cout << endl;
	}
}

int main() {
	Matrix matrixA, matrixB, matrixSum, matrixDiff, matrixProd, matrixTransposeA, matrixTransposeB;
	int nA, mA, nB, mB;
	char decision1, decision2;

	cout << "Matrix A" << endl;
	do {
		cout << "Input matrix or generate random matrix (i / g): ";
		cin >> decision1;
	} while (decision1 < 'g' || decision1 == 'h' || decision1 > 'i');
	cout << "Enter the number of rows in the matrix: ";
	cin >> nA;
	cout << "Enter the number of columns in the matrix: ";
	cin >> mA;
	switch (decision1) {
	case 'i':
		inputMatrix(&matrixA, nA, mA);
		cout << "Your matrix:" << endl;
		printMatrix(&matrixA);
		break;
	case 'g':
		generateMatrix(&matrixA, nA, mA);
		cout << "Generated matrix:" << endl;
		printMatrix(&matrixA);
		break;
	default:
		cout << "Error! Matrix A not created!" << endl;
		break;
	}
	cout << endl;
	cout << "Matrix B" << endl;
	do {
		cout << "Input matrix or generate random matrix (i / g): ";
		cin >> decision2;
	} while (decision2 < 'g' || decision2 == 'h' || decision2 > 'i');
	cout << "Enter the number of rows in the matrix: ";
	cin >> nB;
	cout << "Enter the number of columns in the matrix: ";
	cin >> mB;
	switch (decision2) {
	case 'i':
		inputMatrix(&matrixB, nB, mB);
		cout << "Your matrix:" << endl;
		printMatrix(&matrixB);
		break;
	case 'g':
		generateMatrix(&matrixB, nB, mB);
		cout << "Generated matrix:" << endl;
		printMatrix(&matrixB);
		break;
	default:
		cout << "Error! Matrix B not created!" << endl;
		break;
	}
	if (calculateSum(&matrixA, &matrixB, &matrixSum)) {
		cout << endl << "Matrix A + Matrix B =" << endl;
		printMatrix(&matrixSum);
	}
	else
		cout << endl << "Operation + non supported! Different matrix dimensions!" << endl;
	if (calculateDiff(&matrixA, &matrixB, &matrixDiff)) {
		cout << endl << "Matrix A - Matrix B =" << endl;
		printMatrix(&matrixDiff);
	}
	else
		cout << endl << "Operation - non supported! Different matrix dimensions!" << endl;
	if (calculateProd(&matrixA, &matrixB, &matrixProd)) {
		cout << endl << "Matrix A * Matrix B =" << endl;
		printMatrix(&matrixProd);
	}
	else
		cout << endl << "Operation * non supported! (mA != nB)" << endl;
	transposeMatrix(&matrixA, &matrixTransposeA);
	cout << endl << "A' =" << endl;
	printMatrix(&matrixTransposeA);
	transposeMatrix(&matrixB, &matrixTransposeB);
	cout << endl << "B' =" << endl;
	printMatrix(&matrixTransposeB);
	freeMatrix(&matrixA);
	freeMatrix(&matrixB);
	freeMatrix(&matrixSum);
	freeMatrix(&matrixDiff);
	freeMatrix(&matrixProd);
	freeMatrix(&matrixTransposeA);
	freeMatrix(&matrixTransposeB);
	return 0;
}