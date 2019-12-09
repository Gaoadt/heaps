#pragma once
#include "TreeBasedHeap.h"
#include <vector>
namespace Heaps {
	class BinomialHeap : public TreeBasedHeap {
	public:
		BinomialHeap();
		virtual int GetMin() const override;
		virtual void InsertKey(int key) override;
		virtual bool Empty() const override;
		virtual void Merge(IHeap* otherHeap) override;
		virtual void Merge(BinomialHeap* otherHeap);
	protected:
		struct Node : TreeBasedHeap::Node
		{
			Node(int someKey);
			std::vector<Node*> childs;
			size_t minIndex = 0;
		};
	    virtual Node* _mergeSimilar(Node* first, Node* second);
		virtual void _deleteMinimum() override;
		virtual void _removeLeadingNullPointers();
	private:
		Node* _binomialRoot() const;
		void _mergeBinomialForests(std::vector<Node*> &heap1,std::vector<Node *>&heap2, Node* reminder, size_t index);
		void _tryPush(Node*& position, Node*& value) const;
		void _updateMinimum();

		const int _FICTIVE_KEY = 0;

#ifdef  HEAP_TESTING
		FRIEND_TEST(BinomialHeapInternal, UpdateMinimum1);
		FRIEND_TEST(BinomialHeapInternal, UpdateMinimum2);
#endif // HEAP_TESTING

	};

};