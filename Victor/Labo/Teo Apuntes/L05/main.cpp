#include <iostream>
#include <cstdlib>

using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

/* VAMOS A TENER UN DATO Y UN PUNTERO
 * EL PUNTERO APUNTA AL NODO QUE LE SEGUIRA
 * LOS NODOS SERAN LA PRIMERA ESTRUCTURA RECURSIVA
 * EL SIGUIENTE A APUNTAR ES UN NODO
*/

class Node{
public:
    Node* next;
    int data;
};

class LinkedList{
    public:
        int length;
        Node* head;

        LinkedList();
        ~LinkedList();
        void add(int data);
        void print();
    private:
    void _destruir();

    struct Nodo{
        Nodo(const int& elem);
        int valor;
        Nodo* siguiente;
    };
    Nodo *_primero;
};

LinkedList::LinkedList() :length(0), head(NULL){};
void LinkedList::add(int data){
    // Primer paso -> encapsular el dato en nodo
    Node* node = new Node();
    node->data = data;
    // Segundo paso -> enganchar el nodo al resto de la lista
    node->next = this->head;
    this->head = node;
    this->length++;
}

// La cantidad de New debe ser igual a la cantidad de Delete
LinkedList::~LinkedList()
{
    Node* temp = head->next;
    while(temp != NULL)
    {
        temp = temp->next;
        delete(head);
        head = temp;
    }
}