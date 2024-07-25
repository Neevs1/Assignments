#include <iostream>
using namespace std;

struct Student{
    int rollNum;
    string name;
    float sgpa;
};

void bsort(struct Student[],int);
void inSort(struct Student[],int);
void qSort(struct Student[],int,int);
int partition(struct Student[],int,int);
void gpasearch(struct Student[],int);

int main(){
    struct Student se_it[15]={{15,"X",8.77},{12,"P",9.54},{13,"Q",6.22},{14,"W",7.55},{5,"E",9.23},
    {6,"R",5.40},{10,"T",8.77},{8,"Y",5.68},{7,"U",9.18},{9,"I",7.89},
    {11,"O",8.90},{1,"A",7.25},{3,"S",8.04},{4,"D",7.79},{2,"F",9.33}};
    int length = sizeof(se_it)/sizeof(se_it[0]);
    

    bsort(se_it,length-1);
    cout<<endl;
    inSort(se_it,length-1);
    cout<<endl;
    qSort(se_it,0,length-1);
    cout<<"10 toppers in classroom are"<<endl;
    for(int i=14;i>4;i--){
        cout<<se_it[i].rollNum<<" "<<se_it[i].name<<" "<<se_it[i].sgpa<<endl;
        
    }
    cout<<endl;
    gpasearch(se_it,length);

    return 0;
}

void bsort(Student  arr[],int length){
    int temp;
    string tmp;
    float t;
   for(int i =0;i<length;i++){
        for(int j=0;j<length;j++){
            if(arr[j].rollNum>arr[j+1].rollNum){
                swap(arr[j+1],arr[j]);              
            }

        }
    }
    cout<<"List sorted by roll number is"<<endl;
    for(int i=0;i<length+1;i++){
        cout<<arr[i].rollNum<<" "<<arr[i].name<<" "<<arr[i].sgpa;
        cout<<"\n";
    }
}



void inSort(struct Student arr[],int length)
{
    int j;
    for(int i=1;i<length+1;i++){
        Student key=arr[i];
        j=i-1;
        while(j>=0){
            if(arr[j].name<key.name){
                break;
            }else{
                arr[j+1].name=arr[j].name;
                arr[j].name=key.name;
                arr[j+1].rollNum=arr[j].rollNum;
                arr[j].rollNum=key.rollNum;
                arr[j+1].sgpa=arr[j].sgpa;
                arr[j].sgpa=key.sgpa;
                j--;
            }
        }
            
    }
    std::cout<<"Sorted alphabetically"<<endl;
    for(int i =0;i<15;i++){
        
        std::cout<<arr[i].rollNum<<" "<<arr[i].name<<" "<<arr[i].sgpa;
        std::cout<<endl;
    }
}


int partition(Student arr[],int low,int high){
    float pivot = arr[high].sgpa;
    int i = low-1;
    for(int j = low;j<high;j++){
        if(arr[j].sgpa<=pivot){
            i++;
            swap(arr[i],arr[j]);
            
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}

void qSort(struct Student arr[],int low,int high){
    if (low < high) {
    
    int pi = partition(arr, low, high);
    qSort(arr, low, pi - 1);
    qSort(arr, pi + 1, high);
  }
}

void gpasearch(Student arr[],int length){
    float target;
    int counter=-1;
    cout<<"Enter CGPA of student to be found ";
    cin>>target;
    for(int i=0;i<length;i++){
        if(target==arr[i].sgpa){
            cout<<"Student having CGPA "<<target<<" is "<<arr[i].name<<" and their roll no is "<<arr[i].rollNum<<endl;
            counter++;
        }
    }
    if(counter<0){
        cout<<"No student having CGPA "<<target<<" found"<<endl;
    }

}