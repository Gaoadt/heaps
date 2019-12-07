#pragma once
namespace Heaps {
	namespace Testing {
		class IHeapTestingEnvironment {
		public:

			virtual size_t AddHeap(int key) = 0;

			virtual void Insert(size_t index, int key) = 0;

			virtual void Meld(int index1, int index2) = 0;

			virtual int GetMin(int index) = 0;

			virtual int ExtractMin(int index) = 0;

		};
	};

};