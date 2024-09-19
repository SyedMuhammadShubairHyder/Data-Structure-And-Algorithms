#include "matmult.h"
#include "Lab2Task2.cpp"
#include <iostream>

using namespace calculate;
using namespace std;
int main()
{
    int r1,c1,r2,c2;

    cout<<"Wellcom to MATMULT "<<endl;
    cout<<"Enter  Matrix A Dimensions ";
    cin>>r1>>c1;
    
    cout<<"Enter  Matrix B Dimensions ";
    cin>>r2>>c2;

    matrixMultiplyer mat3;

    if(mat3.chkMultiplication(c1,r2))
    {
    int **mat1 = new int *[r1];
    for (int i = 0; i < r1; ++i)
    {
        mat1[i] = new int[c1];
    }

    int **mat2 = new int *[r2];
    for (int i = 0; i < r2; ++i)
    {
        mat2[i] = new int[c2];
    }


    cout << "Enter matrix A :" << endl;
    for (int i = 0; i < r1; ++i)
    {
        for (int j = 0; j < c1; ++j)
        {
            cout<<"["<<i+1<<"]"<<"["<<j+1<<"] : ";cin >> mat1[i][j];
        }
    }

    cout << "Enter matrix B : " << endl;
    
    for (int i = 0; i < r2; ++i)
    {
        for (int j = 0; j < c2; ++j)
        {
            cout<<"["<<i+1<<"]"<<"["<<j+1<<"] : ";cin >> mat2[i][j];
        }
    }

    cout << "Result matrix " << endl;

    mat3.calculateMatrix(mat1, r1, c1, mat2, r2, c2);
    mat3.displayMatrix();

    for (int i = 0; i < r1; ++i)
        delete[] mat1[i];
    delete[] mat1;

    for (int i = 0; i < r2; ++i)
        delete[] mat2[i];
    delete[] mat2;
    }
    else
    {
        return 0 ;
    }
}



