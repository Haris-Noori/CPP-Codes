#include <iostream>
#include <stdlib.h>
using namespace std;


int fib(int num)
{
    if(num <= 1)
    {
        return num;
    }

   else
   {
   		return fib(num-1) + fib(num-2);
   }
    
    
}

int main()
{
    cout << fib(6) << endl;
}
