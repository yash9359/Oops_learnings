#include <bits/stdc++.h>
using namespace std;

//! 1.single level inheritance-> child contain only one paremt
// class Human {
//     protected:
//     string name;
//     int age;

//     public:

//     Human(string name,int age){
//         this->name = name;
//         this->age = age;
//     }
//     // 2 fn name same hai lekin call ye wala nahi hoga kyuki local scope mai dekega child apne mai dekhega then parent mai ayeg agar nahi mila to display mai ye nahi chlega student wala chlega
//     void display(){
//         cout<<name<<" "<<age<<endl;
//     }

//     void work()
//     {
//         cout<<"I am working\n"<<endl;
//     }

//     Human (){
//         cout<<"Hello I am Human constructor"<<endl;
//     }
// };

// class Student:public Human{
//     int roll_number,fees;

//     public:
//     // phele human ka constucter chalega bcz it is a parent man smzo then student
//     Student(string name,int age,int roll_number,int fees):Human( name, age){
//         // this->name=name;
//         // this->age = age;
//         this->roll_number=roll_number;
//         this->fees=fees;
//     }

//     Student (){
//         cout<<"Hello mai hu student constructor"<<endl;
//     }

//     void display(){
//         cout<<name<<" "<<age<<" "<<roll_number<<" "<<fees<<" "<<endl;
//     }

// };

// int main(){
//     Student A1("yash",21,240,180000);
//     A1.work();

//     Student A2;

//     A1.display();
// }

// ! 2.Multilevel Inheritance-> layers of parent , Gfather->Father->Child

// class Person
// {
// protected:
// 	string name;
// 	int age;

// 	void introduce()
// 	{
// 		cout << "Hello my name is :" << name << endl;
// 	}
// };

// class Employee : public Person
// {
// protected:
// 	int salary;

// public:
// 	void monthly_salary()
// 	{
// 		cout << "My Monthly Salary is:" << salary << endl;
// 	}
// };

// class Manager : public Employee
// {
// public:
// 	string department;

// 	Manager(string name, int salary, string department)
// 	{
// 		this->name = name;
// 		this->salary = salary;
// 		this->department = department;
// 	}
// 	void work()
// 	{
// 		introduce();
// 		cout << "I am leading the department " << department << endl;
// 	}
// };

// int main()
// {
// 	Manager A1("Yash", 1e8, "Founder/Ceo");
// 	// introucde cant work directly bcz of protected work only derived class and intself class
// 	//  A1.introduce();
// 	A1.work();
// 	A1.monthly_salary();
// }

// ! 3. Multiple Inheritance-> multiple classes se inherite karna and they are not related to ecahother nah to multilevel ho jayga multiple ki jagh or (multiple parent contain single child or one derived  class inharite multiple Base class )

// class Engineer
// {
// 	void money(){
// 		cout<<"Hello money\n"<<endl;
// 	}

// 	public:
// 	string specilization;

// 	void work()
// 	{
// 		cout<<"I have specialization in "<<specilization<<endl;
// 	}

// 	Engineer(){
// 		cout<<" hello Engineer "<<endl;
// 	}
// };

// class Youtuber
// {
// 	public:
// 	int subscriber;

// 	void contentcreater()
// 	{
// 		cout<<"I have a subscriber base of "<<subscriber<<endl;
// 	}
// 	Youtuber(){
// 		cout<<"Hello Youtuber"<<endl;
// 	}
// };

// class CodeTeacher:public Engineer,public Youtuber
// {
// 	public:
// 	string name;

// 	CodeTeacher(string name,string specilization,int subscriber)
// 	{
// 		this->name = name;
// 		this->specilization = specilization;
// 		this->subscriber = subscriber;
// 	}

// 	void showcase()
// 	{
// 		cout<<"My name is: "<<name<<endl;
// 		work();
// 		contentcreater();

// 	}

// 	CodeTeacher(){
// 		cout<<"Hello CodeTeacher"<<endl;
// 	}

// };

