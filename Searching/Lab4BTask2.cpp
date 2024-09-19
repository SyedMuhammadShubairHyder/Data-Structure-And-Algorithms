/*
Your team has been given a large dataset (input by user) of sorted, uniformly distributed account balances.
If the data is not sorted, you have to sort it first. If the data is not uniformly distributed after you apply sorting (if
necessary) you can prompt an error. Your manager has asked you to implement Interpolation Search because it
estimates the position of the target value based on the data distribution. This will allow the search to &quot;jump&quot; closer
to the target in fewer iterations.
*/
#include <iostream>
using namespace std;

bool isSorted(int arr[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

bool isUniformlyDistributed(int arr[], int size)
{
    if (size < 2)
        return true;

    int diff = arr[1] - arr[0];
    bool flag;
    for (int i = 1; i < size - 1; i++)
    {
        if (arr[i + 1] - arr[i] != diff)
            return false;
    }
    return true;
}
void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];

        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int InterpolationSearch(int arr[], int size, int key)
{
    int low = 0, high = size - 1;

    while (low <= high && key >= arr[low] && key <= arr[high])
    {
        if (low == high)
        {
            if (arr[low] == key)
                return low;
            return -1;
        }

        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);//interpolation formula

        if (arr[pos] == key)
            return pos;

        if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}
int main()
{
    int size;
    cout << "Enter Size of DataSet : ";
    cin >> size;
    int dataset[size];
    for (int i = 0; i < size; i++)
    {
        cout << "[" << i << "] =";
        cin >> dataset[i];
    }

    if (!isSorted(dataset, size))
        InsertionSort(dataset, size);

    if (!isUniformlyDistributed(dataset, size))
    {
        cout << "ERROR !   data is not uniformly distributed" << endl;
        return 1;//to show error
    }

    int key;
    cout << "Enter the balance to search for: ";
    cin >> key;

    int result = InterpolationSearch(dataset, size, key);
    if (result != -1)
        cout << "Balance found at index: " << result << endl;
    else
        cout << "Balance not found." << endl;
}