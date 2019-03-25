#include <iostream>
using namespace std;


struct node 
{
	int data;
	node* next;
};

class Stack 
{
	private:
		node* top;
	
	public:
		
		Stack()
		{
			top = NULL;
			
		}
		~Stack() 
		{
			delete top;
		}
		
		void push(int x) 
		{
			if(top == NULL) 
			{
				top = new node;
				top->data = x;
				top->next = NULL;
			}
			else
			{
				node* temp = new node;
				temp->data = x;
				temp->next = top;
				top = temp;
			}
		}
		
		int pop() 
		{
			if(top == NULL) 
			{
				cout << "Underflow... " << endl;
				return 0;
			}
			
			node* temp = new node;
			
			cout << top->data << endl;
			temp = top;
			top = top->next;
			delete temp;
		}
		
		int size() 
		{
			int count = 0;
			node *temp;
			temp = top;
			
			while(temp != NULL)
			{
				count++;
				temp = temp->next;	
			}
			
			cout << "Stack size is: " << count << endl;
				
		}
	
};

int main() 
{
	Stack s;
	
	for(int i = 0; i < 10; i++)
	{
		s.push(i);	
	}
	
	
	s.size();
	
	/*s.pop();
	s.pop();
	s.pop();
	s.pop();*/
}
