#include <bits/stdc++.h>
using namespace std;

class Customer
{
    string name;
    int account_number;
    int balance;

public:
    // default constructer
    Customer()
    {
        cout<<"Hello I am Default Constructer\n";

        name = "Yash";
        account_number = 827363;
        balance = 2132;

    }
    // parameterized constructer;
    Customer (string name,int account_number, int balance){
        this->name= name; // agr dono jagh name name ho toooo this  proper ye obj ka address store rakhnta
        this->account_number = account_number;
        this->balance = balance;
    }
    
// multiple constructer hai sbke parameter alg alg hai to isse constructer overloading kehte hai
    Customer(string a, int b){
        name = a;
        account_number = b;

    }

    void display(){
        cout<<name<<"->"<<account_number<<"->"<<balance<<endl;
    }

};

int main()
{

    Customer *A1 = new Customer();
    Customer *A2 = new Customer("Honey Singh",1,12345);
    Customer*A3 = new Customer("Mohit",2);
    // yaya A1.display nahi lagega due to pointer bcz A1 is pointer jo satck ma obj ka aad ress store kare hai
    A1->display();
    A2->display();
    A3->display();

}