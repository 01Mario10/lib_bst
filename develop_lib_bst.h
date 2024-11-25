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

        Node* insert(int k) {
            if (k == this->data) {
                return this; 
            }

            if (k < this->data) {
                if (this->lchild == nullptr) {
                    this->lchild = new Node(k);
                } else {
                    this->lchild = this->lchild->insert(k);
                
            } else if(k >this->data){
                if (this->rchild == nullptr) {
                this->rchild = new Node(k);
                } else {
                this->rchild = this->rchild->insert(k); 
            }
        }

        return this; 
    }

    void Inorder() const {
        if (this->lchild != nullptr) {
            this->lchild->InOrder();
        }
        cout << this->data << " ";
        if (this->rchild != nullptr) {
            this->rchild->InOrder();
        }
    }
};