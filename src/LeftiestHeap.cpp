#include "LeftiestHeap.h"
#include <algorithm>

size_t Heaps::LeftiestHeap::_rank(Node* root)
{
	if (root == nullptr)return 0;
	return root->rank;
}

void Heaps::LeftiestHeap::_fixHeap(BinaryTreeBasedHeap::Node *givenRoot)
{
	LeftiestHeap::Node* root = dynamic_cast<LeftiestHeap::Node*>(givenRoot);
	if (root == nullptr)return;
	if (_rank(dynamic_cast<LeftiestHeap::Node*>(root->right)) > _rank(dynamic_cast<LeftiestHeap::Node*>(root->right))) {
		std::swap(root->left, root->right);
	}
	root->rank = std::min(_rank(dynamic_cast<LeftiestHeap::Node*>(root->right)), _rank(dynamic_cast<LeftiestHeap::Node*>(root->right))) + 1;
}

Heaps::TreeBasedHeap::Node* Heaps::LeftiestHeap::_makeNode(int key)
{
	return new Node(key);
}

Heaps::LeftiestHeap::Node::Node(int someKey) : Heaps::BinaryTreeBasedHeap::Node::Node(someKey)
{
	rank = 1;
}





