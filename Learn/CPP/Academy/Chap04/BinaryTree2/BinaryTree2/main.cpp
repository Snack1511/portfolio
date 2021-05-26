#include <iostream>
#include <string>

using namespace std;

struct Node
{
	Node* Left;
	Node* Right;
	int Data;
};

class BinaryTree
{
public:
	Node* rootNode;
	BinaryTree()
	{
		rootNode = nullptr;
	}

	void AddNode(int data)
	{
		Node* newNode = CreateNode(data);

		if (rootNode == nullptr)
		{
			rootNode = newNode;
		}
		else
		{
			InsertNode(rootNode, newNode);
		}
	}

	void RemoveNode(int num)
	{
		Delete(rootNode, num);
	}

	void printAllNode()
	{
		Inorder(rootNode);
	}

private:
	Node* CreateNode(int data)
	{
		Node* newNode = new Node;
		newNode->Left = nullptr;
		newNode->Right = nullptr;
		newNode->Data = data;

		return newNode;
	}
	void InsertNode(Node* tree, Node* newNode)
	{
		if (newNode->Data > tree->Data)
		{
			if (tree->Right != nullptr)
			{
				InsertNode(tree->Right, newNode);
			}
			else
			{
				tree->Right = newNode;
			}
		}
		else if (newNode->Data < tree->Data)
		{
			if (tree->Left != nullptr)
			{
				InsertNode(tree->Left, newNode);

			}
			else
			{
				tree->Left = newNode;
			}
		}

	}

	Node* Delete(struct Node* tree, int data) {

		Node* temp;
		if (tree == nullptr)
		{
			return tree;
		}
		else if (data < tree->Data)
		{
			tree->Left = Delete(tree->Left, data);
		}
		else if (data > tree->Data)
		{
			tree->Right = Delete(tree->Right, data);
		}
		else 
		{
			// Case 1: No Child
			if (tree->Left == nullptr && tree->Right == nullptr) {
				delete tree;
				tree = nullptr;
			}
			// Case 2: one child
			else if (tree->Left == nullptr) {
				temp = tree;
				tree = tree->Right;
				delete temp;
			}
			else if (tree->Right == nullptr) {
				temp = tree;
				tree = tree->Left;
				delete temp;
			}
			// Case 3: two child
			else {
				temp = FindMin(tree->Right);
				tree->Data = temp->Data;
				tree->Right = Delete(tree->Right, temp->Data);
			}
		}
		return tree;
	}

	Node* FindMin(Node* root) {

		while (root->Left != nullptr)
		{
			root = root->Left;
		}
		return root;
	}

	void Inorder(Node *root) {

		if (root == nullptr)
		{
			return;
		}
		Inorder(root->Left);

		cout << root->Data << endl;

		Inorder(root->Right);
	}

public:

	~BinaryTree();

};

BinaryTree::~BinaryTree()
{
}

void main()
{

	BinaryTree binary;



	binary.AddNode(1);
	binary.AddNode(2);
	binary.AddNode(3);
	binary.AddNode(4);
	binary.AddNode(5);

	binary.printAllNode();

	binary.RemoveNode(3);

	binary.printAllNode();


}
