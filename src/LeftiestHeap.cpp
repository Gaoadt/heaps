#include "LeftiestHeap.h"
#include <algorithm>
#include <iostream>

size_t Heaps::LeftiestHeap::_rank(Node* root)
{
	if (root == nullptr)return 0;
	return root->rank;
}

void Heaps::LeftiestHeap::_fixHeap(BinaryTreeBasedHeap::Node *givenRoot)
{
	LeftiestHeap::Node* root = dynamic_cast<LeftiestHeap::Node*>(givenRoot);
	if (root == nullptr)return;

	if (_rank(dynamic_cast<LeftiestHeap::Node*>(root->left)) > _rank(dynamic_cast<LeftiestHeap::Node*>(root->right))) {

		std::swap(root->left, root->right);
	}
	root->rank = std::min(_rank(dynamic_cast<LeftiestHeap::Node*>(root->left)), _rank(dynamic_cast<LeftiestHeap::Node*>(root->right))) + 1;
}

Heaps::TreeBasedHeap::Node* Heaps::LeftiestHeap::_makeNode(int key)
{
	return new Node(key);
}

void Heaps::LeftiestHeap::_printHeap(Heaps::BinaryTreeBasedHeap::Node *root)
{
	if (root == nullptr)return;
	std::cout << "(";
	_printHeap(root->left);
	std::cout << ")";
	std::cout << root->key;
	std::cout << "(";
	_printHeap(root->right);
	std::cout << ")";
}

int Heaps::LeftiestHeap::_realRank(Node* root)
{
	if (root == nullptr)return 0;
	int realRank=  std::min(_realRank(dynamic_cast<Node*>(root->left)), _realRank(dynamic_cast<Node*>(root->right))) + 1;
	if (_rank(root) != realRank) throw "Rank exception";
	return realRank;
}

Heaps::LeftiestHeap::Node::Node(int someKey) : Heaps::BinaryTreeBasedHeap::Node::Node(someKey)
{
	rank = 1;
}






