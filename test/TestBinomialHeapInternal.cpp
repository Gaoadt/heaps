#include "TestEnvironment.h"
using namespace Heaps;

TEST(Heaps::BinomialHeapInternal, UpdateMinimum1) {
	BinomialHeap* heap = new BinomialHeap();
	heap->_binomialRoot()->childs.assign(4, nullptr);
	heap->_binomialRoot()->childs[3] = new BinomialHeap::Node(1);
	heap->_updateMinimum();
	ASSERT_EQ(heap->_binomialRoot()->minIndex, 3);
}

TEST(Heaps::BinomialHeapInternal, UpdateMinimum2) {
	BinomialHeap* heap = new BinomialHeap();
	heap->_binomialRoot()->childs.assign(4, nullptr);
	heap->_binomialRoot()->childs[3] = new BinomialHeap::Node(2);
	heap->_binomialRoot()->childs[2] = new BinomialHeap::Node(1);
	heap->_updateMinimum();
	ASSERT_EQ(heap->_binomialRoot()->minIndex, 2);

	heap->_binomialRoot()->childs[3] = new BinomialHeap::Node(1);
	heap->_binomialRoot()->childs[2] = new BinomialHeap::Node(2);
	heap->_updateMinimum();
	ASSERT_EQ(heap->_binomialRoot()->minIndex, 3);
	delete heap;
}

TEST(Heaps::BinomialHeapInternal, Merge3to1) {
	BinomialHeap heap1, heap2;
	heap1.InsertKey(2);
	heap2.InsertKey(3);
	heap2.InsertKey(4);
	heap2.InsertKey(5);
	heap1.Merge(&heap2);
	ASSERT_EQ(heap1._binomialRoot()->childs[0], nullptr);
	ASSERT_EQ(heap1._binomialRoot()->childs[1], nullptr);
	ASSERT_EQ(heap1._binomialRoot()->childs[2]->childs.size(), 2);
}