// doubly Linked List c++

// Akshit Sharma
// 21107018 
// mechanical



#include <iostream>                   
using namespace std;                  

// NODE CLASSS
class Node{
    public:
    
    string name;
    int age;

    Node*next; 
    Node*prev; 

    //constructor
    Node(string name,int age){
        this->name=name;
        this->age=age;
        next=NULL; 
        prev=NULL; 
    }
};

//insertion at start
void insert_start(Node* &head,string name,int age){
    Node*temp=head;
    Node*new_node=new Node(name,age);
    if(temp==NULL){
        head=new_node;
    }

    else{
        while(temp->next!=NULL){temp=temp->next;}
        temp->next=new_node;
        new_node->prev=temp;
    }
}

//insertion at start
void insert_at_head(Node*&head,string name,int age){
    Node*new_node=new Node(name,age);
    new_node->next=head;
    head->prev=new_node;
    head=new_node;
}

// print from start
void print_start(Node*head){
    Node*temp=head;
    while(temp->next!=NULL){
        cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]"<<"<=>";
        temp=temp->next;
    }
	
    //last element without "<=>" at the end
    if(temp->next==NULL)
    {
        cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]";
    }
}

//print from end
void print_end(Node*head){
    Node*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    while(temp!=NULL){cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]"<<"<-s>";temp=temp->prev;}
    cout<<endl;
}

//delete a node
void delete_ith(Node*&head,int i){
    if(i==0){
        Node*temp=head;
        head=temp->next;
        head->prev=NULL;
        delete temp;
    }
    else{
        Node*temp=head;
        for(int j=0;j<i;j++){temp=temp->next;}
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
}

//delete last element
void pop(Node*&head){
    Node*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    temp->prev->next=NULL;
    delete temp;
}

int main(){

    Node*head=NULL;

	int total_no_of_family_members;

// total family members as input
	cout<<"Enter Number Of Family Members:";
    cin>>total_no_of_family_members;
    
	for(int i=1;i<=total_no_of_family_members;i++){
		string name;
		int age;
		cout<<"Enter Family Member "<<i<<" Name:"<<endl;
        cin>>name;
		cout<<"Enter Family Member "<<i<<" Age:"<<endl;
        cin>>age;

		insert_start(head,name,age);
	}

    cout<<endl;


    cout<<"Doubly Linked list is : "<<endl;
    cout<<endl;

print_start(head);

}

// Akshit Sharma   21107018   mechanical
/*BONUS QUESTION
Q.Try to find a way to link the family members' doubly-linked list based on their relationship.(IF POSSIBLE)
solution. One way is to sort Doubly Linked List in decending order on the basis of age,   so older generation will be closer to head.
// or
take the input in form of the levels of a family tree , ie, taking the input generation wise 


*/
