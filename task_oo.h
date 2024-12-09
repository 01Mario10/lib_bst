#include <iostream>

using namespace std;

class Node {
private:
    int data;        
    int weight;      
    Node* lchild;    
    Node* rchild;

public:
    friend ostream& operator<<(ostream& os, const Node* n);
    friend istream& operator>>(istream& is,  Node* n);

    
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

ostream& operator<<(ostream& os, const Node* n){
    if(n->lchild == NULL){
        if(n->rchild == NULL){
            os<<"key nodo: "<<n->data<<" right child: NULL"<<" left child: NULL"<<endl;
        }else {
            os<<"key nodo: "<<n->data<<" right child: "<<n->rchild->data<<" left child: NULL"<<endl;
        }
    }else{
        os<<"key nodo: "<<n->data<<" right child: "<<n->rchild->data<<" left child: "<<n->lchild->data<<endl;
    }

    return os;

}

istream& operator>>(istream& is,  Node* n){

    bool p1 = false;
    bool p2 = false;
    cout<<"inserisci la key del nodo: ";
    is>>n->data;
    do{
       cout<<"inserisci il right child: ";
       is>>n->rchild->data;

       if(n->data > n->rchild->data){
        cout<<"key minore o uguale a quella del root, riprova"<<endl;
       }else{
        p1 = true;
       }

    }while(p1 == false);

    do{
       cout<<"inserisci il left child: ";
       is>>n->lchild->data;

       if(n->data < n->lchild->data){
        cout<<"key maggiore o uguale a quella del root, riprova"<<endl;
       }else{
        p2 = true;
       }

    }while(p2 == false);
    

    return is;
}
