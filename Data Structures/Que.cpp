#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

class QUE
{
    private:
        node *head, *temp, *current;
    public:

        QUE()
        {
            head = temp = current = NULL;
        }

        void enque(int data)
        {
            if(head == NULL)
            {
                head = new node;
                current = temp = head;
                head->next = NULL;
                head->data = data;
            }
            else
            {
                current = new node;
                current->next = NULL;
                current->data = data;
                temp->next = current;
                temp = current;
            }
        }

        void deque()
        {
            if(head==NULL)
            {
                cout<<"No item in que"<<endl;
            }

            else
            {
                current = head;
                head = head->next;
                delete(current);

                while(current != NULL)
                {
                    current = current->next;
                }
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


};

int main()
{
    QUE que1;

    que1.enque(6);
    que1.enque(3);
    que1.enque(2);
    que1.enque(5);
    que1.enque(7);
    que1.enque(1);
    que1.enque(9);

    que1.display();

    que1.deque();
    que1.deque();
    que1.deque();
    que1.deque();
    que1.deque();
    que1.deque();
    que1.deque();
    

    que1.display();

    return 0;
}