#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(node* Node,int data){
    if(Node == NULL){
        return createNode(data);
    }
    if(data < Node->data){
        Node->left = insert(Node->left,data);
        cout<<"Inserted "<<data<<" to the left of "<<Node->data<<endl;
    }else if(data > Node->data){    
        Node->right = insert(Node->right,data);
        cout<<"Inserted "<<data<<" to the right of "<<Node->data<<endl;
    }else if(data==Node->data){
        cout<<"Value already present"<<endl;
        return Node;
    }
    return Node;    
}

void inorder(node* Node){
    if(Node == NULL){
        return;
    }
    inorder(Node->left);
    cout<<Node->data<<" ";
    inorder(Node->right);
}

int main(){
      cout<<"Enter data for root node: "<<endl;
      int data;
      cin>>data;
      string choice;
      struct node* root = createNode(data);
      do{
          cout<<"Enter data for new node: "<<endl;
          cin>>data;
          insert(root,data); 
          cout<<"Do you want to enter more data? (yes/no)"<<endl;
        cin>>choice;
      }while(choice == "yes");

      inorder(root);



    return 0;
}