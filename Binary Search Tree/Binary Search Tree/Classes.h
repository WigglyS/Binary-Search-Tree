#pragma once
#include <string>
#include <iostream>

using namespace std;

template<typename T>
class Node
{
public:
	Node(T newData) { data = newData; }
	Node<T>* GetLeft() { return Left; }
	void SetLeft(Node<T>* left) { Left = left; }
	Node<T>* GetRight() { return Right; }
	void SetRight(Node<T>* right) { Right = right; }
	Node<T>* GetParent() { return Parent; }
	void SetParent(Node<T>* parent) { Parent = parent; }

	T Getdata() { return data; };
	void SetData(T d) { data = d; };
private:
	Node<T>* Left = nullptr;
	Node<T>* Right = nullptr;
	Node<T>* Parent = nullptr;
	T data;
};

template<typename T> 
class BinarySearchTree
{
private:
	Node<T>* Root = nullptr;

public:

	void Insert(T data)
	{
		if (Root == NULL) {
			Root = new Node<T>(data);
			return;
		}
		else {
			Node<T>* temp = Root;
			RecursiveInsert(temp);
		}
	}

	void RecursiveInsert(Node<T>* pointer, T data) {
		
		if (data == pointer->Getdata()) {
			cout << "data already exists" << endl;
			return;
		}
		if (data > pointer->GetData()) {
			if (pointer->GetRight() == NULL) {
				Node<T>* temp = new Node<T>(data);
				pointer->SetRight(temp);
				temp->SetParent(pointer);
				return;
			}
			else {

				RecursiveInsert(pointer->GetRight(), data);
			}

		}
		else if (data < pointer->GetData()) {
			if (pointer->GetLeft() == NULL) {
				Node<T>* temp = new Node<T>(data);
				pointer->SetLeft(temp);
				temp->SetParent(pointer);
				return;
			}
			else
			{
				RecursiveInsert(pointer->GetLeft(), data);
			}
		}
	
	}


	void Delete(Node<T>* N)
	{

	}


	void Delete(T data) {

	}

	Node<T>* Find(T data) {
		if (Root == nullptr) {
			cout << "There is no data in the List" << endl;
			return nullptr;
		}
		Node<T>* SearchPointer = Root;
		return RecusiveFind(SearchPointer, data);
	}

	Node<T>* RecusiveFind(Node<T>* SearchPointer, T data) {
		if (data == SearchPointer->Getdata()) {
			return SearchPointer;
		}
		if (data > SearchPointer->Getdata()) {
			if (SearchPointer->GetRight() == nullptr) {
				cout << "That value is not search tree" << endl;
				return nullptr;
			}
			else {
				RecusriveFind(SearchPointer->GetRight(), data);
			}
		}
		if (data < SearchPointer->Getdata()) {
			if (SearchPointer->GetLeft() == nullptr) {
				cout << "That value is not search tree" << endl;
				return nullptr;
			}
			else {
				RecursiveFind(SearchPointer->GetLeft(), data);
			}
		}
	}



	void Traverse() {
		//recursively call left and right for all the nodes
	}

	Node<T>* Maximum(Node<T>* startingPoint)
	{
		//search for the farthest node to the right 
		Node<T>* IterativePointer;
		while (IterativePointer->GetRight() != nullptr) {
			IterativePointer = IterativePointer->GetRight();
		}
		return IterativePointer;	
	}
	Node<T>* Minimum(Node<T>* startingPoint)
	{
		//search for the farthest node to the left
		Node<T>* IterativePointer;
		while (IterativePointer->GetLeft() != nullptr) {
			IterativePointer = IterativePointer->GetLeft();
		}
		return IterativePointer;
	}
};
