#include <iostream>
#include <cstdlib>
#define MAX_VALUE 65536
using namespace std;


struct N {   //node declaration
    int k;
   N *l, *r;
   bool leftTh, rightTh;
};

//global root
N *root;
 
  //creating the inorder threaded BT
void insert(int key)
{
N *ptr = NULL;
   if(root==NULL)
   {
  	 root= new N();
 		 root->r= root->l= root;
 		 root->leftTh = true;
 		 root->k = MAX_VALUE;
   }
   /*else
   {
  	 ptr= new N();
 		 ptr->r= root->l= root;
 		 ptr->leftTh = true;
 		 ptr->k = MAX_VALUE;
   }*/
  	N *p = root;
  	for (;;) {
     	if (p->k< key) { //move to right thread
        	if (p->rightTh)
           	break;
        	p = p->r;
     	} else if (p->k > key) { // move to left thread
        	if (p->leftTh)
           	break;
        	p = p->l;
     	} else {
        	return;
     	}
  	}
  	N *temp = new N();
  	temp->k = key;
  	temp->rightTh= temp->leftTh= true;
  	if (p->k < key) {
     	temp->r = p->r;
     	temp->l= p;
     	p->r = temp;
     	p->rightTh= false;
  	} else {
     	temp->r = p;
     	temp->l = p->l;
     	p->l = temp;
     	p->leftTh = false;
  	}
   }
   

void displayTree() { //print the tree
   N *temp = root, *p;
   for (;;) {
  	p = temp;
  	temp = temp->r;
  	if (!p->rightTh) {
     	while (!temp->leftTh) {
        	temp = temp->l;
     	}
  	}
  	if (temp == root)
     	break;
  	cout<<temp->k<<" ";
   }
   cout<<endl;
}

int main() {
   
   cout<<"Inorder ThreadedBinaryTree\n";
   char ch;
   int c, v;  
   while(1) {
  	cout<<"1. Insert "<<endl;
  	cout<<"2. Inorder Traversal"<<endl;
    cout<<"3. Preorder Traversal"<<endl;
  	cout<<"6. Exit"<<endl;
  	cout<<"Enter Your Choice: ";
  	cin>>c;
  	//perform switch operation
  	switch (c) {
     	case 1 :
        	cout<<"Enter integer element to insert: ";
        	cin>>v;
        	insert(v);
        	break;
     	case 2:
        	cout<<"In-order Display tree: \n ";
        	displayTree();
        	break;
     	case 6:
        	exit(1);
     	default:
        	cout<<"\nInvalid type! \n";
  	}
   }
   cout<<"\n";
   return 0;
}
