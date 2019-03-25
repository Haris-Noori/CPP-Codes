#include <iostream>
using namespace std;

struct node
{
	int data;
	node *previous;
	node *next;
};

class rdll
{
	private:
		node * head, *temp, *current;

		public:
			rdll()
			{
				head = temp = current = NULL;
			}
//..........................................................................
			void append(int x)
			{
				if(head == NULL)
				{
					head = new node;
					head->data = x;					
					head->next = head;
					head->previous = head;

					current = temp = head;
				}

				else
				{
					current = new node;
					current->data = x;
					current->next = head;
					head->previous = current;
					current->previous = temp;
					temp->next = current;
					temp = current;
				}
			}
//...............................................................................
			void display()
			{
				current = head;

				while(current->next != head)
				{
					cout << current->data << "-->";
					current = current->next;
				}
				cout << current->data << endl;

			}
//.................................................................................
			void deleteNode(int x)
			{
				if(head->data == x)
				{
					current = head;
					head->previous->next = head->next;
					head = head->next;
					head->previous = temp;
					delete(current);
					current = temp;
				}

				else if(temp->data == x)
				{
					temp->previous->next = temp->next;
					temp->next->previous = temp->previous;
					current = head->previous;
					delete(temp);
					temp = current;
				}

				else
				{
					current = head;

					while(current->data != x)
					{
						current = current->next;
					}

					current->previous->next = current->next;
					current->next->previous = current->previous;
					delete(current);
					current = temp;
				}
			}
//.......................................................................................

};





int main()
{
	rdll l1;

	l1.append(10);
//	l1.display();

	l1.append(20);
//	l1.display();

	l1.append(30);
	l1.append(40);
	l1.append(50);

	l1.deleteNode(30);
	l1.display();
}