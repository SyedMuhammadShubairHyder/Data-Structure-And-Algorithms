/*
In a bustling corporate office, the facilities management team is tasked with organizing the seating
arrangements for employees based on their designations. The office layout consists of rows of computer desks,
and each desk has a designated employee. The priority is to sort out the computer desks for employees using the
Insertion Sort algorithm, with the designation determining the sorting order. The higher the designation, the closer

the employee should be seated to the corner office. The designations and their corresponding priorities are as
follows:
i. CEO (Chief Executive Officer) - Highest Priority
ii. CTO (Chief Technology Officer)
iii. CFO (Chief Financial Officer)
iv. VP (Vice President)
v. MGR (Manager)
vi. EMP (Employee) - Lowest Priority
Here&#39;s the initial arrangement of employees&#39; desks from left to right:
i. Employee (EMP)
ii. CFO (Chief Financial Officer)
iii. Manager (MGR)
iv. Employee (EMP)
v. VP (Vice President)
vi. CTO (Chief Technology Officer)
vii. Manager (MGR)
viii. CEO (Chief Executive Officer)
*/

#include<iostream>
using namespace std;


 
class EmployeePrioty{
public:
string position;
void input()
{
    cout<<"ENTER ROLE : ";
    cin>>position;
}
void display()
{
    cout<<position<<endl;
}
};

int getPriority(string designation) {
    if (designation == "CEO") return 1;
    if (designation == "CTO") return 2;
    if (designation == "CFO") return 3;
    if (designation == "VP") return 4;
    if (designation == "MGR") return 5;
    if (designation == "EMP") return 6;
    return 0; 
}

void sortingEmp(EmployeePrioty * arr,int size)
{
    for (int  i =1; i < size; i++)
    {
        EmployeePrioty key=arr[i];
        
        int j = i-1;
        
        while(j>=0 && getPriority(arr[j].position)>getPriority(key.position))
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
         arr[j+1]=key;
    }
}
 
int main()
{
    int size = 8;
    EmployeePrioty empArr[size];
    //"EMP", "CFO", "MGR", "EMP", "VP", "CTO", "MGR", "CEO"
    for (int i = 0; i < size; i++)
    {
        cout << "Empolyee " << i + 1 << ":" << endl;
        empArr[i].input();
    }

    sortingEmp(empArr, size);

    cout << "Sorted Employees:" << endl;
    for (int i = 0; i < size; i++)
    {
        empArr[i].display();
    }
}