// int main()
// {
// 	// CodeTeacher A1("yash","CSE",1e8);
// 	// A1.showcase();

// }

// ! 4.Hierarchial Inheritance -> one Base class contains multiple derived class

// class Human
// {
// protected:
// 	string name;
// 	int age;

// public:
// 	Human() {

// 	};

// 	Human(string name, int age)
// 	{
// 		this->name = name;
// 		this->age = age;
// 	}
// };

// class Teacher : public Human
// {
// 	int salary;

// public:
// 	//* agr parent class mai parametrize constructer bana diya hai to usse use karna padega kyui abb uska default constructor compilre nahi bnayega; to agr mai ek kahli default constructer bana du to ye ese human nahi dena padega
// 	Teacher(int salary, string name, int age)
// 	{
// 		this->salary = salary;
// 		this->name = name;
// 		this->age = age;
// 	}
// 	void display()
// 	{
// 		cout << name << " " << age << " " << salary << endl;
// 	}
// };

// class Student : public Human
// {
// 	int roll_number, fees;

// public:
// 	// phele human ka constucter chalega bcz it is a parent man smzo then student
// 	Student(string name, int age, int roll_number, int fees) : Human(name, age)
// 	{
// 		// this->name=name;
// 		// this->age = age;
// 		this->roll_number = roll_number;
// 		this->fees = fees;
// 	}

// 	void display()
// 	{
// 		cout << name << " " << age << " " << roll_number << " " << fees << " " << endl;
// 	}
// };

// int main()
// {
// 	Teacher A1(100000, "Honey singh", 21);
// 	A1.display();
// 	Student A2("Yash", 21, 22, 1800000);
// 	A2.display();
// }

// ! 5.Hybrid Inheritance -> when we combined any of the  Inhertince type then it is called Hybrid inheritance

//// //*student,boy ,girl,male,female

// class Student{

// 	public:
// 	void print(){
// 		cout<<"I am Student"<<endl;
// 	}

// };

// class Male{
// 	public:
// 	void Maleprint(){
// 		cout<<" I am Male\n";
// 	}
// };

// class Female{
// 	public:
// 	void Femaleprint(){
// 		cout<<" I am Female\n";
// 	}
// };

// class Boy:public Student, public Male{

// 	public:
// 	void Boyprint(){
// 		cout<<"I am Boy"<<endl;

// 	}

// };

// class Girl:public Student, public Female{

// 	public:
// 	void Girlprint(){
// 		cout<<"I am Girl"<<endl;

// 	};

// };

// int main(){

// 	Girl G1;
// 	G1.Girlprint();
// 	G1.print();

// 	Boy B1;
// 	B1.Maleprint();

// }

// ! 6.Multipath Inheritance-> parent multiple path ek hi children ko mile human -> codeTeacher

//          Human
//         /     \
    //        /       \
    //   Youtuber     Engineer
//        \       /
//         \     /
//        CodeTeacher

class Human
{
public:
	string name;
	void display(){
		cout<<"My name is "<<name<<endl;
	}
};

class Engineer : public virtual Human
{

public:
	string specilization;

	void work()
	{
		cout << "I have specialization in " << specilization << endl;
	}

	
};

class Youtuber : public virtual Human
{
public:
	int subscriber;

	void contentcreater()
	{
		cout << "I have a subscriber base of " << subscriber << endl;
	}
	
};

class CodeTeacher : public Engineer, public Youtuber
{
public:
	int salary;

	CodeTeacher(string name, string specilization, int subscriber,int salary)
	{	
		// *yaha name engineer and youtuber dono ke pass se ayega to ambigous ka error ayega  ye pata nahi laga paa raha kon sa name mai du  isse banche ke liye "virtual" ka use karte hai

		this->name = name;
		this->specilization = specilization;
		this->subscriber = subscriber;
		this->salary =salary;
	}
	CodeTeacher(){

	}

	
};

int main()
{
	CodeTeacher A1("yash","CSE",1e8,1e8);
	A1.display();
	
}