#include <iostream>
using namespace std;

class EmptyStackException: public exception {
private:
	char *msj;
public:
	EmptyStackException(char *msj = (char*) "Empty stack!") {
		this->msj = msj;
	}
	const char* what() const throw () {
		return msj;
	}
};

template <typename T>
class Node{
	public:
		T item;
		Node<T> *next;
		Node(const T& item,Node *next=NULL){
			this->item=item;
			this->next=next;
		}
};


template <typename T>
class Stack{
	private:
		Node<T> *stack_top;//head
		int count;
	public:
		Stack(){
			stack_top=NULL;
			count=0;
		}
		bool empty() const{
			return stack_top == NULL;
		}
		void push(const T& item){
			Node<T> *temp = new Node<T>(item);
			temp->next=stack_top;
			stack_top=temp;
			//Below is a more concise equivalent code:
			//stack_top = new Node<T>(item,stack_top);
			count++;
		}
		void pop(){
			if(stack_top == NULL) throw EmptyStackException();
			Node<T> *del_top = stack_top;
			stack_top = stack_top->next;
			count--;
			delete del_top;
		}
		const T& top() const{
			if(stack_top == NULL) throw EmptyStackException();
			return stack_top->item;
		}
		void clear(){
			while(!(stack_top == NULL))
				pop();
		}

		int size(){
			return count;
		}
		~Stack(){//destructor
			clear();
		}
};

int main() {
	cout << "An example stack usage" << endl; // prints hello earth

	Stack<string> stack;
	stack.push("orange");
	stack.push("lemon");
	stack.push("grapefruit");
	stack.push("lime");

	cout<<"print and pop the stack top:"<<endl;
	while(!stack.empty()){
		cout<<"stack.top()="<<stack.top()<<endl;
		stack.pop();
	}


	try {
		stack.pop();
	} catch (EmptyStackException &e) {
		cout<<"EmptyStackException "<<endl;
	} catch (exception &e) {
		cout<<"exception "<<endl;
	}

	return 0;
}
