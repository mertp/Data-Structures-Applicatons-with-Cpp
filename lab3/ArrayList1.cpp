
#include <iostream>
using namespace std;
#define MAX_SIZE 10


class ArrayList //vector
{
private:
	int *Elements;
	int n;
	int capacity;

	void resize() { // increase the array size two times
		int newcap= capacity>0? 2 * capacity:1;
		int *Temp = new int[newcap];
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
		Elements = new int[capacity]; //array on heap
		n = 0;
		cout << "constructor capacity=" << capacity << endl;
	}

	void add(int data) //push_back
	{
		if (n == capacity) { //is capacity full
			cout << "Capacity is full. Resizing the array" << endl;
			resize();
		}
		Elements[n] = data;
		n++;
	}

	void insert(int pos, int data) //throw (exception) before c++11
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

	int get(int pos) //throw (exception)
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
		Elements = new int[capacity]; //array on heap
		n = 0;
	}

	int length() {
		return n;
	}
};

int main() {
	//set initial capacity to zero
	ArrayList *list1 = new ArrayList(0);

	// add elements
	list1->add(10);  //0
	list1->add(15); //1
	list1->add(12); //2
	list1->add(11);   //3
	list1->add(17);   //4
	list1->add(13); //5
	list1->print();

	//insert an item to specified location
	list1->insert(3, 25);
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

