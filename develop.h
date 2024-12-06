#include <iostream>

using namespace std;

class Node {
private:
    int data;        
    int weight;      
    Node* lchild;    
    Node* rchild;    

public:
    
    Node(int k, int w = 0) : data(k), weight(w), lchild(nullptr), rchild(nullptr) {}

   
    Node* insertR(int k) {
        if (k == this->data) {
            return this;
        }

        if (k < this->data) {
            if (this->lchild == nullptr) {
                this->lchild = new Node(k);
            } else {
                this->lchild = this->lchild->insertR(k);
            }
        } else {
            if (this->rchild == nullptr) {
                this->rchild = new Node(k);
            } else {
                this->rchild = this->rchild->insertR(k);
            }
        }

        return this;
    }

    Node* insertI(int k) {
        Node* current = this;
        while (true) {
            if (k == current->data) {
                return current; 
            }

            if (k < current->data) {
             
                if (current->lchild == nullptr) {
                    current->lchild = new Node(k);
                    return this;
                }
                current = current->lchild;
            } else {

                if (current->rchild == nullptr) {
                    current->rchild = new Node(k);
                    return this;
                }
                current = current->rchild;
            }
        }
    }


    bool searchI(int k) {
        Node* current = this;
        while (current != nullptr) {
            if (k == current->data) {
                return true; 
            }
            if (k < current->data) {
                current = current->lchild; 
            } else {
                current = current->rchild;
            }
        }
        return false; 
    }
    
    bool searchR(int k) {
        if (k == this->data) {
            return true; 
        }
        if (k < this->data && this->lchild != nullptr) {
            return this->lchild->searchR(k); 
        }
        if (k > this->data && this->rchild != nullptr) {
            return this->rchild->searchR(k); 
        }
        return false; 
    }

    void inOrder() const {
        if (this->lchild != nullptr) {
            this->lchild->inOrder();
        }
        cout << this->data << " ";
        if (this->rchild != nullptr) {
            this->rchild->inOrder();
        }
    }
};
