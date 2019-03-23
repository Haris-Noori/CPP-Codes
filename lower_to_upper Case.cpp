/* THIS PROGRAM CONVERTS LOWER CASE TO UPPER CASE */

#include <iostream>
using namespace std;

void convert(string& s)
{
	
	for(int i = 0; i < s.length(); i++)
	{
		s[i] = toupper(s[i]);
		
	}
}

int main()
{
	
	string s;
	cout << "Enter string:  " << endl;
	getline(cin , s);
	convert(s);
	cout << s << endl;
	
	
	
}
