#include <iostream>
#include "User.hpp"
#include "Video.hpp"

void User::printSubscriptions() {
    Node< Video*> * first = subscriptions.first();
    while (first) {
        cout << *(first->getData());
        first = first->getNext();
    }
    cout << std::endl;
}

void User::printFriends() {
    Node< User*> * first = friends.first();
    while (first) {
        cout << *(first->getData());
        first = first->getNext();
    }
    cout << std::endl;
}

ostream& operator<<(ostream& out, const User & user) {
    string st = (user.status == ACTIVE) ? "active" : "suspended";
    out << "username:" << user.username << ",name:" << user.name << ",surname:" << user.surname << ",Status:" << st << endl;
    return out;
}

/* TO-DO: method implementations below */

User::User(){
  username=string();
  name=string();
  surname=string();
  status=ACTIVE;
  subscriptions=LinkedList<Video*>();
  friends=LinkedList<User*>();
}

User::User(string username, string name, string surname){
  username=username;
  name=name;
  surname=surname;
  status=ACTIVE;
  subscriptions=LinkedList<Video*>();
  friends=LinkedList<User*>();
}

User::~User(){
  delete &username;
  delete &name;
  delete &surname;
  delete &status;
  delete &subscriptions;
  delete &friends;
}

const string& User::getUsername() const{
  return username;
}

const string& User::getName() const{
  return name;
}

const string& User::getSurname() const{
  return surname;
}

Status User::getStatus() const{
  return status;
}

void User::updateStatus(Status st){
  status=st;
}

void User::subscribe(Video * video){
  subscriptions.insertNode(subscriptions.getHead(), video);
}

void User::unSubscribe(Video * video){
  Node<Video*>* p = subscriptions.findPrev(video);
  subscriptions.deleteNode(p);
}

void User::addFriend(User * user){
  friends.insertNode(friends.getHead(), user);
}

void User::removeFriend(User * user){
  Node<User*>* p = friends.findPrev(user);
  friends.deleteNode(p);
}

LinkedList<Video*>* User::getSubscriptions(){
  return &subscriptions;
}

LinkedList<User*>* User::getFriends(){
  return &friends;
}

bool User::operator==(const User& rhs) const{
  return getUsername()==rhs.getUsername();
}





























