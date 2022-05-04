//============================================================================
// Name        : Queue_ArrayBased.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;


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

template <class Object>
class Queue{
private:
	Object *items;
	int front;
	int rear;
	int length;
	int capacity;

	void resize(int newcap){
		Object *temp=new Object[newcap];
		for (int var = 0; var < length; ++var) {
			temp[var]=items[(var+front)%capacity];
		}
		capacity=newcap;
		front=0;
		rear=length-1;
		delete[] items;
		items=temp;
	}

public:
	Queue(int capacity=1){
		this->capacity=capacity;
		items=new Object[capacity];
		front=0;
		rear=-1;
		length=0;
	}
	void enqueue(const Object &item){
		if (length==capacity) resize(2*capacity);
		rear=(rear+1)%capacity;//circular
		items[rear]=item;
		length++;
	}

	const Object &peek()const{
		if (length==0) throw EmptyQueueException();
		return items[front];
	}
	void dequeu(){
		if (length==0) throw EmptyQueueException();
		front=(front+1)%capacity;
		length--;
	}

	int size()const{
		return length;
	}

	bool empty(){
		return rear==-1;
	}
	~Queue(){//destructor
		delete[] items;
	}

	void print(){
		cout<<"\nQueue state:"<<endl;
		for (int var = front; var <=rear; ++var) {
			cout<<items[var]<<"|";
		}
		cout<<endl;
	}

};

int main() {
	Queue<int> *queue=new Queue<int>(1);
	for (int var = 1; var < 100; ++var) {
		queue->enqueue(var*5);
	}
	queue->print();

	/*
	queue->enqueue("apple orange");
	queue->enqueue("portakal");
	queue->enqueue("lemon");
	queue->enqueue("cherry");
	cout<<"length="<<queue->size()<<endl;
	queue->print();
	cout<<"queue->peek()="<<queue->peek()<<endl;
	cout<<"queue->dequeu();"<<endl;
	queue->dequeu();
	cout<<"length="<<queue->size()<<endl;
	queue->print();
	cout<<"queue->peek()="<<queue->peek()<<endl;
	cout<<"queue->dequeu();"<<endl;
	queue->dequeu();
	cout<<"length="<<queue->size()<<endl;
	cout<<"queue->peek()="<<queue->peek()<<endl;
	queue->print();
	queue->dequeu();
	cout<<"length="<<queue->size()<<endl;
	cout<<"queue->peek()="<<queue->peek()<<endl;
	*/
	return 0;
}
