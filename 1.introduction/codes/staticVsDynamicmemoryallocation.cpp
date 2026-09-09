#include <bits/stdc++.h>
using namespace std;


class Student{
    public:
    string name;
    int age,roll_number;
    string grade;

};


int main(){

    Student *s = new Student;

    // (*s).name = "yash" ya -> jada use hota hai
    s->name = "yash";
    s->age = 10;
    s->grade="A+";
    s->roll_number=22;

    cout<< s->name <<endl;


    return 0;
}