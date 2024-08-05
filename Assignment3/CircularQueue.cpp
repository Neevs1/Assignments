#include <iostream>
using namespace std;

void enqueue(string[],int,int,int);
void dequeue(string[],int,int,int);
string isFull(int,int);

int main(){
    int length,front=0,rear=0;
    cout<<"Enter length of queue\n";
    cin>>length;
    string queue[length];
    enqueue(queue,length,front,rear);
    

    return 0;
}

void enqueue(string queue[],int length,int front,int rear){
    if (rear==length-1){
        cout<<"Queue is full"<<endl;
    }else{
       
        string element;
        cout<<"Enter element"<<endl;
        cin>>element;
        queue[rear]=element;
        cout<<"Queue is now \n";
        for(int i=front;i<=rear;i++){
            cout<<element<<" ";
        }
        rear++;
    }
    
}