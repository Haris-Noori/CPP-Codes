#include <iostream>
#include <cmath>
using namespace std;

float pi = 3.142;
class shape
{	
	private:
		string color;

	public:
		shape()
		{
			cout << "constructor of SHAPE" << endl;
		}
		~shape()
		{
			cout << "***DESTROYING SHAPE***" << endl;
		}
		void print()
		{
			cout << "---CLASS SHAPE---" << endl;
		}

		void perimeter()
		{
			cout << "---Perimeter of SHAPE class---" << endl;
		}

};

class circle: virtual public shape
{
	private:
		float radius;
	public:
		circle()
		{
			cout << "constructor of circle" << endl;
		}

		virtual ~circle()
		{
			cout << "***DESTROYING CIRCLE***" << endl;
		}
		/*void print()
		{
			cout << "---CLASS CIRCLE---" << endl;
		}

		void perimeter()
		{
			cout << "---perimeter of rectangle class---" << endl;
		}

		void area(float r)
		{
			radius = r;
			cout << "---area of CIRCLE class:  ";
			cout << pi * pow(radius,2.0) << endl;
		}*/
};

class rectangle: virtual public shape
{
	private:
		float width;
		float height;
	public:
		rectangle()
		{
			cout << "constructor of rectangle" << endl;
		}

		virtual ~rectangle()
		{
			cout << "***DESTROYING RECTANGLE***" << endl;
		}
		/*void print()
		{
			cout << "---Rectangle class---" << endl;
		}

		void perimeter()
		{
			cout << "---perimeter of rectangle class---" << endl;
		}*/

};

class test: public circle, rectangle
{
	public:
		
		/*void print_test()
		{
			cout << "---CLASS TEST---" << endl;
		}

		void perimeter_test()
		{
			cout << "---perimeter of test---" << endl;
		}*/
};


int main()
{
	//shape* ptrobj[2];
	/*shape* ptr1 = new circle;              //objects of circle class
	shape* ptr2 = new rectangle;*/           //objects of rectangle class

	/*for( int i = 0; i < 2; i++)
	{
		ptrobj[0]->print();
	}*/ 
	
	/*ptr1->print();
	ptr2->print();

	circle obj;
	obj.area(2);

	rectangle obj1;
	obj.perimeter();*/

	test obj;
	obj.print();
	obj.perimeter();
	

}
