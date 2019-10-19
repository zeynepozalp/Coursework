#ifndef __list_hpp__
#define __list_hpp__

#include <iostream>

// Node is a class template that represents a linked-list node.
// It contains an element and a pointer to the next node.
template <class T>
class Node {
    public:
        // Constructor
        Node(const T& e = T(), Node *n = NULL);
        //
        void setNext(Node<T>* n);
        void setElement(const T& e);
        //
        Node<T>* getNext() const;
        T getElement() const;
        T* getElementPtr();
    
    private:
        T element;
        Node<T>* next;
};

template <class T>
Node<T>::Node(const T& e, Node<T>* n){
    element = e;
    next = n;
}

template <class T>
void Node<T>::setNext(Node<T>* n){
    next = n;
}

template <class T>
void Node<T>::setElement(const T& e){
    element = e;
}

template <class T>
Node<T>* Node<T>::getNext() const{
    return next;
}

template <class T>
T Node<T>::getElement() const{
    return element;
}

template <class T>
T* Node<T>::getElementPtr(){
    return &element;
}


// This class template implements a singly linked-list
template <class T>
class List{

    public:
        // Constructor
        List();

        // Copy-constructor
        List(const List& rhs);

        // Destructor
        ~List();

        // Assignment operator (remember the rule of three)
        List& operator=(const List& rhs);

        bool isEmpty() const;
        void makeEmpty();

        // Returns a pointer to the actual first node
        Node<T>* first();
        const Node<T>* first() const;

        // Returns a pointer to the first node that contains "data"
        Node<T>* find(const T& data);

        // Insert a new element that contains "data" after the
        // node pointed to by "p". Note that "p" will be modified
        // by this operation as its next will point to the new node.
        void insert(const T& data, Node<T>* p);

        // Insert a new node to the end of the list
        void push_back(const T& data);

        // Insert a new node to the beginning of the list
        void push_front(const T& data);

        // Remove the first node that contains "data"
        void remove(const T& data);

        // Remove the node indicated by its pointer "p"
        void remove(Node<T>* p);

    private:
        // Pointer to the dummy header
        Node<T>* dummyHead;

        // Used to return a pointer to the node, which
        // points to the first node that contains "data".
        Node<T>* findPrevious(const T& data);

        // Returns a pointer to the dummy header node. Note that
        // because whether we use a dummy header or not is an
        // implementation detail, we make this function private.
        Node<T>* zeroth();

};

template <class T>
List<T>::List(){
    dummyHead = new Node<T>;
}

template <class T>
List<T>::List(const List& rhs){

    dummyHead = new Node<T>;
    // use operator=. Note that this is safe as
    // we already initialized dummyHead.
    *this = rhs; 
}

template <class T>
List<T>::~List(){

    makeEmpty();
    // Destructor should give back all the memory
    // so we must delete the dummy header as well.
    delete dummyHead;
}

template <class T>
List<T>& List<T>::operator=(const List& rhs){

    if (this != &rhs){
        makeEmpty();

        const Node<T>* r = rhs.first();
        Node<T>* p = zeroth();

        while (r) {
            insert(r->getElement(), p);
            r = r->getNext();
            p = p->getNext();
        }
    }
    return *this;
}

template <class T>
void List<T>::makeEmpty(){

    Node<T>* dummy = zeroth();

    while (dummy->getNext()){
        // At every iteration, the following happens
        //
        // Before: Dummy --> A --> B --> ...
        // After: Dummy --> B --> ...
        //
        // Stops when "B" is NULL, so we are only left
        // with "Dummy"
        Node<T>* tmp = dummy->getNext();
        dummy->setNext(tmp->getNext());

        delete tmp;
    }
}

template <class T>
bool List<T>::isEmpty() const{
    return first() == NULL;
}

template <class T>
Node<T>* List<T>::zeroth(){
    return dummyHead;
}

template <class T>
Node<T>* List<T>::first(){
    return dummyHead->getNext();
}


template <class T>
const Node<T>* List<T>::first() const{

    return dummyHead->getNext();
}

template <class T>
void List<T>::insert(const T& data, Node<T>* p){

    Node<T>* newNode = new Node<T>(data, p->getNext());
    p->setNext(newNode);
}

template <class T>
void List<T>::push_back(const T& data){

    /* TO-DO: find the correct position and 
            insert a new node that contains data
     */
}

template <class T>
void List<T>::push_front(const T& data){
    insert(data, zeroth());
}

template <class T>
Node<T>* List<T>::find(const T& data){
    
    Node<T>* p = first();

    while (p){
        if (p->getElement() == data){
            return p;
        }
        p = p->getNext();
    }

    return NULL;
}

template <class T>
Node<T>* List<T>::findPrevious(const T& data){
    
    Node<T>* p = zeroth();

    while (p->getNext()){
        if (p->getNext()->getElement() == data){
            return p;
        }
        p = p->getNext();
    }

    return NULL;
}

template <class T>
void List<T>::remove(const T& data){
    
    Node<T>* p = findPrevious(data);
    if (p){
        Node<T>* tmp = p->getNext();
        p->setNext(tmp->getNext());
        delete tmp;
    }
}

template <class T>
void List<T>::remove(Node<T>* p){

    if (p){
        // In this case, we cannot find the previous element
        // by using data because multiple nodes may contain
        // the same data. We need to find it by its pointer
        // address.

        Node<T>* q = zeroth();

        while (q->getNext() != p){
            q = q->getNext();
            
            if (q == NULL){
                // There is no node in this list whose pointer
                // address matches "p". In this case, we
                // must return to avoid a segmentation fault.
                return;
            }
        }

        // If we are here then q->next is equal to p
        Node<T>* tmp = p->getNext();
        q->setNext(tmp);

        delete p;
    }
}

#endif // __list_hpp__
