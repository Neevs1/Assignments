#include <iostream>
using namespace std;

void enqueue(string[],int,int,int);
void dequeue(string[],int,int,int);
string isFull(int,int);

int main(){
    int length,front=0,rear=0;
    cout<<"Enter length of queue\n";
    cin>>length;
    string queue[length],repeat;
    //
    do{
        cout<<"Enter operation of choice\n1.Enqueue\n2.Dequeue\n3.Check if full"<<endl;
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
            enqueue(queue,length,front,rear);
            rear++;
            break;
            case 2:
            cout<<"In development sorry"<<endl;
            break;
            case 3:
            cout<<"In development sorry"<<endl;
            break;
            default:
            cout<<"Invalid operation"<<endl;
        }
        cout<<"Do you wish to continue (yes/no)(case sensitive)"<<endl;
        cin>>repeat;        
    }while(repeat == "yes");
    

    return 0;
}

void enqueue(string queue[],int length,int front,int rear){
    if (rear!=-1&&(rear+1)%length==front){
        cout<<"Queue is full"<<endl;
    }else if(rear==-1&&front==-1){
        rear=0;front=0;
        string element;
        cout<<"Enter element"<<endl;
        cin>>element;
        //rear=(rear+1)%length;
        queue[rear]=element;
        cout<<"Queue is now \n";
        for(int i=front;i<=rear;i++){
            cout<<queue[i]<<" ";
        }
        
    }else{
        string element;
        cout<<"Enter element"<<endl;
        cin>>element;
        //rear=(rear+1)%length;
        queue[rear]=element;
        cout<<"Queue is now \n";
        for(int i=front;i<=rear;i++){
            cout<<queue[i]<<" ";
    }
    }
    
}