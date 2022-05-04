#include <iostream>
using namespace std;
template <class T>
class Node {
    public:
    
	T data;
	Node<T> *next;
	Node(T data, Node *next = NULL) {
		this->data = data;
		this->next = next;
	}
};
template <class T>
class SinglyLinkedList {
private:
	Node<T> *head;
public:
	SinglyLinkedList() {
		head = NULL;
	}
		
		SinglyLinkedList(const SinglyLinkedList<T>&  list) {
		    head = NULL;
		    for(int i=0;i<list.length();++i){
		        push_back(list.at(i));
		    }
	
	}




	Node<T>* find_prev(int inx) const{
		Node<T> *temp = head;
		int cnt = 0;
		while (temp->next != NULL) {
			if (cnt == inx - 1)
				break; //location found
			temp = temp->next;
			cnt++;
		}
		return temp;
	}

	T &at(int inx)const{
		if (inx < 0 || inx >= length())
						throw exception();
		if (inx==0){
			return head->data;
		}
		else{
			Node<T> *temp = find_prev(inx+1);
			return temp->data;
		}

	}

	void remove(int inx){
		if (inx < 0 || inx >= length())
				throw exception();
		Node<T> * temp=head;
		if (inx==0){
			head=head->next;
			delete temp;
		}
		else{
			Node<T> *temp = find_prev(inx);
			Node<T> *removenode=temp->next;
			temp->next=removenode->next;
			delete removenode;
		}
	}

	void insert(int inx, const T &data) {

		if (inx < 0 || inx > length())
			throw exception();

		if (inx == 0) {
			push_front(data);
		} else {
			Node<T> *node = new Node<T>(data);
			Node<T> *temp = find_prev(inx);
			node->next = temp->next;
			temp->next = node;
		}
	}

	void push_front(const T &data) {
		Node<T> *node = new Node<T>(data);
		if (head == NULL) { //if (head==0){
			head = node;
		} else {
			node->next = head;
			head = node;
		}

	}

	void push_back(const T &data) {
		Node<T> *node = new Node<T>(data);
		if (head == NULL) { //if (head==0){
			head = node;
		} else {
			Node<T> *temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = node;
		}
	}


	void clear(){
		Node<T> *temp=head;
		Node<T> *delnode;

		while(temp!=NULL){
			delnode=temp;
			temp=temp->next;
			delete delnode;
		}
		head=NULL;
	}

	~SinglyLinkedList() { //destructor
		//delete nodes
		clear();
	}

	int length()const{
		int cnt = 0;
		Node<T> *temp = head;
		while (temp != NULL) {
			cnt++;
			temp = temp->next;
		}
		return cnt;
	}

	void print() {
		cout << "list elements:" << endl;
		Node<T> *temp = head;
		while (temp != NULL) {
			cout << "\t " << temp->data;
			temp = temp->next;
		}
		cout << endl;
	}

};

int main() {
	//define a singly linked list
	SinglyLinkedList<string> list1;
    
    list1.push_back("banana");
    list1.push_back("orange");
    list1.push_back("kiwi");
    list1.push_back("apple");
    list1.print();
    
   
    SinglyLinkedList<string>list2(list1);
    
    
    list2.print();
    list2.push_front("22");
    list1.print();
    list2.print();
    
	return 0;
}