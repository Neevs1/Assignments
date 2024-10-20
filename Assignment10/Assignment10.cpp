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
    tempf.open("temp.txt",std::ios::out);
    while(getline(file,line)){
        string temp = line.substr(0,4);
        if(temp == to_string(roll)){
            found = true;
            continue;
           
        }else{
            tempf << line << endl;
        }
    }
    file.close();
    remove("StudentRecord.txt");
    tempf.close();
    rename("temp.txt","StudentRecord.txt");
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

/*
Output: 
1. Add record
2. Search record
3. Display all records
4. Delete
5.Exit
Enter your choice: 1
Enter name: (Use underscore instead of space) Neevan_Redkar
Enter address: (Use underscore instead of space) Sinhagad_Road,Pune-30
Enter roll no: 3069
Enter division: B
1. Add record
2. Search record
3. Display all records
4. Delete
5.Exit
Enter your choice: 1
Enter name: (Use underscore instead of space) Aryan_Parihar
Enter address: (Use underscore instead of space) Dhayri_Phata,Pune-41
Enter roll no: 3030
Enter division: C
1. Add record
2. Search record
3. Display all records
4. Delete
5.Exit
Enter your choice: 1
Enter name: (Use underscore instead of space) Aryan_Dhamdhere
Enter address: (Use underscore instead of space) Warje,Pune-52
Enter roll no: 3074
Enter division: H
1. Add record
2. Search record
3. Display all records
4. Delete
5.Exit
Enter your choice: 2
Enter roll number of student to be found: 3080
Record not found
1. Add record
2. Search record
3. Display all records
4. Delete
5.Exit
Enter your choice: 2
Enter roll number of student to be found: 3030
3030 Aryan Parihar C Dhayri Phata,Pune-41
1. Add record
2. Search record
3. Display all records
4. Delete
5.Exit
Enter your choice: 1
Enter name: (Use underscore instead of space) Riddhi_Shete
Enter address: (Use underscore instead of space) ????
Enter roll no: 3067
Enter division: ?
1. Add record
2. Search record
3. Display all records
4. Delete
5.Exit
Enter your choice: 1
Enter name: (Use underscore instead of space) Chirag_Budhbaware
Enter address: (Use underscore instead of space) Near_PVG,Pune-09
Enter roll no: 3059
Enter division: B
1. Add record
2. Search record
3. Display all records
4. Delete
5.Exit
Enter your choice: 4
Enter roll number of student to be deleted: 3067
Record deleted successfully
1. Add record
2. Search record
3. Display all records
4. Delete
5.Exit
Enter your choice: 3
3069 Neevan Redkar B Sinhagad Road,Pune-30
3030 Aryan Parihar C Dhayri Phata,Pune-41
3074 Aryan Dhamdhere H Warje,Pune-52
3059 Chirag Budhbaware B Near PVG,Pune-09
1. Add record
2. Search record
3. Display all records
4. Delete
5.Exit
Enter your choice: 4
Enter roll number of student to be deleted: 3069
Record deleted successfully
1. Add record
2. Search record
3. Display all records
4. Delete
5.Exit
Enter your choice: 3
3030 Aryan Parihar C Dhayri Phata,Pune-41
3074 Aryan Dhamdhere H Warje,Pune-52
3059 Chirag Budhbaware B Near PVG,Pune-09
1. Add record
2. Search record
3. Display all records
4. Delete
5.Exit
Enter your choice: 1
Enter name: (Use underscore instead of space) Neevan_Redkar
Enter address: (Use underscore instead of space) Sinhagad_Road,Pune-30
Enter roll no: 3069
Enter division: B
1. Add record
2. Search record
3. Display all records
4. Delete
5.Exit
Enter your choice: 2
Enter roll number of student to be found: 3067
Record not found
1. Add record
2. Search record
3. Display all records
4. Delete
5.Exit
Enter your choice: 3
3030 Aryan Parihar C Dhayri Phata,Pune-41
3074 Aryan Dhamdhere H Warje,Pune-52
3059 Chirag Budhbaware B Near PVG,Pune-09
3069 Neevan Redkar B Sinhagad Road,Pune-30
1. Add record
2. Search record
3. Display all records
4. Delete
5.Exit
Enter your choice: 5
Exiting



*/