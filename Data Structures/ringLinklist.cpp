#include <iostream>
using namespace std;

struct node 
{
    int data;
    node *next;
};

class cll 
{
    private: 
        node *head, *current, *temp;

        public:

            cll()
            {
                head = current = temp = NULL;
            }

            void append(int x)
            {
                if (head == NULL)
                {
                    head = new node;
                    head->data = x;
                    head->next = head;
                    current = temp = head;
                }

                else
                {
                    //current = head;
                    current = new node;
                    current->data = x;
                    current->next = head;
                    temp->next = current;
                    temp = current;
                }
            }

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

            void deleteNode(int x)
            {
                current = head;

                if(current->data == x)
                {
                    temp->next = head->next;
                    head = head->next;
                    delete(current);
                    current = temp;
                }

                else if(temp->data == x)
                {
                    while(current->next != temp)
                    {
                        current = current->next;
                    }

                    current->next = temp->next;
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

                    temp = head;
                    while(temp->next != current)
                    {
                        temp = temp->next;
                    }
                
                    temp->next = current->next;
                    delete(current);
                    current = temp;   
                }
            }




};

int main()
{
    cll l1;

    for(int i = 1; i < 11; i++)
    {
        l1.append(i);
    }

    l1.display();

    l1.deleteNode(1);
    l1.display();

    l1.deleteNode(5);
    l1.display();

    l1.deleteNode(10);
    l1.display();
}