#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "VideoShare.hpp"
#include "User.hpp"

using namespace std;

void VideoShare::printAllVideos() {
    videos.print();
}

void VideoShare::printAllUsers() {
    users.print();
}

/* TO-DO: method implementations below */

    Node<User>* VideoShare::findUserNode(LinkedList<User> users, const string & userName){
      Node<User>* userNodePtr=users.first();

      while (userNodePtr){
        if((userNodePtr->getData()).getUsername()==userName){
          return userNodePtr;
        }
        userNodePtr=userNodePtr->getNext();
      }
      return NULL;
    }

    User* VideoShare::findUser(LinkedList<User> users, const string & userName){
      Node<User>* userNodePtr=findUserNode(users, userName);
      return userNodePtr->getDataPtr();
    }

    Video* VideoShare::findVideo(LinkedList<Video> videos, const string & videoName){
      Node<Video>* videoNodePtr=videos.first();

      while (videoNodePtr){
        if((videoNodePtr->getData()).getTitle()==videoName){
          return videoNodePtr->getDataPtr();
        }
        videoNodePtr=videoNodePtr->getNext();
      }
      return NULL;
    }

    void VideoShare::bubbleSort(LinkedList<Video*> subs){
      bool sorted=false;
      size_t l=subs.getLength();
      Node<Video*>* leftNodePtr = subs.first();
      Video* leftVideoPtr = leftNodePtr->getData();
      Node<Video*>* rightNodePtr = leftNodePtr->getNext();
      Video* rightVideoPtr = rightNodePtr->getData();
      string leftTitle, rightTitle;

      for(int i=0; (i<l-1) && !sorted; i++){
        sorted=true;
        for(int j=1; j<=l-i-1; j++){
          leftTitle=leftVideoPtr->getTitle();
          rightTitle=rightVideoPtr->getTitle();
          if(leftTitle>rightTitle){
            subs.swap(j,j-1);
            sorted=false;
          }
          leftNodePtr = rightNodePtr;
          leftVideoPtr = rightVideoPtr;
          rightNodePtr = rightNodePtr->getNext();
          rightVideoPtr = rightNodePtr->getData();
        }
      }
    }

VideoShare::VideoShare(){
  users=LinkedList<User>();
  videos=LinkedList<Video>();
}

VideoShare::~VideoShare(){
  delete &users;
  delete &videos;
}

void VideoShare::createUser(const string & userName, const string & name, const string & surname){
  User newUser=User(userName, name, surname);
  users.insertNode(users.getHead(),newUser);
}

void VideoShare::loadUsers(const string & fileName){
  ifstream infile(fileName.data());
  string line, username, name, surname;
  size_t pos;
    while(getline(infile,line)){
      pos=line.find(";");
      username = line.substr(0, pos);
      line.erase(0, pos + 1);
      pos=line.find(";");
      name = line.substr(0, pos);
      surname = line.substr(pos+1, line.length());
      if(username!=""){
        createUser(username, name, surname);
      }
    }
}

void VideoShare::createVideo(const string & title, const string & genre){
  Video newVideo=Video(title,genre);
  videos.insertNode(videos.getHead(),newVideo);
}

void VideoShare::loadVideos(const string & fileName){
  ifstream infile(fileName.data());
  string line, title, genre;
  size_t pos;
    while(getline(infile,line)){
      pos=line.find(";");
      title = line.substr(0, pos);
      genre = line.substr(pos+1, line.length());
      if(title!=""){
        createVideo(title, genre);
      }
    }
}

void VideoShare::addFriendship(const string & userName1, const string & userName2){
  User* userPtr1=findUser(users, userName1);
  User* userPtr2=findUser(users, userName2);

  userPtr1->addFriend(userPtr2);
  userPtr2->addFriend(userPtr1);
}

void VideoShare::removeFriendship(const string & userName1, const string & userName2){
  User* userPtr1=findUser(users, userName1);
  User* userPtr2=findUser(users, userName2);

  userPtr1->removeFriend(userPtr2);
  userPtr2->removeFriend(userPtr1);
}

void VideoShare::updateUserStatus(const string & userName, Status newStatus){
  User* userPtr=findUser(users, userName);
  userPtr->updateStatus(newStatus);
}

void VideoShare::subscribe(const string & userName, const string & videoTitle){
  User* userPtr=findUser(users, userName);
  Video* videoPtr=findVideo(videos, videoTitle);
  if(userPtr!=NULL && userPtr->getStatus()==ACTIVE) userPtr->subscribe(videoPtr);
}

void VideoShare::unSubscribe(const string & userName, const string & videoTitle){
  User* userPtr=findUser(users, userName);
  Video* videoPtr=findVideo(videos, videoTitle);
  if(userPtr!=NULL && userPtr->getStatus()==ACTIVE) userPtr->unSubscribe(videoPtr);
}

void VideoShare::deleteUser(const string & userName){
  Node<User>* UserPtrNode = findUserNode(users, userName);
  User* UserPtr = findUser(users, userName);
  Node<User>* tempUserNode = users.first();
  User tempUser = tempUserNode->getData();
  Node<User*>* tempFriendNode = tempUser.getFriends()->first();
  User* tempFriend = tempFriendNode->getData();

  size_t lengthUsers = users.getLength();
  while (lengthUsers>=0) {
    size_t lengthFriends = tempUser.getFriends()->getLength();
    while(lengthFriends>=0){
      if(tempFriend==UserPtr){
        tempUser.removeFriend(UserPtr);
        break;
      }
      tempFriendNode=tempFriendNode->getNext();
      tempFriend=tempFriendNode->getData();
      lengthFriends--;
    }
    tempUserNode = tempUserNode->getNext();
    tempUser = tempUserNode->getData();
    lengthUsers--;
  }

  Node<User>* p=users.findPrev(UserPtrNode->getData());
  users.deleteNode(p);
}

void VideoShare::sortUserSubscriptions(const string & userName){
  User* userPtr = findUser(users, userName);
  LinkedList<Video*> subs = *(userPtr->getSubscriptions());
  bubbleSort(subs);
}

void VideoShare::printUserSubscriptions(const string & userName){
  User* userPtr = findUser(users, userName);
  userPtr->printSubscriptions();
}

void VideoShare::printFriendsOfUser(const string & userName){
  User* userPtr = findUser(users, userName);
  userPtr->printFriends();
}

void VideoShare::printCommonSubscriptions(const string & userName1, const string & userName2){
  Node<User>* UserPtrNode1 = findUserNode(users, userName1);
  User* UserPtr1 = findUser(users, userName1);
  Node<User>* UserPtrNode2 = findUserNode(users, userName2);
  User* UserPtr2 = findUser(users, userName2);

  sortUserSubscriptions(userName1);
  sortUserSubscriptions(userName2);

  Node<User*>* tempFriendNode1 = UserPtr1->getFriends()->first();
  User* tempFriend1 = tempFriendNode1->getData();
  Node<User*>* tempFriendNode2 = UserPtr2->getFriends()->getHead();
  User* tempFriend2 = tempFriendNode2->getData();

  while(tempFriend1){
    while(tempFriend2){
      tempFriendNode1 = tempFriendNode1->getNext();
      tempFriend1 = tempFriendNode1->getData();
      if(&tempFriend1==&tempFriend2){
        std::cout << tempFriendNode1->getData() << std::endl;
        break;
      }
    }
    tempFriendNode2 = tempFriendNode2->getNext();
    tempFriend2 = tempFriendNode2->getData();
  }
}






















