//============================================================================
// Name        : w9_lab.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


template <class T> class Node {
public:
	T data;
	int priority;
	Node *next;
	Node(T data, int priority, Node *next = NULL) {
		this->data = data;
		this->next = next;
		this->priority=priority;
	}
};

class EmptyQueueException: public exception {
private:
	char *msj;
public:
	EmptyQueueException(char *msj = (char*) "Empty queue!") {
		this->msj = msj;
	}
	const char* what() const throw () {
		return msj;
	}
};


template <class T> class PriorityQueue{
private:

	Node<T> *head;
	int length;
public:

	PriorityQueue() {
		head = NULL;
		length=0;
	}

	const T &peek(){
		if (head==NULL) throw EmptyQueueException();
		return head->data;
	}

	void push(const T &data,int priority){
		Node <T> *que;
		que=head;
		Node <T> *node=new Node<T>(data,priority);
		if(head==NULL || priority>head->priority){
			node->next=head;
			head=node;
		}
		else{
			while(que->next!=NULL && que->next->priority > priority)
			que=que->next;
			node->next=que->next;
			que->next=node;

		}

	}

	void pop(){
		if (head==NULL) throw EmptyQueueException();
		else{
			Node<T> *temp=head;
			head=head->next;
			free(temp);
		}
	}

	bool empty(){
		return head==NULL;
	}
};


int main() {
	// Test priority queue
	PriorityQueue<string> pqueue;

	pqueue.push("item 1",10);
	pqueue.push("item 2",2);
	pqueue.push("item 3",5);
	pqueue.push("item 4",20);
	pqueue.push("item 5",1);
	pqueue.push("item 6",7);

	cout<<"priority queue content:"<<endl;
	while(!pqueue.empty()){
		cout<<" |"<<pqueue.peek();
		pqueue.pop();
	}
	cout<<"| "<<endl;
	return 0;
}
