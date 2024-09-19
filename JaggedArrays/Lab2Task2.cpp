
/*
Create a header file called matrix_multuply.h that takes two arrays as input and multiplies them
and outputs a multiplied array.
[HINT: Use 2D arrays to accomplish this]
*/
#include "matmult.h"
#include <iostream>

using namespace calculate;
using namespace std;

matrixMultiplyer::matrixMultiplyer() : Matrix(nullptr), row(0), col(0) {}

matrixMultiplyer::~matrixMultiplyer()
{
    for (int i = 0; i < row; i++)
    {
        delete[] Matrix[i];
    }
}

void matrixMultiplyer::calculateMatrix(int **mat1, int row1, int col1, int **mat2, int row2, int col2)
{
    if (chkMultiplication(col1,row2))
    {
        row = row1;
        col = col2;
        Matrix = new int *[row];
        for (int i = 0; i < row; i++)
        {
            Matrix[i] = new int[col];
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                Matrix[i][j] = 0;
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < row; k++)
                {
                    Matrix[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
    }
    else
    {
      return ;
    }
}

void matrixMultiplyer::displayMatrix()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << Matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

bool matrixMultiplyer::chkMultiplication(int col1,int row2){
    if (col1==row2)
    return true;
    else
    {
        cout<<"Multiplication Is Not Possible "<<endl;
    return false;
    }
}

