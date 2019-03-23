#include<iostream>
using namespace std;

class bankAccount
{
	private:
		int acc_num;
		double balance;
	public:
		bankAccount()                              //DEFAULT CONSTRUCTOR...........
		{
			acc_num = 0;
			balance = 0;
		}

		bankAccount(int ac, double bal)               //MY CONSTRUCTOR
		{
			acc_num = ac;
			balance = bal;
		}

		~bankAccount()
		{
			cout << "*-*-*DESTROYING MEMBER DATA OF bankAccount*-*-*" << endl;
		}

		void setAccNumber(int a)
		{
			acc_num = a;
		}

		void retrieveAccNumber()
		{
			cout << "+++YOUR ACCOUNT NUMBER is:  " << acc_num << endl;
		}

		double retrieveBalance()
		{
			cout << "+++YOUR BALANCE is:  " << balance << endl;
		}

		void withdraw(double b)
		{
			cout << "---CHECKING YOUR AMOUNT---" << endl;
			if(b > balance)
			{
				cout << "***SORRY!! YOU CAN NOT WITHDRAW THIS AMOUNT, YOU DO NOT HAVE ENOUGH BALANCE***";
				cout << "\n---YOUR BALANCE is:  " << balance << endl;
			}
			else
			{
				cout << "+++HERE IS YOUR AMOUNT+++" << endl;
				cout << "NOW YOUR REMAINNG BALANCE is:  " << balance - b << endl;
			}
		}

		void deposit(double b)
		{
			cout << "---THANKYOU FOR DEPOSIT YOUR MONEY---" << endl;
			cout << "YOUR BALANCE is:  " << balance + b << endl;
		}


};

class checkingAccount:public bankAccount
{
	private:
		int interestRate;
		double minimumBalance;
		double serviceCharges;
	public:
		checkingAccount()                      //DEFAULT CONSTRUCTOR..........
		{
			interestRate = 0;
			minimumBalance = 0.0;
			serviceCharges = 0.0;
		}

		checkingAccount(int i, double m, double s)         //MY CONSTRUCTOR..........
		{
			interestRate = i;
			minimumBalance = m;
			serviceCharges = s;
		}

		~checkingAccount()
		{
			cout << "*-*-*DESTROYING MEMBER DATA OF checkingAccount*-*-*" << endl;
		}

		void setInterestRate(int in_rate)
		{
			bankAccount::setAccNumber(176003);
			interestRate = in_rate;
		}

		void retrieveInterestRate()
		{
			bankAccount::retrieveAccNumber();
			cout << "---INTEREST RATE is:  " << interestRate << "%" << endl;
		}

		void setMinimumBalance(double min_bal)
		{
			minimumBalance = min_bal;
		}

		void retrieveMinimumBalance()
		{
			cout << "---MINIMUM BALANCE SHALL BE:  " << minimumBalance << endl;
		}

		void setServiceCharges(double ser_char)
		{
			serviceCharges = ser_char;
		}

		void retrieveServiceCharges()
		{
			if(bankAccount::retrieveBalance() < minimumBalance)
			{
				cout << "***SORRY!! You have to pay for service charges because your balance is less than minimum balance" << endl;
				cout << "SERVICE CHARGES:  " << serviceCharges << endl;
			}
			else
			{
				cout << "InCase service charges are:  " << serviceCharges << endl;
			}
		}

		void withdraw()
		{
			bankAccount::withdraw(500);
		}


};


int main()
{
	bankAccount a1;

	//a1.setAccNumber(176003);
	//a1.retrieveAccNumber();
	//a1.retrieveBalance();
	//a1.withdraw(500);
	//a1.deposit(500);

	checkingAccount c1;
	c1.setInterestRate(5);
	c1.retrieveInterestRate();
	c1.setMinimumBalance(250);
	c1.retrieveMinimumBalance();
	c1.setServiceCharges(50);
	c1.retrieveServiceCharges();
	c1.withdraw();

}
