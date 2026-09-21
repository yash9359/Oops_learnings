// ! Abstraction
#include<bits/stdc++.h>
using namespace std;

// ** Abstraction -> Display only essential inforamtion & hiding the details.

class customer {
    string name;
    int balance;

    public:
    customer(string a,int b){
        name = a;
        balance = b;
    }

    void deposit(int amount){
        // mujhe ye user ko nahi ddikahan ye chupana hoga let says bank mai dalaa 500 but store hua 499 1 tax lekin user ko kya apata
        if(amount>0){
            this->balance+=amount;
        }
    }

};


int main(){


    customer A1("rohit", 500);
    // hme ye nahi socne ki zarooart ki ye kese store hoga bss hogya bss yahi ahai abstraction
    A1.deposit(5000);


    return 0;
}