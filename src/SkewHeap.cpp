#include "SkewHeap.h"
#include <algorithm>

void Heaps::SkewHeap::_fixHeap(Node* root)
{
	std::swap(root->left, root->right);
}
