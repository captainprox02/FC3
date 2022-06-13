#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

class BSTTree{
public:
    Node* root;

    BSTTree(){
        this->root = NULL;
    }

    void insert(int data){
        Node* newNode = new Node(data);
        if(this->root == NULL){
            this->root = newNode;
        }
        else{
            Node* current = this->root;
            Node* parent;
            while(true){
                parent = current;
                if(data < current->data){
                    current = current->left;
                    if(current == NULL){
                        parent->left = newNode;
                        return;
                    }
                }
                else{
                    current = current->right;
                    if(current == NULL){
                        parent->right = newNode;
                        return;
                    }
                }
            }
        }
    }

    void inOrder(Node* node){
        if(node == NULL)
            return;
        inOrder(node->left);
        cout<<node->data<<" ";
        inOrder(node->right);
    }

    void preOrder(Node* node){
        if(node == NULL)
            return;
        cout<<node->data<<" ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void print(Node* node){
        if(node == NULL)
            return;
        print(node->left);
        cout<<node->data<<" ";
        print(node->right);
    }


    void printLevelOrder(Node* node){
        if(node == NULL)
            return;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* current = q.front();
            q.pop();
            cout<<current->data<<" ";
            if(current->left != NULL)
                q.push(current->left);
            if(current->right != NULL)
                q.push(current->right);
        }
    }
};

int main(){
    BSTTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);

    tree.printLevelOrder(tree.root);
}