#include <iostream>
#include <map>
#include<string>
#include <iterator>
using namespace std;
//An ordered map(or simply map) is used to implement a hospital management system 
//It is a better way to implement as compared to that done by priority queue;
//Out of the 6  functions, 3 are O(1) and 2 are O(N).
//for a priority queue, 3 were O(N) and 2 were O(1).
//the function print entirequeue cannot be improved from O(N)
int idcounter=0;

class patient{
    public:
    string name;
    int patientid;
    int age;
    int Priority;
};

map<int ,patient> plist;
map<int, int> ispresent;
map<int ,patient> dq;


void addpatient(){
    patient temp;
    cout<<"Enter the patients name:";
    cin>>temp.name;
    cout<<"Enter the patients age:";
    cin>>temp.age;
    temp.patientid=idcounter;
    cout<<"Enter the patient critical factor(Priority):";
    cin>>temp.Priority;
    plist[idcounter]=temp;
    ispresent[idcounter]=1;
    dq[temp.Priority]=temp;
    idcounter++;
}

void getTop(){
    patient temp;
    int i,count=0, ans=-1;
    for(map<int, patient>::iterator it=plist.begin();it!=plist.end();it++){
        if(ans<it->second.Priority){
            // cout<<"check1 "<<ans<<" "<<it->second.Priority<<endl;
            ans=it->second.Priority;
            i=count;
            temp=it->second;
        }
        count++;
    }
    cout<<"The details of the next patient:"<<endl<<endl;
    cout<<"Name of patient:"<<temp.name<<endl;
    cout<<"Age of patient:"<<temp.age<<endl;
    cout<<"Id of patient:"<<temp.patientid<<endl;
    cout<<endl;
}

void removetop(){
    int i,count=0, ans=-1;
    for(map<int, patient>::iterator it=plist.begin();it!=plist.end();it++){
        if(ans<it->second.Priority){
            // cout<<"check1 "<<ans<<" "<<it->second.Priority<<endl;
            ans=it->second.Priority;
            i=count;
        }
        count++;
    }
    // cout<<i<<plist[i].name<<endl;
    ispresent[i]=0;
}

void removeany(){
    int id;
    cin>>id;
    ispresent[id]=0;
}

void search(){
    int id;
    cout<<"Enter the patient id: "<<endl;
    cin>>id;
    if(ispresent[id]!=1){
        cout<<"There is no patient."<<endl;
    }
    else{
        cout<<"The details of the patient with the given id found:"<<endl<<endl;
        cout<<"Name of patient:"<<plist[id].name<<endl;
        cout<<"Age of patient:"<<plist[id].age<<endl;
        cout<<"Id of patient:"<<plist[id].patientid<<endl;
        cout<<endl;
    }
}

void printqueue(){
    int counter=0;
    for(map<int, patient>::reverse_iterator it=dq.rbegin();it!=dq.rend();it++){
        if(ispresent[it->second.patientid]==0){
            continue;
        }
        cout<<"Name of patient:"<<it->second.name<<endl;
        cout<<"Age of patient:"<<it->second.age<<endl;
        cout<<"Id of patient:"<<it->second.patientid<<endl;
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