#include "AVLTree.h"

const string FILE_1 = "before.dot";
const string FILE_2 = "after.dot";


AVLTree::AVLTree()
{
	root = nullptr;
}

AVLTree::~AVLTree()
{
}

int AVLTree::balanceFactor(Node* tempNode)
{
	int balance = heightCheck(tempNode->getLeft()) - heightCheck(tempNode->getRight());
	return balance;
}
void AVLTree::insert(const string& phrase1)
{
//	cout << "hello" << endl;
	Node* newNode = new Node(1, phrase1, 0);
	if(root == nullptr)
	{
		root = newNode;
		newNode->setParent(nullptr);
		return;
	}
	Node* tempNode = root;
	while(tempNode != nullptr)
	{
//		cout << "Node we at: " << tempNode->getNodeData() << endl;
		if(tempNode->getNodeData() > newNode->getNodeData())
		{
			if(tempNode->getLeft() == nullptr)
			{
				tempNode->setLeft(newNode);
				newNode->setParent(tempNode);
				break;
			}
			else
			{
				tempNode = tempNode->getLeft();
			}
		}
		else if(tempNode->getNodeData() < newNode->getNodeData())
		{
			if(tempNode->getRight() == nullptr)
			{
				tempNode->setRight(newNode);
				newNode->setParent(tempNode);
				break;
			}
			else
			{
				tempNode = tempNode->getRight();
			}
		}
		else
		{
			tempNode->updateNodeCounter();
			return;
		}
	}
	visualizeTree(FILE_1);
	treeBalance();
//	cout << "Node Inserted: " << newNode->getNodeData() << endl;
//	Node* tempNode1 = findUnbalancedNode(newNode);
//	cout << "going to move: " << tempNode1->getNodeData() << endl;
	if(findUnbalancedNode(newNode) == nullptr)
	{
//		cout << "We chillin" << endl;
//	return;
	}
	else
	{
//		cout << "going to move: " << findUnbalancedNode(newNode)->getNodeData() << endl;
		rotate(findUnbalancedNode(newNode));
	}
	treeBalance();
	visualizeTree(FILE_2);
}

Node* AVLTree::findUnbalancedNode(Node* temp)
{
//	cout << "bruh" << endl;
	while(temp != nullptr)
	{
//		cout << "yessir" << endl;
		if(temp->getBalanceFactor() > 1 || temp->getBalanceFactor() < -1)
		{
//			cout << temp->getNodeData() << " balance factor: " << temp->getBalanceFactor() << endl;
			return temp;
		}
		temp = temp->getParent();
	}
	return temp;
}

void AVLTree::rotate(Node* temp)
{
	if(temp->getBalanceFactor() > 1)    
	{
		if(temp->getLeft()->getLeft() != nullptr)
		{
			rotateRight(temp);
		}
		else
		{
			rotateLeft(temp->getLeft());
			rotateRight(temp);
		}
	}
	else 
	{
		if(temp->getRight()->getRight() !=  nullptr)
		{
			rotateLeft(temp);
		}
		else
		{
			rotateRight(temp->getRight());
			rotateLeft(temp);
		}
	}
}
void AVLTree::rotateRight(Node* temp)
{
	Node* temp1 = temp->getLeft();
	Node* parentTemp =  temp->getParent();
	if(temp1->getRight() == nullptr)
	{
//		{
//		rotateRight(temp1);
//		}
	if(parentTemp == nullptr)
	{
		root = temp1;
		temp1->setParent(nullptr);
	}
	else
	{
		if(parentTemp->getLeft() == temp)
		{
			parentTemp->setLeft(temp1);
		}
		else
		{
			parentTemp->setRight(temp1);
		}
	}
	
	}
//	temp = temp1->getLeft();
	if(temp1->getRight() != nullptr)
	{
		Node* temp2 = temp1->getRight();
		Node* temp3 = temp2->getRight();
//		temp1->setParent(temp);
		rotateLeft(temp1);
//		root = temp1;
		temp2->setParent(temp);
		if(temp->getParent() == nullptr)
		{
			temp2->setParent(nullptr);
			root = temp2;
		}
		else
		{
			temp2->setParent(temp->getParent());
		}
		temp->setLeft(temp3);
		temp3->setParent(temp);
		temp->setParent(temp2);
		temp2->setRight(temp);
		
		//		rotateLeft(temp);
//		temp->setRight(nullptr);
////		Node* temp2 = temp1->getLeft();
//		temp1->setLeft(temp);
//		temp->setParent(temp1);
//		temp->setRight(temp2);
//		temp1->setParent(parentTemp);
	}
	else
	{
		temp->setLeft(nullptr);
		temp1->setRight(temp);
		temp->setParent(temp1);
		temp1->setParent(parentTemp);
	}
}

