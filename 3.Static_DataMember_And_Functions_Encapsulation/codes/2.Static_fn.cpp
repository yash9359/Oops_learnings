// static member function
#include <bits/stdc++.h>
using namespace std;
// const ke bare mai ekk dm ache se example ke sath depth mai batana kyu ,kaha, kese use hota hai code ke sath iski jarurat kyu padi

class Customer
{

    string name;
    int acc_num, balance;
    static int total_Customer;
    static int total_Balance;

public:
    Customer(string name, int acc_num, int balance)
    {
        this->name = name;
        this->acc_num = acc_num;
        this->balance = balance;
        total_Customer++;
        total_Balance+=balance;
    }
    void display()
    {
        cout << name << " " << acc_num << " " << balance << " " << total_Customer << " " << endl;
    }
    void display_total()
    {
        cout << total_Customer << endl;
    }
    // static member fn
    static void accessStatic(){
        // static member fn bhi class ka member bn jayega na ki obj ka abb iss fn se hm kewal static variable hi access kar skte hai dusro ko nahi kyuki voobj ka part hote hai
        cout<<"Total Number of Customers: "<<total_Customer<<endl;
    }
    static void accessBalance(){
        cout<<"Universal balance: "<<total_Balance<<endl;
    }
    void deposit(int amount){
        if(amount>0){
            balance+=amount;
            total_Balance+=amount;
            cout<<"Deposit Successfull"<<endl;
        }
    }
    void withdraw(int amount){
        if(balance>=amount && amount>0){
            balance-=amount;
            total_Balance-=amount;
             cout<<"withdrawal Successfull"<<endl;
        }else if(balance<amount){
            cout<<"Insufficient balance"<<endl;
        }else{
            cout<<"Amount is Negative"<<endl;
        }
    }
};
// !class ke bahar hi initialize karna
// ! ab static ko intialize kiya ye bhi discus karna ki bahar kyu kiya kese hua kya hai ye
//! imp hai
int Customer::total_Customer = 0;
int Customer::total_Balance = 0;

int main()
{

    Customer A1("Narendra Modi", 1, 2000);
    Customer A2("Yash", 2, 1000);
    Customer A3("Rahul Gandhi", 3, 1000);
    

    

    // abhi ye access nahi hoga kuki total_Cutomer ko privte bana diye isko acces karne ke liye through class se isko static fn ki jarurat hoti ye static fn ko achse smjhna ache example kke sath
    // Customer::total_Customer += 6;
    // Customer::display_total();
    
    // A1.display_total();

    /// abb access ho jayega Customer se static fn bana diya kyuki
    Customer::accessStatic();
    Customer::accessBalance();

    A1.deposit(500);
    Customer::accessBalance();
    A2.withdraw(105);

    Customer::accessBalance();



    


}