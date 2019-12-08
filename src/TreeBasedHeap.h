#pragma once
#include "GeneralHeap.h"

namespace Heaps {
	class TreeBasedHeap : public GeneralHeap {
	public:
	protected:
		struct Node {
			Node(int someKey);
			virtual ~Node();
			
			int key;
		};
		virtual Node* _makeNode(int key);
		Node* _root = nullptr;
	};

};