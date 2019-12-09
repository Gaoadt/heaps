#include "TestEnvironment.h"
#include "MockHeapTestingEnvironment.h"


#include <cmath>
#include <set>

using namespace Heaps;
using namespace Testing;

enum Operations {
	GetMin = 0,
	ExtractMin = 1,
	Insert = 2,
	Merge = 3
};

void StressTest(IHeapTestingEnvironment* env) {
	env->Clear();

//	MockHeapTestingEnvironment* correctEnv = new MockHeapTestingEnvironment();

	const size_t OPERATIONS_COUNT = 100000;
	const size_t HEAPS_COUNT = 100;

	for (size_t i = 0; i < HEAPS_COUNT; ++i) {
		int key = rand();
		env->AddHeap(key);
	//	correctEnv->AddHeap(key);
	}

	for (size_t i = 0; i < OPERATIONS_COUNT; ++i) {
		int heap1 = rand() % HEAPS_COUNT;
		int heap2 = rand() % HEAPS_COUNT;
		int oper;
		if (i < OPERATIONS_COUNT / 2) {
			oper = Operations::Insert;
		}
		else {
			oper = Operations::ExtractMin;
		}
	//	ASSERT_EQ(env->ContainsHeap(heap1), correctEnv->ContainsHeap(heap1));
	//	ASSERT_EQ(env->ContainsHeap(heap2), correctEnv->ContainsHeap(heap2));
		
		if (!env->ContainsHeap(heap1)) {
			continue;
		}

		switch (oper)
		{
		case Operations::GetMin: {
			env->GetMin(heap1);
			break;
		}
		case Operations::ExtractMin: {
			env->ExtractMin(heap1);
			break;
		}
		case Operations::Insert: {
			int key = rand();
			env->Insert(heap1, key);

			break;
		}
		case Operations::Merge: {
			if (!env->ContainsHeap(heap2)) {
				heap2 = env->AddHeap(0);

			}

			env->Meld(heap1, heap2);
			break;
		}

		default:
			break;
		}
	}
	
}

TEST_P(HeapStressTest, RandomStressTest) {
	const std::vector<int> seeds = { 0,1,2,343,235,1324,532 };
	for (std::vector<int>::const_iterator iter = seeds.cbegin(); iter != seeds.cend(); ++iter) {
		srand(*iter);
		StressTest(GetParam());
	}

}

INSTANTIATE_TEST_CASE_P(StressTest, HeapStressTest, testing::Values(
//  new MockHeapTestingEnvironment(),
  new GeneralHeapTestingEnvironment(new HeapFactory<SkewHeap>()),
	new GeneralHeapTestingEnvironment(new HeapFactory<LeftiestHeap>()),
  new GeneralHeapTestingEnvironment(new HeapFactory<BinomialHeap>())
), Heaps::Testing::heapParamName);




