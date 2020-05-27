#include<iostream>
#include<conio.h>

using namespace std;


struct bstnode //Creating A Binary Search Tree
{
	int data;
	bstnode *left; 
	bstnode *right;
};

bstnode *FindMin(bstnode *root);

bstnode *GetnewNode(int data)
{
	bstnode* temp = new bstnode;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}


bstnode *Insert(bstnode *root, int data)
{
	bstnode *newnode = GetnewNode(data);
	bstnode *x = root;
	bstnode *y = NULL;

	while (x != NULL)
	{
		y = x;
		if (data < x->data)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	if (y == NULL)
	{
		y = newnode;
	}
	else if (data < y->data)
	{
		y->left = newnode;
	}
	else
	{
		y->right = newnode;
	}
	return y;
}
bstnode *Delete(bstnode *&root, int data)
{
	if (root == NULL)
	{
		return root;
	}
	else if (data < root->data)
	{
		root->left=Delete(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = Delete(root->right, data);
	}
	else
	{
		//Case 1:-No Child Root
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
			cout << "Deleted Node Is:- " << data << endl;
			
		}
		//Case 2:-One Left Child Is NULL
		else
			if (root->left == NULL)
			{
				bstnode *ptr = root;
				root = root->right;
				delete ptr;
				cout << "Deleted Node Is:- " << data << endl;
			}
			else
				if (root->right == NULL)
				{
					bstnode *ptr = root;
					root = root->left;
					delete ptr;
					cout << "Deleted Node Is:- " << data << endl;
				
				}
		// Case:-3 Two Children
				else
				{
					bstnode *temp = FindMin(root->right);
					root->data = temp->data;
					root->right = Delete(root->right, temp->data);
				}

	}
	return root;

}
bstnode* FindMin(bstnode *root)
{
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root;
}

void Inorder(bstnode *root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		Inorder(root->left);
		cout << root->data << " ";
		Inorder(root->right);
		
	}
}
void Postorder(bstnode *root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		Postorder(root->left);
		Postorder(root->right);
		cout << root->data << " ";
	}
}
void Preorder(bstnode *root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		cout << root->data << " ";
		Preorder(root->left);
		Preorder(root->right);
	}
}
void Update(bstnode *&root, int data)
{
	bstnode *temp, *temp1, *temp2, *temp3;
	temp = root;
	while (temp != NULL)
	{
		if (temp->data == data)
		{
			cout << "New Node Already Exists!" << endl;
			return;
		}
		else
			if (data > temp->data)
			{
				temp = temp->right;
			}
			else if (data < temp->data)
			{
				temp = temp->left;
			}
				
	}
	temp = root;
	while (temp != NULL)
	{
		if (temp->data == data)
		{

		}
	}

}




int main()
{
	bstnode *root = NULL;//creating an empty tree
	int data;
	root = Insert(root, 15);	
	Insert(root, 13);
	Insert(root, 12);
	Insert(root, 14);
	Insert(root, 17);
	Insert(root, 16);
	Insert(root, 18);
	
	Delete(root, 14);
	cout << endl;

	cout << "Inorder Traversal Of Binary Tree:- " << endl;
	Inorder(root);
	cout << endl;
	cout << "Postorder Traversal Of Binary Tree:- " << endl;
	Postorder(root);
	cout << endl;
	cout << "Preorder Traversal Of Binary Tree:- " << endl;
	Preorder(root);
	
	
	_getch();
	return 0;
}
/*
Follow me on my github ID https://github.com/Junaid-byte
Credits:-Junaid Jawed
*/


