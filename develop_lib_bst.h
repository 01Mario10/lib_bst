
Ecco il codice riscritto e corretto con le modifiche richieste, inclusi i nuovi nomi delle funzioni:

cpp
Copia codice
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
