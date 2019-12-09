#include "TestEnvironment.h"

std::string Heaps::Testing::heapParamName(const testing::TestParamInfo<HeapBehaviourTest::ParamType>& info)
{
	IHeapTestingEnvironment* env = dynamic_cast<IHeapTestingEnvironment *>(info.param);
	return env->ToString();
}
