#ifndef BINARY_TREE_H
#define BINARY_TREE_H

/** Class for a binary tree. */

#include <cstddef>
#include <sstream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "BTNode.h"
#include <vector>
#include <map>
using namespace std;

template<typename Item_Type>
class Binary_Tree
{
public:

	void setRoot(BTNode<Item_Type>* newRoot);

	BTNode<Item_Type>* getRoot();

	// Constructors and Functions

	/** Construct an empty Binary_Tree. */
	Binary_Tree() : root(NULL) {}

	/** Construct a Binary_Tree with two subtrees.
	@param the_data The data at the root
	@param left_child The left subtree
	@param right_child The right subtree
	*/
	Binary_Tree(const Item_Type& the_data,
		const Binary_Tree<Item_Type>& left_child
		= Binary_Tree(),
		const Binary_Tree<Item_Type>& right_child
		= Binary_Tree()) :
		root(new BTNode<Item_Type>(the_data, left_child.root,
			right_child.root)) {}

	/** Virtual destructor to avoid warnings */
	virtual ~Binary_Tree() {} // Do nothing.


	//template<typename Item_Type>
	void insert(std::map<char, std::string>& item, vector<string> temp);

	string Decode(string morse);
	string Encode(string character, map<char, string> themap);

	Binary_Tree<Item_Type> read_tree(vector<string> temp);

	Binary_Tree<Item_Type> read_binary_tree(vector<string>& text, int& i);

	/** Return a string representation of the root */

protected:

	// Protected constructor
	/** Construct a Binary_Tree with a given node as the root */
	Binary_Tree(BTNode<Item_Type>* new_root) : root(new_root) {}

	// Data Field
	BTNode<Item_Type>* root;

};
template<typename Item_Type>
void Binary_Tree<Item_Type>::setRoot(BTNode<Item_Type>* new_root) {

	root = new_root;
}


template<typename Item_Type>
BTNode<Item_Type>* Binary_Tree<Item_Type>::getRoot() {

	return root;
}


// Implementation of member functions

template<typename Item_Type>
Binary_Tree<Item_Type> Binary_Tree<Item_Type>::read_tree(vector<string> temp) {
	int i = 0;
	string text = "XX";
	Binary_Tree<Item_Type> newTree = read_binary_tree(temp, i);
	setRoot(newTree.getRoot());

	return newTree;
}

template<typename Item_Type>
void Binary_Tree<Item_Type>::insert(map<char, string>& item, vector<string> temp)
{

	//To make an full empty tree
	Binary_Tree<Item_Type> parentTree = read_tree(temp);


	for (map<char, string>::iterator it = item.begin(); it != item.end(); it++)
	{
		int i = 0;
		int x = it->second.size();
		//root = parent_root->left;
		while (i < x)
		{
			if (it->second[i] == '.')
			{
				root = root->left;
				//parentTree.to_string();

			}

			else
			{
				if (it->second[i] == '_')
				{
					root = root->right;
				}

			}
			i++;

		}

		root->data = it->first;
		root = parentTree.getRoot();
	}
}
template<typename Item_Type>
string Binary_Tree<Item_Type>::Decode(string morse)
{
	//goes back to the root
	BTNode<Item_Type>* toproot = getRoot();
	root = toproot;

	int i = 0;
	string result = " "; 
	while (i < morse.size())
	{
		if (morse[i] == ' ') {
			result += root->data;
			root = toproot;
		}

		if (morse[i] == '.')
		{
			root = root->left;
			//parentTree.to_string();

		}

		else
		{
			if (morse[i] == '_')
			{
				root = root->right;
			}

		}
		i++;

	}
	result += root->data;


	return result; 
}

template<typename Item_Type>
string Binary_Tree<Item_Type>::Encode(string character, map<char, string> themap) {
	string result = " ";
	for (int i = 0; i < character.size(); i++) 
	{
			for (map<char, string>::iterator it = themap.begin(); it != themap.end(); it++)
			{
				if (character[i] == it->first) 
				{
				result += it->second;
				result += " ";
				}
			}
	}
	return result;

}

template<typename Item_Type>
Binary_Tree<Item_Type> Binary_Tree<Item_Type>::
read_binary_tree(vector<string>& text, int& i) {
	if (i > text.size()-1 || text[i] == "NULL")
	{
		return Binary_Tree<Item_Type>();
	}

	else {
		string txt = text[i];
		//i = i + 1;
		Binary_Tree<Item_Type> left = read_binary_tree(text, ++i);
		//i = i + 1;
		Binary_Tree<Item_Type> right = read_binary_tree(text, ++i);
		return Binary_Tree<Item_Type>(txt, left, right);
	}
}



#endif
