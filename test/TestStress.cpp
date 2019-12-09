#include "TestEnvironment.h"
#include "MockHeapTestingEnvironment.h"


#include <cmath>
#include <set>

using namespace Heaps;
using namespace Testing;

void StressTest(IHeapTestingEnvironment* env) {
	env->Clear();

	MockHeapTestingEnvironment* correctEnv = new MockHeapTestingEnvironment();

	const size_t OPERATIONS_COUNT = 100000;
	const size_t HEAPS_COUNT = 100;

	for (size_t i = 0; i < HEAPS_COUNT; ++i) {
		int key = rand();
		env->AddHeap(key);
		correctEnv->AddHeap(key);
	}

	for (size_t i = 0; i < OPERATIONS_COUNT; ++i) {
		int heap1 = rand() % HEAPS_COUNT;
		int heap2 = rand() % HEAPS_COUNT;
		int oper = rand() % 4;
		ASSERT_EQ(env->ContainsHeap(heap1), correctEnv->ContainsHeap(heap1));
		ASSERT_EQ(env->ContainsHeap(heap2), correctEnv->ContainsHeap(heap2));
		
		if (!env->ContainsHeap(heap1)) {
			continue;
		}

		switch (oper)
		{
		case 0: {
			ASSERT_EQ(env->GetMin(heap1), correctEnv->GetMin(heap1));
			break;
		}
		case 1: {
			ASSERT_EQ(env->ExtractMin(heap1), correctEnv->ExtractMin(heap1));
			break;
		}
		case 2: {
			int key = rand();
			env->Insert(heap1, key);
			correctEnv->Insert(heap1, key);
			break;
		}
		case 3: {
			if (!env->ContainsHeap(heap2)) {
				heap2 = env->AddHeap(0);
				heap2 = correctEnv->AddHeap(0);
			}

			env->Meld(heap1, heap2);
			correctEnv->Meld(heap1, heap2);

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
	new MockHeapTestingEnvironment(),
	new GeneralHeapTestingEnvironment(new HeapFactory<SkewHeap>()),
	new GeneralHeapTestingEnvironment(new HeapFactory<LeftiestHeap>()),
	new GeneralHeapTestingEnvironment(new HeapFactory<BinomialHeap>())
), Heaps::Testing::heapParamName);




