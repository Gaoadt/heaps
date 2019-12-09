#include "MockHeapTestingEnvironment.h"

size_t Heaps::Testing::MockHeapTestingEnvironment::AddHeap(int key)
{
	_mockHeaps.push_back(std::list<int>(1, key));
	return _mockHeaps.size() - 1;
}

void Heaps::Testing::MockHeapTestingEnvironment::Insert(size_t index, int key)
{
	_mockHeaps[index].push_back(key);
	_mockHeaps[index].sort();
}

size_t Heaps::Testing::MockHeapTestingEnvironment::Meld(size_t index1, size_t index2)
{
	_mockHeaps[index1].merge(_mockHeaps[index2]);
	return index1;
}

int Heaps::Testing::MockHeapTestingEnvironment::GetMin(size_t index)
{
	return *_mockHeaps[index].begin();
}

int Heaps::Testing::MockHeapTestingEnvironment::ExtractMin(size_t index)
{
	int extractedMinimum = GetMin(index);
	_mockHeaps[index].pop_front();
	return extractedMinimum;
}

bool Heaps::Testing::MockHeapTestingEnvironment::ContainsHeap(size_t index)
{
	if (index >= _mockHeaps.size())return false;
	return !_mockHeaps[index].empty();
}

std::string Heaps::Testing::MockHeapTestingEnvironment::ToString()
{
	return "MockEnvironment";
}

void Heaps::Testing::MockHeapTestingEnvironment::Clear()
{
	_mockHeaps.clear();
}
