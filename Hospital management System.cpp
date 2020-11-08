#include <iostream>
#include <string>
using namespace std;
//A sorted linked list is being used to implement a priority queue which will be used to implement a hospital management system
//patient represnts the Node of LL using which a Priority queue is implemented 
//Out of the 6  functions, 2 are O(1) and 4 are O(N).
//the function print entirequeue cannot be improved from O(N)
int idcounter=0;
class patient{
    public:
    string name;
    int patientid;
    int age;
    int Priority;
    patient* next;
};

patient* RemovetopPatient(patient* head){
    if(head==NULL){
        cout<<"The queue is empty";
        return NULL;
    }
    if(idcounter==0){
        cout<<"no patient in the queue"<<"\n";
        return NULL;
    }
    head=head->next;
    return head;
}

int indexfinder(int id, patient* head){
    int ans=1;
    patient* temp=head;
    while(temp->next!=NULL){
        if(temp->patientid==id){
            return ans;
        }
        temp=temp->next;
        ans++;
    }
    return ans+1;
}

patient* RemoveAnyPatient(patient* head){
    if(head==NULL){
        cout<<"The queue is empty";
        return NULL;
    }
    int id;
    cout<<"enter the patient id"<<"\n";
    cin>>id;
    if(head->patientid==id){
        return RemovetopPatient(head);
    }
    patient* temp= new patient;
    temp=head;
    int index=indexfinder(id,head);
    patient*previous;
    patient*headcopy=head;
    for(int j=1;j<index;j++)
    {
        previous=head;
        head=head->next;
    }
    previous->next=head->next;
    head=headcopy;
    cout<<endl<<endl<<"Jobe done"<<endl<<endl;
    return head;
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

patient* addPatient(patient* head){
    patient* temp=new patient;
    cout<<"Enter the patients name:";
    cin>>temp->name;
    cout<<"Enter the patients age:";
    cin>>temp->age;
    temp->patientid=++idcounter;
    cout<<"Enter the patient critical factor(Priority):";
    cin>>temp->Priority;
    temp->next=NULL;
    if (head==NULL){
        head=temp;
        return head;
    }
    if (temp->Priority<=head->Priority){
        patient* traversal=new patient;
        traversal=head;
        while(traversal->next->next!=NULL){
            if(traversal->next->Priority<=temp->Priority){
                temp->next=traversal->next;
                traversal->next=temp;
                return head;
            }
            traversal=traversal->next;
        }
        if(traversal->next->Priority<=temp->Priority){
            temp->next=traversal->next;
            traversal->next=temp;
            return head;
        }
        else{
            traversal=traversal->next;
            traversal->next=temp;
            temp->next=NULL;
            return head;
        }
    }
    else{
        temp->next=head;
        head=temp;
    }
    return head;
}

patient* gettopPatient(patient* head){
    cout<<"The details of the next patient:"<<endl<<endl;
    cout<<"Name of patient:"<<head->name<<endl;
    cout<<"Age of patient:"<<head->age<<endl;
    cout<<"Id of patient:"<<head->patientid<<endl;
    cout<<endl;
    return head;
}

void search(patient*head, string input){
    patient*temp=head;
    while(temp!=NULL){
        if(temp->name==input){
            cout<<"Patient found: "<<endl<<endl;
            cout<<"Name of the patient: "<<temp->name<<endl;
            cout<<"Age of the patient: "<<temp->age<<endl;
            cout<<"Id of the patient: "<<temp->patientid<<endl<<endl;
            return;
        }
        temp=temp->next;
    }
    cout<<"No patient found"<<endl<<endl;
}

void search(patient*head, string input){
    patient*temp=head;
    while(temp!=NULL){
        if(temp->name==input){
            cout<<"Patient found: "<<endl<<endl;
            cout<<"Name of the patient: "<<temp->name<<endl;
            cout<<"Age of the patient: "<<temp->age<<endl;
            cout<<"Id of the patient: "<<temp->patientid<<endl<<endl;
            return;
        }
        temp=temp->next;
    }
    cout<<"No patient found"<<endl<<endl;
}


patient* printEntireQueue(patient* head){
    patient* temp=head;
    while (temp!=NULL){
          cout<<"Name of the patient: "<<temp->name<<endl;
          cout<<"Age of the patient: "<<temp->age<<endl;
          cout<<"Id of the patient: "<<temp->patientid<<endl;
          temp=temp->next;
    }
    cout<<endl<<endl;
    return head;
}

int main(){
    patient* queuehead=NULL;
    int choice=choiceinput();
    while (choice){
        if(choice==1){
            queuehead=addPatient(queuehead);
        }
        else if(choice==2){
            queuehead=gettopPatient(queuehead);
        }
        else if(choice==3){
            queuehead=RemovetopPatient(queuehead);
        }
        else if(choice==4){
            queuehead=RemoveAnyPatient(queuehead);
        }
        else if(choice==5){
            queuehead=printEntireQueue(queuehead);
        }
        else if(choice==6){
            string input;
            cout<<"Enter patient name to search for: ";
            cin.ignore();
            getline(cin,input);
            search(queuehead,input);
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
