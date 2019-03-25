#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct node
{
	int data;
	node *next;
};

class linklist
{
	private:
		node *head, *current, *temp;

	public:
		linklist()
		{
			current = temp = head = NULL;
		}

		void append(int data)
		{
			if(head == NULL)
			{
				head = new node;
				head->data = data;
				head->next = NULL;
				current = temp = head;
			}

			else
			{
				current = new node;
				current->data = data;
				current->next = NULL;
				temp->next = current;
				temp = current;
			}
		}

		void display()
		{
			current = head;
			while(current != NULL)
			{
				cout << current->data << " ";
				current = current->next;
			}
			cout << endl;
		}

		void deletenode(int data){

			if(head->data == data){
				current = head;
				head = head->next;
				delete(current);
				current = head;
			}
			else if(temp->data == data){
				current = head;
				while(current->next != temp){
					current = current->next;
				}
				delete(temp);
				temp = current;
				temp->next = NULL;
			}
			else{
				current = head;

				while(current->data != data){
					current = current->next;
				}

				temp = head;

				while(temp->next != current){
					temp = temp->next;
				}

				temp->next = current->next;
				delete(current);

				while(temp != NULL){
					temp = temp->next;
				}
				
				current = temp;
			}
			
		}

		
};


int main()
{
	linklist l1;
	l1.append(2);
	l1.append(3);
	l1.append(4);
	l1.append(5);
	l1.append(6);
	l1.append(7);
	l1.append(8);


	l1.display();

	l1.deletenode(2);
	l1.display();

	l1.deletenode(8);
	l1.display();

	l1.deletenode(5);
	l1.display();

	return 0;
}
