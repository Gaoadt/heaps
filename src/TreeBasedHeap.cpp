#include "TreeBasedHeap.h"

Heaps::TreeBasedHeap::Node* Heaps::TreeBasedHeap::_makeNode(int key)
{
	return new Node(key);
}

Heaps::TreeBasedHeap::Node::Node(int someKey)
{
	key = someKey;
}


Heaps::TreeBasedHeap::Node::~Node()
{

}

