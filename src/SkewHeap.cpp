#include "SkewHeap.h"
#include <algorithm>

void Heaps::SkewHeap::_fixHeap(Node* root)
{
	if (root == nullptr) return;
	std::swap(root->left, root->right);
}
