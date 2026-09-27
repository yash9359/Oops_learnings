#include <bits/stdc++.h>
using namespace std;

//* Exception Handling-> An exception  is an unexpected problem that arises during the execution of a program & our program terminates suddenly with some issuess/errors->execption hmesa run time pe hi aate hai

// 3 types-> try ,catch, throw explain it properly kese use karte syntax kaha use  hota kese handle karte hai

class exeception{
    protected:
    string msg;

    public:
    exeception(string msg){
        this->msg = msg;
    }


    string what() const{
        return msg;
    }

};

class my_runtime_error:public exeception {

    public:

    my_runtime_error(const  string &msg):exeception(msg){

    }

};

class InvalidAmountError :  public runtime_error{
    public:

    InvalidAmountError(const string &msg):runtime_error(msg){

    }
};




class Customer
{
    string name;
    int balance, acc_no;

public:
    Customer(string name, int balance, int acc_no)
    {
        this->name = name;
        this->balance = balance;
        this->acc_no = acc_no;
    }

    //* deposit

    void deposit(int amount)
    {

        if (amount <= 0)
            throw runtime_error("amount should be gerater than 0\n");

        balance += amount;
        cout << amount << "rs is credited successfully\n";
    }
    //* withdraw
    void withdraw(int amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << amount << "rs is debited successfully";
        }
        else if (amount < 0)
        {
            throw InvalidAmountError("amount should greater than 0");
        }
        else
        {   

            // bina object banye constructer call
            throw my_runtime_error("insufficient amount");
        }
    }
};

int main()
{
    Customer C1("Yash", 5000, 1234);
    try
    {
        C1.deposit(100);
        
        C1.withdraw(-1);

        // yechelga hi nahi upper wale mai error kyuki
        C1.deposit(500);
    }
    catch(const InvalidAmountError &e){
        cout<<"Exception Occured: "<<e.what()<<endl;
    }
    catch (const char *error)
    {
        cout << "Exception Occured: " << error << endl;
    }
    catch(const runtime_error &e){
        cout << "runtime_error Occured: " << e.what() << endl;
    }
    catch(const my_runtime_error &e){
        cout << "runtime_error Occured: " << e.what() << endl;
    }catch(...){
        // default constrctor
        cout<<"Eception occured"<<endl;
    }
}




// exception class as well as its types-> jitni bhi jo hoti hai sbbb smhjana depth mai



// class exeception{
//     protected:
//     string msg;

//     public:
//     exeception(string msg){
//         this->msg = msg;
//     }


//     string what(){
//         return msg;
//     }

// };


// int main(){


//     try{

//         int *p = new int[1000000000000LL];
        
//         cout<<"Memory allocation is successfull\n";

//         delete []p;

//     }catch(const bad_alloc &e ){
//          cout<<"Execption occurred due to line 97: "<<e.what()<<endl;
//     }
    // catch(const exception &e){
    //     cout<<"Execption occurred due to line 97: "<<e.what()<<endl;
    // }
// }