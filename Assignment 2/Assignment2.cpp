/*
 Name - Neevan Redkar
 Class - SE
 Batch S3
 Roll no 3069
*/
#include <iostream>
using namespace std;



struct node{ //defined struct
  string data;
  struct node *next;
};

node* createNode(struct node** head,int input){
  node* new_node = (node*)malloc(sizeof(node));
  new_node->data = input;
  new_node->next = NULL;
  return new_node;    
}

string in2post();
void in2pre();
void evalPost();
void evalPre();

int main(){
  cout<<"Enter choice of operation\n1.Infix to postfix\n2.Infix to Prefix";
  cout<<"\n3.Evaluate postfix\n4.Evaluate prefix";
  int choice;
  cin>>choice;
  switch(choice){

  }  

    return 0;
}

string in2post(){
  string input;
  string stop,exp;
  do{
    cout<<"Enter element";
    
    

  }while(stop != "yes");

}