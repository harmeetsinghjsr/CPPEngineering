#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node* prev;

    Node(int data){
        val=data;
        next=NULL;
        prev=NULL;
    }
};
class DoubleLinkedList{
    public:
    Node* head;
    Node* tail;

    DoubleLinkedList(){
        head=NULL;
        tail=NULL;
    }
    void insertionAtStart(int val){
        Node* new_node=new Node(val);
        if(head==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        new_node->next=head;
        head->prev=new_node;
        head=new_node;
        return;
    }
    void insertAtEnd(int val){
        Node* new_node=new Node(val);
        if(tail==NULL){ // checks if the dll is empty or not
        head=new_node;//if its null then we need to create both head and tail and point them to new_node
            tail=new_node;
            return;
        }
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
        return;
    }
    bool isPalindromle(){
        while(head!=tail && tail!=head->prev){
            if(head->val!=tail->val){
                return false;
            }
            head=head->next;
            tail=tail->next;
        }
        return true;
    }
    void ForTraverse(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"<->";
            temp=temp->next;
        }
    }
    
};

int main()
{
    Node* new_node=new Node(3);
    DoubleLinkedList dll;
    dll.insertionAtStart(0); // Insert at the start
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtEnd(4);
    dll.ForTraverse();
    cout<<endl;
    cout<<"The dll is 0/1 : "<<dll.isPalindromle()<<endl;
    return 0;
}