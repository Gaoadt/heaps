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
}