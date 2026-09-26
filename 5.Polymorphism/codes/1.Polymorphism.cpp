#include <bits/stdc++.h>
using namespace std;

//* poly = many, morphism = froms -> many forms
//* male -> son,papa,husband,brother
//* polymorphism has two type-> 1.compile Time, 2.Run time
//* 1.complie Time has two types= > B.function overloading , B.Opertaor OverLoading
//* 2.Runtime has 1 type=> Virtual Function
//* ek runner hai  jab vo practice karta hai tab jo error compile time , jab real race mai run karega jab jo error run time

//* ye upper wali chize depth mai  defintion ke  sath example sahit smjahana

// //* 1. Function Overloading
// class Area
// {
// public:
//     //! doo fn same name ke but parameter same isse fn overloading kehte hai and yaha sirf prameter se hi alaga alag area calculate hoga jo compile time mai pata lagea kaha jana hai depene upon parameter

//     int calculateArea(int r)
//     {
// *circle
//         return 1LL * 3.14 * r * r;
//     }
//     int calculateArea(int l, int b)
//     {
//         //* Rectangle
//         return 1LL * l * b;
//     }
// };

// int main()
// {
//     Area A1,A2;

//     cout<<"Circle: " << A1.calculateArea(2) << endl;// compile time mai decide kar lega parametr se kaha jayega

//     cout<<"Rectangle: " << A1.calculateArea(4, 5) << endl;

//     cout<<A2.calculateArea("yash")<<endl;// compile time mai hi erro dikh raha
// }

//! 2. Operator Overlaodiing
// . operator and  -> opertaor kab lagate ye bhi batana conguse ho gay hu
// ye operator ke bare mai bbi batana c.opertaor+c2 bhai
// class Complex
// {

//     // * a + ib;

//     int real, img;

// public:
//     Complex(int real, int img)
//     {
//         this->real = real;
//         this->img = img;
//     }
//     void display()
//     {
//         cout << real << " + i" << img << endl;
//     }
//     Complex operator+(Complex &c)
//     {
//         //* within the class same type ke private meeber ko access kar skte hai c.real,c.img ki baat ho rahi
//         Complex temp(0, 0);
//                     //*C1  +  C2
//         temp.real = real + c.real;
//         temp.img = img + c.img;
//         return temp;
//     }
// };

// int main()
// {
//     Complex c1(5, 2);
//     Complex c2(4, 6);

//     Complex c3 = c1 + c2; // lekin class ko to ye jodna hi nahi ata ye ache se smjhana bhaut complex lgg raha  hai smjhne mai

//     c3.display();
// }

// Run time polmorphism -> 1.virtual Fn
// ye bhi confuseing hai bhai achee se smjahan virtual kyu
// kyu maine animal ka hi type bnaya mai to dog bhi bana skte thaa naa bhai
// direct dog ka bark print hota ,ye abstract class kya hai, pure virtual fn ?

class Animal
{

public:
    // run time pe decide karna kn sa speak na ki compile time pe -> virtual 
    // virtual void speak()
    // {
    //     cout << "HUHU" << endl;
    // }
    virtual void speak()=0; //  pure virtual fn Abstact class iska kabhi bhi object nahi banega ye bhi smjna kyu banyi jati hai
};

class Dog : public Animal
{

public:
    void speak()
    {
        cout<<"bark"<<endl;
    }
    // void roti (){
    //     cout<<"Hello"<<endl;
    // }
};

class Cat : public Animal
{

public:
    void speak()
    {
        cout<<"meow"<<endl;
    }
    // void roti (){
    //     cout<<"Hello"<<endl;
    // }
};

int main()
{
    // Animal *p;
    // p = new Dog();
    // ye p ko pata ki vo animal class ko hi use karega to vo dog ke wahi fn ko use kar skta jo animal yani parent mai hoga  roti nahi kar payega kyuki vo god ka apana  fn hai but  ye bhi depth mai smjhana yaar 
    // p->roti();

    Animal *p;
    vector<Animal*>animals;
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    // animals.push_back(new Animal());
    animals.push_back(new Dog());
    animals.push_back(new Cat());
   
    // isi liye animal ke child ye sb banye alg lag bante to kafi if else lagane pdte

    for(int i = 0 ;i<animals.size();i++){
        p = animals[i];
        p->speak();
    }

}