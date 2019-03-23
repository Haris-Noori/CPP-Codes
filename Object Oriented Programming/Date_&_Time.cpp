/*
NAME:  MUHAMMAD HARIS NOORI
ROLL NO:  P17-6003
SECTION: A
DEPT: CS
ASSIGNMENT#4
*/

/*
Make a class “DateandTime”, its object can store both the time and date. Where time should be store in “AM/PM” format (Not 24 Hrs format).
Code should include:
1. All the Mutator and Accessor functions for the data members part of a class.
2. Overload the constructor that can handle all the initialization scenarios you can think.
3. Provide a destructor that will remove the data present in data members of an object.
4. Provide input function that will take the date and time as input in the given formats (DD-MM-YYYY and HH:MM:SS).
5. Provide the output functions for the following requirements to be fulfilled:
a. Object can be used to print Short Date(Date Only).
b. To print Short Time(Time Only).
c. To print Long Date(Date and Time both).
d. To print Date in English(8th March, 2018).
*/

#include<iostream>
using namespace std;

class DateandTime
{
	private:
		string Time;
		string Date;
	public:
		DateandTime()                 //...............constructor with no arguments.........
		{
			Time = "00:00:00 AM";
			Date = "01-01-2018";
		};
		
		DateandTime(string T, string D)       //.........constructor with 2 arguments...........
		{
			Time = T;
			Date = D;
		};
		~DateandTime()
		{
			cout << "...destroying Time and Date..." << endl;//destructor_destroying time and date duzz duzz duzz....
			Time = '\0';
			Date = '\0';
		}

		int setDate()
		{
			cout << "...Enter Date in format DD-MM-YYYY..:" << endl;
			cin >> Date;
		}

		int setTime()
		{
			cout << "...Enter Time in format HH:MM:SS...AM/PM..:" << endl;
			cin >> Time;
		}

		int ShortDate()
		{
			cout << "short Date:  " << Date << endl;
		}

		int ShortTime()
		{
			char t1 = Time[0];
			char t2 = Time[1];

			if( t1 >= '2' && t2 >= '4')
			{
				cout << "*****INVALID HOUR*****" << endl;
			}
			
			if( Time[3] >='6' )
			{
				cout << "*****INVALID MINUTES*****" << endl;
			}

			if( Time[6] >='6' )
			{
				cout << "*****INVALID SECONDS*****" << endl;
			}
			
			if( t1 == '1' && t2 == '3')
			{
				Time[0] = '0';
				Time[1] = '1';
				cout <<"short Time:  " <<  Time << " PM"<< endl;
			}
			if( t1 == '1' && t2 == '4')
			{
				Time[0] = '0';
				Time[1] = '2';
				cout <<"short Time:  " <<  Time << " PM"<< endl;
			}
			if( t1 == '1' && t2 == '5')
			{
				Time[0] = '0';
				Time[1] = '3';
				cout <<"short Time:  " <<  Time << " PM"<< endl;
			}
			if( t1 == '1' && t2 == '6')
			{
				Time[0] = '0';
				Time[1] = '4';
				cout <<"short Time:  " <<  Time << " PM"<< endl;
			}
			if( t1 == '1' && t2 == '7')
			{
				Time[0] = '0';
				Time[1] = '5';
				cout <<"short Time:  " <<  Time << " PM"<< endl;
			}
			if( t1 == '1' && t2 == '8')
			{
				Time[0] = '0';
				Time[1] = '6';
				cout <<"short Time:  " <<  Time << " PM"<< endl;
			}
			if( t1 == '1' && t2 == '9')
			{
				Time[0] = '0';
				Time[1] = '7';
				cout <<"short Time:  " <<  Time << " PM"<< endl;
			}
			if( t1 == '2' && t2 == '0')
			{
				Time[0] = '0';
				Time[1] = '8';
				cout <<"short Time:  " <<  Time << " PM"<< endl;
			}
			if( t1 == '2' && t2 == '1')
			{
				Time[0] = '0';
				Time[1] = '9';
				cout <<"short Time:  " <<  Time << " PM"<< endl;
			}
			if( t1 == '2' && t2 == '2')
			{
				Time[0] = '1';
				Time[1] = '0';
				cout <<"short Time:  " <<  Time << " PM"<< endl;
			}
			if( t1 == '2' && t2 == '3')
			{
				Time[0] = '1';
				Time[1] = '1';
				cout <<"short Time:  " <<  Time << " PM"<< endl;
			}
		}

		int LongDate()
		{
			cout << "Long Date:  " << Date << "  " << Time << endl;
		}

