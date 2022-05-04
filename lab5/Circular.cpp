//============================================================================
// Name        : CircularLinkedList.cpp
// Description : An example implementation for Circular Linked List
//============================================================================
#include <iostream>
using namespace std;

class IndexException: public exception {
private:
	char *msj;
public:
	IndexException(char *msj = (char*) "Index out of bounds!") {
		this->msj = msj;
	}
	const char* what() const throw () {
		return msj;
	}
};
class EmptyListException: public exception {
private:
	char *msj;
public:
	EmptyListException(char *msj = (char*) "Empty list!") {
		this->msj = msj;
	}
	const char* what() const throw () {
		return msj;
	}
};

template<typename T>
class Node {
private:
	T data;
	Node *next, *prev;
public:
	Node(const T &data, Node<T> *next = NULL, Node<T> *prev = NULL) {
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
	template<typename U> friend class CircularLinkedList;
};

template<typename T>
class CircularLinkedList {
private:
	Node<T> *head;
	int nItems; //number of items

	Node<T>* find_prev(int inx) {
		Node<T> *temp = head;
		int cnt = 0;
		while (temp->next != head) {
			if (cnt == inx - 1)
				break; //location found
			temp = temp->next;
			cnt++;
		}
		return temp;
	}

public:

	class ListIterator{
		private:
			Node<T> *current;
		public:
			ListIterator(Node<T> *current=NULL){
				this->current=current;
			}
			void next(){
				if (current==NULL) throw IndexException();
				current=current->next;
			}
			void prev(){
				if (current==NULL) throw IndexException();
					current=current->prev;
			}
			T& get()const{
				return current->data;
			}
			bool end(){
				return (current==NULL);
			}
	};

	CircularLinkedList() {
		head = NULL;
		nItems = 0;
	}

	bool isEmpty() {
		return head == NULL;
	}
	ListIterator begin() const {
			if (head == NULL)
				EmptyListException();
			return ListIterator(head);
	}
	ListIterator end() const {
				if (head == NULL)
					EmptyListException();
				return ListIterator(head->prev);
	}

	T& at(int inx) {
		if ((inx < 0) | (inx >= nItems))
			throw IndexException();
		if (nItems == 1)
			return head->data;
		else {
			Node<T> *temp = find_prev(inx + 1);
			return temp->data;
		}
	}

	void push_front(const T &data) {
	Node<T> *newNode = new Node<T>(data);	
	newNode->next = NULL;
  	newNode->prev = NULL; 	
	 if(head == NULL) {
    head = newNode;
    newNode->next = head;
    newNode->prev = head;
   }
   else {
    Node<T>* temp = head;
    while(temp->next != head)
	  temp = temp->next;
     temp->next = newNode;
    newNode->next = head;
    newNode->prev = temp;
    head->prev = newNode;
	head=newNode;
  }       
			}

	void push_back(const T &data) {
		Node<T> *newNode = new Node<T>(data);
		newNode->next=NULL;
		newNode->prev=NULL;
		if(head==NULL){
			head = newNode;
    		newNode->next = head;
  		    newNode->prev = head;
		}
		else{
			 Node<T>* temp = head;
    		while(temp->next != head)
    		temp = temp->next;
			temp->next = newNode;
   			newNode->next = head;
   		    newNode->prev = temp;
   			head->prev = newNode;
		}

		
		
	}

	void insert(int inx, const T &data) {
		if ((inx < 0) | (inx > nItems))
			throw IndexException();
		if (inx == 0)
			push_front(data);
		else if (inx == nItems)
			push_back(data);
		else {
			Node<T> *node = new Node<T>(data);
			Node<T> *temp = find_prev(inx);

			node->next = temp->next;
			temp->next->prev = node;
			temp->next = node;
			node->prev = temp;
			nItems++;
		}

	}

	void remove(int inx) {
		if ((inx < 0) | (inx >= nItems))
			throw IndexException();
		if (head == NULL)
			throw EmptyListException();
		Node<T> *rem;
		if (inx == 0) {
			rem = head;
			head = head->next;
			if (head != NULL)
				head->prev = rem->prev;
			//head->prev = NULL;
		} else {
			Node<T> *rem;
			Node<T> *temp = find_prev(inx);
			rem = temp->next;
			temp->next = rem->next;
			rem->next->prev = temp;
		}
		delete rem;
		nItems--;
	}

	int length() {
		return nItems;
	}

	friend ostream& operator<<(ostream &out, CircularLinkedList<T> &list) {
		cout << "--list items---------" << endl;
		for (int i = 0; i < list.length(); i++) {
			out << list.at(i) << " ";
		}
		out << endl;
		return out;
	}

};

template<typename T>
void print(CircularLinkedList<T> &list) {
	cout << "--list items---------" << endl;
	for (int i = 0; i < list.length(); i++) {
		cout << list.at(i) << endl;
	}
}

int main(int argc, char **argv) {
	CircularLinkedList<string> list;
	list.push_front("apple");
	list.push_back("orange");
	list.push_back("blueberry");
	list.push_front("cherry");
	cout << "--list items---------" << endl;
	cout<<"cherry apple orange blueberry"<<endl;

	cout<<"--forward print using iterator:"<<endl;
	CircularLinkedList<string>::ListIterator itr=list.begin();
	for (int i=0;i<10;i++){
		cout<<itr.get()<<" ";
		itr.next();
	}
	cout<<endl;
	cout<<"--backward print using iterator:"<<endl;
	itr=list.end();
	for (int i=0;i<10;i++){
			cout<<itr.get()<<" ";
			itr.prev();
	}
	cout<<endl;
	return 0;
}

