
#include<iostream>
using namespace std;

class Numbers
{
	private:
		int num;

	public:
		Numbers()                         //...........DEFAULT CONSTRUCTOR
		{
			num = 0;
		}

		Numbers(int a)            //...........MY CONSTRUCTOR
		{
			num = a;
		}
		
		friend istream & operator >> (istream &input, Numbers &a);             //..........CIN OF number
		
		friend ostream & operator << (ostream &output, Numbers &a);         //..........COUT of number
		
		setData()
		{
			cout << "---Enter Any NUMBER---" << endl;
			cin >> num; 
		}

		showData()
		{
			cout << "---The NUMBER you entered is---" << num << endl;
		}

		

		Numbers operator ++()
		{
			++num;
			cout << "---After PRE-INCREMENT---: " << num << endl;
		}

		Numbers operator --(int)
		{
			num--;
			cout << "After POST-DECREMENT---: " << num << endl;
		}

		Numbers operator --()
		{
			--num;
			cout << "---After PRE-DECREMENT---: " << num << endl;
		}

		bool operator >(Numbers b)
		{
			if( num > b.num )
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool operator <(Numbers b)
		{
			if( num < b.num )
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool operator ==(Numbers b)
		{
			if( num == b.num )
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		Numbers operator +=(Numbers b)
		{
			num = num + b.num;
			cout << "---After a = a + b---" << num << endl;
			cout << "---b: " << b.num << endl;
		}

		Numbers operator =(Numbers b)
		{
			num = b.num;
			cout << "---a After a = b ---: " << num << endl;
			cout << "---b After a = b ---: " << b.num << endl;
		}

		Numbers operator ++(int);


};

istream & operator >>(istream &input, Numbers &a)
{
	cout << "---Enter the number: " << endl;
	input >> a.num;
	return input;
}

ostream & operator << (ostream &output, Numbers &a)
{
	output << a.num << endl;                                                     
}          

Numbers Numbers::operator ++(int)
{
	num++;
	cout << "---After POST-INCREMENT---: " << num << endl; 
}                                                  							




int main()
{
	Numbers a, b;
	cin >> a;   //  OR a.setData();
	cin >> b;   //  OR b.setData();
	cout << a << endl;  // OR a.showData();
	cout << b << endl;  // OR b.showData();
	a++;
	b++;
	++a;
	++b;
	a--;
	--a;
	b--;
	--b;

	if(a > b)
		{ cout << "---a is greater---" << endl; }
	if(a < b)
		{ cout << "a is smaller---" << endl; }
	if(a == b)
		{ cout << "---a is equal to b---" << endl; }
	a += b;
	a = b;
}
