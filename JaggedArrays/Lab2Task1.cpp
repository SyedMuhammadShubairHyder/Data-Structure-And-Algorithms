/*
Implement Jagged arrays from the above pseudocode by taking a size of 5 and resizing it to 10 in
each index.
*/
#include<iostream>
using namespace std;


void DisplayArray(int **Arr,int * size,int row)
{
    cout << "Jagged array content:" << endl;
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < size[i]; j++)
        { 
            cout << Arr[i][j] << " ";
        }
            cout << endl;
    }
}

void InputArrayElemnts(int ** Arr,int * size,int start,int end)
{
    for(int i=start;i<end;i++)
    {
        cout<<"Enter row " <<i+1<<" elements: ";
        for(int j=0;j<size[i];j++)
        {  
            cin>>Arr[i][j];  
        }
    }
}

int main()
{
    int ** JagArr = new int*[5];//Intialize with row size of 5 
    int * Size=new int [5];

    //allocating memory for rows
    for(int i=0;i<5;i++)
    {
        cout<<"Enter Size of Row "<<i+1<< " : ";
        cin>>Size[i];
        JagArr[i] =new int[Size[i]];
    }

    InputArrayElemnts(JagArr,Size,0,5);
    
    DisplayArray(JagArr,Size,5);
 
    cout<<"Now Resizing Array Row Size to 10 "<<endl;


    int ** tempArr=new int* [10];//creating a new array to store the elemnets by copying them
    int * tempSize=new int [10];

    for (int i = 0; i < 5; i++) {
        tempSize[i] = Size[i];
        tempArr[i] = new int[tempSize[i]];     
    }

      //copying previous array element into new one
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < tempSize[i]; j++)
        {
            tempArr[i][j]=JagArr[i][j];
        }
    }

    //enetring new rows for resized array
    for(int i=5;i<10;i++)
    {
        cout<<"Enter Size of Row "<<i+1<< " : ";
        cin>>tempSize[i];
        tempArr[i] =new int[tempSize[i]];
    }
  

    
    InputArrayElemnts(tempArr,tempSize,5,10);
    cout << "Resized ";
    delete [] Size;
    Size=tempSize;
    for(int i=0;i<5;i++)
    {
        delete [] JagArr [i];
    }    
    delete [] JagArr;
    JagArr=tempArr;
    DisplayArray(JagArr,Size,10);
    
}