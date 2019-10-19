#ifndef TWOPHASEBST_H
#define TWOPHASEBST_H

#include <iostream>
#include <string>
#include <stack>
#include <list>
// do not add any other library.
// modify parts as directed by assignment text and comments here.

template <class T>
class TwoPhaseBST {
private: //do not change
    struct SecondaryNode {
        std::string key;
        T data;
        SecondaryNode *left;
        SecondaryNode *right;

        SecondaryNode(const std::string &k, const T &d, SecondaryNode *l, SecondaryNode *r);
    };

    struct PrimaryNode {
        std::string key;
        PrimaryNode *left;
        PrimaryNode *right;
        SecondaryNode *rootSecondaryNode;

        PrimaryNode(const std::string &k, PrimaryNode *l, PrimaryNode *r, SecondaryNode *rsn);
    };

public: // do not change.
    TwoPhaseBST();
    ~TwoPhaseBST();

    TwoPhaseBST &insert(const std::string &primaryKey, const std::string &secondaryKey, const T &data);
    TwoPhaseBST &remove(const std::string &primaryKey, const std::string &secondaryKey);
    TwoPhaseBST &print(const std::string &primaryKey = "", const std::string &secondaryKey = "");
    T *find(const std::string &primaryKey, const std::string &secondaryKey);

private: // you may add your own utility member functions here.
    void destructNode(PrimaryNode * &root);
    void destructNode(SecondaryNode * &root);
    PrimaryNode* findPN(PrimaryNode * &pn, const std::string &primaryKey){
      if(!pn) return NULL;
      else if(primaryKey<pn->key) return findPN(pn->left, primaryKey);
      else if(primaryKey>pn->key) return findPN(pn->right, primaryKey);
      else return pn;
    }
    SecondaryNode* findSN(SecondaryNode * &sn, const std::string &secondaryKey){
      if(!sn) return NULL;
      else if(secondaryKey<sn->key) return findSN(sn->left, secondaryKey);
      else if(secondaryKey>sn->key) return findSN(sn->right, secondaryKey);
      else return sn;
    }
    void insertSN(PrimaryNode * &pn, SecondaryNode * &sn, const std::string &key, const T &data){
      if(!sn){
        SecondaryNode* newSn = new SecondaryNode(key,data,NULL,NULL);
        pn->rootSecondaryNode=newSn;
      }
      else if(key<sn->key){
        if(sn->left==NULL){
          SecondaryNode* newSn = new SecondaryNode(key,data,NULL,NULL);
          sn->left=newSn;
          return;
        }
        else insertSN(pn, sn->left, key, data);
      }
      else if(key>sn->key){
        if(sn->right==NULL){
          SecondaryNode* newSn = new SecondaryNode(key,data,NULL,NULL);
          sn->right=newSn;
          return;
        }
        else insertSN(pn, sn->right, key, data);
      }
    }
    void insertPN(PrimaryNode * &pn, SecondaryNode * &sn, const std::string &key){
      if(key<pn->key){
        if(pn->left==NULL){
          pn->left = new PrimaryNode(key, NULL, NULL, sn);
        }
        else insertPN(pn->left, sn, key);
      }
      else if(key>pn->key){
        if(pn->right==NULL){
          pn->right = new PrimaryNode(key, NULL, NULL, sn);
        }
        else insertPN(pn->right, sn, key);
      }
    }
    SecondaryNode* & findMaxSN(SecondaryNode * &sn){
      if(sn->right==NULL) return sn;
      findMaxSN(sn->right);
    }
    PrimaryNode* findMaxPN(PrimaryNode * &pn){
      if(pn==NULL) return NULL;
      if(pn->right==NULL) return pn;
      findMaxPN(pn->right);
    }
    void printSN(SecondaryNode * sn, SecondaryNode * maxSN){
      if(sn){
        printSN(sn->left, maxSN);
        std::cout<<"\""<<sn->key<<"\" : \""<<sn->data<<"\"";
        if(sn!=maxSN){
          std::cout<<", ";
        }
        printSN(sn->right, maxSN);
      }
    }
    void printPN(PrimaryNode* pn, PrimaryNode* maxPN){
      if(pn!=NULL){
        SecondaryNode* sn=findMaxSN(pn->rootSecondaryNode);
        printPN(pn->left, maxPN);
        std::cout<<"\""<<pn->key<<"\" : {";
        if(sn!=NULL) printSN(pn->rootSecondaryNode,sn);
        std::cout<<"}";
        if(pn!=maxPN){
          std::cout<<", ";
        }
        printPN(pn->right, maxPN);
      }
    }
    void removeSN(PrimaryNode* &pn, SecondaryNode* &snRoot, SecondaryNode* &sn){
      //int i=-1;
      if(snRoot==NULL) return;
      if(sn->key<snRoot->key) removeSN(pn,snRoot->left, sn);
      else if(sn->key>snRoot->key) removeSN(pn,snRoot->right, sn);

      else if(snRoot->left!=NULL && snRoot->right!=NULL){
        SecondaryNode* & max = findMaxSN(snRoot->left);
        SecondaryNode* old = snRoot;
        SecondaryNode* old2 = max;

        max=max->left;
        old2->right=snRoot->right;
        old2->left=snRoot->left;
        snRoot=old2;
        delete old;

      }
      else{
        SecondaryNode* oldNode=snRoot;
        snRoot=(snRoot->left!=NULL) ? snRoot->left : snRoot->right;
        delete oldNode;
      }
    }
    // void removePN(PrimaryNode* &pnRoot, PrimaryNode* &pn){
    //   if(pn->key<pnRoot->key) removePN(pnRoot->left, pn);
    //   else if(pn->key>pnRoot->key) removePN(pnroot->right, pn);
    //   else if(pnRoot==pn){
    //
    //   }
    // }
    void deleteMax(SecondaryNode* &sn){
      if(sn->right==findMaxSN(sn)){
        SecondaryNode* temp =sn->right;
        delete sn->right;
        sn->right=temp->left;
        return;
      }
      deleteMax(sn->right);
    }
    SecondaryNode* findParent(SecondaryNode* snRoot, SecondaryNode* sn, int& i){
      if(sn->key<snRoot->key){
        if(snRoot->left==sn) {i=0; return snRoot;}
        return findParent(snRoot->left, sn, i);
      }
      else if(sn->key>snRoot->key){
        if(snRoot->right==sn) {i=1; return snRoot;}
        return findParent(snRoot->right, sn, i);
      }
      return snRoot;
    }
private: // do not change.
    PrimaryNode *root; //designated root.

