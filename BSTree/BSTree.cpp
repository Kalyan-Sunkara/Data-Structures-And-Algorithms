#include "BSTree.h"

BSTree::BSTree()
{
	root = nullptr;
	height1 = 0;
}

BSTree::~BSTree()
{
}

void BSTree::insert(const string& phrase1)
{
	Node* newNode = new Node(1, phrase1, 0);
	if(root == nullptr)
	{
		root = newNode;
		return;
	}
	Node* tempNode = root;
	while(tempNode != nullptr)
	{
		if(tempNode->getNodeData() > newNode->getNodeData())
		{
			newNode->updateHeight();
			if(tempNode->getLeft() == nullptr)
			{
				tempNode->setLeft(newNode);
				if(newNode->getHeight() > height1)
				{
					height1 = newNode->getHeight();
				}
				return;
			}
			tempNode = tempNode->getLeft();
		}
		else if(tempNode->getNodeData() < newNode->getNodeData())
		{
			newNode->updateHeight();
			if(tempNode->getRight() == nullptr)
			{
				tempNode->setRight(newNode);
				if(newNode->getHeight() > height1)
				{
					height1 = newNode->getHeight();
				}
				return;
			}
			tempNode = tempNode->getRight();
		}
		else
		{
			tempNode->updateNodeCounter();
			return;
		}
	}
}

string BSTree::largest() const
{
	Node* tempNode = root;
	if(tempNode == nullptr)
	{
		return "";
	}
	while(tempNode->getRight() != nullptr)
	{
		tempNode = tempNode->getRight();
	}
	return tempNode->getNodeData();
}
string BSTree::smallest() const
{
	Node* tempNode = root;
	if(tempNode == nullptr)
	{
		return "";
	}
	while(tempNode->getLeft() != nullptr)
	{
		tempNode = tempNode->getLeft();
	}
	return tempNode->getNodeData();
}
bool BSTree::search(const string &temp)const //recursive version
{
//	Node* tempNode = root;
//	while(tempNode != nullptr)
//	{
//		if(tempNode->getNodeData() > temp)
//		{
//			tempNode = tempNode->getLeft();
//		}
//		else if(tempNode->getNodeData() < temp)
//		{
//			tempNode = tempNode->getRight();
//		}
//		else
//		{
//			return true;
//		}
//	}
//	return false;
	int binary = search(root, temp);
	if(binary == 1)
	{
		return true;
	}
	else
	{
//		cout << endl;
//		cout << "Not Found" << endl;
//		cout << endl;
		return false;
	}
}

int BSTree::height(const string &temp) const
{
	Node* tempNode = root;
	int counter1 = 0;
	
	while(tempNode != nullptr)
	{
		if(tempNode->getNodeData() < temp)
		{
			counter1++;
			tempNode = tempNode->getRight();
		}
		else if(tempNode->getNodeData() > temp)
		{
			counter1++;
			tempNode = tempNode->getLeft();
		}
		else
		{
			//int counter2 = tempNode->getNodeCounter();
			if(tempNode->getRight() == nullptr && tempNode->getLeft() == nullptr)
			{
				return 0;
			}
			int num = heightCheck(root);
			num = num -1;
//			if(num == 0)
//			{
//				height1--;
//			}
			return num - counter1;// tree was found;
		}
	}
//	cout << "Height of subtree rooted at " << tempNode->getNodeData() << ": ";
	return -1; //string does not exist in the tree
}
bool BSTree::remove(Node* parentNode, Node* dummyNode) {
	if (dummyNode == nullptr) 
		{
			return false;
		}	
// Case 1: Internal node with 2 children
	if (dummyNode->getLeft() && dummyNode->getRight()) {
// Find pred and pred's parent
	Node* predNode = dummyNode->getLeft();
	Node* predParent = dummyNode;
	while (predNode->getRight()) 
		{
			predParent = predNode;
			predNode = predNode->getRight();
		}
	dummyNode->setNodeData(predNode->getNodeData());
	dummyNode->setNodeCounter(predNode->getNodeCounter());

	// Recursively remove 
	remove(predParent, predNode);
}

// Case 2: Root node (with 1 or 0 children)
		else if (dummyNode == root) 
			{
			if (dummyNode->getLeft())
			{
				root = dummyNode->getLeft();
			}
			else
			{
				root = dummyNode->getRight();
			}
		}

// Case 3: Internal with left child only
		else if (dummyNode->getLeft()) 
			{

// Find pred and pred's parent
			Node* predNode = dummyNode->getLeft();
			Node* predParent = dummyNode;
			while (predNode->getRight()) 
				{
					predParent = predNode;
					predNode = predNode->getRight();
				}

// Copy the value from the pred node
				dummyNode->setNodeData(predNode->getNodeData());
				dummyNode->setNodeCounter(predNode->getNodeCounter());

// Recursively remove pred
				remove(predParent, predNode);
			}

// Case 4: Internal with right child only
			else if (dummyNode->getRight()) {
				Node* succNode = dummyNode->getRight();
				Node* successorParent = dummyNode;
				while (succNode->getLeft()) {
				successorParent = succNode;
				succNode = succNode->getLeft();
				}
// Copy the value from the successor node
			dummyNode->setNodeData(succNode->getNodeData());
			dummyNode->setNodeCounter(succNode->getNodeCounter());
// Recursively remove successor
			remove(successorParent, succNode);
//get succ: go right (1), go left until nullptr (leftmost node in right subtree)
		}
//Case 5 Leaf
		else {
			if (dummyNode == parentNode->getLeft()) 
			{
			parentNode->setLeft(nullptr);
			}
		else {
				parentNode->setRight(nullptr);
			}
	}
	return true;
}

