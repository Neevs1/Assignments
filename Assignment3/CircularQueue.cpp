#include <iostream>
using namespace std;

int enqueue(string[],int,int,int);
int dequeue(string[],int,int,int);
string isFull(int,int,int);

int main(){
    int length,front,rear;
    cout<<"Enter length of queue\n";
    cin>>length;
    string queue[length],repeat="";
    front=-1;
    rear=-1;
    do{
        cout<<"Enter operation of choice\n1.Enqueue\n2.Dequeue\n3.Check if full"<<endl;
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
            rear = enqueue(queue,length,front,rear);
            if(front==-1&&rear!=-1){
                front=0;
            }
            break;
            case 2:
            front=dequeue(queue,front,rear,length);
            if(front==-1&&rear!=-1){
                rear=-1;
            }
            break;
            case 3:
            cout<<isFull(front,rear,length)<<endl;
            break;
            default:
            cout<<"Invalid operation"<<endl;
        }
        cout<<"Do you wish to continue (yes/no)(case sensitive)"<<endl;
        cin>>repeat;        
    }while(repeat == "yes");
    

    return 0;
}

int enqueue(string queue[],int length,int front,int rear){
    
    if (rear!=-1&&(rear+1)%length==front){
        cout<<"Queue is full"<<endl;
        for(int i=front;i<=rear;i++){
            cout<<queue[i]<<" ";
        }
        cout<<endl;
        return rear;
    }else if(rear==-1&&front==-1){
        rear=0;front=0;
        string element;
        cout<<"Enter element"<<endl;
        cin>>element;
        //cout<<rear;
        queue[rear]=element;
        cout<<"Queue is now \n";
        for(int i=front;i<=rear;i++){
            cout<<queue[i]<<" ";
        }
        cout<<"\n";
        return rear;
        
    }else{
        
        string element;
        cout<<"Enter element"<<endl;
        cin>>element;
        rear=(rear+1)%length;        
        queue[rear]=element;
        cout<<"Queue is now \n";
        for(int i=front;i<=rear;i++){
            cout<<queue[i]<<" ";
       }
       cout<<endl;
     return rear;
    }
    
}

int dequeue(string queue[],int front,int rear,int length){
    if(rear==-1){
        cout<<"Queue is empty"<<endl;
        return front;
    }else if(rear==0 && front==0){
        cout<<"Dequeued element is "<<queue[0];
        cout<<"\nQueue is now empty"<<endl;
        front--;
        return front;        
    }else{
        cout<<"Dequeued element is "<<queue[front]<<endl;
        front=(front+1)%length;
        cout<<"Queue is now \n";
        for(int i=front;i<=rear;i++){
            cout<<queue[i]<<" ";
        }
        cout<<endl;
        return front;
    }

}

string isFull(int front,int rear,int length){
    if (rear!=-1&&(rear+1)%length==front){
        return "Queue is full";
    }else{
        return "Queue not full";
    }
    
}