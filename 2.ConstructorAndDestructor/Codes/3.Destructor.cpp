#include <bits/stdc++.h>
using namespace std;

class Customer
{
    string name;
    int *balance;

public:
    Customer(string name, int bal)
    {   
        cout<<"Constructor is called"<<endl;
        this->name = name;
        // memory pehle allocate karyi pointer ki isko deep mai batana imp concept ache se smjhana
        balance = new int;
        *balance = bal;
    }
    
    ~Customer(){
        cout<<"Destructor free all the memory, dynamic memory release karayega";
        delete balance;
    }
};

int main()
{
    Customer *A1 = new Customer("Yash", 1000);
    \
    // iski wajh se hamara destrutor call hota werna nahi hota kyuiki hmne dynamic object banye thee abb ye a1 ko bhi dlete kar dega
    delete A1;
}


/// key claude ye bhi batna ki destrutor mai dependency kya hoti hai matlb constutre line wise call hote but destutre ulta hota uska bilkul ache se batana