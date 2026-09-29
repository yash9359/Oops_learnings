#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main()
{

    //* 1. File Write

    // File ko open karna

    // ofstream fout;

    // fout.open("zoom.txt"); // if file doesn't exist then it will create the file

    // // Write kar skta hu

    // fout << "Hello India";

    // fout.close();// file close iss liye taki sari resource ko release karwa paau

    //* 2.File read

    //! read krne ke liye ifstream lgta

    // ifstream fin;

    // // open the file
    // fin.open("zoom.txt");
    // // fir read karo

    // char c;

    // while (fin.get(c))
    //     cout << c;

    // fin.close();

    //*3. IN diff way(diff Example)

    // vector<int>arr(5);
    // cout<<"Enter the Input"<<endl;
    // for(int i = 0;i<5;i++){
    //     cin>>arr[i];
    // }

    // file ko open karo

    // write ke liye ofstream hai

    // ofstream fout;

    // fout.open("Zero.txt");

    // fout<<"Original Data\n";

    // for(int i = 0;i<5;i++){
    //     fout<<arr[i]<<" ";
    // }

    // fout<<"\nSorted data\n";

    // sort(arr.begin(),arr.end());

    // for(int i = 0;i<5;i++){
    //     fout<<arr[i]<<" ";
    // }
    // fout.close();

    //* 4.

    ofstream fout;
    fout.open("z1.txt");
    fout << "Hello India" << endl;
    fout << "Hello Rohit" << endl;
    fout << "Hello Brother" << endl;
    fout.close();

    ifstream fin;
    fin.open("z1.txt");

    string s;

    while (getline(fin, s))
    {
        cout << s << "\n";
    }
}