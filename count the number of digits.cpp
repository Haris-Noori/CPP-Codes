// this program counts the number of digits in -num- variable

#include <iostream>
using namespace std;

int main()
{
	int num = 123;
	int digits = 0;
	while( num != 0)
	{
		num = num / 10;
		digits = digits + 1;
	}
	cout << digits << endl;
	

}
