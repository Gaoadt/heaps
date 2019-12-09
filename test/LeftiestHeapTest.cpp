#include "TestEnvironment.h"
#include "../src/LeftiestHeap.h"
#include <vector>
using namespace Heaps;
TEST(Heaps::LeftiestTest, Structure) {
	LeftiestHeap heap;
	std::vector<int> arr = { 1,4,3,2,6,7,8,9,2,5,4 };
	for (auto x : arr) {
		heap.InsertKey(x);
		heap._realRank(dynamic_cast<Heaps::LeftiestHeap::Node*>(heap._root));
	}

	for (size_t i = 0; i < 5; ++i) {
		heap.ExtractMin();
		heap._realRank(dynamic_cast<Heaps::LeftiestHeap::Node*>(heap._root));
	}
	heap._printHeap(dynamic_cast<Heaps::BinaryTreeBasedHeap::Node *>(heap._root));
}

TEST(Heaps::LeftiestTest, Ranks) {

}