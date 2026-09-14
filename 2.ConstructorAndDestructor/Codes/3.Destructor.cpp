#include <bits/stdc++.h>
using namespace std;

class Customer
{
    string name;
    int *balance;

public:
    Customer(string name, int bal)
    {
        this->name = name;
        // memory pehle allocate karyi pointer ki isko deep mai batana
        balance = new int;
        *balance = bal;
    }
    
    ~Customer(){
        cout<<"Destructor free all the memory, dynamic memory release karayega"
    }
};

int main()
{
    Customer *A1 = new Customer("Yash", 1000);


}