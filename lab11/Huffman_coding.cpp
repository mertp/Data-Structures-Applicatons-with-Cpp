//============================================================================
// Name        : w11_lab.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

// C++(STL) program for Huffman Coding with STL
#include <bits/stdc++.h>

// A Huffman tree node
class MinHeapNode {
public:
	// One of the input characters
	char data;
	// Frequency of the character
	unsigned freq;
	// Left and right child
	MinHeapNode *left, *right;
	MinHeapNode(unsigned char data, unsigned freq) {
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

// For comparison of
// two heap nodes (needed in min heap)
class compare {
public:
	bool operator()(MinHeapNode *left, MinHeapNode *right)
	{
		return (left->freq > right->freq);
	}
};

// Prints huffman codes from
// the root of Huffman Tree.
void printCodes(MinHeapNode *root, string str) {

	if (!root)
		return; //if your node is null then stop printing

	if (root->data != '$')
		cout << root->data << ": " << str << "\n";

	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size) {
	MinHeapNode *left, *right, *top;

	// Create a min heap & inserts all characters of data[]
	priority_queue< MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
	//https://en.cppreference.com/w/cpp/container/priority_queue

	for (int i = 0; i < size; ++i){
		MinHeapNode *node=new MinHeapNode(data[i], freq[i]);
		minHeap.push(node);
	}


	// Iterate while size of heap doesn't become 1
	while (minHeap.size() != 1) {

		// Extract the two minimum
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		//Create a new internal node with frequency equal to the sum of the two nodes frequencies.
		//Make the two extracted node as left and right children of this new node.
		top = new MinHeapNode('$', left->freq + right->freq);

		top->left = left;
		top->right = right;

		minHeap.push(top);
	}

	// Print Huffman codes using the Huffman tree built above
	printCodes(minHeap.top(), "");
}

string readFile(string path){
	string lines;
	ifstream file(path.c_str());
	if (file.is_open())
	{
		while (getline(file,lines))
		{
			lines+=lines;
			lines+='\n';
		}
		file.close();
	}
	else throw "File could not be opened";
	return lines;
}
void computeFrequencies(char *&arr,int *&freq,int &size,string path){
	string lines=readFile(path);
	char characters[lines.size()-1];
	int frequencies[256];
	strcpy(characters, lines.c_str());
	for(int i=0;i<characters.size();i++){
		freq[characters[i]-'a']++;
	}
	 for (int i = 0; i < n; i++) {

        // if frequency of character str[i] is not
        // equal to 0
        if (freq[characters[i] - 'a'] != 0) {

            // print the character along with its
            // frequency
            cout << characters[i] << freq[characters[i] - 'a'] << " ";

            // update frequency of str[i] to 0 so
            // that the same character is not printed
            // again
            freq[characters[i] - 'a'] = 0;
        }
    }
}

}

int main() {
    char *arr;
    int *freq;
    int size;
	//compute frequencies
    computeFrequencies(arr,freq,size,"C:\Users\MertPc\Desktop\Lab Applications\lab\test.txt");
    cout<<"found characters and their frequencies:"<<endl;
    for (int i=0;i<size;i++)
		cout<<arr[i]<<": "<<freq[i]<<endl;

    cout<<"\ncompute Huffman code:"<<endl;
	HuffmanCodes(arr, freq, size);

	return 0;
}
