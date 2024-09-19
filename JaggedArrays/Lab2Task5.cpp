/*
You&#39;re developing a program to manage a seating chart for a conference held in a hall with multiple rows
of seats. Each row has a different seat capacity. To efficiently handle the seating arrangements, you decide to use
a dynamic array. Implement a C++ code that allocates memory for the seating chart and allows attendees&#39; names
to be inputted for each seat. Choose and implement the appropriate type of dynamic array for this scenario.
*/
#include<iostream>
using namespace std;

//we are using Jagged array for this problem

int main(){

    
    int row;
    cout<<"Enter Number of Rows : ";
    cin>>row;
    string ** seatingChart=new string * [row];
    int * seats=new int [row];

    for (int i = 0; i < row; i++)
    {
        cout<<"Enter Row "<<i+1<<" Seats : ";
        cin>>seats[i];
        seatingChart[i]=new string[seats[i]];
    }


    for(int i=0;i<row;i++)
    {
        for (int j = 0;j<seats[i]; j++)
        {
            cout<<"Name : ";
            cin>>seatingChart[i][j];
        }
    }


    cout<<"Participents Data "<<endl;
    for(int i=0;i<row;i++)
    {
        for (int j = 0;j<seats[i]; j++)
        {
            cout<<seatingChart[i][j]<<"   ";
        }
        cout<<endl;
    }

    for (int i = 0; i < row; ++i) {
        delete[] seatingChart[i]; 
    }
    delete[] seatingChart;
    delete[] seats;
}