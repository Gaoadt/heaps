#pragma once
#include "BinaryTreeBasedHeap.h"
namespace Heaps {
	class SkewHeap : public BinaryTreeBasedHeap {
	public:

	protected:
		virtual void _fixHeap(Node* root) override;
	};
}