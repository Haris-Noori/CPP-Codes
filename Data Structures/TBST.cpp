/*                            THREADED BINARY SEARCH TREE                                        
-------------------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

struct node
{
	int data;
	int LTH,RTH;
	node *left, *right;
};

class TBST
{
	private:
		node *current;

	public:
		node *root, *Dummy;

		TBST()
		{
			root = NULL;
			Dummy = new node;
			Dummy->left = Dummy;
			Dummy->right = Dummy;
			Dummy->LTH = Dummy->RTH = 1;
		}

		//.......................INSERT FUNCTION STARTS HERE.........//
		void insert(int x, node *temp)
		{
			if(root == NULL)
			{
				temp = new node;
				temp->data = x;
				Dummy->left = temp;
				temp->left = Dummy;
				temp->right = Dummy;
				Dummy->LTH = 1; 
				temp->LTH = 0;
				temp->RTH = 0;
				root = temp; 
				cout << "---ROOT " << x << " INSERTED---" << endl;
				return;
			}
			
			if(x == temp->data)
			{
				cout << "---ALREADY PRESENT IN TREE---" << endl;
				return;
			}
			
			else if(x < temp->data)
			{
				if(temp->LTH != 0)
				{
					insert(x,temp->left);
					return;
				}
				else
				{
					current = new node;
					current->data = x;
					current->left = temp->left;
					temp->left = current;
					temp->LTH = 1;
					current->right = temp;
					current->LTH = 0;
					current->RTH = 0;
					cout << "---NODE " << x << " INSERTED---" << endl;
					return;
				}
			}

			else
			{
				if(temp->RTH != 0)
				{
					insert(x,temp->right);
					return;
				}
				else
				{
					current = new node;
					current->data = x;
					current->right = temp->right;
					temp->right = current;
					temp->RTH = 1;
					current->left = temp;
					current->LTH = 0;
					current->RTH = 0;
					cout << "---NODE " << x << " INSERTED---" << endl;
					return;
				}
			}

			
		}
		//.................INSERT FUNCTION ENDS HERE.................//

		//.................INORDER TRAVERSAL STARTS HERE.........................//
		node* nextInOrder(node *temp)
		{
			if(temp->RTH == 0)
			{
				return temp->right;
			}
			else
			{
				temp = temp->right;
				while(temp->LTH == 1)
				{
					temp = temp->left;
				}
				return temp;
			}
		}
		
		node* fastInOrder(node *temp)
		{
			while( (temp = nextInOrder(temp)) != Dummy)
			{
				cout << temp->data << " " << "temp->LTH: " << temp->LTH << " " << "temp->RTH: " << temp->RTH << endl;
			}
		}
		//.................INORDER TRAVERSAL ENDS HERE.........................//

		//.................DELETION STARTS HERE...............................//
		void deleteNode(int x, node *temp)
		{

			if(temp->left == NULL)
			{
				cout << "---NODE NOT PRESENTT IN TREE---" << endl;
				return;
			}

			if(x == temp->left->data)
			{
				if(temp->left->RTH == 0 && temp->left->RTH == 0) //CASE 1(NO CHILD)
				{
					current = new node;
					current = temp->left;
					temp->left = current->left;
					temp->LTH = 0;
					delete current;
					current = NULL;
					return;
				}
				if(temp->left->LTH == 1 && temp->left->RTH == 0) //CASE 2(LEFT CHILD)
				{
					current = new node;
					current = temp->left;
					temp->left = current->left;
					current->left->right = current->right;
					delete current;
					current = NULL;
					cout << "before return" << endl;
					return;
					cout << "after return" << endl;
				}
				if(temp->left->LTH == 0 && temp->left->RTH == 1) //CASE 2(RIGHT CHILD)
				{
					cout << "case 2_right child funtion in" << endl;
					current = new node;
					current = temp->left;
					temp->left = current->right;
					current->left->left = current->left;
					delete current;
					current = NULL;
					cout << "before return" << endl;
					return;
				}
			}

			if(x < temp->left->data && temp->left->left != NULL)
			{
				deleteNode(x,temp->left);
				return;
			}

			if(temp->left->data < x && temp->left->right != NULL)
			{
				deleteNode(x,temp->left->right);
				return;
			}

		}
		//..................DELETION ENDS HERE.........................//

			




};
////////////////////////////////////////////////////////////////////////////
///////                     MAIN FUNCTION                             //////
////////////////////////////////////////////////////////////////////////////
int main()
{
	TBST tbst;
	
	tbst.insert(10,tbst.root);
	//tbst.insert(12,tbst.root);
	tbst.insert(4,tbst.root);

	/*tbst.insert(2,tbst.root);
	tbst.insert(10,tbst.root);
	tbst.insert(11,tbst.root);
	tbst.insert(5,tbst.root);
	tbst.insert(3,tbst.root);
	tbst.insert(1,tbst.root);*/

	tbst.fastInOrder(tbst.Dummy); 
	cout << endl;

	tbst.deleteNode(10,tbst.Dummy);
	cout << "delete function ends" << endl;
	tbst.fastInOrder(tbst.Dummy); 


}
