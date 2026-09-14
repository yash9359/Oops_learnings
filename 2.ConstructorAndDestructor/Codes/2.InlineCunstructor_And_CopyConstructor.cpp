// #include <bits/stdc++.h>
// using namespace std;

// class Customer
// {
//     string name;
//     int account_number;
//     int balance;
//     // koi bhi change advance mai chiye to custructer mai lelte
//     int *roi;

// public:
//     // default constructer
//     Customer()
//     {
//         cout<<"Hello I am Default Constructer\n";

//         name = "Yash";
//         account_number = 827363;
//         balance = 2132;
//         roi = new int[100];

//     }

//     // Inline constructer

//   inline  Customer(string a,int b,int c) : name(a),account_number(b),balance(c){

//   }

//   void Display(){
//     cout<<name<<" "<<account_number<<" "<<balance<<endl;
//   }

// };

// int main(){
//     Customer *A1 =new Customer("Honey_Singh",1,999999);
//     Customer *A2 = new Customer();
//     A1->Display();
//     A2->Display();

// }

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
        cout << "Hello I am Default Constructer\n";

        name = "Yash";
        account_number = 827363;
        balance = 2132;
    }

    inline Customer(string a, int b, int c) : name(a), account_number(b), balance(c)
    {
    }

    void Display()
    {
        cout << name << " " << account_number << " " << balance << endl;
    }

    // our copy contsruter yaah & lagana bahut imp hai nahi to B ki har baar copy bnge and default copy construtre hai nahi recursion mai fs jeyga
    Customer(Customer &B){
        name = B.name;
        account_number = B.account_number;
        balance = B.balance;
    }
};

int main()
{
    Customer *A1 = new Customer("Honey_Singh", 1, 999999);
    // copy constructer default bn gya abhi hmne bnaya nahi lekin jab banyenge tab default nahi banega
    Customer *A2 = new Customer(*A1);

    Customer *A3 = new Customer();
    // copy constructer
    A3 = A2;
    A1->Display();
    A2->Display();
    A3->Display();
}