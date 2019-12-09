#pragma once
#include "GeneralHeap.h"
#include <vector>
namespace Heaps {
	class TreeBasedHeap : public GeneralHeap {
	public:
	protected:
		struct Node {
			Node(int someKey);
			virtual ~Node();
			virtual std::vector<Node*> GetChilds() = 0;

			int key;
		};
		virtual Node* _makeNode(int key) = 0;
		virtual void _deleteRecursively(Node* root);
		virtual ~TreeBasedHeap();

		Node* _root = nullptr;

	};

};