#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node
{
    int info;
    node *right;
    node *left;    
};

class BST
{
    private:
        node *temp;

    public:
        node *root, *current, *temp1;
        int key, height = 0;

    BST()
    {
        temp = root = NULL;
    }

//......................................................................
    void insert(int x, node *temp)
    {
        //temp = root;

        if(root == NULL)
        {
            root = new node;
            root->info = x;
            root->right = NULL;
            root->left = NULL;
            //cout << "node inserted" << endl;
            return;
        }

        else
        {    
            if(temp->info == x)
            {
                cout << "***_ALREADY PRESENT IN BST_***" << endl;
                return;
            }

            if(temp->info < x)
            {
                if(temp->right == NULL)
                {
                    
                    temp->right = new node;
                    temp->right->info = x;
                    temp->right->right = NULL;
                    temp->right->left = NULL;
                    //cout << "node inserted" << endl;
                    return;
                }
                else
                {
                    insert(x, temp->right);
                    return;
                }
            }
            if(temp->info > x)
            {
                if(temp->left == NULL)
                {
                    temp->left = new node;
                    temp->left->info = x;
                    temp->left->right = NULL;
                    temp->left->left = NULL;
                    //cout << "node inserted" << endl;
                    return;
                }
                else
                {
                    insert(x,temp->left);
                    return;
                }
            }
        }
    }    
//............................................................................
	void InOrder(node *temp)
	{
		//temp = root;
		if(root == NULL)
		{
			cout << "--BST is empty" << endl;
			return;
		}

		if(temp->left != NULL)
		{
			InOrder(temp->left);
		}
		
		cout << temp->info << "  ";

		if(temp->right != NULL)
		{
			InOrder(temp->right);
		}
	}

    void PreOrder(node *temp)
    {
        if(root == NULL)
        {
            cout << "---BST is empty---" << endl;
            return;
        }

        cout << temp->info << " ";

        if(temp->left != NULL)
        {
            PreOrder(temp->left);
        }

        if(temp->right != NULL)
        {
            PreOrder(temp->right);
        }
    }

    void PostOrder(node *temp)
    {
        if(root == NULL)
        {
            cout << "---TREE is empty---" << endl;
            return;
        }

        if(temp->left != NULL)
        {
            PostOrder(temp->left);
        }

        if(temp->right != NULL)
        {
            PostOrder(temp->right);
        }

        cout << temp->info << " ";
    }
/////////////////////////////////////////////////////////////////////////
//                                  DELETE NODE                        //
/////////////////////////////////////////////////////////////////////////


