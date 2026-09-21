#include <bits/stdc++.h>
using namespace std;

class customer
{

private:
    string name;
    int balance, age;

public:
    customer(string a, int b, int c)
    {
        this->name = a;
        this->balance = b;
        this->age = c;
    }

    void deposit(int amount)
    {
        if (amount < 0)
        {
            cout << "Enter a valid amount" << endl;
            return;
        }

        this->balance += amount;
        cout << "amount Updated successfully: " << this->balance << endl;
    }

    void display(){
        cout<<name<<" "<<balance<<" "<<age<<endl; 
    }
};

int main()
{

    customer A1("Rohit", 1000, 20);
    customer A2("Honey Singh",100,20);
    // ye dekho isss variable ko balance -5vkar diya inn sb  chizo ko sahi karen ke liye incapsulation aya
    // A1.balance = -5;
    //  ye bhi whi direct access
    // A1.age =230;
    /// ! ihi sb se bache ke liye hmm inhe privet karte and geters and setters ki madt se proper value check karte hai
    // cout<< A1.balance <<endl;
    // cout<< A1.age <<endl;

    A1.deposit(3000);
    A1.deposit(-4);
    A1.display();
}
