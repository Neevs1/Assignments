#include <iostream>
using namespace std;

struct Student{
    int rollNum;
    string name;
    float sgpa;
};

void bsort(struct Student[]);

int main(){
    struct Student se_it[15]={{15,"X",8.77},{12,"P",9.54},{13,"Q",6.22},{14,"W",7.55},{5,"E",9.23},
    {6,"R",5.40},{10,"T",8.77},{8,"Y",5.68},{7,"U",9.18},{9,"I",7.89},
    {11,"O",8.90},{1,"A",7.25},{3,"S",8.04},{4,"D",7.79},{2,"F",9.33}};

    bsort(se_it);

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
        cout<<arr[i].rollNum<<" "<<arr[i].name<<" "<<arr[i].sgpa<<"\n";
    }
}