    void delte(node *temp, int value)
    {
    	if(temp == NULL)
    	{
    		cout << "tree is empty\n";
    		return;
    	}
    	if(value == temp->info)
    	{
    		if(temp->right == NULL and temp->left == NULL)
    			delete temp;
    		if(temp->right != NULL and temp->left == NULL)
    			temp  = temp->right;
    		if(temp->left != NULL and temp->right == NULL)
    			temp = temp->left; 
    	}
    	if(value > temp->info)
    	{
	    	if (temp->right != NULL)
	    	{
		    	if(temp->right->info == value)
		    	{
		    		if(temp->right->right == NULL and temp->right->left == NULL)
		    		{
		    			delete temp->right;
		    			temp->right = NULL;
		    			return;
		    		}
		    		if(temp->right->right != NULL and temp->right->left == NULL)
		    		{
		    			temp1 = temp->right;
		    			temp->right = temp->right->right;
		    			delete temp1;
		    			temp1 = NULL;
		    			return;
		    		}
		    		if(temp->right->right == NULL and temp->right->left != NULL)
		    		{
		    			temp1 = temp->right;
		    			temp->right = temp->right->left;
		    			delete temp1;
		    			temp1 = NULL;
		    			return;
		    		}
		    		if(temp->right->right != NULL and temp->right->left != NULL)
		    		{
		    			if(temp->right->right->left == NULL)
		    			{
		    				swap(temp->right->info, temp->right->right->info);
		    				if(temp->right->right->right != NULL)		    					
		    				{
		    					temp1 = temp->right->right;
		    					temp->right->right = temp->right->right->right;
		    					delete temp1;
		    					temp1 = NULL;
		    					return;
		    				}
		    				else
		    				{
		    					delete temp->right->right;
		    					temp->right->right = NULL;
		    					return;
		    				}
		    			}
		    			else
		    			{
		    				temp1 = temp->right->right;
		    				while(temp1->left->left !=  NULL)
		    				{
		    					temp1 = temp1->left;
		    				}
		    				swap(temp1->left->info, temp->right->info);
		    				delte(temp1, value);
		    			}
		    		}
	    		}
	    		else
	    			delte(temp->right, value);
	    	}
	    	else
	    	{
	    		cout << "element is not in the list\n";
	    		return;
	    	}
	    }
	    if(value < temp->info)
	    {
	    	if (temp->left != NULL)
	    	{
		    	if(temp->left->info == value)
		    	{
		    		if(temp->left->right == NULL and temp->left->left == NULL)
		    		{
		    			delete temp->left;
		    			temp->left = NULL;
		    			return;
		    		}
		    		if(temp->left->right != NULL and temp->left->left == NULL)
		    		{
		    			temp1 = temp->left;
		    			temp->left = temp->left->right;
		    			delete temp1;
		    			temp1 = NULL;
		    			return;
		    		}
		    		if(temp->left->right == NULL and temp->left->left != NULL)
		    		{
		    			temp1 = temp->left;
		    			temp->left = temp->left->left;
		    			delete temp1;
		    			temp1 = NULL;
		    			return;
		    		}
		    		if(temp->left->right != NULL and temp->left->left != NULL)
		    		{
		    			if(temp->left->left->right == NULL)
		    			{
		    				swap(temp->left->info, temp->left->left->info);
		    				if(temp->left->left->left != NULL)		    					
		    				{
		    					temp1 = temp->left->left;
		    					temp->left->left = temp->left->left->left;
		    					delete temp1;
		    					temp1 = NULL;
		    					return;
		    				}
		    				else
		    				{
		    					delete temp->left->left;
		    					temp->left->left = NULL;
		    					return;
		    				}
		    			}
		    			else
		    			{
		    				temp1 = temp->left->left;
		    				while(temp1->right->right !=  NULL)
		    				{
		    					temp1 = temp1->right;
		    				}
		    				swap(temp1->right->info, temp->left->info);
		    				delte(temp1, value);
		    			}
		    		}

	    		}
	    		else
	    			delte(temp->left, value);
	    	}
	    	else
	    	{
	    		cout << "element is not in the list\n";
	    		return;
	    	}
	    }
    }

//............................................................................
//............................................................................

    void findMin()
    {
        temp = root;
        if(root == NULL)
        {
            cout << "---TREE is empty---" << endl;
            return;
        }

        while(temp->left != NULL)
        {
            temp = temp->left;
        }
        cout << "Minimum node: " << temp->info << endl;    
    }

    void findMax()
    {
        temp = root;
        if(root == NULL)
        {
            cout << "---TREE is empty---" << endl;
            return;
        }

        while(temp->right != NULL)
        {
            temp = temp->right;
        }
        cout << "Maximum node: " << temp->info << endl;
    }
//..............................................................
//.............................FIND HEIGHT.....................

    int findHeight(node *temp)
    {
        if(temp == NULL)
        {
            return 0;
        }

        return max(findHeight(temp->left),findHeight(temp->right)) + 1;

        
    }

};

int main()
{
    BST B;
    int delNode, option;

    do
    {
        cout << endl;
        cout << "WELCOME TO Binary Search Tree" << endl;
        cout << "1- Insert" << endl;
        cout << "2- InOrder" << endl;
        cout << "3- PreOrder" << endl;
        cout << "4- PostOrder" << endl;
        cout << "5- Delete Node" << endl;
        cout << "6- Find Minimum" << endl;
        cout << "7- Find Maximum" << endl;
        cout << "8- Find Height " << endl;
        cout << "9- EXIT Function" << endl;
        cout << "ENTER OPTION: ";

        cin >> option;
        switch(option)
        {
            case 1:
                cout << "Enter node: ";
                cin >> B.key;
                B.insert(B.key,B.root);
                break;

            case 2:
                B.InOrder(B.root);
                cout << endl;
                break;

            case 3:
                B.PreOrder(B.root);
                cout << endl;
                break;

            case 4:
                B.PostOrder(B.root);
                cout << endl;
                break;

            case 5:
                cout << "Enter node to delete: ";
                cin >> delNode;
                B.delte(B.root,delNode);
                break;

            case 6:
                B.findMin();
                break;

            case 7:
                B.findMax();
                break;
            
            case 8:
                cout << "Height of BST: " << B.findHeight(B.root) - 1 << endl;
                break;
            
            case 9:
                exit(1);
        }
    }
    while(option != 999);
    

}