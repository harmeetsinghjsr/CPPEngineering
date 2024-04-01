#include<iostream>
using namespace std;
class Node{
    public: 
        int val;
        Node* next;
        Node(int data){
            val=data;
            next=NULL;
        }
};

void display(Node* &head){  
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}   

void insertatHead(Node* &head,int val){
    Node* new_node=new Node(val);
    new_node->next=head;
    head=new_node;
}

void insertatTail(Node* &head,int val){
    Node* new_node=new Node(val);
    Node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    // temp reached last node
    temp->next=new_node;
}

void insertatPosition(Node* &head,int val,int pos){
    if(pos==0){
        insertatHead(head,val);
        return;
    }
    Node* temp=head;
    Node* new_node=new Node(val);
    int curr_pos=0;
    while(curr_pos!=pos-1){
        temp=temp->next;
        curr_pos++;
    }
    new_node->next=temp->next;
    temp->next=new_node;
}

void updateValue(Node* &head,int val, int pos){
    Node* temp=head;
    int curr_pos=0;
    while(curr_pos!=pos){
        temp=temp->next;
        curr_pos++;
    }
    //temp reached the desired position
    temp->val=val;
}

void deleteFirstNode(Node* &head){
    Node* temp=head;
    head=head->next;
    free(temp);
}

void deleteatTail(Node* &head){
    Node* second_last=head;
    while(second_last->next->next!=NULL){
        second_last=second_last->next;
    }
    Node* temp=second_last->next;
    second_last->next=NULL;
    free(temp);
}

void deleteatPosition(Node* &head,int pos){
    if(pos==0){
        deleteFirstNode(head);
        return;
    }
    Node* prev=head;
    int curr_pos=0;
    while(curr_pos!=pos-1){
        prev=prev->next;
        curr_pos++;
    }
    Node* temp=prev->next;
    prev->next=prev->next->next;
    free(temp);
}

int main()
{
    Node *head=NULL;
    insertatHead(head,2);
    display(head);
    insertatHead(head,1);
    display(head);
    insertatTail(head,3);
    display(head);
    insertatPosition(head,4,3);
    display(head);
    updateValue(head,5,1);
    display(head);
    deleteFirstNode(head);
    display(head);
    deleteatTail(head);
    display(head);
    deleteatPosition(head,1);
    display(head);
    return 0;
}