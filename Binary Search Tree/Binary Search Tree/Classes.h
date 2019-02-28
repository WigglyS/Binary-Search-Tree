#pragma once
#include <string>
#include <iostream>

using namespace std;

template<typename T>
class Node
{
public:
	Node(T newData) { data = newData; }
	Node* GetLeft() { return Left; }
	void SetLeft(Node* prev) { Left = prev; }
	Node* GetRight() { return Right; }
	void SetRight(Node* next) { Right = next; }

	T Getdata() { return data; };
	void SetData(T d) { data = d; };
private:
	Node* Left = nullptr;
	Node* Right = nullptr;
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
				pointer->SetRight(new Node<T>(data));
				return;
			}
			else {

				RecursiveInsert(pointer->GetRight());
			}

		}
		else if (data < pointer->GetData()) {
			if (pointer->GetLeft() == NULL) {
				pointer->SetLeft(new Node<T>(data));
				return;
			}
			else
			{
				RecursiveInsert(pointer->GetLeft());
			}
		}
	
	}


	void Delete(Node<T>* N)
	{

	}


	void Delete(T data) {

	}

	Node<T>* Find(T data) {

	}

	void Traverse() {
		//recursively call left and right for all the nodes
	}

	Node<T>* Maximum(Node<T>* startingPoint)
	{
		//search for the farthest node to the right 
	}
	Node<T>* Minimum(Node<T>* startingPoint)
	{

	}
};
