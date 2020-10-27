#include <iostream>
#include <limits>
#include "BSTree.h"

using namespace std;

void printOrders(BSTree *tree) {
  cout << "Preorder = ";
  tree->preOrder( );
  cout << "Inorder = ";
  tree->inOrder( );
  cout << "Postorder = ";
  tree->postOrder( );
}

int menu() {
  int choice = 0;
  cout << endl << "Enter menu choice: ";
  cout << endl;
  cout 
    << "1. Insert" << endl
    << "2. Remove" << endl
    << "3. Print" << endl
    << "4. Search" << endl
    << "5. Smallest" << endl
    << "6. Largest" << endl
    << "7. Height" << endl
    << "8. Quit" << endl;
  cin >> choice;
  
  // fix buffer just in case non-numeric choice entered
  // also gets rid of newline character
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return choice;
}

int main( ) {
    // Pass all your tests before running the executable main

    BSTree tree;
	BSTree* tree1 = &tree;
    int choice = menu();

    string entry;
  
    while (choice != 8) {
    
        if (choice == 1) {
          cout << "Enter string to insert: ";
		  string temp = "";
		  getline(cin, temp);
		  tree.insert(temp);
		  cout << endl;
        } else if (choice == 2) {
          cout << "Enter string to remove: ";
		  string temp1 = "";
		  getline(cin, temp1);
		  cout << endl;
		  tree.remove(temp1);
        } else if (choice == 3) {
			printOrders(tree1);
        } else if (choice == 4) {
          cout << "Enter string to search for: ";
		  string temp3 = "";
		  getline(cin, temp3);
		  cout << endl;
		  if(tree.search(temp3))
		  {
			  cout << "Found" << endl;
		  }
		  else
		  {
			  cout << "Not Found" << endl;
		  }
        } else if (choice == 5) {
          cout << "Smallest: ";
		  cout << tree.smallest();
		  cout << endl;
        } else if (choice == 6) {
          cout << "Largest: ";
		  cout << tree.largest();
		  cout << endl;
        } else if (choice == 7) {
          cout << "Enter string: ";
		  string temp4 = "";
		  getline(cin,temp4);
		  cout << endl;
		  int number1 = tree.height(temp4);
		  cout << "Height of subtree rooted at " << temp4 << ": ";
		  cout << number1 << endl;
        }
        //fix buffer just in case non-numeric choice entered
        choice = menu();
    }
    return 0;
}

