#include <bits/stdc++.h>
using namespace std;

class Customer
{

    string name;
    int acc_num, balance;

    // * static ki definition and all yahi se  hme total number chiye tha but yaha to sbke liye naya bnta isi liye static bayanaya taki ek class ke liye ek hi bnee che kitne obj kyu naa ho
    // this is  the part of the class

  public:  
    static int total_Customer;

public:
    Customer(string name, int acc_num, int balance)
    {
        this->name = name;
        this->acc_num = acc_num;
        this->balance = balance;
        total_Customer++;
    }
    void display()
    {
        cout<<name<<" "<<acc_num<<" "<<balance<<" "<<total_Customer<<" "<<endl;
    }
    void display_total(){
        cout<<total_Customer<<endl;
    }
};
// !class ke bahar hi initialize karna
// ! ab static ko intialize kiya ye bhi discus karna ki bahar kyu kiya kese hua kya hai ye
//! imp hai
int Customer::total_Customer = 0;

int main()
{

    Customer A1("Narendra Modi", 1, 2000);
    Customer A2("Yash", 2, 1000);
    // A1.display();
    // A2.display();
    Customer A3("Rahul Gandhi",3,1000);
    // A3.display();
    // A1.display();
    // A2.display();

 
    A1.display_total();

       //! kyuki static ke karan  class se associated hai to bina object baanye bhi access kar skte hai,lekin public hona jaruri hai
    Customer::total_Customer += 6;
    A1.display_total();
    

}