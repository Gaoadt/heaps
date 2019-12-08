#pragma once
#include "IHeapFactory.h"
namespace Heaps {
	template <typename T> class HeapFactory : public IHeapFactory {
		virtual IHeap* MakeHeap() override {
			return dynamic_cast<IHeap *>(new T());
		}

		virtual std::string HeapType() override {
			return typeid(T).name();
		}
	};
};