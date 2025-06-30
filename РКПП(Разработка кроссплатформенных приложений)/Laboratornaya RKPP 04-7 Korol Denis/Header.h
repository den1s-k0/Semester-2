#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include <istream>
#include <sstream> 


using namespace std;

struct internet_service;

template<typename T>
class Dlist {
public:
	Dlist();
	~Dlist();

	void push_back(T data);
	void push_head(T data);
	void push_ind(T data, const int index);
	void pop_head();
	void pop_back();
	void pop_ind(const int index);
	void clear();
	int Get_Size() { return Size; }
	T& operator[](const int index);
	void print();
	void fread(const string& path);
	void list_sort();



private:

	template<typename T>
	class Node {
	public:
		Node* pprev;
		Node* pnext;
		T data;
		Node(T data = T(), Node* pprev = nullptr, Node* pnext = nullptr) {
			this->data = data;
			this->pnext = pnext;
			this->pprev = pprev;
		}
	};
	Node<T>* head;
	Node<T>* back;
	int Size;

	void swap_node(Node<T>* A, Node<T>* B) {
		if (A == B) return;

		if (head == A) head = B;
		else if (head == B) head = A;
		if (back == A) back = B;
		else if (back == B) back = A;

		if (A->pnext == B) {
			Node<T>* prevA = A->pprev;
			Node<T>* nextB = B->pnext;

			if (prevA) prevA->pnext = B;
			B->pprev = prevA;
			B->pnext = A;
			A->pprev = B;
			A->pnext = nextB;
			if (nextB) nextB->pprev = A;
		}
		else if (B->pnext == A) {
			Node<T>* prevB = B->pprev;
			Node<T>* nextA = A->pnext;

			if (prevB) prevB->pnext = A;
			A->pprev = prevB;
			A->pnext = B;
			B->pprev = A;
			B->pnext = nextA;
			if (nextA) nextA->pprev = B;
		}
		else {
			Node<T>* prevA = A->pprev;
			Node<T>* nextA = A->pnext;
			Node<T>* prevB = B->pprev;
			Node<T>* nextB = B->pnext;

			if (prevA) prevA->pnext = B;
			B->pprev = prevA;
			B->pnext = nextA;
			if (nextA) nextA->pprev = B;

			if (prevB) prevB->pnext = A;
			A->pprev = prevB;
			A->pnext = nextB;
			if (nextB) nextB->pprev = A;
		}
	}
};

template<typename T>
Dlist<T>::Dlist() {
	Size = 0;
	head = nullptr;
	back = nullptr;
}

template<typename T>
Dlist<T>::~Dlist() {
	Node<T>* current = head;
	while (current != nullptr) {
		Node<T>* next = current->pnext;
		delete current;
		current = next;
	}
}

template<typename T>
void Dlist<T>::push_back(T data)
{
	if (back == nullptr) {
		head = new Node<T>(data);
		back = head;
	}
	else {
		back->pnext = new Node<T>(data, back);
		back = back->pnext;
	}
	Size++;
}

template<typename T>
void Dlist<T>::push_head(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
		back = head;
	}
	else {
		head->pprev = new Node<T>(data, nullptr, head);
		head = head->pprev;
	}
	Size++;
}

template<typename T>
void Dlist<T>::push_ind(T data, const int index)
{
	if (index < 0 || index > Size) {
		throw std::out_of_range("Index out of range");
	}
	if (index == 0) (*this).push_head(data);
	else
		if (index == Size) (*this).push_back(data);
		else
			if (index + 1 <= Size / 2) {
			Node<T>* current = head;
			for (int i = 0; i < index - 1; i++) {
				current = current->pnext;
			}
			Node<T>* current2;
			current2 = new Node<T>(data, current, current->pnext);
			current->pnext = current2;
			current2->pnext->pprev = current2;
			Size++;
			}
			else {
			Node<T>* current = back;
			for (int i = Size - 1; i > index; i--) {
				current = current->pprev;
			}
			Node<T>* current2;
			current2 = new Node<T>(data, current->pprev, current);
			current->pprev = current2;
			current2->pprev->pnext = current2;
			Size++;
			}
}

