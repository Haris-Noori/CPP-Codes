//Q6: Write a program that asks for an integer value of any length and find the number of zeros
  //  in the integer.


#include <iostream>
using namespace std;

int main() {
  int count = 0;
  long num;
  cout<<"enter a number: "<< endl;
  cin>>num;
  string a;
  a = to_string(num);
  int len = a.length();
    for (int i = 0; i<= len; i++) 
        {
            if (a[i] == '0')
            count = count + 1;
        }
    cout<<"the number of zeros in integer are:  "<<cout;
   

    return 0;
}
