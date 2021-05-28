#include <iostream>
#include <string>

using namespace std;

struct Node
{
	Node* Left;
	Node* Right;
	int Data;
};

class BinaryTree {
public:
	Node* rootNode;
	BinaryTree() 
	{
		rootNode = nullptr;
	}
public:
	void AddNode(int data) 
	{
		Node* newNode = CreateNode(data);
		if (rootNode == nullptr)
		{
			rootNode = newNode;
		}
		else
		{

		}
	}

	
private:
	Node* CreateNode(int data) 
	{
		Node* newNode = new Node;

		newNode->Data = data;
		newNode->Right = nullptr;
		newNode->Left = nullptr;

		return newNode;
	}

	void InsertNode(Node* tree, Node* newNode) 
	{
		if (newNode->Data > tree->Data) 
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
	}

	

	Node* FindMinNode(Node* tree)
	{
		if (tree = nullptr)
		{
			return nullptr;
		}

		if (tree->Left != nullptr)
		{
			return FindMinNode(tree->Left);
		}
		else
		{
			return tree;
		}
	}

};