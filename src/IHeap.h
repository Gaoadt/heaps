#pragma once

namespace Heaps {
	class IHeap {
	public:
		virtual int GetMin() const = 0;
		virtual int ExtractMin() = 0;
		virtual void InsertKey(int key) = 0;
		virtual bool Empty() const  = 0;
		virtual void Merge(IHeap* otherHeap) = 0;
	};
};