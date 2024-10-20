#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

void add_record(){
    fstream file;
    file.open("StudentRecord.txt", ios::app);
    string name, address;
    int roll;
    char division;
    cout << "Enter name: (Use underscore instead of space) ";
    cin >> name;
    for(int i = 0; i < name.length(); i++){
        if(name[i] == '_'){
            name[i] = ' ';
        }
    }
    cout << "Enter address: (Use underscore instead of space) ";
    cin >> address;
    for(int i = 0; i < address.length(); i++){
        if(address[i] == '_'){
            address[i] = ' ';
        }
    }
   
    cout << "Enter roll no: ";
    cin >> roll;
    cout << "Enter division: "; 
    cin >> division;
    file << roll << " " << name << " " << division <<" "<<address << endl;
    file.close();
}

string search(){
    fstream file;
    file.open("StudentRecord.txt");
    int roll;
    cout<<"Enter roll number of student to be found: ";
    cin>>roll;
    string line;
    while(getline(file,line)){
        string temp = line.substr(0,4);
        if(temp == to_string(roll)){
            return line;
            break;
        }
    }
    return "Record not found";


}
void display(){
    fstream file;
    file.open("StudentRecord.txt");
    string line;
    while(getline(file, line)){
        cout << line << endl;
    }
    file.close();
}

void deleteLine(){
    bool found = false;
    fstream file,tempf,f2;
    file.open("StudentRecord.txt");
    int roll;
    cout<<"Enter roll number of student to be deleted: ";
    cin>>roll;
    string line;
    tempf.open("temp.txt", ios::app);
    while(getline(file,line)){
        string temp = line.substr(0,4);
        if(temp == to_string(roll)){
            found = true;
            continue;
            //line="";
            /*tempf.open("temp.txt", ios::app);
            while(getline(file,line)){
                tempf << line << endl;
            }
            while(getline(tempf,line)){
                file << line << endl;
            }*/
            //cout<<"Record deleted successfully\n";
            //remove("temp.txt");
            
        }else{
            tempf << line << endl;
        }
    }
    file.close();
    //remove("StudentRecord.txt");
    f2.open("StudentRecord.txt");
    while(getline(tempf,line)){
        f2 << line << endl;
    }   
    tempf.close();
    remove("temp.txt");
    f2.close();
    if(found){
        cout<<"Record deleted successfully\n";
    }else{  
        cout<<"Record not found\n";
    }

    
}

int main(){
    int choice;
    do{
        cout << "1. Add record\n2. Search record\n3. Display all records\n4. Delete\n5.Exit\nEnter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                add_record();
                break;
            case 2:
                cout << search() << endl;
                break;
            case 3:
                display();
                break;
            case 4:
                deleteLine();
                break;
            case 5:
                cout << "Exiting\n";
                break;
            
            default:
                cout << "Invalid choice\n";
        }   
    }while(choice != 5);
    return 0;


}
