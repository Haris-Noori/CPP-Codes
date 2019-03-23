#include <iostream>
using namespace std;

int main()
{
	int num, a, b;
	cout << "Enter 3_DIGIT Number:  " <<  endl;
	cin >> num;
	
	b = num%10;
	while( num>=10 )
	{
		num = num/10;
	}
	a = num;
	
	cout << "First digit: " << a << endl;
	cout << "Last digit : " << b << endl;

}  
