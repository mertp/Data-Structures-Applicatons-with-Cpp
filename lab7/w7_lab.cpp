//============================================================================
// Name        : w7_lab.cpp
// Description : Laboratory application
//============================================================================

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Customer {
private:
	string name;
	string id;
	int points;
public:
	Customer() {
		name = "not assigned";
		id = "not assigned";
		points = 0;
	}
	Customer(string name, string id, int points) {
		this->name = name;
		this->id = id;
		this->points = points;
	}
	string get_details() const {
		string str = "name=" + name + " id=" + id + " points="
				+ to_string(points);
		return str;
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

template<typename T>
class Node {
public:
	T item;
	Node<T> *next;
	Node(const T &item, Node<T> *next = NULL) {
		this->item = item;
		this->next = next;
	}
};

template<typename T>
class Queue {
private:
	Node<T> *front;
	Node<T> *back;
	int count;

public:
	Queue() {
		front = back = NULL;
		count = 0;
	}

	int size() const {
		return count;
	}

	//return the item at the front of the queue
	const T& peek() const {
		if (count == 0)
			throw EmptyQueueException();
		return front->item;
	}

	void enqueue(const T &item) { //add an item to queue
		Node<T> *last = new Node<T>(item);
		if (count == 0)
			front = back = last;
		else {
			back->next = last;
			back = last;
		}
		count++;
	}
	void dequeue() { //remove
		if (count == 0)
			throw EmptyQueueException();
		Node<T> *del_front = front;
		front = front->next;
		delete del_front;
		count--;
	}

	void clear() {
		while (count != 0)
			dequeue();
	}
	bool empty() const {
		if (count == 0)
			return true;
		return false;
	}
	//reverse queue using queue from C++ STL
	void reverse(Queue<T>&Queue) {
		stack<Customer> Stack;
		while(!Queue.empty()){
			Stack.push(Queue.peek());
			Queue.dequeue();	
		}
		while(!Stack.empty()){
			Queue.enqueue(Stack.top());
			Stack.pop();
		}
		
	}

	~Queue() {
		clear();
	}
};

int main() {
	Queue<Customer> queue;
	queue.enqueue(Customer("Ahmet", "A1261", 71));
	queue.enqueue(Customer("Ayşe", "A2243", 100));
	queue.enqueue(Customer("Can", "A8237", 39));
	queue.enqueue(Customer("Canan", "A4862", 55));

	cout << "print and dequeu:" << endl;
	while (!queue.empty()) {
		cout << queue.peek().get_details() << endl;
		queue.dequeue();
	}

	// add the same elements to queue
	queue.enqueue(Customer("Ahmet", "A1261", 71));
	queue.enqueue(Customer("Ayşe", "A2243", 100));
	queue.enqueue(Customer("Can", "A8237", 39));
	queue.enqueue(Customer("Canan", "A4862", 55));

	//reverse the queue
	queue.reverse(queue);

	cout << "\nReversed queue. Print and dequeue:" << endl;
	while (!queue.empty()) {
		cout << queue.peek().get_details() << endl;
		queue.dequeue();
	}

	return 0;
}
