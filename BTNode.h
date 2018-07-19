#pragma once
#ifndef BTNODE_H_
#define BTNODE_H_
#include <sstream>
#include <map>
#include <set>

/** A node for a Binary Tree. */
template<typename Item_Type>
struct BTNode
{
	// Data Fields
	Item_Type data;
	BTNode* left;
	BTNode* right;

	// Constructor
	BTNode(const Item_Type& the_data,
		BTNode<Item_Type>* left_val = NULL,
		BTNode<Item_Type>* right_val = NULL) :
		data(the_data), left(left_val), right(right_val) {}

	// Destructor (to avoid warning message)
	virtual ~BTNode() {}

	// to_string
	virtual std::string to_string() const {
		std::ostringstream os;
		os << data;
		return os.str();
	}
}; // End BTNode


#endif
