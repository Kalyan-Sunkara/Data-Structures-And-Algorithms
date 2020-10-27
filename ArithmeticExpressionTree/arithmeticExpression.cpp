#include "arithmeticExpression.h"

arithmeticExpression::arithmeticExpression(const string &ye)
{
	infixExpression = ye;
	root = nullptr;
}

void arithmeticExpression::buildTree()
{
	int counter = 0;
	int counter1 = 0;
	int counter2 = 0;
	char temp1 = 'a';
	string newString = infix_to_postfix();
	int i = newString.size()-1;
	while(i >= 0)
	{
		TreeNode* newNode = new TreeNode(newString.at(i), temp1);
		if(root == nullptr)
		{
			root = newNode;
		}
		else
		{
			if(counter == 0)
			{
				TreeNode* tempNode = root;
				
				if(tempNode->left != nullptr)
				{
					tempNode = tempNode->left;
					counter1++;
				}
				
				while(tempNode->right != nullptr)
				{
					if(priority(newString.at(i)) > 0)
					{
						tempNode = tempNode->right;
					}
					else if(priority(newString.at(i)) == 0 && priority(tempNode->right->data) > 0)
					{
						tempNode = tempNode->right;
					}
					else if(tempNode->left != nullptr)
					{
						tempNode = tempNode->right;
					}
					else
					{
						tempNode = tempNode->right;
						break;
					}
				}
				if(counter1 == 0)
				{
					tempNode->left = newNode;
				}
				else if(priority(newString.at(i)) > 0)
				{
//					tempNode->left = newNode;
					tempNode->right = newNode;
				}
				else if(priority(newString.at(i)) == 0 && tempNode->right == nullptr && tempNode->left != nullptr)
				{
					tempNode->right = newNode;
					counter++;
				}
				else
				{
					tempNode->left = newNode;
				}
			}
			else
			{
				TreeNode* tempNode = root;
				if(tempNode->right != nullptr)
				{
					tempNode = tempNode->right;
				}
				while(tempNode->left != nullptr)
				{
					if(tempNode ==  root)
					{
						break;
					}
					else if(priority(newString.at(i)) > 0)
					{
						tempNode = tempNode->left;
					}
					else if(priority(tempNode->left->data) > 0 && tempNode->right != nullptr)
					{
						tempNode = tempNode->left;
					}
					else if(priority(tempNode->left->data) > 0 && tempNode->right == nullptr 
							&& ((tempNode->left->left == nullptr) || (tempNode->left->right == nullptr)))
					{
						tempNode = tempNode->left;
					}
					else
					{
//						tempNode = tempNode->right;
						break;
					}
				}
				if(priority(newString.at(i)) > 0 && counter2 == 0)
				{
					tempNode->right = newNode;
					counter2++;
				}
				else if(priority(newString.at(i)) > 0)
				{
					tempNode->left = newNode;
				}
				else if(priority(newString.at(i)) == 0 && tempNode->right == nullptr && tempNode->left != nullptr)
				{
					tempNode->right = newNode;
					
				}
				else
				{
					tempNode->left = newNode;
				}
			}
		}
		i--;
		temp1++;
	}
}

void arithmeticExpression::infix()
{
	infix(root);
}

void arithmeticExpression::prefix()
{
	prefix(root);
}
void arithmeticExpression::postfix()
{
	postfix(root);
}

void arithmeticExpression::infix(TreeNode *q)
{
	if(q->right != nullptr)
	{
		cout << "(";
		infix(q->right);
	}
	cout << q->data;
	if(q->left != nullptr)
	{
		infix(q->left);
		cout << ")";
	}

}

void arithmeticExpression::prefix(TreeNode *q)
{
	cout << q->data;
	if(q->right != nullptr)
	{
		prefix(q->right);
	}
	if(q->left != nullptr)
	{
		prefix(q->left);
	}
}

void arithmeticExpression::postfix(TreeNode *q)
{
	if(q->right != nullptr)
	{
		postfix(q->right);
	}
	if(q->left != nullptr)
	{
		postfix(q->left);
	}
	cout << q->data;
	
}
//arithmeticExpression::~arithmeticExpression()
//{
//}

int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
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

void arithmeticExpression::visualizeTree(ofstream &out, TreeNode* tempNode){
//	out << tempNode->key << " -> " << tempNode->left->key;
	if(tempNode->left != nullptr)
	{
		out << tempNode->key <<" -> " << tempNode->left->key << endl;
		visualizeTree(out, tempNode->left);
	}
	if(tempNode->right != nullptr)
	{
		out << tempNode->key <<" -> " << tempNode->right->key << endl;
		visualizeTree(out, tempNode->right);
	}
	return;
}
