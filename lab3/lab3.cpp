#include <iostream>
using namespace std;
#define MAX_SIZE 10
template <typename T>
class ArrayList //vector
{
private:
	T *Elements;
	int n;
	int capacity;

	void resize() { // increase the array size two times
		int newcap= capacity>0? 2 * capacity:1;
		T *Temp = new T[newcap];
		for (int i = 0; i < n; i++)
			Temp[i] = Elements[i];
		delete[] Elements; //delete the old array
		Elements = Temp; //use new array
		capacity = newcap;
		cout << "new capacity=" << capacity << endl;
	}
public:
	ArrayList(int capacity = MAX_SIZE) //constructor
	{
		this->capacity = capacity;
		Elements = new T[capacity]; //array on heap
		n = 0;
		cout << "constructor capacity=" << capacity << endl;
	}

	void add(T data) //push_back
	{
		if (n == capacity) { //is capacity full
			cout << "Capacity is full. Resizing the array" << endl;
			resize();
		}
		Elements[n] = data;
		n++;
	}

	void insert(int pos, T data) //throw (exception) before c++11
	{
		//check if the entered position is valid
		if (pos < 0 || pos >= n)
			throw exception();

		if (n == capacity) { //is capacity full
			cout << "Capacity is full. Resizing the array" << endl;
			resize();
		}

		//make room for the new element at "pos"
		for (int i = n - 1; i >= pos; i--)
			Elements[i + 1] = Elements[i];

		//write the new element
		Elements[pos] = data;
		//increase the number of elements
		n++;
	}

	void remove(int pos)
	{
		//check if the entered position is valid
		if (pos < 0 || pos >= n)
			throw exception();

		//reduce the number of elements
		n--;
		//shift all the elements to the left
		for (int i = pos; i < n; i++)
			Elements[i] = Elements[i + 1];
	}

	T get(int pos) //throw (exception)
	{
		if (pos < 0 || pos >= n) {
			throw exception();
		}
		return Elements[pos];
	}
	~ArrayList() //destructor
	{
		delete[] Elements;
		cout << "destructor worked" << endl;
	}

	void print() {
		cout << "--Elements:" << endl;
		for (int i = 0; i < n; i++)
			cout << "\t" << Elements[i];
		cout << endl;
	}

	void clear() {
		delete[] Elements;
		Elements = new T[capacity]; //array on heap
		n = 0;
	}

	 int  length() {
		return n;
	}
};

int main() {
	//set initial capacity to zero
	ArrayList<string> *list1 = new ArrayList<string>(0);
// add elements
list1->add("apple"); //0
list1->add("orange"); //1
list1->add("banana"); //2
list1->add("kiwi"); //3
list1->add("plum"); //4
list1->add("cherry"); //5
list1->print();
//insert an item to specified location
list1->insert(3, "blueberry");
//remove the item at 5
list1->remove(5);
list1->print();
//try catch block example
try {
cout << "list1->get(5)=" << list1->get(5) << endl;
// this should produce exception
cout << "list1->get(50)=" << list1->get(50) << endl;
} catch (exception &e) {
cout << e.what() << endl;
}
cout << "list1->length()=" << list1->length() << endl;
list1->clear();
return 0;

}