    // do not provide an implementation. TwoPhaseBST's are not copiable.
    TwoPhaseBST(const TwoPhaseBST &);
    const TwoPhaseBST &operator=(const TwoPhaseBST &);
};

template <class T>
TwoPhaseBST<T>::SecondaryNode::SecondaryNode(const std::string &k, const T &d, SecondaryNode *l, SecondaryNode *r)
        : key(k), data(d), left(l), right(r) {}

template <class T>
TwoPhaseBST<T>::PrimaryNode::PrimaryNode(const std::string &k, PrimaryNode *l, PrimaryNode *r, SecondaryNode *rsn)
        : key(k), left(l), right(r), rootSecondaryNode(rsn) {}

template <class T>
TwoPhaseBST<T>::TwoPhaseBST() : root(NULL) {}

template <class T>
TwoPhaseBST<T>::~TwoPhaseBST() {
    destructNode(root);
}

template <class T>
TwoPhaseBST<T> &
TwoPhaseBST<T>::insert(const std::string &primaryKey, const std::string &secondaryKey, const T &data) {
    /* IMPLEMENT THIS */
    if(!root){
      SecondaryNode* sn = new SecondaryNode(secondaryKey,data,NULL,NULL);
      root = new PrimaryNode(primaryKey, NULL, NULL, sn);
    }
    else{
      PrimaryNode* temp = findPN(root,primaryKey);
      if(temp){
        insertSN(temp, temp->rootSecondaryNode, secondaryKey, data);
      }
      else{
        SecondaryNode* sn = new SecondaryNode(secondaryKey,data,NULL,NULL);
        insertPN(root, sn, primaryKey);
      }
    }
    return *this;
}

template <class T>
TwoPhaseBST<T> &
TwoPhaseBST<T>::remove(const std::string &primaryKey, const std::string &secondaryKey) {
    /* IMPLEMENT THIS */
    PrimaryNode* pn=findPN(root, primaryKey);
    if(!pn) return *this;
    SecondaryNode* sn=findSN(pn->rootSecondaryNode, secondaryKey);
    if(!sn) return *this;
    removeSN(pn, pn->rootSecondaryNode, sn);
    return *this;
}

template <class T>
TwoPhaseBST<T> &TwoPhaseBST<T>::print(const std::string &primaryKey, const std::string &secondaryKey) {
    /* IMPLEMENT THIS */
    if(root==NULL) std::cout<<"{}"<<std::endl;
    else if(primaryKey=="" && secondaryKey!="") {;}
    else if(primaryKey!="" && secondaryKey==""){
      PrimaryNode* pn=findPN(root, primaryKey);
      if(!pn) std::cout<<"{}";
      else{
        std::cout<<"{\"" << pn->key << "\" : {";
        printSN(pn->rootSecondaryNode, findMaxSN(pn->rootSecondaryNode));
        std::cout<<"}}"<< std::endl;
      }
    }
    else if(secondaryKey!="" && secondaryKey!=""){
      PrimaryNode* pn=findPN(root, primaryKey);
      if(!pn) std::cout<<"{}"<<std::endl;
      else{
        SecondaryNode* sn=findSN(pn->rootSecondaryNode, secondaryKey);
        if(!sn) std::cout<<"{}"<<std::endl;
        else{
          std::cout<<"{\"" << pn->key << "\" : {\""<<sn->key<<"\" : \""<<sn->data<<"\"}}"<<std::endl;
        }
      }
    }
    else{
      PrimaryNode* pn=findMaxPN(root);
      std::cout<<"{";
      if(pn) printPN(root, pn);
      std::cout<<"}"<<std::endl;
    }
    return *this;
}

template <class T>
T *TwoPhaseBST<T>::find(const std::string &primaryKey, const std::string &secondaryKey) {
    /* IMPLEMENT THIS */
    PrimaryNode* pn=findPN(root, primaryKey);
    SecondaryNode* sn=findSN(pn->rootSecondaryNode, secondaryKey);
    if(!pn || !sn) return NULL;
    else return &(sn->data);
}

template <class T>
void TwoPhaseBST<T>::destructNode(TwoPhaseBST::PrimaryNode * &root)
{
    if (root == NULL)
        return;

    destructNode(root->left);
    destructNode(root->right);

    destructNode(root->rootSecondaryNode);

    delete root;

    root = NULL;
}

template <class T>
void TwoPhaseBST<T>::destructNode(TwoPhaseBST::SecondaryNode * &root)
{
    if (root == NULL)
        return;

    destructNode(root->left);
    destructNode(root->right);

    delete root;

    root = NULL;
}

#endif //TWOPHASEBST_H
