/*
    You are tasked with designing a Document class for a document editor program. The class should
handle text content, ensuring that copying a document creates a deep copy of the content to maintain
data integrity. Follow the Rule of Three to manage resource allocation and deallocation correctly.
Here are the key requirements:
(a) Create a constructor that takes initial text content and allocates memory for it.
(b) Implement a destructor to deallocate memory used for the text content.
(c) Create a copy constructor that performs a deep copy of the text content, preventing unintended
sharing.
(d) Create a copy assignment operator that ensures a deep copy of the text content, maintaining
separation between objects.
(e) Provide a sample program that showcases your Document class. Create an original document,
generate copies using both the copy constructor and copy assignment operator, modify the
original&#39;s content, and show that the copies remain unaffected.

*/
#include <iostream>
#include <cstring>
using namespace std;


class Document{
    string * content;
    public:
   
    Document(string * intialContent){
        content=new string;
        content=intialContent;
    }


    Document(Document & newdoc){
        content=new string;
        content=newdoc.content;
    }

    Document& operator=(Document& sameDoc) {
        if (this != &sameDoc) {
            delete content;  
            content = new string; 
            content=sameDoc.content; 
        }
        return *this;  
    }

    void ModifyContent(string * newcontent)
    {
        delete  content;
        content=new string;
        content=newcontent;
    }

    
    void DisplayContent()
    {
        cout<<* content<<endl;
    }
    ~ Document()
    {
        delete  content;
    }
};
int main(){
    
    string * str=new string;
    cout<<"Enter DOC 1 content : ";
    getline(cin,*str);
    
    Document doc1(str);


    Document doc2 = doc1; // it use Copy constructor for  deep copy

    delete str;
    str=new string;
    cout<<"Enter DOC 3 content : ";
    getline(cin,*str);

    Document doc3(str);//use copy assignment operator
    doc3 = doc1;//doc 3 mai jobhi store tha sab erase hokar doc1 ka content ajiage
    
    
    cout << "Original document (doc1): ";
    doc1.DisplayContent();

    cout << "Copy using copy constructor (doc2): ";
    doc2.DisplayContent();

    cout << "Copy using copy assignment operator (doc3): ";
    doc3.DisplayContent();

    delete str;
    str=new string;
    cout<<"Enter DOC 1 content to Modify : ";
    getline(cin,*str);

    doc1.ModifyContent(str);//modify content it will only modify doc 1 because doc 2 is copied in deep method


    cout << "\nAfter modifying the original document:\n";

    cout << "Doc 1 : ";
    doc1.DisplayContent();
    cout << "Doc2 : ";
    doc2.DisplayContent();
    cout << "Doc3 : ";
    doc3.DisplayContent();

    return 0;
}