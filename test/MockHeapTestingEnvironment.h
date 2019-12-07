#pragma once
#include "IHeapTestingEnvironment.h"
namespace Heaps {
	namespace Testing {
		class MockHeapTestingEnvironment : public IHeapTestingEnvironment {
			virtual size_t AddHeap(int key) override;
			virtual void Insert(size_t index, int key) override;
			virtual void Meld(int index1, int index2) override;
			virtual int GetMin(int index) override;
			virtual int ExtractMin(int index) override;
		};

	};
};