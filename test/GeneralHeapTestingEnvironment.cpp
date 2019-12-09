#include "GeneralHeapTestingEnvironment.h"

Heaps::Testing::GeneralHeapTestingEnvironment::GeneralHeapTestingEnvironment(IHeapFactory* someFactory)
{
	_factory = someFactory;
}

size_t Heaps::Testing::GeneralHeapTestingEnvironment::AddHeap(int key)
{
	size_t index = _heaps.size();
	_heaps.push_back(_factory->MakeHeap());
	Insert(index, key);
	return index;
}

void Heaps::Testing::GeneralHeapTestingEnvironment::Insert(size_t index, int key)
{
	_heaps[index]->InsertKey(key);
}

size_t Heaps::Testing::GeneralHeapTestingEnvironment::Meld(size_t index1, size_t index2)
{
	_heaps[index1]->Merge(_heaps[index2]);
	return index1;
}

int Heaps::Testing::GeneralHeapTestingEnvironment::GetMin(size_t index)
{
	return _heaps[index]->GetMin();
}

int Heaps::Testing::GeneralHeapTestingEnvironment::ExtractMin(size_t index)
{
	return _heaps[index]->ExtractMin();
}

bool Heaps::Testing::GeneralHeapTestingEnvironment::ContainsHeap(size_t index)
{
	if (_heaps.size() <= index)return false;
	if (_heaps[index] == nullptr)return false;
	return !_heaps[index]->Empty();
}

std::string Heaps::Testing::GeneralHeapTestingEnvironment::ToString()
{
	std::string heapTypeName = _factory->HeapType();
	std::string result = "GeneralEnvironment";
	std::string alphaNumerics = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890";
	for (std::string::iterator iter = heapTypeName.begin(); iter != heapTypeName.end(); ++iter) {
		if (alphaNumerics.find(*iter) < alphaNumerics.size()) {
			result.push_back(*iter);
		}
	}

	return result;
}

void Heaps::Testing::GeneralHeapTestingEnvironment::Clear()
{
	_heaps.clear();
}
