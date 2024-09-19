/*
Write a program that creates a 2D array of 5x5 values of type Boolean. Suppose indices
represent people and the value at row i, column j of a 2D array is true just in case i and j are friends and
false otherwise. You can use initializer list to instantiate and initialize your array to represent the
following configuration: (* means “friends”)Write a method to check whether two people have a common friend. For example, in the example above, 0 and 4
are both friends with 3 (so they have a common friend), whereas 1 and 2 have no common friends.
*/
#include<iostream>
using namespace std;


class FriendList{
    bool List [5][5];

    public:
    FriendList(){
        List[0][0]=false,List[0][1]=true,List[0][2]=false,List[0][3]=true,List[0][4]=true;
        List[1][0]=true,List[1][1]=false,List[1][2]=true,List[1][3]=false,List[1][4]=true;
        List[2][0]=false,List[2][1]=true,List[2][2]=false,List[2][3]=false,List[2][4]=false;
        List[3][0]=true,List[3][1]=false,List[3][2]=false,List[3][3]=false,List[3][4]=true;
        List[4][0]=true,List[4][1]=true,List[4][2]=false,List[4][3]=true,List[4][4]=false;
    }



void checkMutual(int personA,int personB)
{
    bool lonely=true;
    cout<<personA<<" and "<<personB<<" are both friends with : ";
    for (int i = 0; i < 5; i++)
    {
        if(List[personA][i]&& List[personB][i])
        {
            if(!lonely)
            cout<<", ";

            cout<<i;
            lonely=false;
        }              
    }
    if(lonely)
    cout<<"NONE"<<endl;;
}
  };

int main(){
    FriendList bff;
    bff.checkMutual(1,2);
    
}