#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    // data ya attributes
    string name;
    int age, roll_number;
    string grade;

public:
    // function ya Metods
    void setName(string studentName)
    {
        if (studentName.empty())
        {
            cout << "invalid name: ";
            return;
        }
        name = studentName;
    }

    string getName()
    {
        return name;
    }

    void setAge(int studentAge)
    {
        if (studentAge < 18 || studentAge > 100)
        {
            cout << "Invalid age: " << endl;
            return;
        }
        age = studentAge;
    }

    int getAge()
    {
        return age;
    }

    void setRollNumber(int studentRollNumber)
    {
        roll_number = studentRollNumber;
    }

    int getRollNumber()
    {
        return roll_number;
    }

    void setGrade(string studentGrade)
    {
        grade = studentGrade;
    }

    string getGrade(int pin)
    {
        if (pin == 123)
        {
            return grade;
        }
        return "Enter valid password to get grades";
    }
};

class a
{
    // int b,c,d;
    // C++ mein har object ka unique address hona chahiye. Agar empty object ka size 0 hota, to multiple objects ka same address ho sakta tha.
    // Empty class = aisi class jisme koi data member aur member function nahi hota. sizeof(emptyClass) generally 1 byte hota hai.
};

class b
{

    char d;
    int c;
    char e;
    // padding concept
};

int main()
{

    // object of Student class
    Student s1;

    s1.setName("Yash");
    s1.setAge(21);
    s1.setRollNumber(2401);
    s1.setGrade("A");

    Student s2;

    s2.setName("Honey");
    s2.setAge(22);
    s2.setRollNumber(2400);
    s2.setGrade("B");

    cout << s1.getName() << endl;
    cout << s1.getAge() << endl;
    cout << s1.getRollNumber() << endl;
    cout << s1.getGrade(123) << endl;

    a obj;
    cout << sizeof(obj) << " " << endl;

    b obj1;
    cout << sizeof(obj1) << " ";
}
