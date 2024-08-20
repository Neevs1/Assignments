/*
 Name - Neevan Redkar
 Class - SE
 Batch S3
 Roll no 3069
*/
#include <iostream>
#include <cctype>
using namespace std;



struct node{ //defined struct
  string data;
  struct node *next;
};

node* createNode(string input){
  node* new_node = (node*)malloc(sizeof(node));
  new_node->data = input;
  new_node->next = NULL;
  return new_node;    
}

struct Stack{
      node* head;
};



string in2post(Stack*);
void in2pre();
void evalPost();
void evalPre();

int main(){
  Stack stack;
  cout<<"Enter choice of operation\n1.Infix to postfix\n2.Infix to Prefix";
  cout<<"\n3.Evaluate postfix\n4.Evaluate prefix";
  int choice;
  cin>>choice;
  switch(choice){
    case 1:
    cout<<in2post(&stack);
    break;
    default:
    cout<<"Option not yet available/invalid input";    

  }  

    return 0;
}

void push(Stack* stack,string input){
  node *new_node = createNode(input);
  new_node->next=stack->head;
  stack->head= new_node;
}



string in2post(Stack* stack){
  string input;
  string stop,exp;
  bool isNum;
  do{
    cout<<"Enter element";
    cin>>input;
    for(int i=0;i<input.length();i++){
      if (isdigit(input[i])==false){
        isNum = false;
      }else{
        isNum = true;
      }
    }
    if(isNum==true){
      exp.append(input);
      exp.append(" ");
    }else if(input=="+"||input=="-"||input=="*"||input=="/"){
      push(stack,input);
    }else{
      cout<<"Invalid input";
    }
    cout<<"\nDo you wish to continue?(type 'yes' case sensitive to continue)";
    cin>>stop;
  }while(stop == "yes");
  if(stack->head->data.empty()==false){
  exp.append(stack->head->data);}
  return exp;

}