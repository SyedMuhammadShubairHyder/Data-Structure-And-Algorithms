/*
You are tasked with implementing the Shell Sort algorithm to sort the weights of employees in a company.
However, instead of using the traditional gap sequence (where the gap is divided by 2), you must create and
implement a custom gap sequence of your choice that you think can align with the problem.
*/

#include <iostream>
using namespace std;
//(2^k-1)
int* SedgewickGaps(int size, int& numGaps) {
    int* gaps = new int[size]; 
    int k = 0;
    int gap;
    numGaps = 0;

    do {
        if (k == 0) {
            gap = 1;
        } else {
            gap = 9 * (1 << (2 * k)) - 9 * (1 << k) + 1; 
        }
        if (gap < size) {
            gaps[numGaps++] = gap;
        }
        k++;
    } while (gap < size);

    return gaps;
}

void shellSort(int arr[], int size) {
    int numGaps;
    int * gaps=SedgewickGaps(size,numGaps);

    for (int g = numGaps-1; g >= 0; g--) 
    {
        int gap=gaps[g];
        for (int j = gap; j < size; j++) {
            int temp = arr[j];
            int i = j;
            
            while (i >= gap && arr[i - gap] > temp) {
                arr[i] = arr[i - gap];
                i -= gap;
            }
            arr[i] = temp;
        }
    }
    delete [] gaps;
}

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int weights[] = {82, 72, 91, 80, 50, 52, 98, 115, 69, 100};
    int size = sizeof(weights) / sizeof(weights[0]);

    cout << "Original weights: ";
    display(weights, size);

    shellSort(weights, size);

    cout << "Sorted weights: ";
    display(weights, size);

    return 0;
}
