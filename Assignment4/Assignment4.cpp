#include <iostream>
#include <cctype>
#include <algorithm>
#include <stack>
using namespace std;

struct node{
 char data;
 
  node* left;
  node* right;
};



node* createNode(char input){
    node* node = (struct node*)malloc(sizeof(struct node));
    node->data = input;
    node->left = NULL;
    node->right=NULL;
   
    return node;
}

node* buildtree(string input){
  stack<node*> stack;
  for(int i=0;i<input.length();i++){
    if(isdigit(input[i])||isalpha(input[i])){
      node* new_node = createNode(input[i]);
      stack.push(new_node);
    }else if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'){
      struct node* new_node =createNode(input[i]);
      new_node->left=(stack.top());
      stack.pop();
      new_node->right= (stack.top());
      stack.pop();
      stack.push(new_node);

    }

  }
  return stack.top();  
  
}

void inorder(struct node* root) {
    if (root) {
        inorder(root->left);
        cout<<(root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root){
  if(root){
    cout<<(root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(struct node* root){
  if(root){
    postorder(root->left);
    postorder(root->right);
    cout<<(root->data);
  }
}

int main(){
   string input;
   cout<<"Enter input \n";
   cin>>input;
   node* tree = buildtree(input);
   inorder(tree);
   


    return 0;
}

