#include <iostream>

using namespace std;
typedef struct Node
{
  int data;
  Node *right;
  Node *left;

} node;
node *root = NULL;
node *
findorder (node * temp)
{
  node *current = temp;
  while (current == NULL && current->left == NULL)
    {
      current = current->left;
    }
  return current;
}



node *
dele (node * temp, int dat)
{
  if (temp == NULL)
    {

      return NULL;
    }
  else if (dat > temp->data)
    {
      temp->left = dele (temp->left, dat);
    }
  else if (dat < temp->data)
    {
      temp->right = dele (temp->right, dat);
    }
  else
    {


      if (temp->left == NULL && temp->right == NULL)
	{
	  delete temp;
	  return NULL;
	}
      else if (temp->left == NULL && temp->right != NULL)
	{
	  node *r = temp->right;
	  temp->data = r->data;
	  temp->left = NULL;
	  temp->right = r->right;
	  delete r;


	}
      else if (temp->left != NULL && temp->right == NULL)
	{
	  node *r = temp->left;
	  temp->data = r->data;
	  temp->left = r->left;
	  temp->right = NULL;
	  delete r;

	}
      else
	{
	  node *r = findorder (temp->right);
	  temp->data = r->data;
	  dele (temp->right, r->data);
	}
    }

  return temp;



}

void
insert (node * temp, int dat)
{
  node *ne = new node;
  ne->data = dat;
  ne->left = NULL;
  ne->right = NULL;
  if (root == NULL)
    {
      root = ne;
    }
  else
    {
      node *current = root;
      node *parent = NULL;
      while (1)
	{
	  parent = current;
	  if (dat < current->data)
	    {
	      current = current->right;
	      if (current == NULL)
		{
		  parent->right = ne;
		  break;
		}
	    }
	  else if (dat > current->data)
	    {
	      current = current->left;
	      if (current == NULL)
		{
		  parent->left = ne;
		  break;
		}
	    }
	  else
	    {
	      delete ne;
	      break;
	    }
	}
    }

}

void
inorder (node * temp)
{
  if (temp == NULL)
    {
      return;
    }
  else
    {
      inorder (temp->left);
      cout << temp->data << "\n";
      inorder (temp->right);
    }
}

int
main ()
{
  int choice, data;
  do
    {
      cout << "enter 1 for insertion 2 for traversal 3 for deletion";
      cin >> choice;
      switch (choice)
	{
	case 1:
	  cout << "enter the value";
	  cin >> data;
	  insert (root, data);
	  break;
	case 2:
	  inorder (root);
	  break;
	case 3:
	  cout << "enter data to read";
	  cin >> data;
	  root = dele (root, data);
	  break;
	default:
	  cout << "wrong choice \n";
	  break;
	};
    }
  while (1);

  return 0;
}
