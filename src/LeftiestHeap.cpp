#include "LeftiestHeap.h"

int Heaps::LeftiestHeap::GetMin()
{
	return _root->key;
}

int Heaps::LeftiestHeap::ExtractMin()
{
	int extractedMinimnum = GetMin();
	Node* temp = _root;
	_root = _merge(_root->left, _root->right);
	delete temp;
	return extractedMinimnum;

}

void Heaps::LeftiestHeap::InsertKey(int key)
{
	_root = _merge(_root, new Node(key));
}

bool Heaps::LeftiestHeap::Empty()
{
	return _root == nullptr;
}

void Heaps::LeftiestHeap::Merge(IHeap* otherHeap)
{
	LeftiestHeap* heap = dynamic_cast<LeftiestHeap *>(otherHeap);
	if (heap != nullptr) {
		Merge(heap);
	}
	else {
		GeneralHeap::Merge(otherHeap);
	}
}

void Heaps::LeftiestHeap::Merge(LeftiestHeap* otherHeap)
{
	_root = _merge(_root, otherHeap->_root);
	otherHeap->_root = nullptr;
}

size_t Heaps::LeftiestHeap::_rank(Node* root)
{
	if (root == nullptr)return 0;
	return root->rank;
}

void Heaps::LeftiestHeap::_fixLeftiestProperty(Node* root)
{
	if (root == nullptr)return;
	if (_rank(root->right) > _rank(root->left)) {
		std::swap(root->left, root->right);
	}
	root->rank = std::min(_rank(root->left), _rank(root->right)) + 1;
}

Heaps::LeftiestHeap::Node* Heaps::LeftiestHeap::_merge(Node* left, Node* right)
{
	if (left == nullptr) return right;
	if (right == nullptr)return left;

	if (left->key > right->key) {
		std::swap(left, right);
	}

	left->right = _merge(left->right, right);
	_fixLeftiestProperty(left);
	return left;
}

Heaps::LeftiestHeap::Node::Node(int nodeKey)
{
	key = nodeKey;
	rank = 1;
}

