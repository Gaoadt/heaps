#pragma once
#include "GeneralHeap.h"

namespace Heaps {
	class BinaryTreeBasedHeap : public GeneralHeap {
	public:
		virtual int GetMin() const override;
		virtual int ExtractMin() override;
		virtual void InsertKey(int key) override;
		virtual bool Empty() const override;
		virtual void Merge(IHeap* other) override;
		virtual void Merge(BinaryTreeBasedHeap* other);
	protected:
		struct Node {
		    Node(int nodeKey);
			virtual ~Node();
			int key;
			Node* left = nullptr;
			Node* right = nullptr;

		};
		virtual Node* _merge(Node* left, Node *right);
		virtual Node* _makeNode(int key);
		virtual void _fixHeap(Node* root) = 0;

		Node* _root = nullptr;
	};
};