void BSTree::remove(const string& key) {
	if (!search(key)) 
		{
		return; // key not found do nothing
		}

Node* tempNode = root;
Node* parNode = nullptr;

while (tempNode && tempNode->getNodeData() != key) 
	{
	if (key < tempNode->getNodeData()) 
		{
		parNode = tempNode;
		tempNode = tempNode->getLeft();
		}
		else {
			parNode = tempNode;
			tempNode = tempNode->getRight();
			}
	}

	if (tempNode->getNodeData() == key && tempNode->getNodeCounter() > 1) 
		{
		tempNode->setNodeCounter(tempNode->getNodeCounter() - 1);
		return;
		}
//	if(tempNode->getHeight() == height1)
//	{
//		height1--;
//	}
	remove(parNode, tempNode);
//	heightCheck();
}
void BSTree::preOrder()
{
	if(root == nullptr)
	{
//		cout << "Empty Tree" << endl;
		cout << endl;
		return;
	}
	preOrder(root);
	cout << endl;
}
void BSTree::inOrder()
{
	if(root == nullptr)
	{
//		cout << "Empty Tree" << endl;
		cout << endl;
		return;
	}
	inOrder(root);
	cout << endl;
}
void BSTree::postOrder()
{
	if(root == nullptr)
	{
//		cout << "Empty Tree" << endl;
		cout << endl;
		return;
	}
	postOrder(root);
	cout << endl;
}

void BSTree::inOrder(Node* temp)
{
	if(temp->getLeft() != nullptr)
	{
		inOrder(temp->getLeft());
	}
	cout << temp->getNodeData() << "(" << temp->getNodeCounter() <<"), ";
	if(temp->getRight() != nullptr)
	{
		inOrder(temp->getRight());
	}
}

void BSTree::preOrder(Node* temp)
{
	cout << temp->getNodeData() << "(" << temp->getNodeCounter() <<"), ";
	if(temp->getLeft() != nullptr)
	{
		preOrder(temp->getLeft());
	}
	if(temp->getRight() != nullptr)
	{
		preOrder(temp->getRight());
	}
}
void BSTree::postOrder(Node* temp)
{
	if(temp->getLeft() != nullptr)
	{
		postOrder(temp->getLeft());
	}
	if(temp->getRight() != nullptr)
	{
		postOrder(temp->getRight());
	}
	cout << temp->getNodeData() << "(" << temp->getNodeCounter() <<"), ";
}
int BSTree::search(Node* tempNode, const string &temp) const
{
	if(tempNode == nullptr)
	{
		return -1;
	}
	if(tempNode->getNodeData() == temp)
	{
		return 1;
	}
	if(tempNode->getNodeData() > temp)
	{
		return search(tempNode->getLeft(), temp);
	}
	if(tempNode->getNodeData() < temp)
	{
		return search(tempNode->getRight(), temp);
	}
	else
	{
		return 0;
	}
}

int BSTree::heightCheck(Node* node) const
{  
    if (node == nullptr)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int leftD = heightCheck(node->getLeft());  
        int rightD = heightCheck(node->getRight());  
      
        /* use the larger one */
        if (leftD > rightD) 
		{
            return(leftD + 1); 
		} 
        else 
			{
				return(rightD + 1);  
			}
    }  
}  
//int BSTree::heightCheck(Node* tempNode)
//{
//	if(tempNode->getLeft() != nullptr)
//	{
//		if(tempNode->getLeft()->getHeight() >= height1)
//		{
//			return 1; 
//		}
//		heightCheck(tempNode->getLeft());
//	}
//	if(tempNode->getHeight() >= height1)
//	{
//		return 1;
//	}
////	cout << temp->getNodeData() << "(" << temp->getNodeCounter() <<"), ";
//	if(tempNode->getRight() != nullptr)
//	{
//		if(tempNode->getRight()->getNodeCounter() >= height1)
//		{
//			return 1;
//		}
//		heightCheck(tempNode->getRight());
//	}
//	return 0;
//}
//
//void BSTree::heightCheck()
//{
//	int num = heightCheck(root);
//	if(num == 0)
//	{
//		height1--;
//	}
//}