		int Date_in_English()
		{
			char D1 = Date[0];
			char D2 = Date[1];
			char M1 = Date[3];
			char M2 = Date[4];
			string month;

			if( M1=='0' && M2=='1' )    //...............................January..............
			{
				if( D1 == '0' )
				{
					if(D2 >='1' && D2 <='9')
					{
						month = "January";
					}
				}
				else if(D1 == '1' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "January";
					}
				}
				else if(D1 == '2' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "January";
					}
				}
				else if(D1 == '3' )
				{
					if(D2 =='0' or D2 =='1')
					{
						month = "January";
					}
				}
				else
				{
					cout << "***Invalid Date***" << endl;
				}
			}

			else if( M1=='0' && M2=='2' )       //............Febraury..................
			{
				if( D1 == '0' )
				{
					if(D2 >='1' && D2 <='9')
					{
						month = "February";
					}
				}
				else if(D1 == '1' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "February";
					}
				}
				else if(D1 == '2' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "February";
					}
				}
				else
				{
					cout << "***Invalid Date***" << endl;
				}
			}

			else if( M1=='0' && M2=='3' )        //............March.............................
			{
				if( D1 == '0' )
				{
					if(D2 >='1' && D2 <='9')
					{
						month = "March";
					}
				}
				else if(D1 == '1' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "March";
					}
				}
				else if(D1 == '2' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "March";
					}
				}
				else if(D1 == '3' )
				{
					if(D2 =='0' or D2 =='1')
					{
						month = "March";
					}
					else
					{
						cout << "****************************Invalid Date********************" << endl;
					}
				}
				else
				{
					cout << "***Invalid Date***" << endl;
				}
			}

			else if( M1=='0' && M2=='4' )          //............April
			{
				if( D1 == '0' )
				{
					if(D2 >=1 && D2 <='9')
					{
						month = "April";
					}
				}
				else if(D1 == '1' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "April";
					}
				}
				else if(D1 == '2' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "April";
					}
				}
				else if(D1 == '3' && D2 == '0')
				{
					month = "April";
				}
				else
				{
					cout << "***Invalid Date***" << endl;
				}
			}

			else if( M1=='0' && M2=='5' )          //....................May..................
			{
				if( D1 == '0' )
				{
					if(D2 >=1 && D2 <='9')
					{
						month = "May";
					}
				}
				else if(D1 == '1' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "May";
					}
				}
				else if(D1 == '2' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "May";
					}
				}
				else if(D1 == '3' )
				{
					if(D2 =='0' or D2 =='1')
					{
						month = "May";
					}
				}
				else
				{
					cout << "***Invalid Date***" << endl;
				}
			}

			else if( M1=='0' && M2=='6' )            //...................JUNE.......................
			{
				if( D1 == '0' )
				{
					if(D2 >='1' && D2 <='9')
					{
						month = "June";
					}
				}
				else if(D1 == '1' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "June";
					}
				}
				else if(D1 == '2' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "June";
					}
				}
				else if(D1 == '3' && D2 == '0')
				{
					month = "June";
				}
				else
				{
					cout << "***Invalid Date***" << endl;
				}
			}

			else if( M1=='0' && M2=='7' )         //............JULY.................
			{
				if( D1 == '0' )
				{
					if(D2 >='1' && D2 <='9')
					{
						month = "July";
					}
				}
				else if(D1 == '1' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "July";
					}
				}
				else if(D1 == '2' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "July";
					}
				}
				else if(D1 == '3' )
				{
					if(D2 =='0' or D2 =='1')
					{
						month = "July";
					}
				}
				else
				{
					cout << "***Invalid Date***" << endl;
				}
			}

			else if( M1=='0' && M2=='8' )     //....................August.........................
			{
				if( D1 == '0' )
				{
					if(D2 >='1' && D2 <='9')
					{
						month = "August";
					}
				}
				else if(D1 == '1' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "August";
					}
				}
				else if(D1 == '2' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "August";
					}
				}
				else if(D1 == '3' )
				{
					if(D2 =='0' or D2 =='1')
					{
						month = "August";
					}
				}
				else
				{
					cout << "***Invalid Date***" << endl;
				}
			}

			else if( M1=='0' && M2=='9' )        //.........September..........................
			{
				if( D1 == '0' )
				{
					if(D2 >='1' && D2 <='9')
					{
						month = "September";
					}
				}
				else if(D1 == '1' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "September";
					}
				}
				else if(D1 == '2' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "September";
					}
				}
				else if(D1 == '3' && D2 == '0')
				{
					month = "September";
				}
				else
				{
					cout << "***Invalid Date***" << endl;
				}
			}

			else if( M1=='1' && M2=='0' )       //...........October................
			{
				if( D1 == '0' )
				{
					if(D2 >='1' && D2 <='9')
					{
						month = "October";
					}
				}
				else if(D1 == '1' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "October";
					}
				}
				else if(D1 == '2' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "October";
					}
				}
				else if(D1 == '3' )
				{
					if(D2 =='0' or D2 =='1')
					{
						month = "October";
					}
				}
				else
				{
					cout << "***Invalid Date***" << endl;
				}
			}

			else if( M1=='1' && M2=='1' )         //............November............
			{
				if( D1 == '0' )
				{
					if(D2 >='1' && D2 <='9')
					{
						month = "November";
					}
				}
				else if(D1 == '1' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "November";
					}
				}
				else if(D1 == '2' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "November";
					}
				}
				else if(D1 == '3' && D2 == '0')
				{
					month = "November";
				}
				else
				{
					cout << "***Invalid Date***" << endl;
				}
			}

			else if( M1=='1' && M2=='2' )     //.............December................
			{
				if( D1 == '0' )
				{
					if(D2 >='1' && D2 <='9')
					{
						month = "December";
					}
				}
				else if(D1 == '1' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "December";
					}
				}
				else if(D1 == '2' )
				{
					if(D2 >='0' && D2 <='9')
					{
						month = "December";
					}
				}
				else if(D1 == '3' )
				{
					if(D2 =='0' or D2 =='1')
					{
						month = "December";
					}
				}
				else
				{
					cout << "***Invalid Date***" << endl;
				}
				
			}
			
			else
			{
				cout << "*.*.*.*.Invalid Date or Month.*.*.*.*" << endl;
			}
			
			cout<<"Date in English:-> "<<Date[0]<<Date[1]<<" "<<month<<", "<<Date[6]<<Date[7]<<Date[8]<<Date[9]<<endl;	

			
		}

		
		




};



int main()
{
	DateandTime dt;
	dt.setDate();
	dt.setTime();
	dt.ShortDate();
	dt.ShortTime();
	dt.LongDate();
	dt.Date_in_English();
	
	
}
