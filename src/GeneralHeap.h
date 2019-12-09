#pragma once
#include "IHeap.h"
namespace Heaps {
	class GeneralHeap : public IHeap {
	public:
		virtual void Merge(IHeap* otherHeap) override;
		virtual int ExtractMin() override;
	protected:
		virtual void _deleteMinimum() = 0;
	};
};