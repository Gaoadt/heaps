#include "GeneralHeap.h"

void Heaps::GeneralHeap::Merge(IHeap* otherHeap)
{
	while (!otherHeap->Empty()) {
		InsertKey(otherHeap->ExtractMin());
	}
}

int Heaps::GeneralHeap::ExtractMin()
{
	int extractedMinimum = GetMin();
	_deleteMinimum();
	return extractedMinimum;

}
