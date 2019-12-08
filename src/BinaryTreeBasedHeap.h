#pragma once
#include "TreeBasedHeap.h"

namespace Heaps {
	class BinaryTreeBasedHeap : public TreeBasedHeap {
	public:
		virtual int GetMin() const override;
		virtual int ExtractMin() override;
		virtual void InsertKey(int key) override;
		virtual bool Empty() const override;
		virtual void Merge(IHeap* other) override;
		virtual void Merge(BinaryTreeBasedHeap* other);
	protected:
		struct Node : TreeBasedHeap::Node{
			Node(int someKey);

			Node* left = nullptr;
			Node* right = nullptr;

		};
		virtual Node* _merge(Node* left, Node *right);
		virtual Node* _merge(TreeBasedHeap::Node* left, TreeBasedHeap::Node* right);
		virtual TreeBasedHeap::Node* _makeNode(int key) override;
		virtual void _fixHeap(Node* root) = 0;

		
	};
};