

#include <iostream>
using namespace std;

typedef struct Node
{
  int data;
  Node *right;
  Node *left;
  int height;
}

node;
node *
ne (int dat)
{
  node *n = new node ();
  n->data = dat;
  n->right = NULL;
  n->left = NULL;
  n->height = 0;
}

node *
findinorder (node * root)
{
  while (root->left != NULL)
    {
      root = root->left;
    }

  return root;
}

int
getheight (node * left, node * right)
{
  int a, b;
  if (left == NULL && right != NULL)
    {
      return right->height;
    }
  else if (right == NULL && left != NULL)
    {
      return left->height;
    }
  else if (right == NULL && left == NULL)
    {
      return -1;
    }
  else
    {
      if (right->height > left->height)
	return right->height;
      else if (right->height < left->height)
	return left->height;
      else
	return left->height;
    }
}

int
balancefactor (node * lef, node * righ)
{
  int a, b;
  if (lef == NULL)
    a = -1;
  else
    a = 1 + getheight (lef->left, lef->right);
  if (righ == NULL)
    b = -1;
  else
    b = 1 + getheight (righ->left, righ->right);
  return (a - b);
}

node *rightrotate (int dat, node * nod);
node *
leftrotate (int dat, node * nod)
{
  cout << nod;
  node *z = nod->right;
  if (dat < z->data)
    {
      nod->right = rightrotate (dat, nod->right);
    }
  else
    {
      node *x = nod->right;
      node *y = x->left;
      nod->right = y;
      x->left = nod;
      nod->height = 1 + getheight (nod->left, nod->right);
      return x;






    }
}

node *
rightrotate (int dat, node * nod)
{
  cout << nod;
  node *z = nod->left;
  if (z->data < dat)
    {

      nod->left = leftrotate (dat, nod->left);

    }
  {
    node *x = nod->left;
    node *y = x->right;
    nod->left = y;
    x->right = nod;
    nod->height = 1 + getheight (nod->left, nod->right);
    return x;
  }
}

node *
insert (node * root, int dat)
{
  if (root == NULL)
    {
      return ne (dat);
    }
  else if (root->data > dat)
    {
      root->left = insert (root->left, dat);
    }
  else
    {
      root->right = insert (root->right, dat);
    }

  root->height = 1 + getheight (root->left, root->right);
  int balance = balancefactor (root->left, root->right);
  if (balance > 1)
    {
      root = rightrotate (dat, root);
    }
  else if (balance < -1)
    {
      root = leftrotate (dat, root);

    }

  return root;

}

void
traverse (node * root)
{
  if (root == NULL)
    {
      return;
    }
  else
    {
      traverse (root->left);
      cout << root->data << " " << root->height << "\n";
      traverse (root->right);
    }
}

node *dele (node * root);
node *
de (node * root, int dat)
{
  if (root == NULL)
    {
      return NULL;
    }
  else if (root->data > dat)
    {
      root->left = de (root->left, dat);
      root->height = 1 + getheight (root->left, root->right);
    }
  else if (root->data < dat)
    {
      root->right = de (root->right, dat);
      root->height = 1 + getheight (root->left, root->right);
    }
  else
    {
      return dele (root);
    }

  return root;
}

node *
dele (node * root)
{
  if (root->left == NULL && root->right == NULL)
    {
      return NULL;
    }
  else if (root->left == NULL && root->right != NULL)
    {
      node *n = root->right;
      root->data = n->data;
      root->right = NULL;
      root->height = 1 + getheight (root->left, root->right);
      return root;
    }
  else if (root->left != NULL && root->right == NULL)
    {
      node *n = root->left;
      root->data = n->data;
      root->left = NULL;
      root->height = 1 + getheight (root->left, root->right);
      return root;
    }
  else
    {
      node *n = root->right;
      n = findinorder (n);
      root->data = n->data;
      root->right = de (root->right, n->data);
      root->height = 1 + getheight (root->left, root->right);
      return root;
    }
}

int
main ()
{
  int choice, data;
  node *root = NULL;
  do
    {
      cout << "enter 1 for insertion 2 for traversal 3 for deletion \n";
      cin >> choice;
      switch (choice)
	{
	case 1:
	  cout << "enter the data \n";
	  cin >> data;
	  root = insert (root, data);
	  break;
	case 2:
	  traverse (root);
	  break;
	case 3:
	  cout << "enter data to delete \n";
	  cin >> data;
	  root = de (root, data);
	  break;
	default:
	  cout << "wrong choice \n";
	  break;
	};

    }
  while (1);
  return 0;
}
