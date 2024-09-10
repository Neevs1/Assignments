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



void inorder(struct node*);


int main(){
   int choice;
   string input;
   cout<<"Enter whether input is prefix or postfix \n 1. Type 1 for Postfix \n 2. Type 2 for prefix\n";
   cin>>choice;
   cout<<"Enter input string"<<endl;
   cin>>input;
   node* tree;
   switch(choice){
    case 1:
    tree = buildtree(input);
    break;
    case 2:
    reverse(input.begin(),input.end());
    tree = buildtree(input);
    break;
    default:
    cout<<"Invalid input"<<endl;
    

   }
   
  cout<<"\nInorder is\n";
  inorder(tree);
  cout<<endl;


    return 0;
}

void inorder(struct node* root) {
    if (root) {
        inorder(root->left);
        cout<<(root->data);
        inorder(root->right);
    }
    
}

