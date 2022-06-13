#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    Node(int data, Node *next){
        this->data = data;
        this->next = next;
    }
};

class LinkedList{
public:
    Node *head;
    LinkedList(){
        this->head = NULL;
    }

    void add(int data){
        Node *node = new Node(data);
        if(this->head == NULL){
            this->head = node;
        }
        else{
            Node *temp = this->head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = node;
        }
    }

    void print(){
        Node *temp = this->head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void inputLinkedList(){
        while (true){
            int data;
            cin>>data;
            if(data == -1){
                break;
            }
            this->add(data);
        }
    }

    void sumNode(){
        Node *temp = this->head;
        int sum = 0;
        while(temp != NULL){
            sum += temp->data;
            temp = temp->next;
        }
        cout<<sum<<endl;
    }

    void insertPos( int pos, int data){
        Node *node = new Node(data);
        if(pos < 1){
            cout<<"Invalid position"<<endl;
            return;
        }else if(pos == 1){
            node->next = this->head;
            this->head = node;
        }
        else{
            Node *temp = this->head;
            int i = 0;
            while(i < pos){
                temp = temp->next;
                i++;
            }
            node->next = temp->next;
            temp->next = node;
        }
    }

    void deleteFirstNode(){
        if(this->head == NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        Node *temp = this->head;
        this->head = this->head->next;
        delete temp;
    }

    void deleteLastNode(){
        if(this->head == NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        Node *temp = this->head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next = NULL;
        delete temp->next;
    }

    void deletePos(int pos){
        if(this->head == NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        if(pos < 1){
            cout<<"Invalid position"<<endl;
            return;
        }else if (pos = 1)
        {
            deleteFirstNode();
        }else{
            Node *temp = this->head;
            int i = 0;
            while(i < pos){
                temp = temp->next;
                i++;
            }
            Node *temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
        }
        
    }
};

int main(){
    LinkedList list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(1);
    
    // list.inputLinkedList();
    list.print();
    list.sumNode();

    list.insertPos(1, 5);
    list.print();
    list.deleteFirstNode();
    list.print();
    list.deleteLastNode();
    list.print();
    list.deletePos(1);
    list.print();
}