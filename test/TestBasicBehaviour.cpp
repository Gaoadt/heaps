#pragma once
#include "TestEnvironment.h"
using namespace Heaps;
using namespace Testing;

TEST_P(HeapBehaviourTest, SimpleInsertAndExtractTest) {
			IHeapTestingEnvironment *environment = GetParam();
			size_t heap1 = environment->AddHeap(0);
			ASSERT_TRUE(environment->ContainsHeap(heap1));
			ASSERT_EQ(environment->ExtractMin(heap1), 0);
}

TEST_P(HeapBehaviourTest, MultipleInsertAndExtractTest) {
			IHeapTestingEnvironment* environment = GetParam();
			size_t heap1 = environment->AddHeap(3);
			environment->Insert(heap1, 2);
			environment->Insert(heap1, 1);
			environment->Insert(heap1, 0);
			ASSERT_TRUE(environment->ContainsHeap(heap1));
			ASSERT_EQ(environment->ExtractMin(heap1), 0);
			ASSERT_TRUE(environment->ContainsHeap(heap1));
			ASSERT_EQ(environment->ExtractMin(heap1), 1);
			ASSERT_TRUE(environment->ContainsHeap(heap1));
			ASSERT_EQ(environment->ExtractMin(heap1), 2);
			ASSERT_TRUE(environment->ContainsHeap(heap1));
			ASSERT_EQ(environment->ExtractMin(heap1), 3);
			ASSERT_FALSE(environment->ContainsHeap(heap1));
			
}

TEST_P(HeapBehaviourTest, LongInsertAndExtractTest) {
			IHeapTestingEnvironment* environment = GetParam();
			std::vector<int> values = { 12, 143, 13,23,345,1, -33, -40 };
			size_t heap1 = environment->AddHeap(values[0]);
			for (size_t i = 1; i < values.size(); ++i) {
				environment->Insert(heap1, values[i]);
			}
			std::sort(values.begin(), values.end());
			for (size_t i = 0; i < values.size(); ++i) {
				ASSERT_TRUE(environment->ContainsHeap(heap1));
				ASSERT_EQ(values[i], environment->GetMin(heap1));
				ASSERT_EQ(values[i], environment->ExtractMin(heap1));
			}
}

TEST_P(HeapBehaviourTest, SimpleMelding) {
	IHeapTestingEnvironment *environment = GetParam();
	int heap1 = environment->AddHeap(0);
	environment->Insert(heap1, 1);
	environment->Insert(heap1, 2);
	ASSERT_TRUE(environment->ContainsHeap(heap1));

	int heap2 = environment->AddHeap(3);
	environment->Insert(heap2, 4);
	environment->Insert(heap2, 5);
	ASSERT_TRUE(environment->ContainsHeap(heap2));

	int heap3 = environment->AddHeap(6);
	environment->Insert(heap3, 7);
	environment->Insert(heap3, 8);
	ASSERT_TRUE(environment->ContainsHeap(heap3));

	heap1 = environment->Meld(heap1, heap2);
	ASSERT_TRUE(environment->ContainsHeap(heap1));
	ASSERT_FALSE(environment->ContainsHeap(heap2));

	ASSERT_EQ(environment->ExtractMin(heap1), 0);
	ASSERT_EQ(environment->ExtractMin(heap1), 1);
	ASSERT_EQ(environment->ExtractMin(heap1), 2);
	ASSERT_EQ(environment->ExtractMin(heap1), 3);
	
	heap3 = environment->Meld(heap3, heap1);
	ASSERT_TRUE(environment->ContainsHeap(heap3));
	ASSERT_FALSE(environment->ContainsHeap(heap1));

	ASSERT_EQ(environment->ExtractMin(heap3), 4);
	ASSERT_EQ(environment->ExtractMin(heap3), 5);
	ASSERT_EQ(environment->ExtractMin(heap3), 6);
	ASSERT_EQ(environment->ExtractMin(heap3), 7);
	ASSERT_EQ(environment->ExtractMin(heap3), 8);

}

TEST_P(HeapBehaviourTest, MeldToMin) {
	IHeapTestingEnvironment* environment = GetParam();
	int heap1 = environment->AddHeap(0);
	int heap2 = environment->AddHeap(1);
	heap1 = environment->Meld(heap1, heap2);
	ASSERT_TRUE(environment->ContainsHeap(heap1));
	ASSERT_FALSE(environment->ContainsHeap(heap2));
	ASSERT_EQ(environment->ExtractMin(heap1), 0);
	ASSERT_EQ(environment->ExtractMin(heap1), 1);
}

TEST_P(HeapBehaviourTest, MeldToMax) {
	IHeapTestingEnvironment* environment = GetParam();
	int heap1 = environment->AddHeap(1);
	int heap2 = environment->AddHeap(0);
	heap1 = environment->Meld(heap1, heap2);
	ASSERT_TRUE(environment->ContainsHeap(heap1));
	ASSERT_FALSE(environment->ContainsHeap(heap2));
	ASSERT_EQ(environment->ExtractMin(heap1), 0);
	ASSERT_EQ(environment->ExtractMin(heap1), 1);
}

TEST_P(HeapBehaviourTest, MeldAndInsert ) {
	IHeapTestingEnvironment* environment = GetParam();
	int heap1 = environment->AddHeap(0);
	int heap2 = environment->AddHeap(3);
	environment->Insert(heap1, 13);
	environment->Insert(heap2, 12);
	heap1 = environment->Meld(heap1, heap2);

	ASSERT_TRUE(environment->ContainsHeap(heap1));
	ASSERT_FALSE(environment->ContainsHeap(heap2));

	ASSERT_EQ(environment->ExtractMin(heap1), 0);
	ASSERT_EQ(environment->ExtractMin(heap1), 3);

	int heap3 = environment->AddHeap(14);
	heap3 = environment->Meld(heap3, heap1);

	ASSERT_TRUE(environment->ContainsHeap(heap3));
	ASSERT_FALSE(environment->ContainsHeap(heap1));

	ASSERT_EQ(environment->ExtractMin(heap3), 12);
	ASSERT_EQ(environment->ExtractMin(heap3), 13);
	ASSERT_EQ(environment->ExtractMin(heap3), 14);
}



INSTANTIATE_TEST_CASE_P(BehaviourTest, HeapBehaviourTest, testing::Values(
//	new MockHeapTestingEnvironment(),
//	new GeneralHeapTestingEnvironment(new HeapFactory<SkewHeap>()),
//	new GeneralHeapTestingEnvironment(new HeapFactory<LeftiestHeap>()),
	new GeneralHeapTestingEnvironment(new HeapFactory<BinomialHeap>())
), Heaps::Testing::heapParamName);

