#include <iostream>
#include <fstream>
using namespace std;

class fakebook
{
	private:
		string name1;
		string name2;
		string Date_of_Birth;
		string occupation;
		string school;
		string status;
	
	public:
		void setName()
		{
			cout << "*****************||Welcome to your Account||**************************" << endl;
			cout << "|First things first__" << endl;
			fstream namef("names.txt", ios::in | ios::out | ios::app);
				cout << "-Enter your first name:  ";
				cin >> name1;
				cout << "-Enter your second name:  ";
				cin >> name2;
				namef << name1 << " " << name2 << endl;
			namef.close();

			namef.open("names.txt");               //copying names file data to friends file

				ofstream friendf;
				friendf.open("friends.txt");
				char ch;
				while(! namef.eof() )
				{
					namef.get(ch);
					friendf << ch;
				}
				friendf.close();
			namef.close();
		}

		void setBdate()
		{
			cout << "||__DATE OF BIRTH__||" << endl;
			cout << "|Enter your date of birth so your friends can check it|" << endl;
			fstream dobf("dob.txt", ios::in | ios::out | ios::app);
				cout << "--Input Date in format MM/DD/YYYY:  ";
				cin >> Date_of_Birth;
				dobf << Date_of_Birth << endl;
			dobf.close();
		}

		void setOccupation()
		{
			cout << "||__OCCUPATION__||" << endl;
			cout << "|Enter your occupation|" << endl;
			fstream ocpf("occupation.txt", ios::in | ios::out | ios::app);
				cin >> occupation;
				ocpf << occupation << endl;
			ocpf.close();
		}

		void setSchool()
		{
			cout << "||__SCHOOL/COLLEGE__||" << endl;
			cout << "|Enter any school or college you have attended:  " << endl;
			fstream sclf("school.txt", ios::in | ios::out | ios::app);
				cin >> school;
				sclf << school << endl;
			sclf.close();
		}

		void setStatus()
		{
			cout << "||__STATUS__||" << endl;
			cout << "|Enter  your status....(single/in a relationship/engaged/married/divorced/widowed.." << endl;
			fstream statf("status.txt", ios::in | ios::out | ios::app);
				cin >> status;
				statf << status << endl;
			statf.close();
		}

		void setFriends()
		{
			cout << "||__FRIENDS__||" << endl;
			string line;
			cout << "|You have no friends in your list|" << endl;
			cout << "_but you can make some, here are other fakebook users::" << endl;
			ifstream friendf;
			friendf.open("friends.txt");
				while(!friendf.eof())
				{
					getline(friendf, line);
					cout << line << endl;
				}
				cout << "You can send them request" << endl;
			friendf.close();
		}

		void setGroups()
		{
			cout << "||__GROUPS__||" << endl;
			cout << "*_You have not made any groups yet_*" << endl;
		}

		void setPages()
		{
			cout << "||__PAGES__||" << endl;
			cout << ".....You have no pages to read....." << endl;
			cout << "press 1 to read/pick some::" << endl;
			int select;
			cin >> select;
			if( select == 1)
			{
				fstream pagef("pages.txt", ios:: in | ios:: out | ios::app);
					string line;
					getline(pagef, line);
					cout << line << endl;
				pagef.close();
			}
			else
			{
				cout << "***_Incorrect input_***" << endl;
			}
		}

		void setGames()
		{
			cout << "||__GAMES__||" << endl;
			cout << "--No games played yet--" << endl;
		}

		void showName()
		{
			cout << "*******************||Welcome to your Account||**************************" << endl;
			string line;
			fstream namef("names.txt", ios::in | ios::out | ios::app);
				getline(namef, line);
				cout << "Name:  " << line << endl;
			namef.close();	
		}

		void showBdate()
		{
			string line;
			fstream dobf("dob.txt", ios::in | ios::out | ios::app);
				getline(dobf, line);
				cout << "Date of Birth:  " << line << endl;
			dobf.close();
		}

		void showOccupation()
		{
			string line;
			fstream ocpf("occupation.txt", ios::in | ios::out | ios::app);
				getline(ocpf, line);
				cout << "Occupation:  " << line << endl;
			ocpf.close();
		}

