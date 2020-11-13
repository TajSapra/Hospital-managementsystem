#include <iostream>
#include <vector>
#include<string>
#include <iterator>
#include <climits>
#include <unordered_map>
using namespace std;
//An unordered mapalong with a vector is used to implement a hospital management system 
//It is a better way to implement as compared to that done by priority queue;
//Out of the 5 functions, 3 are O(1) and 2 are O(N).
//for a priority queue, 3 were O(N) and 2 were O(1).
int idcounter=1;
class patient{
    public:
    string name;
    int patientid;
    int age;
    int Priority;
};
unordered_map<int,patient> database;
vector<int>ispresent;

void addpatient(){
    patient temp;
    cout<<"Enter the patients name:";
    cin>>temp.name;
    cout<<"Enter the patients age:";
    cin>>temp.age;
    temp.patientid=idcounter;
    cout<<"Enter the patient critical factor(Priority):";
    cin>>temp.Priority;
    ispresent.push_back(1);
    database[temp.patientid]=temp;
    idcounter++;
}

void getTop(){
    patient ans;
    ans.Priority=INT_MAX;
    for(auto i:database){
        if(i.second.Priority==0||ispresent[i.second.patientid-1]!=1)
            continue;
        if(i.second.Priority<ans.Priority){
            ans=i.second;
        }
    }
    cout<<"The details of the patient with the given id found:"<<endl<<endl;
    cout<<"Name of patient:"<<ans.name<<endl;
    cout<<"Age of patient:"<<ans.age<<endl;
    cout<<"Id of patient:"<<ans.patientid<<endl;
    cout<<endl;
}

void removetop(){
    patient ans;
    ans.Priority=INT_MAX;
    for(auto i:database){
        if(i.second.Priority==0)
            continue;
        if(i.second.Priority<ans.Priority){
            ans=i.second;
        }
    }
    ispresent[ans.patientid-1]=0;
}

void removeany(){
    cout<<"Enter the patient id to be removed: ";
    int id;
    cin>>id;
    ispresent[id-1]=0;
}

void search(){
    int id;
    cout<<"Enter the patient id: "<<endl;
    cin>>id;
    if(ispresent[id-1]!=1){
        cout<<"There is no patient."<<endl;
    }
    else{
        cout<<"The details of the patient with the given id found:"<<endl<<endl;
        cout<<"Name of patient:"<<database[id].name<<endl;
        cout<<"Age of patient:"<<database[id].age<<endl;
        cout<<"Id of patient:"<<database[id].patientid<<endl;
        cout<<endl;
    }
}

void printqueue(){
    map<int,patient>qu;
    for(int i=0;i<ispresent.size();i++){
        if(ispresent[i]){
            qu[database[i+1].Priority]=database[i+1];
        }
    }
    for(auto i:qu){
        cout<<"Name of patient:"<<i.second.name<<endl;
        cout<<"Age of patient:"<<i.second.age<<endl;
        cout<<"Id of patient:"<<i.second.patientid<<endl;
        cout<<endl;
    }
}

int choiceinput(){
    cout<<"press 1 to add new patient:"<<"\n";
    cout<<"press 2 to gets the details of next patient"<<"\n";
    cout<<"press 3 to remove the patient which goes inside"<<"\n";
    cout<<"press 4 to remove any patient which leaves the queue"<<"\n";
    cout<<"press 5 to print the queue"<<"\n";
    cout<<"press 6 to search in the queue"<<"\n";
    cout<<"press 7 to finish"<<"\n";
    int ans;
    cin>>ans;
    cout<<endl;
    return ans;
}

int main(){
    int choice=choiceinput();
    while (choice){
        if(choice==1){
            addpatient();
        }
        else if(choice==2){
            getTop();
        }
        else if(choice==3){
            removetop();
        }
        else if(choice==4){
            removeany();
        }
        else if(choice==5){
            printqueue();
        }
        else if(choice==6){
            search();
        }
        else if(choice==7){
            cout<<"Exitting the program. BYE BYE "<<endl;
            break;
        }
        else{
            cout<<"Wrong input. Enter Again."<<endl;
        }
        choice=choiceinput();
    }
    return 0;
}