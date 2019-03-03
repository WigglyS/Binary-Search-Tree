#pragma once
#include <string>
#include <iostream>

using namespace std;

template<typename T>
class Node
{
public:
	Node(T newData) { data = newData; }
	void SetLeft(Node<T>* left) { Left = left; }

	Node<T>* GetLeft() { return Left; }
	void SetRight(Node<T>* right) { Right = right; }
	Node<T>* GetRight() { return Right; }
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
	const int DisplaySpace = 3;
public:

	void Insert(T data)
	{
		
		if (Root == nullptr) {
			Root = new Node<T>(data);
			return;
		}
		else {
			Node<T>* temp = Root;
			RecursiveInsert(temp,data);
		}
	}

	//only used by the insert funvtion shouldnt be called otherwise
	void RecursiveInsert(Node<T>* pointer, T data) {
		
		if (data == pointer->Getdata()) {
			cout << "data already exists" << endl;
			return;
		}
		if (data > pointer->Getdata()) {
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
		else if (data < pointer->Getdata()) {
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


	void Delete(Node<T>* NodeToDelete)
	{
		if (NodeToDelete == nullptr ) {
			return;
		}
		//2 children case
		if ((NodeToDelete->GetLeft() != nullptr) && ( NodeToDelete->GetRight() != nullptr)) {
			//going with the smallest value in the right subtree to replace it with
			Node<T>* ReplacePointer = Minimum(NodeToDelete->GetRight());
			//check if it has a child// we already know theres none on the left since its the lowest value and that it is on the left of its parent
			ReplacePointer->SetLeft(NodeToDelete->GetLeft());
			NodeToDelete->GetLeft()->SetParent(ReplacePointer);

			if (NodeToDelete->GetRight()->Getdata() != ReplacePointer->Getdata()) {
				ReplacePointer->GetParent()->SetLeft(nullptr);
				if (ReplacePointer->GetRight() != nullptr) {
					ReplacePointer->GetRight()->SetParent(ReplacePointer->GetParent());
				}
				ReplacePointer->SetRight(NodeToDelete->GetRight());
				NodeToDelete->GetRight()->SetParent(ReplacePointer);
			}

			
			if (NodeToDelete->GetParent() != nullptr) {
				ReplacePointer->SetParent(NodeToDelete->GetParent());
				if (NodeToDelete->GetParent()->Getdata() > NodeToDelete->Getdata()) {
					NodeToDelete->GetParent()->SetLeft(ReplacePointer);
				}
				else {
					NodeToDelete->GetParent()->SetRight(ReplacePointer);
				}
			}
			else {
				ReplacePointer->SetParent (nullptr);
				Root = ReplacePointer;
			}
		}

		// nochildren case
		else if (NodeToDelete->GetLeft() == nullptr && NodeToDelete->GetRight() == nullptr) {
			if (NodeToDelete->GetParent() != nullptr) {
				if (NodeToDelete->GetParent()->Getdata() > NodeToDelete->Getdata()) {
					NodeToDelete->GetParent()->SetLeft(nullptr);
				}
				else {
					NodeToDelete->GetParent()->SetRight(nullptr);
				}
			}
			//if it has no parent it is the root
			else
			{
				Root = nullptr;
			}
		}

		//one child cases
		else if (NodeToDelete->GetLeft() == nullptr) {
			if (NodeToDelete->GetParent() != nullptr)
			{
				NodeToDelete->GetRight()->SetParent(NodeToDelete->GetParent());
				if (NodeToDelete->GetParent()->Getdata() > NodeToDelete->Getdata()) {
					NodeToDelete->GetParent()->SetLeft(NodeToDelete->GetRight());
				}
				else {
					NodeToDelete->GetParent()->SetRight(NodeToDelete->GetRight());
				}

			}
			//if it has no parent it is the root
			else {
				NodeToDelete->GetRight()->SetParent(nullptr);
				Root = NodeToDelete->GetRight();
			}

		}
		else if (NodeToDelete->GetRight() == nullptr) {
			if (NodeToDelete->GetParent() != nullptr)
			{
				NodeToDelete->GetLeft()->SetParent(NodeToDelete->GetParent());
				if (NodeToDelete->GetParent()->Getdata() > NodeToDelete->Getdata()) {
					NodeToDelete->GetParent()->SetLeft(NodeToDelete->GetLeft());
				}
				else {
					NodeToDelete->GetParent()->SetRight(NodeToDelete->GetLeft());
				}

			}
			//if it has no parent it is the root
			else {
				NodeToDelete->GetLeft()->SetParent(nullptr);
				Root = NodeToDelete->GetLeft();
			}
		}

		NodeToDelete->SetParent(nullptr);
		NodeToDelete->SetLeft(nullptr);
		NodeToDelete->SetRight(nullptr);
		delete NodeToDelete;
	}

	void Delete(T data) {

		Node<T>* NodeToDelete = Find(data);
		if (NodeToDelete != nullptr)
		{
			Delete(NodeToDelete);
		}
	}

	Node<T>* Find(T data) {
		if (Root == nullptr) {
			cout << "There is no data in the List" << endl;
			return nullptr;
		}
		Node<T>* ReturnPointer = nullptr;
		Node<T>* SearchPointer = Root;
		while (ReturnPointer == nullptr) {

			if (data > SearchPointer->Getdata()) {
				if (SearchPointer->GetRight() == nullptr) {
					cout << "That value is not search tree" << endl;
					return nullptr;
				}
				else {
					SearchPointer = SearchPointer->GetRight();
				}
			}
			if (data < SearchPointer->Getdata()) {
				if (SearchPointer->GetLeft() == nullptr) {
					cout << "That value is not search tree" << endl;
					return nullptr;
				}
				else {
					SearchPointer = SearchPointer->GetLeft();
				}
			}
			if (data == SearchPointer->Getdata()) {
				ReturnPointer = SearchPointer;
				return ReturnPointer;
			}
		}
	}

	void Traverse(Node<T>* StartingPoint) {
		////recursively call left and right for all the nodes
		if (StartingPoint->GetRight() != nullptr) {
			Traverse(StartingPoint->GetRight());
		}
		else if(StartingPoint->GetLeft() != nullptr){
			Traverse(StartingPoint->GetLeft());
		}
	}

	Node<T>* Maximum(Node<T>* startingPoint)
	{
		//search for the farthest node to the right 
		Node<T>* IterativePointer = startingPoint;
		while (IterativePointer->GetRight() != nullptr) {
			IterativePointer = IterativePointer->GetRight();
		}
		return IterativePointer;	
	}

	Node<T>* Minimum(Node<T>* startingPoint)
	{
		//search for the farthest node to the left
		Node<T>* IterativePointer = startingPoint;
		while (IterativePointer->GetLeft() != nullptr) {
			IterativePointer = IterativePointer->GetLeft();
		}
		return IterativePointer;
	}

	void Display() {
		
		Node<T>* StartingPoint = Root;
		if (StartingPoint != nullptr) {
			RecursiveDisplay(StartingPoint, -DisplaySpace);
		}	
	}

	void RecursiveDisplay(Node<T>* Start,int spacing) {
		spacing += DisplaySpace;

		//recursively call left and right for all the nodes
		if (Start->GetRight() != nullptr) {
			RecursiveDisplay(Start->GetRight(),spacing);
		}
		for (int i = 0; i < spacing; i++) {
			cout << " ";
		}
		cout <<"("<< Start->Getdata()<<")" <<endl;
		
		if(Start->GetLeft() != nullptr)
		{
			RecursiveDisplay(Start->GetLeft(), spacing);
		}
	
	}

	void Testing() {

	}
};
