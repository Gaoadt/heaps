#pragma once
namespace Heaps {
	namespace Testing {
		class IHeapTestingEnvironment {
		public:

			virtual size_t AddHeap(int key) = 0;

			virtual void Insert(size_t index, int key) = 0;

			virtual size_t Meld(size_t index1, size_t index2) = 0;

			virtual int GetMin(size_t index) = 0;

			virtual int ExtractMin(size_t index) = 0;

			virtual bool ContainsHeap(size_t index) = 0;
		};
	};

};