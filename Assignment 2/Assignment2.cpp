/*
 Name - Neevan Redkar
 Class - SE
 Batch S3
 Roll no 3069
*/
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;



struct node{ //defined struct
  char data;
  struct node *next;
};

node* createNode(char input){
  node* new_node = (node*)malloc(sizeof(node));
  new_node->data = input;
  new_node->next = NULL;
  return new_node;    
}

struct Stack{
      node* head;
};



string in2post(Stack*);
string in2pre(Stack*);
void evalPost();
void evalPre();

int main(){
  Stack stack;
  cout<<"Enter choice of operation\n1.Infix to postfix\n2.Infix to Prefix";
  cout<<"\n3.Evaluate postfix\n4.Evaluate prefix"<<endl;
  int choice;
  cin>>choice;
  switch(choice){
    case 1:
    cout<<in2post(&stack);
    break;
    case 2:
    cout<<in2pre(&stack);
    break;
    default:
    cout<<"Option not yet available/invalid input";    

  }  

    return 0;
}

void push(Stack* stack,char input){
  node *new_node = createNode(input);
  new_node->next=stack->head;
  stack->head= new_node;
}

char pop(Stack* stack){
  char t = stack->head->data;
  node* temp = stack->head;
  stack->head = (stack->head)->next;
  free(temp);
  return t;
}


string in2post(Stack* stack){
  string input;
  cout<<"Enter infix expression"<<endl;
  cin>>input;
  string exp="";
  int counter=0;
  
  
  for(int i=0;i<input.length();i++){
    if(isdigit(input[i])||isalpha(input[i])){
      exp.append(1,input[i]);
      //cout<<input[i];
    }else if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'){
      exp+=' ';
      if((stack->head->data=='*'||stack->head->data=='/')&&(input[i]=='+'||input[i]=='-')){
       while(counter>0){
        if(stack!=NULL){
          exp.push_back(pop(stack));
          counter--;
        }
       }
       push(stack,input[i]);
       counter++;
      }else{
        push(stack,input[i]);
        counter++;
      }
    }
  }
  if(stack!=NULL){
    exp+=stack->head->data;
  }
  return exp;

}

string in2pre(Stack* stack){
  string input;
  cout<<"Enter infix expression"<<endl;
  cin>>input;
  reverse(input.begin(),input.end());
  string exp="";
  int counter=0;
  
  
  for(int i=0;i<input.length();i++){
    if(isdigit(input[i])||isalpha(input[i])){
      exp.append(1,input[i]);
      //cout<<input[i];
    }else if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'){
      exp+=' ';
      if((stack->head->data=='*'||stack->head->data=='/')&&(input[i]=='+'||input[i]=='-')){
       while(counter>0){
        if(stack!=NULL){
          exp.push_back(pop(stack));
          counter--;
        }
       }
       push(stack,input[i]);
       counter++;
      }else{
        push(stack,input[i]);
        counter++;
      }
    }
  }
  if(stack!=NULL){
    exp+=stack->head->data;
  }
  reverse(exp.begin(),exp.end());
  return exp;

  

}