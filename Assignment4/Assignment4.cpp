#include <iostream>
#include <cctype>
using namespace std;

struct node{
  char data;
  node* next;
  node* left;
  node* right;
};

node* createNode(char input){
    node* node = (struct node*)malloc(sizeof(struct node));
    node->data = input;
}

int main(){
    


    return 0;
}

