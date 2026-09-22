#include <bits/stdc++.h>
using namespace std;

//* Inheritance The  capability of a class to derive property & Charterstics from another class

//! *          External code    Within Class  Derived Class
//* Public =>    Yes                Yes         Yes
//* protected=>  No                 Yes         Yes
//* private=>    No                 Yes         No

// class Human
// {

// private:
//     int a;

// protected:
//     int b;

// public:
//     int c;
//     void fun()
//     {
//         a = 10;
//         b = 20;
//         c = 30;
//         cout << a << " " << b << " " << c << endl;
//     }
// };

// int main()
// {
//     Human Yash;

//     // Yash.a =10;
//     // Yash.b =10;
//     // Yash.c =10;

//     Yash.fun();
// }

//! private > protected > public

// parent class / Base Class

// Base class se private aye and derived mai public ho to kese treat hoga and sare tino combination bnaatnan mila ke ki kya kese treat hoga

class Human
{

    string Religion, color;
    // protected: ye bhi nahi chlne dega student class ke bahar ke alwa
public:
    string name;
    int age, weight;
};

// Child class /Derived Class
// public yaha iss liye likha ki jo ye data ayega parent se too ye yaa to protected hoga ya public to vo yaha public ho jayeg adue to public ye dhnge se smjaho
class Student : private Human
{
    // string name;
    // int age,weight;
private:
    int fees, roll_no;

public:
    // void fn(string n, int a, int w)
    // {
    //     this->name = n;
    //     this->age = a;
    //     this->weight = w;

    // }

    void display()
    {
        cout << name << " , age is " << age << " weight is " << weight << " roll_no is " << roll_no << " , fees " << fees << endl;
    }

    Student(string name, int age, int weight, int roll_no, int fees)
    {
        this->name = name;
        this->age = age;
        this->roll_no = roll_no;
        this->weight = weight;
        this->fees = fees;
    }
};

// Child class /Derived Class
class Teacher : Human
{
    // string name;
    // int age,weight;
    int salary, id;
};

int main()
{
    Student A("yash", 20, 3000, 23, 83883);
    // A.name = "yash";
    // cout<<A.name<<endl;

    // A.fn("yash", 20, 50);
    A.display();
}