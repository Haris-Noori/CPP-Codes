#include <iostream>
using namespace std;

void palindrome()
{
	int size;
	char *top, *last;
	
	cout << "Enter the size of array: " << endl;
	cin >> size;
	
	char arr[size];
	
	//taking input in array
	for(int i = 0; i < size; i++)
	{
		cout << "Enter character " << i + 1 << ": ";
		cin >> *(arr+i);
	}
	
	last = arr;
	top = arr;
	

	//setting *last at end of array
	for(int i = 0; i < size-1; i++)
	{
		last++;
	}
	
	//check if palindrome
	for(int i = 0; i < size; i++)
	{
		if(*top != *last)
		{
			cout << "NOT PALINDROME" << endl;
			break;
		}
		
		else
		{
			top++;
			last--;
		}
	}
	
	
	
	
		
}


int main()
{
	palindrome();
	
}