void AVLTree::rotateLeft(Node* temp)
{
	Node* temp1 = temp->getRight();
	Node* parentTemp =  temp->getParent();
	if(temp1->getLeft() == nullptr)
	{
//		{
//		rotateRight(temp1);
//		}
	if(parentTemp == nullptr)
	{
		root = temp1;
		temp1->setParent(nullptr);
	}
	else
	{
		if(parentTemp->getRight() == temp)
		{
			parentTemp->setRight(temp1);
		}
		else
		{
			parentTemp->setLeft(temp1);
		}
	}
	
	}
//	temp = temp1->getLeft();
	if(temp1->getLeft() != nullptr)
	{
		Node* temp2 = temp1->getLeft();
		Node* temp3 = temp2->getLeft();
//		temp1->setParent(temp);
		rotateRight(temp1);
//		root = temp1;
		temp2->setParent(temp);
		if(temp->getParent() == nullptr)
		{
			temp2->setParent(nullptr);
			root = temp2;
		}
		else
		{
			temp2->setParent(temp->getParent());
		}
		temp->setRight(temp3);
		temp3->setParent(temp);
		temp->setParent(temp2);
		temp2->setLeft(temp);
		
		//		rotateLeft(temp);
//		temp->setRight(nullptr);
////		Node* temp2 = temp1->getLeft();
//		temp1->setLeft(temp);
//		temp->setParent(temp1);
//		temp->setRight(temp2);
//		temp1->setParent(parentTemp);
	}
	else
	{
		temp->setRight(nullptr);
		temp1->setLeft(temp);
		temp->setParent(temp1);
		temp1->setParent(parentTemp);
	}
}
void AVLTree::printBalanceFactors()
{
	if(root == nullptr)
	{
//		cout << "Empty Tree" << endl;
		cout << endl;
		return;
	}
	printBalanceFactors(root);
	cout << endl;
}
void AVLTree::printBalanceFactors(Node* temp)
{
	if(temp->getLeft() != nullptr)
	{
		printBalanceFactors(temp->getLeft());
	}
//	temp->setBalanceFactor(balanceFactor(temp));
	cout << temp->getNodeData() << "(" << temp->getBalanceFactor() <<"), ";
	if(temp->getRight() != nullptr)
	{
		printBalanceFactors(temp->getRight());
	}
}

void AVLTree::treeBalance()
{
	if(root == nullptr)
	{
//		cout << "Empty Tree" << endl;
//		cout << endl;
		return;
	}
	treeBalance(root);
//	cout << endl;
}

void AVLTree::treeBalance(Node* temp)
{
	if(temp->getLeft() != nullptr)
	{
		treeBalance(temp->getLeft());
	}
//	cout << temp->getNodeData() << " height: " << heightCheck(temp) << endl;
//	cout << temp->getNodeData() << " height of left subtree: " << heightCheck(temp->getLeft()) << endl;
//	cout << temp->getNodeData() << " height of right subtree: " << heightCheck(temp->getRight()) << endl;
	temp->setBalanceFactor(balanceFactor(temp));
	if(temp->getRight() != nullptr)
	{
		treeBalance(temp->getRight());
	}
}

int AVLTree::heightCheck(Node* tempNode) const
{  
    if (tempNode == nullptr)  
        return -1;  
    else
    {  
        /* compute the depth of each subtree */
        int leftNum = heightCheck(tempNode->getLeft());  
        int rightNum = heightCheck(tempNode->getRight());  
      
        /* use the larger one */
        if (leftNum > rightNum) 
		{
            return(leftNum + 1); 
		} 
        else 
			{
				return(rightNum +  1);  
			}
    }  
}  

void AVLTree::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    if(n){
        if(n->getLeft()){
            visualizeTree(outFS,n->getLeft());
            outFS<<n->getNodeData() << " -> " << n->getLeft()->getNodeData()<<";"<< endl;    
        }

        if(n->getRight()){
            visualizeTree(outFS,n->getRight());
            outFS<<n->getNodeData() <<" -> " <<n->getRight()->getNodeData()<<";"<<endl;    
        }
    }
}