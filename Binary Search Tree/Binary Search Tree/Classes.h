#pragma once
#include <string>
#include <iostream>

using namespace std;

template<typename T>
class Node
{
public:
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


	}


	void Delete(Node<T>* N)
	{

	}


	void Delete(T data) {

	}

	Node<T>* Find(T data) {

	}

	void Traverse() {

	}
}
