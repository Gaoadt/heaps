#include "BinaryTreeBasedHeap.h"
#include <algorithm>

int Heaps::BinaryTreeBasedHeap::GetMin() const
{
	return _root->key;
}

int Heaps::BinaryTreeBasedHeap::ExtractMin()
{
	int extractedMinimnum = GetMin();
	Node* temp = _root;
	_root = _merge(_root->left, _root->right);
	delete temp;
	return extractedMinimnum;
}

void Heaps::BinaryTreeBasedHeap::InsertKey(int key)
{
	_root = _merge(_root, _makeNode(key));
}

bool Heaps::BinaryTreeBasedHeap::Empty() const
{
	return _root == nullptr;
}


void Heaps::BinaryTreeBasedHeap::Merge(IHeap* otherHeap)
{
	BinaryTreeBasedHeap* heap = dynamic_cast<BinaryTreeBasedHeap*>(otherHeap);
	if (heap != nullptr) {
		Merge(heap);
	}
	else {
		GeneralHeap::Merge(otherHeap);
	}
}

void Heaps::BinaryTreeBasedHeap::Merge(BinaryTreeBasedHeap* otherHeap)
{
	_root = _merge(_root, otherHeap->_root);
	otherHeap->_root = nullptr;
}


Heaps::BinaryTreeBasedHeap::Node* Heaps::BinaryTreeBasedHeap::_merge(Node* left, Node* right)
{
	if (left == nullptr) return right;
	if (right == nullptr)return left;

	if (left->key > right->key) {
		std::swap(left, right);
	}

	left->right = _merge(left->right, right);
	_fixHeap(left);
	return left;
}

Heaps::BinaryTreeBasedHeap::Node* Heaps::BinaryTreeBasedHeap::_makeNode(int key)
{
	return new Node(key);
}

Heaps::BinaryTreeBasedHeap::Node::Node(int someKey) {
	key = someKey;
}


Heaps::BinaryTreeBasedHeap::Node::~Node()
{
}
