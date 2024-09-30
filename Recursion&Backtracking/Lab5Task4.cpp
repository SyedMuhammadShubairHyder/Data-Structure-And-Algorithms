/*
Imagine you are working on a scientific application that involves processing a multi-
dimensional array. You need to implement a function that calculates the sum of all elements

in this array. The array can contain nested arrays, forming a multi-dimensional structure
represented as a jagged array. Write a C++ function int recursiveArraySum(int* arr[], int
sizes[], int dim) that computes the sum of all the elements in such a multi-dimensional array.
The sizes array contains the sizes of each dimension, and dim indicates the current dimension
being processed.
*/
#include<iostream>
using namespace std;

int arraySum1D(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];  
    }
    return sum;
}

// sir dosra function sahi se nhi ban paraha tha
int recursiveArraySum(int** arr, int sizes[], int dim,int currRow) {
if(currRow<dim)
{
    return arraySum1D(arr[currRow],sizes[currRow])+recursiveArraySum(arr,sizes,dim,currRow+1);
}
else
{
    return 0;
}
}


int main() {
    int** JagARR = new int* [3];  
    int* size = new int[3];       

    for (int i = 0; i < 3; i++) {
        cout << "Enter size for row " << i + 1 << ": ";
        cin >> size[i];
        JagARR[i] = new int[size[i]];  
    }

    for (int i = 0; i < 3; i++) {
        cout << "Enter elements for row " << i + 1 << ": ";
        for (int j = 0; j < size[i]; j++) {
            cin >> JagARR[i][j];
        }
    }

    int result = recursiveArraySum(JagARR, size, 3,0);  
    cout << "Sum of all elements: " << result << endl;

    for (int i = 0; i < 3; i++) {
        delete[] JagARR[i];  
    }
    delete[] JagARR;  
    delete[] size;    

    return 0;
}
