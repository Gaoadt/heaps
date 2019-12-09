#include "TestEnvironment.h"
using namespace Heaps;
TEST(Heaps::BinomialHeapInternal, UpdateMinimum) {
	BinomialHeap* heap = new BinomialHeap();
	heap->_binomialRoot()->childs.assign(4, nullptr);
	heap->_binomialRoot()->childs[3] = new BinomialHeap::Node(1);
	heap->_updateMinimum();
	ASSERT_EQ(heap->_binomialRoot()->minIndex, 3);
}