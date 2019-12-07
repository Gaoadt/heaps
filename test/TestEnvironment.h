#pragma once
#include "gtest/gtest.h"
#include "IHeapTestingEnvironment.h"
#include "MockHeapTestingEnvironment.h"

class HeapBehaviourTest : public testing::TestWithParam<Heaps::Testing::IHeapTestingEnvironment*> {};
