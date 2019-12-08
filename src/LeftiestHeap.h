#pragma once
#include "IHeap.h"
#include "GeneralHeap.h"
#include <algorithm>
namespace Heaps {
	class LeftiestHeap : public GeneralHeap {
	public:
		virtual int GetMin() override;

		virtual int ExtractMin() override;

		virtual void InsertKey(int key) override;

		virtual bool Empty() override;

		virtual void Merge(IHeap* otherHeap) override;

		virtual void Merge(LeftiestHeap* otherHeap);
	private:
		struct Node {
			Node(int nodeKey);
			int key;
			size_t rank = 0;
			Node* left = nullptr;
			Node* right = nullptr;
		};

		Node* _root = nullptr;
		
		static size_t _rank(Node* root);
		static void _fixLeftiestProperty(Node* root);
		static Node* _merge(Node* left, Node* right);
	};
};