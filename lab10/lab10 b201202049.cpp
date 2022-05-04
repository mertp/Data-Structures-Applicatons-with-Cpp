//============================================================================
// Name        : w10_lab.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <cmath>
using namespace std;

class NotFoundException: public exception {
private:
	char *msj;
/*public:char EmptyQueueException(char *msj = (char*) "Element not in the BST!") {
		this->msj = msj;
	}
	const char* what() const throw () {
		return msj;
	}*/
};

template<class T>
class Node {
public:
	T data;
	Node *left, *right;
	Node(const T &data, Node *left = NULL, Node *right = NULL) {
		this->data = data;
		this->right = right;
		this->left = left;
	}
};

class Customer {
private:
	string name;
	int id;
public:
	Customer() {
		name = "not assigned";
		id = 0;
	}
	Customer(string name, int id) {
		this->name = name;
		this->id = id;
	}
	friend bool operator>(const Customer &c1, const Customer &c2) {
		return c1.id > c2.id;
	}

	friend bool operator<(const Customer &c1, const Customer &c2) {
		return c1.id < c2.id;
	}
	friend bool operator==(const Customer &c1, const Customer &c2) {
			return c1.id == c2.id;
	}
	friend ostream& operator<<(ostream& out, Customer &cus){
		string str = " name:" + cus.name + " id:" + to_string(cus.id) ;
		out<<str<<" ";
		return out;
	}
	string get_details() const {
		string str = "name=" + name + " id=" + to_string(id);
		return str;
	}
};

template<class T> class BST {
private:
	Node<T> *root;
	int count;
	void addnode(Node<T> *&node, const T &data) {
		if (node == NULL)
			node = new Node<T>(data);
		else if (data < node->data) {
			addnode(node->left, data);
		} else if (data > node->data) {
			addnode(node->right, data);
		} else
			return; //equal. The key already exist
	}
	Node<T>*& findnode(Node<T> *&node, const T &data) {
		if (node == NULL)
			throw NotFoundException();
		if (data == node->data) {
			return node;
		} else if (data < node->data) {
			findnode(node->left, data);
		} else //(data > node->data)
		{
			findnode(node->right, data);
		}
	}

	void levelorder(Node<T> *node, int level) const {
		if (node == NULL)
			return;
		if (level == 0)
			cout<<node->data<<" ";
		else {
			levelorder(node->left, level - 1);
			levelorder(node->right, level - 1);
		}
		//cout<<endl;
	}

public:
	BST() {
		root = NULL;
		count = 0;
	}

	bool empty() {
		return root == NULL;
	}
	void add(const T &data) {
		addnode(root, data);
		count++;
	}

	void remove(const T &data) {
		//find the node to be removed
		Node<T> *&node = findnode(root, data);
		//make connections
		Node<T> *temp = node;

		if (node->left == NULL) //one child case
			node = node->right;
		else if (node->right == NULL) //one child case
			node = node->left;
		else { //two child case
			   //find largest element of left subtree
			temp = node->left;
			Node<T> *parentnode = node;
			while (temp->right != NULL) { //find the rightmost element
				parentnode = temp;
				temp = temp->right;
			}
			//replace the data of the node to be removed
			node->data = temp->data;
			if (parentnode == node)
				node->left = temp->left;
			else
				parentnode->right = temp->left; //rightmost node may have a subtree on the left
		}
		delete temp;

		count--;
	}

	int height(Node<T> *node) const {
		if (node == NULL)
			return -1;
		return 1 + max(height(node->left), height(node->right));
	}
	void clear() {
		while (root != NULL)
			remove(root->data);
	}

	int size() {
		return count;
	}
	void print() {
		int h = height(root);
		for (int level = 0; level <= h; level++) {
			levelorder(root, level);
			cout << endl;
		}
	}
	
		//implement below functions
	T findMin() {
	    Node<T> *temp = root;
		while(temp->left!=NULL){
			temp=temp->left;
		}
		return temp->data;
		
	}

	T findMax() {
	     Node<T> *temp = root;
		while(temp->right!=NULL){
		    temp=temp->right;
		}
		return temp->data;
		
	
	}


	~BST() {
		clear();
	}

};

int main() {

	BST<Customer> bst;
	bst.add(Customer("Ahmet", 4231));
	bst.add(Customer("Ayse", 2243));
	bst.add(Customer("Can",8237));
	bst.add(Customer("Canan",3421));
	bst.add(Customer("Hasan",6781));
	bst.add(Customer("John",1502));
	bst.add(Customer("Sam",1898));
	
	bst.print();

	cout<<"\nfindMin() and findMax() application:"<<endl;
	cout << "findMin()=" << bst.findMin().get_details() << endl;
	cout << "findMax()=" << bst.findMax().get_details()<< endl;

	return 0;
}

