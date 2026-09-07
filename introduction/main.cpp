#include<bits/stdc++.h>
using namespace std;


class Student {
private:
// data ya attributes
    string name;
    int age, roll_number;
    string grade;

public:
// function ya Metods
    void setName(string studentName) {
        name = studentName;
    }

    string getName() {
        return name;
    }

    void setAge(int studentAge) {
        age = studentAge;
    }

    int getAge() {
        return age;
    }

    void setRollNumber(int studentRollNumber) {
        roll_number = studentRollNumber;
    }

    int getRollNumber() {
        return roll_number;
    }

    void setGrade(string studentGrade) {
        grade = studentGrade;
    }

    string getGrade() {
        return grade;
    }
};



int main(){

    // object of Student class
    Student s1;

    s1.setName("Yash");
    s1.setAge(21);
    s1.setRollNumber(2401);
    s1.setGrade("A");

    Student s2 ;

    s2.setName("Honey");
    s2.setAge(22);
    s2.setRollNumber(2400);
    s2.setGrade("B");


    cout<<s1.getName()<<endl;
    cout<<s1.getAge()<<endl;
    cout<<s1.getRollNumber()<<endl;
    cout<<s1.getGrade()<<endl;

}
