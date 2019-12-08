#pragma once
#include "IHeap.h"
#include <string>
namespace Heaps {
	class IHeapFactory {
	public:
		virtual IHeap* MakeHeap() = 0;
		virtual std::string HeapType() = 0;
	};
};