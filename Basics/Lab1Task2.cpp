/*
Create a C++ class named &quot;Exam&quot; designed to manage student exam records, complete with a
shallow copy implementation? Define attributes such as student name, exam date, and score within the
class, and include methods to set these attributes and display exam details. As part of this exercise,
intentionally omit the implementation of the copy constructor and copy assignment operator. Afterward,
create an instance of the &quot;Exam&quot; class, generate a shallow copy, and observe any resulting issues?
*/
#include <iostream>
#include <cstring>

using namespace std;

class Exam{
    string * StudentName;
    string * examDate;
    float score;

    public:

     Exam(string* name, string* date, float s) : score(s) {
        StudentName = new string(*name);
        examDate = new string(*date);
    }

    ~Exam() {
        delete StudentName;
        delete examDate;
    }

    
    void DisplayResult(){
        cout<<"Student Name : "<<*StudentName<<endl;
        cout<<"Exam Date    : "<<*examDate<<endl;
        cout<<"Student Score : "<<score<<endl;
    }

    void setStudentName(string * name) {
        delete StudentName; //delete previous memory take new asake by updatting name
        StudentName=new string(*name);
    }

    void setExamDate(string * date) {
        delete examDate;
        examDate =new string (*date);
    }

    void SetStudentScore(float score){this->score=score;}
    
    
};
int main() {
    string * name=new string ("shubair");
    string * date=new string ("25/8/2024");
    
    Exam exam1(name,date, 55.3);
    cout<<"Exam 1 "<<endl;
    exam1.DisplayResult();

    Exam exam2=exam1;
    cout<<"Exam 2  "<<endl;
    exam2.DisplayResult();
    //in exam 2 as it is a shallow copy so the memory address will be of same as of exam 1 so whenever exam 1 is changed exam 2 will also be changed that why deep copy is essential
    delete name,date;
    name=new string("Hyder");  
    date=new string("9/11/2001");

    exam1.setStudentName(name);
    exam2.setExamDate(date);
    exam1.SetStudentScore(92.97);//this will not change in exam2 because it is static memory
    cout<<"Exam 1 and 2 after changes "<<endl; //as it is shallow copy so memory address will be same of exam 1 and 2 that whys whenever i modify any of two content both will be modified 
    exam1.DisplayResult();
    cout<<"Exam 2"<<endl;
    exam2.DisplayResult();
    
    return 0;
}

