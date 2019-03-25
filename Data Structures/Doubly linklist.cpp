#include <iostream>
using namespace std;

struct node
{
    node *previous;
    int data;
    node *next;
};

class dll
{
    private:
        node *head, *current, *temp;

    public:
        dll()
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
                head->previous = NULL;
                current = temp = head;
            }

            else
            {
                current = new node;
                current->data = data;
                current->next = NULL;
                current->previous = temp;
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

        void deleteNode(int data)
        {
            if(head->data == data)
            {
                //current = head;
                head = head->next;
                delete(head->previous);
            
            }

            else if(temp->data == data)
            {
                current = temp;

                current = current->previous;

                delete(temp);

                temp = current;
                current->next = NULL;

                // current = head;

                // while(current->next != temp){
                //     current = current->next;
                // }
                
                // delete(temp);

                // temp = current;
                // temp->next = NULL;
            }

            else
            {
                current = head;

                while(current->data != data)
                {
                    current = current->next;
                }

                current->previous->next = current->next;
                current->next->previous = current->previous;
                delete(current);
                current = temp;
            }

        }

};

int main()
{
    dll d1;
    
    d1.append(1);
    d1.append(2);
    d1.append(3);
    d1.append(4);
    d1.append(5);
    d1.append(10);

    d1.display();

    d1.deleteNode(1);

    d1.display();

    d1.deleteNode(2);

    d1.display();

    d1.deleteNode(10);

    d1.display();

    d1.deleteNode(3);

    d1.display();

    d1.deleteNode(5);

    d1.display();

    return 0;
}
