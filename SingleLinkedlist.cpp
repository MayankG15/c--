#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void inseartionAtHead(Node* &head,int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;

}
void inseartAtTail(Node* &tail,int data){
    Node* temp=new Node(data);
    tail->next=temp;
    tail=tail->next;
}
void insertAtMiddle(Node* &head,Node* &tail,int position,int data){
    Node* temp=head;
    int cnt=1;
    if(position==1){
        inseartionAtHead(head,data);
    }
    if(temp->next==NULL){
        inseartAtTail(tail,data);
    }
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    Node* nodeToInsert=new Node(data);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node* node1=new Node(7);
    cout<<node1->data<<" ";
    cout<<node1->next<<" ";
    cout<<endl;
    Node* head=node1;
    Node* tail=node1;
    print(head);
    inseartionAtHead(head,9);
    inseartionAtHead(head,10);
    inseartAtTail(tail,11);
    inseartAtTail(tail,12);
    insertAtMiddle(head,tail,4,8);
    print(head);
    return 0;
}