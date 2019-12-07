#pragma once

namespace Heaps {
	class IHeap {
	public:
		virtual int GetMin() = 0;
		virtual int ExtractMin() = 0;
		virtual int InsertKey(int key) = 0;
		virtual bool Empty() = 0;
		virtual void Merge(IHeap*& otherHeap) = 0;
	};
};