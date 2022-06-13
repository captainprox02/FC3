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

    Node(int data, Node* left, Node* right){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class Tree{
public:
    Node* root;

    Node* newNode(int data){
        Node* node = new Node(data);
        return node;
    }

    Node* newNode(int data, Node* left, Node* right){
        Node* node = new Node(data, left, right);
        return node;
    }
    
    Node* insert(Node* node,int data){
        if (node == NULL){
            return(newNode(data));
        }else if(node->left == NULL){
            node->left = newNode(data);
        }else{
            node->right = newNode(data);
        }
        return node;
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

    void createTree(Node* node){
        root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(4);
        root->left->right = newNode(5);
        root->right->right = newNode(8);
    }
};



int main(){
    Tree tree;
    tree.createTree(tree.root);
    tree.printLevelOrder(tree.root);
}