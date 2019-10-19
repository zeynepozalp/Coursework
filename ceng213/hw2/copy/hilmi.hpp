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
    PrimaryNode* searchprimary(PrimaryNode *root,std::string key);
    SecondaryNode* searchsecondary(SecondaryNode * root,std::string key);

    SecondaryNode* findmaxsecondary(SecondaryNode * root);
	PrimaryNode* findmaxprimary(PrimaryNode * t);
	SecondaryNode*& findminsecondary(SecondaryNode * &t);
	void insert2(const std::string &primaryKey, const std::string &secondaryKey, const T &data,PrimaryNode*&);
	void insert3(const std::string &secondaryKey, const T &data, TwoPhaseBST::SecondaryNode * &t);

	void remove2( const std::string &secondaryKey, TwoPhaseBST::SecondaryNode * &t);


    void inorderprimary(PrimaryNode * root);
    void inorderprimarysecondary(PrimaryNode * root,PrimaryNode* max);
    void inordersecondary1(SecondaryNode * p);
    void destructNode(PrimaryNode * &root);
    void destructNode(SecondaryNode * &root);

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
	insert2(primaryKey, secondaryKey, data, this->root);




    return *this;

    /* IMPLEMENT THIS */
}

template <class T>
TwoPhaseBST<T> &
TwoPhaseBST<T>::remove(const std::string &primaryKey, const std::string &secondaryKey) {
  TwoPhaseBST<T>::PrimaryNode *p=searchprimary(this->root,primaryKey);
  using namespace std;
  if(p==NULL) return *this;
  else{
	  if (p->rootSecondaryNode == NULL)return *this;
	  else{
		  remove2(secondaryKey, p->rootSecondaryNode);
	  }
  }
  return *this;
}

template <class T>
TwoPhaseBST<T> &TwoPhaseBST<T>::print(const std::string &primaryKey, const std::string &secondaryKey)
{
	  using namespace std;


	  if(primaryKey == "" &&  secondaryKey =="") //both primary and secondary not given
	  {

		  if(this->root == NULL)
		  cout<<"{}"<<endl;
		  else if(this->root!=NULL)
		  {
			  PrimaryNode * max = findmaxprimary(root);
			cout<<"{";
			inorderprimarysecondary(this->root,max);
			cout<<"}"<<endl;

		  }
	  }
	  else if (primaryKey == "" && secondaryKey != "") // primary not given secondary given
	  {
		  return *this;
	  }
	  else if (primaryKey != "" && secondaryKey == "") // primary key given secondary not
	  {
		  if (searchprimary(this->root, primaryKey) != NULL)
		  {
			  if (searchprimary(this->root, primaryKey)->rootSecondaryNode != NULL)
			  {
				  cout << "{\"" << primaryKey << "\" : " << "{";
				  inordersecondary1(searchprimary(this->root, primaryKey)->rootSecondaryNode);
				  cout << "}" << "}" << endl;
			  }
			  else
			  {
				  cout << "{\"" << primaryKey << "\" : {}}" << endl;
			  }


		  }
		  else
			  cout << "{}" << endl;
	  }

	  else if (primaryKey != "" && secondaryKey != "") //primary and secondary both given
	  {
		  PrimaryNode *t1 = searchprimary(this->root, primaryKey);
		  SecondaryNode * t2 = NULL;
		  if (t1 != NULL)
		  {

			  t2= searchsecondary(t1->rootSecondaryNode, secondaryKey);



		  }

		  if (t1 != NULL && t2 != NULL)
		  {

			  //cout << "----" << endl;
			  /*primarynode *i1 = searchprimary(this->root, primarykey);
			  secondarynode *i2 = searchsecondary(i1->rootsecondarynode, secondarykey);*/

			  cout << "{\"" << t1->key << "\" : {" << "\"" << t2->key << "\" : " << "\"" << t2->data << "\""<<"}}"<<endl;
		  }
		  else
			  cout << "{}" << endl;
		  return *this;
	  }
	 /* else if (searchprimary(this->root, primarykey) == null)
	  {
		  cout << "{}" << endl;
		  return *this;

	  }
	  else if (searchprimary(this->root, primarykey) != null && searchprimary(this->root, primarykey)->rootsecondarynode == null)
	  {
		  cout << "{}" << endl;
		  return *this;
	  }*/





	return *this;

    /* IMPLEMENT THIS */
}

