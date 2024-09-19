/*
Develop C++ solution such that day month and year are taken as input for 5 records and perform Sorting
Dates based on year using Selection Sort. Note: Input must be taken from user.
[Hint: Struct or Class can be used]
It`s not strictly necessary to take inputs in the format as shown in example, but, the output should be
in the given format.
Example Input: Example Output:
01/02/2022 4/07/2015
5/01/2018 5/01/2018
4/07/2015 12/10/2021
12/10/2021 01/02/2022
11/12/2023 11/12/2023
*/
// Have not included edge cassess
#include <iostream>
using namespace std;
class Date
{
public:
    int date;
    int month;
    int year;
    void display()
    {
        if (date < 10)
            cout << "0";
        cout << date << "/";
        if (month < 10)
            cout << "0";
        cout << month << "/" << year << endl;
    }

    void input()
    {

        cout << "Enter Year : ";
        cin >> year;

        do
        {
            cout << "Enter Month : ";
            cin >> month;
            if (month <= 0 || month > 12)
            {
                cout << "Invalid Month: Please enter a month between 1 and 12." << endl;
            }
        } while (month <= 0 || month > 12);

        if (month == 2)//feb
        { 
            do
            {
                cout << "Enter Date : ";
                cin >> date;
                if (date <= 0 || date > 28)
                {
                    cout << "Invalid Date: February has 28  days." << endl;
                }
            } while (date <= 0 || date > 28);
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            do
            {
                cout << "Enter Date : ";
                cin >> date;
                if (date <= 0 || date > 30)
                {
                    cout << "Invalid Date: This month has 30 days." << endl;
                }
            } while (date <= 0 || date > 30);
        }
        else
        {
            do
            {
                cout << "Enter Date : ";
                cin >> date;
                if (date <= 0 || date > 31)
                {
                    cout << "Invalid Date: This month has 31 days." << endl;
                }
            } while (date <= 0 || date > 31);
        }
    }
};

void sortingDates(Date *arr, int size)
{
    // first sort by year
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j].year < arr[minIndex].year)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            Date temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    // then sort by month
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j].year == arr[minIndex].year && arr[j].month < arr[minIndex].month)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            Date temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    // then sort by day
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j].year == arr[minIndex].year && arr[j].month == arr[minIndex].month && arr[j].date < arr[minIndex].date)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            Date temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main()
{
    int size = 5;
    Date dateArr[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter date " << i + 1 << ":" << endl;
        dateArr[i].input();
    }

    sortingDates(dateArr, size);

    cout << "Sorted Dates by Year, Month, and Day:" << endl;
    for (int i = 0; i < size; i++)
    {
        dateArr[i].display();
    }
}
