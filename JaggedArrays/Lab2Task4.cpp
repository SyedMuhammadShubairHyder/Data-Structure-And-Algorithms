/*
You are tasked with developing a program to manage and display the Grade Point Average (GPA) for the
core courses offered in the first semester of four departments: Software Engineering (SE), Artificial Intelligence
(AI), Computer Science (CS), and Data Science (DS). Each department offers a distinct number of core courses
for this semester: SE has 3 core courses, AI has 4 core courses, CS has 2 core courses, and DS has 1 core course.
To efficiently store and present this data, which type of array structure would you employ? implement a solution
using the chosen array structure to display the GPAs of the core courses for each department.
*/
#include<iostream>
using namespace std;

//we will use simple dynamic pointer for linear array as we chose department 
class Department{
    float gpa;
    float * coreCourse;
    int course;
    public:
    Department(string departName):gpa(0){
        if(departName=="CS")
        {
        coreCourse=new float[2];
        course=2;
        }
        else if(departName=="SE")
        {
        coreCourse=new float[3];
        course=3;
        }
        else if(departName=="DS")
        {
        coreCourse=new float[1];
        course=1;
        }
        else if(departName=="AI")
        {
        coreCourse=new float[4];
        course=4;
        }
    }

    void InputCoreCourseGpa()
    {
        for(int i=0;i<course;i++)
        {
            cout<<"Enter Course "<<i+1<<" GPA : ";
            cin>>coreCourse[i];
        }
    }


    void CalculateGPA()
    {
        //consider alll core course has 3 credit hours

        float sumcr=0;

        for (int i = 0; i < course; i++)
        {
            sumcr+=coreCourse[i]*3;
        }

        gpa=sumcr/(3*course);        
    }


    void Display(){
        cout<<"------SLOW NUCES------"<<endl;
        for(int i=0;i<course;i++)
        {
            cout<<"Course "<<i+1<<" GPA : "<<coreCourse[i]<<endl;
        }
        cout<<"Total Course : "<<course<<endl<<"CGPA : "<<gpa<<endl;
    }
};

int main()
{
    string depart;
    cout<<"Enter Your Department Name : ";
    cin>>depart;

    Department cal(depart);

    cal.InputCoreCourseGpa();
    cal.CalculateGPA();
    cal.Display();
}