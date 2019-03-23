//Q11: Write a program that prompts the user to input a positive integer. It should then output a
//     message indicating whether the number is a prime number


#include <iostream>
using namespace std;

int main()  
{
  int num, i;
  bool is_Prime = true;

  cout << "Enter a positive integer: ";
  cin >> num;

  for(i = 2; i <= num / 2; ++i)  {
      if(num % i == 0)  {
          is_Prime = false;
          break;
          }    
      }
  if (is_Prime)
      cout << "number is Prime";
  else
      cout << "number is not Prime";

  return 0;
}