template <class T>
T *TwoPhaseBST<T>::find(const std::string &primaryKey, const std::string &secondaryKey) {
	PrimaryNode * t1 = searchprimary(root, primaryKey);
	SecondaryNode *t2 = NULL;
	if (t1 != NULL)
		t2 = searchsecondary(t1->rootSecondaryNode, secondaryKey);
	if (t1 == NULL || t2 == NULL)
		return NULL;
	else
		return &(t2->data);
    /* IMPLEMENT THIS */
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
template<typename T>
typename TwoPhaseBST<T>::PrimaryNode* TwoPhaseBST<T>::searchprimary(PrimaryNode * root,std::string key)
{
  if(root==NULL)
  return NULL;
  else if(key > root->key)
  {
    return searchprimary(root->right,key);
  }
  else if (key < root->key)
  {
    return searchprimary(root->left,key);
  }
  else
  return root;


}
template<typename T>
typename TwoPhaseBST<T>::SecondaryNode* TwoPhaseBST<T>::searchsecondary(SecondaryNode * root,std::string key)
{
  if(root==NULL)

		return NULL;

  else if(key > root->key)
  {
	  return searchsecondary(root->right, key);
  }
  else if(key < root->key)
  {
	  return searchsecondary(root->left, key);

  }

  else
    return root;



}

template<class T>
void TwoPhaseBST<T>::inorderprimary(PrimaryNode * root)
{
  using namespace std;
  if(root!=NULL)
  {
    inorderprimary(root->left);
    cout<<root->key<<endl;
    inorderprimary(root->right);
  }


}

template<class T>
void TwoPhaseBST<T>::inordersecondary1(SecondaryNode * root)
{
  using namespace std;
  //cout<<"in inordersecondary1 "<<endl;
  if(root==NULL)
  return;

inordersecondary1(root->left);
if(root->left!=NULL)
cout<<", ";
cout<<"\""<<root->key<<"\" "<<": "<<"\""<<root->data<<"\"";
if(root->right!=NULL)
cout<<", ";

inordersecondary1(root->right);


}
template<class T>
void TwoPhaseBST<T>::inorderprimarysecondary(PrimaryNode * p,PrimaryNode* max)
{
  using namespace std;
  if(p==NULL)
  return;
  inorderprimarysecondary(p->left,max);
  cout<<"\""<<p->key<<"\" : {";

  inordersecondary1(p->rootSecondaryNode);
  cout<<"}";
  if(p!=max)
  cout<<", ";

  inorderprimarysecondary(p->right,max);



}
template<typename T>
typename TwoPhaseBST<T>::SecondaryNode* TwoPhaseBST<T>::findmaxsecondary(SecondaryNode * rsecond)
{
  if(rsecond!=NULL)
  {
    return NULL;
  }
  while(rsecond->right!=NULL)
  {
    rsecond=rsecond->right;
  }
  return rsecond;

}
template<typename T>
typename TwoPhaseBST<T>::SecondaryNode* &TwoPhaseBST<T>::findminsecondary(SecondaryNode * &t)
{
	if (t->left == NULL)
	{
		return t;
	}
	else
		findminsecondary(t->left);


}

template<typename T>
void TwoPhaseBST<T>::insert2(const std::string &primaryKey, const std::string &secondaryKey, const T &data, TwoPhaseBST::PrimaryNode * &t)
{
	if (t == NULL)
	{
		TwoPhaseBST<T>::SecondaryNode *newsecond = new TwoPhaseBST<T>::SecondaryNode(secondaryKey, data, NULL, NULL);
		t=new TwoPhaseBST<T>::PrimaryNode(primaryKey,NULL,NULL,newsecond);
	}
	else if (primaryKey > t->key)
	{
		insert2(primaryKey, secondaryKey, data, t->right);
	}
	else if (primaryKey < t->key)
	{
		insert2(primaryKey, secondaryKey, data, t->left);
	}
	else
	{
		insert3(secondaryKey, data, t->rootSecondaryNode);

	}


}
template<typename T>
void TwoPhaseBST<T>::insert3(const std::string &secondaryKey, const T &data, TwoPhaseBST::SecondaryNode * &t)
{
	if (t == NULL)
	{
		t = new TwoPhaseBST<T>::SecondaryNode(secondaryKey, data, NULL, NULL);
	}
	else if (secondaryKey > t->key)
	{
		insert3(secondaryKey, data, t->right);
	}
	else if (secondaryKey < t->key)
	{
		insert3(secondaryKey, data, t->left);
	}
	else
	{


	}

}
template<typename T>
void TwoPhaseBST<T>::remove2(const std::string &secondaryKey, TwoPhaseBST::SecondaryNode * &t)
{
	using namespace std;
	if (t == NULL)return;
	if (secondaryKey < t->key) remove2(secondaryKey, t->left);
	else if (t->key < secondaryKey) remove2(secondaryKey, t->right);
	else if (t->left != NULL && t->right != NULL){
		//it has two children
  	SecondaryNode *&min = findminsecondary(t->right);
		SecondaryNode *old = t;
		SecondaryNode *old2 = min;

		min = min->right;
		old2->right = t->right;
		old2->left = t->left;
		t = old2;
		delete old;
	}
	else{
		SecondaryNode* old = t;
		t = (t->left != NULL) ? t->left : t->right;
		old->left = NULL;
		old->right = NULL;
		delete old;
	}
}






template<typename T>
typename TwoPhaseBST<T>::PrimaryNode* TwoPhaseBST<T>::findmaxprimary(PrimaryNode * t)
{
	if (t == NULL)
		return t;
	while (t ->right != NULL)
		t = t->right;
	return t;


}
#endif //TWOPHASEBST_H
