#include "Classes.h"
//this is for system("CLS");
#include <stdlib.h>

void main() {
	BinarySearchTree<int> BST;

	int Quit = 0;

	do {

		int input;
		BST.Display();
		Node<int>* wtf = new Node<int>(8);
		cout << (wtf->GetLeft() == nullptr);
		cout << "Press (1) to Add Number to List" << endl;
		cout << "Press (2) to Remove A Number From the list" << endl;
		cout << "Press (3) to Display the List" << endl;
		cout << "Press (4) to Run Diagnostics" << endl;
		cout << "Press (0) to Quit" << endl;
		cin >> input;

		switch (input)
		{
		case 1:
			int AddNum;
			cout << "Enter a Number to Add: ";
			cin >> AddNum;
			BST.Insert(AddNum);
			system("CLS");
			break;
		case 2:
			int RemoveNum;
			cout << "Enter a Number to Remove: ";
			cin >> RemoveNum;
			BST.Delete(RemoveNum);
			system("CLS");
			break;
		case 3:
			system("CLS");
			BST.Display();
			break;
		case 4:
			system("CLS");
		
			break;
		case 0:
			Quit = 1;
			break;
		}

	} while (Quit == 0);

}