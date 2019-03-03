#include "Classes.h"
//this is for system("CLS");
#include <stdlib.h>

void main() {
	BinarySearchTree<int> BST;

	int Quit = 0;

	do {

		int input;
		system("CLS");
		BST.Display();
		cout << "Press (1) to Add Number to tree" << endl;
		cout << "Press (2) to Remove A Number From the tree" << endl;
		cout << "Press (3) to Display the tree" << endl;
		cout << "Press (4) to Run Diagnostics" << endl;
		cout << "Press (10) to Add 1 - 10 to the tree" << endl;
		cout << "Press (100) to Add 1 - 100 to the tree" << endl;
		cout << "Press (1000) to Add 1 - 1000 to the tree" << endl;
		cout << "Press (0) to Quit" << endl;
		cin >> input;

		switch (input)
		{
		case 1:
			int AddNum;
			cout << "Enter a Number to Add: ";
			cin >> AddNum;
			BST.Insert(AddNum);
			
			break;
		case 2:
			int RemoveNum;
			cout << "Enter a Number to Remove: ";
			cin >> RemoveNum;
			BST.Delete(RemoveNum);
			
			break;
		case 3:
			
			BST.Display();
			break;
		case 4:
			
		
			break;
		case 10:
			for  (int i = 0; i <= 10 ; i++)
			{
				BST.Insert(i);
			}
			break;
		case 100:
			for (int i = 0; i <= 100; i++)
			{
				BST.Insert(i);
			}
			break;
		case 1000:
			for (int i = 0; i <= 1000; i++)
			{
				BST.Insert(i);
			}
			break;
		case 0:
			Quit = 1;
			break;
		}

	} while (Quit == 0);

}