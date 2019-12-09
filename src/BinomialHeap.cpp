#include "BinomialHeap.h"
#include <algorithm>
#include <iostream>
Heaps::BinomialHeap::BinomialHeap()
{
	_root = new Node(_FICTIVE_KEY);
}

int Heaps::BinomialHeap::GetMin() const
{
	Node* root = _binomialRoot();
	return root->childs[root->minIndex]->key;
}

void Heaps::BinomialHeap::InsertKey(int key)
{
	std::vector<Node *> &myForest = _binomialRoot()->childs;
	myForest.push_back(nullptr);
	std::vector<Node*> forest(myForest.size(), nullptr);
	forest[0] = new Node(key);
	_mergeBinomialForests(myForest, forest, nullptr, 0);
	_removeLeadingNullPointers();
	_updateMinimum();
}

bool Heaps::BinomialHeap::Empty() const
{
	for (std::vector<Node*>::const_iterator iter = _binomialRoot()->childs.cbegin(); iter != _binomialRoot()->childs.end(); ++iter) {
		if (*iter != nullptr)return false;
	}
	return true;
}

void Heaps::BinomialHeap::Merge(IHeap* otherHeap)
{
	BinomialHeap* binomialHeap = dynamic_cast<BinomialHeap *>(otherHeap);
	if (binomialHeap != nullptr) {
		Merge(binomialHeap);
	}
	else {
		GeneralHeap::Merge(otherHeap);
	}
}

void Heaps::BinomialHeap::Merge(BinomialHeap* otherHeap)
{
	if (otherHeap == this)return;
	std::vector<Node*>& forest1 = _binomialRoot()->childs;
	std::vector<Node*>& forest2 = otherHeap->_binomialRoot()->childs;
	size_t new_size = std::max(forest1.size(), forest2.size()) + 1;
	forest1.resize(new_size, nullptr);
	forest2.resize(new_size, nullptr);
	_mergeBinomialForests(forest1, forest2, nullptr, 0);
	_removeLeadingNullPointers();
	otherHeap->_removeLeadingNullPointers();
	_updateMinimum();
}

Heaps::BinomialHeap::Node* Heaps::BinomialHeap::_mergeSimilar(Node* first, Node* second)
{
	if (first == nullptr || second == nullptr)return nullptr;
	if (first->key > second->key) {
		std::swap(first, second);
	}
	first->childs.push_back(second);
	return first;
}

void Heaps::BinomialHeap::_deleteMinimum()
{
	Node* root = _binomialRoot();
	BinomialHeap* tempHeap = new BinomialHeap();
	tempHeap->_root = root->childs[root->minIndex];
	root->childs[root->minIndex] = nullptr;
	Merge(tempHeap);

	delete tempHeap;
}

void Heaps::BinomialHeap::_removeLeadingNullPointers()
{
	std::vector<Node*> &forest = _binomialRoot()->childs;
	while (!forest.empty() && forest.back() == nullptr) {
		forest.pop_back();
	}
}

Heaps::BinomialHeap::Node* Heaps::BinomialHeap::_binomialRoot() const
{
	return dynamic_cast<Node*>(_root);
}

void Heaps::BinomialHeap::_mergeBinomialForests(std::vector<Node*>& heap1, std::vector<Node*>& heap2, Node* reminder, size_t index)
{
	if (index == heap1.size()) {
		return;
	}

	_tryPush(heap1[index], heap2[index]);
	_tryPush(heap2[index], reminder);
	_tryPush(heap1[index], heap2[index]);

	_mergeBinomialForests(heap1, heap2, _mergeSimilar(heap1[index], heap2[index]), index + 1);
	
	if (heap2[index] != nullptr) {
		heap1[index] = reminder;
	    heap2[index] = nullptr;
	}
}

void Heaps::BinomialHeap::_tryPush(Node*& position, Node*& value) const
{
	if (position == nullptr) {
		std::swap(position, value);
	}
}

void Heaps::BinomialHeap::_updateMinimum()
{
	std::vector<Node*>& forest1 = _binomialRoot()->childs;
	size_t loaclMinimum = 0;
	for (size_t i = 0; i < forest1.size(); ++i) {
		if (forest1[loaclMinimum] == nullptr || (forest1[i] != nullptr && forest1[i]->key < forest1[loaclMinimum]->key)) {
			loaclMinimum = i;
		}
	}

	_binomialRoot()->minIndex = loaclMinimum;
}

Heaps::TreeBasedHeap::Node* Heaps::BinomialHeap::_makeNode(int key)
{
	return new Node(key);
}

Heaps::BinomialHeap::Node::Node(int someKey) : Heaps::TreeBasedHeap::Node(someKey) {

}

std::vector<Heaps::TreeBasedHeap::Node *> Heaps::BinomialHeap::Node::GetChilds()
{
	return std::vector<TreeBasedHeap::Node *>(childs.begin(), childs.end());
}

