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
    case 1:
    cout<<in2post();

    

  }  

    return 0;
}

string in2post(){
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
    }
    if(input=="+"||input=="-"||input=="*"||input=="/"){
      createNode(input);
    }
    

  }while(stop != "yes");
  return exp;

}