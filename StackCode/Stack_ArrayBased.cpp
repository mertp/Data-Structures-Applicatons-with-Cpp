
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
class Stack{
	private:
		T *Items;
		int stack_top;
		int capacity;

		void resize(int N)
		{
			 T *temp = new T[N];
			 for(int j=0;j<=stack_top;j++)
				 temp[j]= Items[j];
			 if(Items != NULL) delete [] Items;
			 Items = temp;
			 capacity = N;
		}
	public:
		Stack(){
			Items=NULL;
			stack_top=-1;
			capacity=0;
		}
		bool empty() const{
			return stack_top == -1;
		}
		void push(const T &eleman){
			if(stack_top+1 == capacity){
				resize(max(1,2*capacity));
			}
			stack_top++;
			Items[stack_top] = eleman;
		}
		void pop(){
			if(empty()) throw EmptyStackException();
			stack_top--;
		}
		const T& top()const{
			if(empty()) throw EmptyStackException();
			return Items[stack_top];
		}
		void clear(){
			stack_top=-1;
		}

		int size(){
			return stack_top+1;
		}
		~Stack(){
			if(Items != NULL) delete [] Items;
			Items=NULL;
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
