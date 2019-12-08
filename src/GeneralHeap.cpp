#include "GeneralHeap.h"

void Heaps::GeneralHeap::Merge(IHeap* otherHeap)
{
	while (!otherHeap->Empty()) {
		InsertKey(otherHeap->ExtractMin());
	}
}
