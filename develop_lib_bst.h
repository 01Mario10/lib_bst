#include <iostream>

using namespace std;

class Node {
private:
    int data;        // Valore del nodo
    int weight;      // Peso del nodo (non usato in questa versione)
    Node* lchild;    // Puntatore al figlio sinistro
    Node* rchild;    // Puntatore al figlio destro

public:
    // Costruttore
    Node(int k, int w = 0) : data(k), weight(w), lchild(nullptr), rchild(nullptr) {}

    // Inserimento ricorsivo
    Node* insertR(int k) {
        if (k == this->data) {
            return this; // Non si inseriscono duplicati
        }

        if (k < this->data) {
            // Inserimento nel sottoalbero sinistro
            if (this->lchild == nullptr) {
                this->lchild = new Node(k);
            } else {
                this->lchild = this->lchild->insertR(k);
            }
        } else {
            // Inserimento nel sottoalbero destro
            if (this->rchild == nullptr) {
                this->rchild = new Node(k);
            } else {
                this->rchild = this->rchild->insertR(k);
            }
        }

        return this;
    }

    // Inserimento iterativo
    Node* insertI(int k) {
        Node* current = this;
        while (true) {
            if (k == current->data) {
                return current; // Non si inseriscono duplicati
            }

            if (k < current->data) {
                // Scendi a sinistra
                if (current->lchild == nullptr) {
                    current->lchild = new Node(k);
                    return this;
                }
                current = current->lchild;
            } else {
                // Scendi a destra
                if (current->rchild == nullptr) {
                    current->rchild = new Node(k);
                    return this;
                }
                current = current->rchild;
            }
        }
    }

    // Ricerca iterativa
    bool searchI(int k) {
        Node* current = this;
        while (current != nullptr) {
            if (k == current->data) {
                return true; // Nodo trovato
            }
            if (k < current->data) {
                current = current->lchild; // Vai a sinistra
            } else {
                current = current->rchild; // Vai a destra
            }
        }
        return false; // Nodo non trovato
    }

    // Ricerca ricorsiva
    bool searchR(int k) {
        if (k == this->data) {
            return true; // Nodo trovato
        }
        if (k < this->data && this->lchild != nullptr) {
            return this->lchild->searchR(k); // Cerca nel sottoalbero sinistro
        }
        if (k > this->data && this->rchild != nullptr) {
            return this->rchild->searchR(k); // Cerca nel sottoalbero destro
        }
        return false; // Nodo non trovato
    }

    // Attraversamento in ordine
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
