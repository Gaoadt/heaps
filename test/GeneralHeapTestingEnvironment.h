#pragma once
#include "../src/IHeapFactory.h"
#include "IHeapTestingEnvironment.h"
#include <vector>
namespace Heaps {
	namespace Testing {
	    class GeneralHeapTestingEnvironment : public IHeapTestingEnvironment {
		public:
			GeneralHeapTestingEnvironment(IHeapFactory *someFactory);
			virtual size_t AddHeap(int key) override;
			virtual void Insert(size_t index, int key) override;
			virtual size_t Meld(size_t index1, size_t index2) override;
			virtual int GetMin(size_t index) override;
			virtual int ExtractMin(size_t index) override;
			virtual bool ContainsHeap(size_t index) override;
			virtual std::string ToString() override;
			virtual void Clear() override;
			
		private:
			IHeapFactory* _factory;
			std::vector<IHeap*> _heaps;

		};
	};
};