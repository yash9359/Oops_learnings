#include<bits/stdc++.h>
using namespace std;


class Student {
    
    public:
    string name;
    int age,roll_number;
    string grade;


};



int main(){

    // object of Student class
    Student s1;

    s1.name = "Yash";
    s1.age = 21;
    s1.roll_number = 2401;
    s1.grade ="A";

    Student s2 ;

    s2.name = "Honey";
    s2.age = 22;
    s2.roll_number = 2400;
    s2.grade ="B";


    cout<<s1.name<<endl;
    cout<<s1.age<<endl;

}