#include <iostream>
using namespace std;

struct Student{
    int rollNum;
    string name;
    float sgpa;
};

void bsort(struct Student[]);
void inSort(struct Student[]);
void qSort(struct Student[],int,int);
int partition(struct Student[],int,int);

int main(){
    struct Student se_it[15]={{15,"X",8.77},{12,"P",9.54},{13,"Q",6.22},{14,"W",7.55},{5,"E",9.23},
    {6,"R",5.40},{10,"T",8.77},{8,"Y",5.68},{7,"U",9.18},{9,"I",7.89},
    {11,"O",8.90},{1,"A",7.25},{3,"S",8.04},{4,"D",7.79},{2,"F",9.33}};

    bsort(se_it);
    inSort(se_it);

    return 0;
}

void bsort(struct Student arr[]){
   for(int i =0;i<15;i++){
        for(int j=0;j<15;j++){
            if(arr[j].rollNum>arr[j+1].rollNum){
                int temp = arr[j].rollNum;
                arr[j].rollNum = arr[j+1].rollNum;
                arr[j+1].rollNum= temp;
                string tmp = arr[j].name;
                arr[j].name = arr[j+1].name;
                arr[j+1].name= tmp;
                float t = arr[j].sgpa;
                arr[j].sgpa = arr[j+1].sgpa;
                arr[j+1].sgpa= t;
            }
        }
    }
    cout<<"List sorted by roll number is"<<endl;
    for(int i=0;i<15;i++){
        cout<<arr[i].rollNum<<" "<<arr[i].name<<" "<<arr[i].sgpa<<endl;
    }
}

void inSort(struct Student arr[]){
    int j,keyr;
    float keys;
    string key;
    for(int i=1;i<15;i++){
        key=arr[i].name;
        keyr=arr[i].rollNum;
        keys=arr[i].sgpa;
        j=i-1;
        while(j>=0){
            if(arr[j].name<key){
                break;
            }else{
                arr[j+1].name=arr[j].name;
                arr[j].name=key;
                arr[j+1].rollNum=arr[j].rollNum;
                arr[j].rollNum=keyr;
                arr[j+1].sgpa=arr[j].sgpa;
                arr[j].sgpa=keys;
                j--;
            }
        }
            
    }
    cout<<"Sorted alphabetically"<<endl;
    for(int i =0;i<15;i++){
        
        cout<<arr[i].rollNum<<" "<<arr[i].name<<" "<<arr[i].sgpa;
        cout<<endl;
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a =*b;
    *b = temp;
}

int partition(Student arr[],int low,int high){
    float pivot = arr[high].sgpa;
    int i = low-1;
    for(int j = low;j<high;j++){
        if(arr[j].sgpa<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void qSort(struct Student arr[],int low,int high){
    if (low < high) {
    
    int pi = partition(arr, low, high);
    qSort(arr, low, pi - 1);
    qSort(arr, pi + 1, high);
  }
}