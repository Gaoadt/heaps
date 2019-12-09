#include "TreeBasedHeap.h"


Heaps::TreeBasedHeap::Node::Node(int someKey)
{
	key = someKey;
}


Heaps::TreeBasedHeap::Node::~Node()
{
	
}

void Heaps::TreeBasedHeap::_deleteRecursively(Node* root)
{
	if (root == nullptr)return;
	std::vector<Node*> childs = root->GetChilds();
	for (std::vector<Node*>::iterator iter = childs.begin(); iter != childs.end(); ++iter) {
		_deleteRecursively(*iter);
	}

	delete root;
}

Heaps::TreeBasedHeap::~TreeBasedHeap()
{
	_deleteRecursively(_root);
}
