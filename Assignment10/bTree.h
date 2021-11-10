// bTree.h

#ifndef BTREE_LOCK
#define BTREE_LOCK

#include <iostream>

template<class T>
class TreeNode
{
public:
	template<class T>
	friend class bTree;

	TreeNode(const T& _data = T(), TreeNode* _leftNode = NULL, TreeNode* _rightNode = NULL)
		:data(_data), leftNode(_leftNode), rightNode(_rightNode)
	{}
	
private:
	T data;
	TreeNode* leftNode;
	TreeNode* rightNode;
};

template<class T>
class bTree 
{
private:
	TreeNode<T>* root;
	int nodeCount;
public:
	bTree()
	{
		root = NULL;
		nodeCount = 0;
	}

	bTree(const T& _data)
	{
		TreeNode<T>* temp = new TreeNode<int>(_data);
		root = temp;
		nodeCount = 0;
	}

	~bTree()
	{
		deleteTree();
	}

	void push(const T& _data)
	{
		TreeNode<T>* thisNode = new TreeNode<T>(_data);
		if (root == NULL) { root = thisNode; return; }
		TreeNode<T>* currentNode = root;
		insert(thisNode, currentNode);
	}

	void insert(TreeNode<T>* thisNode, TreeNode<T>* currentNode)
	{
		if (thisNode->data < currentNode->data || thisNode->data == currentNode->data) 
		{
			if (currentNode->leftNode == NULL)
			{
				currentNode->leftNode = thisNode;
				return;
			}
			else insert(thisNode, currentNode->leftNode);
		}
		else
		{
			if (currentNode->rightNode == NULL)
			{
				currentNode->rightNode = thisNode;
				return;
			}
			else insert(thisNode, currentNode->rightNode);
		}
	}


	void printPreOrder(void)
	{
		if (root == NULL) throw invalid_argument("ERROR: bTree is empty.");
		TreeNode<T>* currentNode = root;
		iteratePreOrder(currentNode);
	}

	void iteratePreOrder(TreeNode<T>* currentNode)
	{
		if (currentNode != NULL)
		{
			std::cout << "\t\t" << currentNode->data << std::endl;
			iteratePreOrder(currentNode->leftNode);

		}
		else return;
		iteratePreOrder(currentNode->rightNode);
	}

	void printInOrder(void)
	{
		if (root == NULL) throw invalid_argument("ERROR: bTree is empty.");
		TreeNode<T>* currentNode = root;
		iterateInOrder(currentNode);
	}

	void iterateInOrder(TreeNode<T>* currentNode)
	{
		if (currentNode != NULL)
		{
			iterateInOrder(currentNode->leftNode);
		}
		else return;
		std::cout << "\t\t" << currentNode->data << std::endl;
		iterateInOrder(currentNode->rightNode);
	}

	void printPostOrder(void)
	{
		if (root == NULL) throw invalid_argument("ERROR: bTree is empty.");
		TreeNode<T>* currentNode = root;
		iteratePostOrder(currentNode);
	}

	void iteratePostOrder(TreeNode<T>* currentNode)
	{
		if (currentNode != NULL)
		{
			iteratePostOrder(currentNode->leftNode);
		}
		else return;
		iteratePostOrder(currentNode->rightNode);
		std::cout << "\t\t" << currentNode->data << std::endl;
	}


	void deleteTree(void)
	{
		if (root == NULL) throw invalid_argument("ERROR: bTree is empty.");
		TreeNode<T>* currentNode = root;
		iteratePostOrderDelete(currentNode);
		root = NULL;
		nodeCount = 0;
	}

	void iteratePostOrderDelete(TreeNode<T>* currentNode)
	{
		if (currentNode != NULL)
		{
			iteratePostOrderDelete(currentNode->leftNode);
		}
		else return;
		iteratePostOrderDelete(currentNode->rightNode);
		delete currentNode;
	}


	int countNodes(void)
	{
		nodeCount = 0;
		TreeNode<T>* currentNode = root;
		iteratePostOrderCount(currentNode);
		return nodeCount;
	}

	void iteratePostOrderCount(TreeNode<T>* currentNode)
	{
		if (currentNode != NULL)
		{
			iteratePostOrderCount(currentNode->leftNode);
		}
		else return;
		iteratePostOrderCount(currentNode->rightNode);
		nodeCount++;
	}


	bool searchNode(T nodeData)
	{
		if (root == NULL) throw invalid_argument("ERROR: bTree is empty.");
		bool nodeFound = false;
		TreeNode<T>* currentNode = root;
		iteratePostOrderSearch(currentNode, nodeFound, nodeData);
		return nodeFound;
	}

	void iteratePostOrderSearch(TreeNode<T>* currentNode, bool& nodeFound, T nodeData)
	{
		if (currentNode != NULL)
		{
			iteratePostOrderSearch(currentNode->leftNode, nodeFound, nodeData);
		}
		else return;
		iteratePostOrderSearch(currentNode->rightNode, nodeFound, nodeData);
		if (currentNode->data == nodeData) nodeFound = true;
	}

};

#endif