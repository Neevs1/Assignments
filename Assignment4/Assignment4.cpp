#include <iostream>
#include <cctype>
using namespace std;

struct node{
  char data;
  node* next;
  node* left;
  node* right;
};

node* head=NULL;

node* createNode(char input){
    node* node = (struct node*)malloc(sizeof(struct node));
    node->data = input;
    node->left = NULL;
    node->right=NULL;
    node->next=NULL;
    return node;
}

void push(struct node*){

}

int main(){
   string input;
   cout<<"Enter input \n";
   cin>>input;


    return 0;
}

