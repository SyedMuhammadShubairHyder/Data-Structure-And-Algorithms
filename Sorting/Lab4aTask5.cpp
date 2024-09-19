#include <iostream>
using namespace std;

int getNextGap(int gap)
{
    gap = (gap) / 1.5;//custom shrink factor
    if (gap < 1)
        return 1;
    return gap;
}

void combsort(int arr[], int n)
{
    int gap = n;
    bool swapped = true;
    while (gap != 1 || swapped == true)
    {
        gap = getNextGap(gap);
        swapped = false;
        for (int i = 0; i < n - gap; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = true;
            }
        }
    }
}   
    void display(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    int main()
    {
        int prices[] = {29,19,49,5,39,9};
        int size = sizeof(prices) / sizeof(prices[0]);

        cout << "Original prices: ";
        display(prices, size);

        combsort(prices, size);

        cout << "Sorted prices: ";
        display(prices, size);

        return 0;
    }
