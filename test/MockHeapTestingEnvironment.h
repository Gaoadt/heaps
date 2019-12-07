#pragma once
#include "IHeapTestingEnvironment.h"
#include <list>
#include <algorithm>
#include <vector>

namespace Heaps {
	namespace Testing {
		class MockHeapTestingEnvironment : public IHeapTestingEnvironment {
		public:
			virtual size_t AddHeap(int key) override;
			virtual void Insert(size_t index, int key) override;
			virtual size_t Meld(size_t index1, size_t index2) override;
			virtual int GetMin(size_t index) override;
			virtual int ExtractMin(size_t index) override;
			virtual bool ContainsHeap(size_t index) override;
		protected:
			std::vector<std::list<int>> _mockHeaps;
		};

	};
};