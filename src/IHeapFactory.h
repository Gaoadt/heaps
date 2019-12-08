#pragma once
#include "IHeap.h"
namespace Heaps {
	class IHeapFactory {
	public:
		virtual IHeap* MakeHeap() = 0;
	};
};