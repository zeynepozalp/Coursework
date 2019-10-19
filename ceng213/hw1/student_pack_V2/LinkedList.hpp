#ifndef LINKEDLIST_HPP
#define	LINKEDLIST_HPP

#include <iostream>
#include "Node.hpp"

using namespace std;

/*....DO NOT EDIT BELOW....*/
template <class T>
class LinkedList {
private:
    Node<T>* head;
    int length;
public:

    LinkedList();
    LinkedList(const LinkedList<T>& ll);
    LinkedList<T>& operator=(const LinkedList<T>& ll);
    ~LinkedList();


    Node<T>* getHead() const;
    Node<T>* first() const;
    Node<T>* findPrev(const T& data) const;
    Node<T>* findNode(const T& data) const;
    void insertNode(Node<T>* prev, const T& data);
    void deleteNode(Node<T>* prevNode);
    void clear();
    size_t getLength() const;
    void print() const;
    void swap(int index1, int index2);
};

template <class T>
void LinkedList<T>::print() const {
    const Node<T>* node = first();
    while (node) {
        std::cout << node->getData();
        node = node->getNext();
    }
    cout << std::endl;
}

/*....DO NOT EDIT ABOVE....*/

/* TO-DO: method implementations below */

template <class T>
LinkedList<T>::LinkedList(){
  head = new Node<T>();
  length=0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& ll){
  head = new Node<T>();
  *this = ll;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& ll){
  if (this != &ll) {
    clear();
    const Node<T>* f=ll.first();
    Node<T>* t=head;

    while(f){
      insertNode(t, f->getData());
      f = f->getNext();
      t=t->getNext();
    }
  }
  return *this;
}

template <class T>
LinkedList<T>::~LinkedList(){
  this->clear();
  delete head;
}

template <class T>
Node<T>* LinkedList<T>::getHead() const {
  return head;
}

template <class T>
Node<T>* LinkedList<T>::first() const {
  return head->getNext();
}

template <class T>
Node<T>* LinkedList<T>::findPrev(const T& data) const {
  Node<T>* f=head->getNext();

  while(f){
    if(f->getNext()->getData()==data){
      return f;
    }
    f=f->getNext();
  }
  return NULL;
}

template <class T>
Node<T>* LinkedList<T>::findNode(const T& data) const {
  Node<T>* f=findPrev(data);
  if(f) {return f->getNext();}
  else return NULL;
}

template <class T>
void LinkedList<T>::insertNode(Node<T>* prev, const T& data){
  Node<T>* newnode=new Node<T>(data);
  Node<T>* tmp = prev->getNext();
  prev->setNext(newnode);
  newnode->setNext(tmp);
  length++;
}

template <class T>
void LinkedList<T>::deleteNode(Node<T>* prevNode){
  Node<T>* tmp=prevNode->getNext()->getNext();
  delete prevNode->getNext();
  prevNode->setNext(tmp);
  length--;
}

template <class T>
void LinkedList<T>::clear(){
  Node<T>* f=this->getHead()->getNext();

  while(f){
    f=f->getNext();
    deleteNode(f);
  }
}

template <class T>
size_t LinkedList<T>::getLength() const{
  return length;
}

template <class T>
void LinkedList<T>::swap(int index1, int index2){
  int i,j;
  Node<T>* c1=head->getNext();
  Node<T>* c2=head->getNext();
  for(i=0; i<(this->getLength()); i++){
    if(i==index1) break;
    c1=c1->getNext();
  }
  for(j=0; j<(this->getLength()); j++){
    if(j==index2) break;
    c2=c2->getNext();
  }
  Node<T>* p1=findPrev(c1->getData());
  Node<T>* p2=findPrev(c2->getData());
  Node<T>* a1=c1->getNext();
  Node<T>* a2=c2->getNext();

  p1->setNext(c2); c2->setNext(a1);
  p2->setNext(c1); c1->setNext(a2);
}

/* end of your implementations*/
#endif
