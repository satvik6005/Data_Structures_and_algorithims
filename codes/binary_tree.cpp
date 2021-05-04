#include <iostream>

using namespace std;
typedef struct Node
{
  int data;
  Node *left;
  Node *right;
} node;

node *root = NULL;
int top = -1, start = -1;

node *que[50];
int
isempty ()
{
  if (start == -1 && top == -1)
    {
      return 1;
    }
  else
    return 0;
}

int
isfull ()
{
  if (top == 49)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

void
enque (node * ne)		/*ne is adding node */
{
  if (isempty () == 1)
    {
      start = 0;
      top = 0;
      que[top] = ne;


    }
  else if (isfull () == 1)
    {
      cout << "memory is overflow";
    }
  else
    {
      top++;
      que[top] = ne;
    }
}

void
deque ()
{
  if (isempty () == 1)
    {
      cout << "underflow";
    }
  else if (start == top)
    {
      start = -1;
      top = -1;
    }
  else
    {

      start++;
    }
}



void
add (int info)
{
  node *ne = new node;
  ne->left = NULL;
  ne->right = NULL;
  ne->data = info;
  if (root == NULL)
    {
      root = ne;

    }
  else
    {
      enque (root);
      node *temp = NULL;


      while (isfull () != 1)
	{

	  temp = que[start];
	  deque ();
	  if (temp->left == NULL)
	    {
	      temp->left = ne;
	      break;
	    }
	  else
	    enque (temp->left);
	  if (temp->right == NULL)
	    {
	      temp->right = ne;
	      break;
	    }
	  else
	    enque (temp->right);


	}
    }
}


void
inorder (node * nod)
{
  if (nod == NULL)
    {
      return;
    }
  else
    {
      inorder (nod->left);
      cout << nod->data;
      inorder (nod->right);
    }

}

int
main ()
{
  int choice, k = 1, val;

  do
    {
      cout << "press 1 for addition press 2 for traversing\n";
      cin >> choice;
      switch (choice)
	{
	case 1:
	  cout << "enter the value\n";
	  cin >> val;
	  add (val);
	  break;
	case 2:
	  inorder (root);
	  break;
	default:
	  cout << "wrong choice \n";
	  break;

	};
    }
  while (k == 1);

  return 0;
}
