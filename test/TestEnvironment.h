#pragma once
#include "gtest/gtest.h"

#define HEAP_TESTING

#include "../src/HeapFactory.h"
#include "../src/LeftiestHeap.h"
#include "../src/SkewHeap.h"
#include "../src/BinomialHeap.h"
#include "IHeapTestingEnvironment.h"
#include "MockHeapTestingEnvironment.h"
#include "GeneralHeapTestingEnvironment.h"

#include <vector>
#include <algorithm>

class HeapBehaviourTest : public testing::TestWithParam<Heaps::Testing::IHeapTestingEnvironment*> {};
class HeapStressTest : public testing::TestWithParam < Heaps::Testing::IHeapTestingEnvironment*> {};

namespace Heaps {
	namespace Testing {
        std::string heapParamName(const testing::TestParamInfo<HeapBehaviourTest::ParamType>& info);
	}
}