		void showSchool()
		{
			string line;
			fstream sclf("school.txt", ios::in | ios::out | ios::app);
				getline(sclf, line);
				sclf << "School/College:  " << school << endl;
			sclf.close();
		}

		void showStatus()
		{
			string line;
			fstream statf("status.txt", ios::in | ios::out | ios::app);
				getline(statf, line);
				statf << "Status:  " << status << endl;
			statf.close();
		}
	

	
};
//////////////////////////////////class end////////////////////////////////////////////////////////////////










int main()
{

	
	cout << "                         ___WELCOME TO FAKEBOOK___" << endl;
	cout << endl;
	cout << "1- ||Create New Account||                          2- ||Login||" << endl;
	
	int choose;
	cin >> choose;
	if( choose == 1)
	{
		cout << "........Creating New Account........" << endl;
		fstream fout("usernames.txt", ios::in | ios::out | ios::app);
			string str1, str2;
			cout << "Create your username:  ";
			cin >> str1;
			fout << str1 << "     ";                  //writing in file
			cout << "Create password:  ";
			cin >> str2;
			fout << str2 << endl;                       //wriing in file
		fout.close();

		fakebook fb1;
		fb1.setName();
		cout << "\n>__Your Bio__<" << endl;
		cout << "...select where to go...:  " << endl;
		cout << "1_ About:  " << endl;
		cout << "2_ Friends: " << endl;
		cout << "3_ Groups: " << endl;
		cout << "4_ Pages: " << endl;
		cout << "5_ Games: " << endl;
		cout << "6_ Make/Find new friends: " << endl;
		
		int choose;
		cin >> choose;
		switch(choose)
		{	
			case 1:
				fb1.setBdate();
				fb1.setOccupation();
				fb1.setSchool();
				fb1.setStatus();
			break;

			case 2:
				cout << "|__You have no friends in your list__|" << endl;
			break;

			case 3:
				fb1.setGroups();
			break;

			case 4:
				fb1.setPages();
			break;

			case 5:
				fb1.setGames();
			break;

			case 6:
				fb1.setFriends();

			default:
				cout << "**_Input number between 1 to 6 only_**" << endl;
		}

		exit(1);
	}
	else if( choose == 2)
	{
		cout << "........Logging in........" << endl;
		
		string login_username, login_key;
		cout << "Enter your username:  ";
		cin >> login_username;
		cout << "Enter your password:  ";
		cin >> login_key;
		
		fstream checkf("usernames.txt", ios::in | ios::out | ios::app);
			string username1, username2;
			while(!checkf.eof())
			{
				checkf >> username1 >> username2;
				if(username1 != login_username)
				{
					cout << "**_Incorrect Username_**" << endl;
					exit(1);
				}
				else if(username2 != login_key)
				{
					cout << "**_Incorrect Password_**" << endl;
					exit(1);
				}
				else
				{
					cout << "_____successfully Logged In_____" << endl;
					break;
				}

			}
		checkf.close();

		cout << "\n>__Your Bio__<" << endl;
		cout << "...select where to go...:  " << endl;
		cout << "1_ About:  " << endl;
		cout << "2_ Friends: " << endl;
		cout << "3_ Groups: " << endl;
		cout << "4_ Pages: " << endl;
		cout << "5_ Games: " << endl;
		cout << "6_ Make/Find new friends: " << endl;

		int choose;
		cin >> choose;
		fakebook fb2;
		switch(choose)
		{
			case 1:
				fb2.showName();
				fb2.showBdate();
				fb2.showOccupation();
				fb2.showSchool();
				fb2.showStatus();
			break;

			case 2:
				fb2.setFriends();
			break;

			case 3:
				fb2.setGroups();
			break;

			case 4:
				fb2.setPages();
			break;

			case 5:
				fb2.setGames();
			break;

			case 6:
				cout << "~~~~____Search new friends____~~~~" << endl;
				fb2.setFriends();

		}
	}			
	else
	{
		cout << "** Enter either 1 or 2 **" << endl;
		exit(1);
	}

    /////////////////////////////////////////////////////////////////////////////////////////
	
			
			
			

	

}
