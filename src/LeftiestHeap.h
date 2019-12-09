#pragma once
#include "BinaryTreeBasedHeap.h"

namespace Heaps {
	class LeftiestHeap : public BinaryTreeBasedHeap {
	protected:
		struct Node : BinaryTreeBasedHeap::Node {
			Node(int someKey);
			int rank = 1;
		};
		size_t _rank(Node* root);
		virtual void _fixHeap(BinaryTreeBasedHeap::Node* givenRoot) override;
		virtual TreeBasedHeap::Node* _makeNode(int key) override;
	};
};