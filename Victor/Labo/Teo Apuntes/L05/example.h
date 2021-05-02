#include <iostream>
#include <cstdlib>
using namespace std;

class Node{
public:
    Node* next;
    int data;
};
// Buscamos encapsular el comportamiento para comportarse como un TAD de enteros
// Asumiendo quue desconocemos el TAD list
class LinkedList{
public:
    int length; // Longitud de la lista
    Node* head; // Apuntando al primer nodo

    LinkedList();
    ~LinkedList();
    void add(int data);
    void print();


};

// Este constructor no utiliza lista de inicializacion. Esto genera que length se inicia con un valor por default
// antes de iniciar el primer ciclo
// Es necesario darle un valor por default
LinkedList::LinkedList() {
    length = 0;
    head = nullptr;
}

// Recivimos un dato, encapsulamos el dato en el nodo, enganchamos el nodo al resto de la lista
/* Casos:
 * 1 - No tengo nada en la lista
 * 2 - tengo datos en la lista, recorro la lista hasta el ultimo nodo y engancho
 * */
void LinkedList::add(int data){
    Node* node = new Node();  // Genero un nodo
    node->data = data;      // Le asigno el dato
    // Enganchar
    node->next = this->head; // El comienzo de la lista
    this->head = node;  // El comienzo de la lista es el nodo
    this->length++; // Incrementamos la longitud de la lista
}

// Destructor
LinkedList::~LinkedList() {
    // La cantidad de new debe ser igual a la cantidad de delete
    Node* temp = head;
    while(temp != NULL){
        temp = temp -> next;
        delete(head);
        head = temp;
    }
}


