/*
1. Implement the bubble sort algorithm to sort the in descending order (starting from the initial pass).
Take array[10]= {5,1,3,6,2,9,7,4,8,10}. You can also take your array as user input.
*/
#include<iostream>
using namespace std;
void display(int * arr,int size){for(int k=0;k<size;k++){cout<<arr[k]<<" ";} cout<<endl; }

int main()
{
    int arr[10] = {5, 1, 3, 6, 2, 9, 7, 4, 8, 10};
    int size = 10;

    

    for (int i = 0; i <size-1; i++)
    {
        for (int  j = 0; j <size-1-i; j++)
        {
            if(arr[j]<arr[j+1])
            {
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }        
    }   

    cout<<"Sorted Array "<<endl;
    display(arr,size);

}