template<typename T>
void Dlist<T>::pop_head()
{
	if (head != nullptr) {
		head = head->pnext;
		Size--;
		if (head != nullptr) {
			delete head->pprev;
			head->pprev = nullptr;
		}
	}
	else {
		cout << "Error\n";
		system("pause");
	}
}

template<typename T>
void Dlist<T>::pop_back()
{
	if (back != nullptr) {
		back = back->pprev;
		Size--;
		if (back != nullptr) {
			delete back->pnext;
			back->pnext = nullptr;
		}
	}
	else {
		cout << "Error\n";
		system("pause");
	}
}

template<typename T>
void Dlist<T>::pop_ind(const int index)
{
	if (index < 0 || index >= Size) {
		throw std::out_of_range("Index out of range");
	}
	if (index == 0) pop_head();
	else
		if (index == Size - 1) pop_back();
		else
			if (index + 1 <= Size / 2) {
				Node<T>* current = head;
				for (int i = 0; i < index; i++) {
					current = current->pnext;
				}
				current->pnext->pprev = current->pprev;
				current->pprev->pnext = current->pnext;
				delete current;
				Size--;
			}
			else {
				Node<T>* current = back;
				for (int i = Size - 1; i > index; i--) {
					current = current->pprev;
				}
				current->pnext->pprev = current->pprev;
				current->pprev->pnext = current->pnext;
				delete current;
				Size--;
			}
}

template<typename T>
void Dlist<T>::clear()
{
	while (Size) {
		pop_head();
	}
}

template<typename T>
T& Dlist<T>::operator[](const int index)
{
	if (index < 0 || index >= Size) {
		throw std::out_of_range("Index out of range");
	}

	if (index <= Size / 2) {
		Node<T>* current = head;
		for (int i = 0; i < index; ++i) {
			current = current->pnext;
		}
		return current->data;
	}
	else {
		Node<T>* current = back;
		for (int i = Size - 1; i > index; --i) {
			current = current->pprev;
		}
		return current->data;
	}
}

template<typename T>
void Dlist<T>::print()
{
	cout << "Size-> " << Size << endl;
	for (int i = 0; i < Size; i++){
		cout << i + 1 << "-> " << (*this)[i] << endl;
	}
}

template<typename T>
void Dlist<T>::list_sort() {
	if (Size < 2) return;

	bool swapped;
	Node<T>* lastUnsorted = nullptr;

	do {
		swapped = false;
		Node<T>* current = head;

		while (current->pnext != lastUnsorted) {
			if (current->data > current->pnext->data) {
				Node<T>* next = current->pnext;
				swap_node(current, next);
				swapped = true;

				if (current == head) {
					head = next;    
					current = next;  
				}
			}
			else {
				current = current->pnext;
			}
		}
		lastUnsorted = current;
	} while (swapped);
}

struct internet_service {
private:
	int Indef;
	string Name;
	double Time;
public:
	internet_service(int ind = 0, string name = "-", double time = 0) : Indef(ind), Name(name), Time(time) {}
	~internet_service() {}
	bool operator > (const internet_service& elem) const {	return (Indef > elem.Indef);	}
	bool operator < (const internet_service& elem) const { return (Indef < elem.Indef); }
	friend istream& operator >> (istream& is, internet_service& elem);
	friend ostream& operator << (ostream& os, const internet_service elem);
};

template<typename T>
void fwrite(const string& path, const T& text) {
	ofstream out;
	out.open(path, ofstream::app);

	if (!out.is_open()) {
		throw runtime_error("Cannot open file: " + path);
	}
	else {
		out << text;
	}
	out.close();
}

void Dlist<internet_service>::fread(const string& path);

