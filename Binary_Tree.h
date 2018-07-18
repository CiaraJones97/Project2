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
//template<typename char>
//class BinaryTree
//{
//public:
//	class TreeNode
//	{
//	public:
//		char data;
//		int count;
//		TreeNode *left;
//		TreeNode *right;
//		TreeNode(char new_data)
//		{
//			data = new_data; left = NULL; right = NULL;
//		};
//

//	};
//	TreeNode *root;
//	BinaryTree(char root_data)
//	{
//		root = new TreeNode(root_data);
//	}
//	
//	//Destructor
//	~BinaryTree();
//};
//
//BinaryTree::~BinaryTree()
//{
//	delete root;
//}
template<typename Item_Type>
class Binary_Tree
{
public:

	void setRoot(BTNode<Item_Type>* newRoot);
	void setParent(BTNode<Item_Type>* newParent);

	BTNode<Item_Type>* getRoot();
	BTNode<Item_Type>* getParent();

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


							  /** Return the left subtree. */
	Binary_Tree<Item_Type> get_left_subtree() const;

	/** Return the right subtree. */
	Binary_Tree<Item_Type> get_right_subtree() const;

	bool isBinarySearch();

	void isBinarySearch(BTNode<Item_Type>* local_root, bool& result);
	
	//template<typename Item_Type>
	void insert(std::map<char, std::string>& item);

	/** Return the data field of the root.
	@throws std::invalid_argument if empty tree
	*/
	const Item_Type& get_data() const;

	/** Indicate that this is the empty tree. */
	bool is_null() const;

	/** Indicate that this tree is a leaf. */
	bool is_leaf() const;

	/** Return a string representation of this tree. */
	virtual std::string to_string() const;

	/** Read a binary tree */
	static Binary_Tree<Item_Type> read_binary_tree(std::istream& in);

	void read_tree(std::map<char, std::string>& text);

	Binary_Tree<Item_Type> read_binary_tree(map<char, string>& text, int& i);

	/** Return a string representation of the root */
	std::string root_to_string() const {
		return root->to_string();
	}


	/** Return a pre-order traversal of the tree */
	std::string pre_order() const {
		return pre_order(root);
	}



	/** Return a post-order traversal of the tree */
	std::string post_order() const {
		return post_order(root);
	}


	std::string in_order() const {
		return in_order(root);
	}



	int height() const {
		if (is_null()) return 0;
		return 1 + std::max(get_left_subtree().height(), get_right_subtree().height());
	}



	int number_of_nodes() const {
		if (is_null()) return 0;
		return 1 + get_left_subtree().number_of_nodes()
			+ get_right_subtree().number_of_nodes();
	}



protected:

	// Protected constructor
	/** Construct a Binary_Tree with a given node as the root */
	Binary_Tree(BTNode<Item_Type>* new_root) : root(new_root) {}

	// Data Field
	BTNode<Item_Type>* root;
	//BTNode<Item_Type>* parent_root;

private:


	std::string pre_order(const BTNode<Item_Type>* local_root) const;



	std::string post_order(const BTNode<Item_Type>* local_root) const;

	std::string in_order(const BTNode<Item_Type>* local_root) const;




};  // End Binary_Tree


	/*template<typename Item_Type>
	bool Binary_Tree<Item_Type>::isBinarySearch(){
	bool result=true;
	isBinarySearch(this->root,result);
	return result;
	}*/

template<typename Item_Type>
void Binary_Tree<Item_Type>::setRoot(BTNode<Item_Type>* new_root) {

	root = new_root;
}


template<typename Item_Type>
BTNode<Item_Type>* Binary_Tree<Item_Type>::getRoot() {

	return root;
}


// Overloading the ostream insertion operator.
template<typename Item_Type>
std::ostream& operator<<(std::ostream& out,
	const Binary_Tree<Item_Type>& tree)
{
	return out << tree.to_string();
}

// Overloading the istream extraction operator
template<typename Item_Type>
std::istream& operator>>(std::istream& in,
	Binary_Tree<Item_Type>& tree)
{
	tree = Binary_Tree<Item_Type>::read_binary_tree(in);
	return in;
}

// Implementation of member functions


// Accessors
/** Return the left-subtree. */
template<typename Item_Type>
Binary_Tree<Item_Type>
Binary_Tree<Item_Type>::get_left_subtree() const {
	if (root == NULL) {
		throw std::invalid_argument("get_left_subtree on empty tree");
	}
	return Binary_Tree<Item_Type>(root->left);
}


/** Return the right-subtree */
template<typename Item_Type>
Binary_Tree<Item_Type>
Binary_Tree<Item_Type>::get_right_subtree() const {
	if (root == NULL) {
		throw std::invalid_argument("get_right_subtree on null tree");
	}
	return Binary_Tree<Item_Type>(root->right);
}

/** Return the data field of the root
@throws std::invalid_argument if null tree
*/
template<typename Item_Type>
const Item_Type& Binary_Tree<Item_Type>::get_data() const {
	if (root == NULL) {
		throw std::invalid_argument("get_data on null tree");
	}
	return root->data;
}

template<typename Item_Type>
bool Binary_Tree<Item_Type>::is_null() const {
	return root == NULL;
}

/** Indicate that this tree is a leaf. */
template<typename Item_Type>
bool Binary_Tree<Item_Type>::is_leaf() const {
	if (root != NULL) {
		return root->left == NULL && root->right == NULL;
	}
	else
		return true;
}

/** Return a string representation of this tree */
template<typename Item_Type>
std::string Binary_Tree<Item_Type>::to_string() const {
	std::ostringstream os;
	if (is_null())
		cout << "NULL\n";
	else {
		cout <<  root->data << '\n';
		cout << get_left_subtree().to_string();
		cout << get_right_subtree().to_string();
	}
	return os.str();
}

/*string_tokenizer st(line, "+ ");
while (st.has_more_tokens()) {
string term = st.next_token();*/

template<typename Item_Type>
void Binary_Tree<Item_Type>::read_tree(map<char, string>& text) {
	int i = 0;
	Binary_Tree<Item_Type> newTree = read_binary_tree(text, i);
	setRoot(newTree.getRoot());
}


template<typename Item_Type>
void Binary_Tree<Item_Type>::insert(map<char, string>& item)
{
	string txt = "T";
	/*Binary_Tree<Item_Type> left = Binary_Tree<Item_Type>("East", string("West"), NULL);*/
	Binary_Tree<Item_Type> right = Binary_Tree<Item_Type>("A", string("B"), string("C"));

	Binary_Tree<Item_Type> left = string("TEST");
	Binary_Tree<Item_Type> parentTree = Binary_Tree<Item_Type>(txt, left, right);

	//Binary_Tree<Item_Type> parentTree = Binary_Tree<Item_Type>("T", string("X"), string("TEST"));

	setRoot(parentTree.getRoot());
	cout << "TO STRING: " << endl;
	parentTree.to_string();
	
	/*cout << root->data << endl 
		<< parentTree.get_left_subtree() << parentTree.get_right_subtree() << endl;*/

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
				root->data = '7';
				cout << "NEXT TREE PHASE" << endl;
				parentTree.to_string();
				

				
			}

			else
			{
				if (it->second[i] == '-')
				{
					root = root->right;
				}

			}
			i++;
		

		}

		root->data = it->first;
		cout << root->data;
	}
}

template<typename Item_Type>
Binary_Tree<Item_Type> Binary_Tree<Item_Type>::
read_binary_tree(std::map<char, string>& text, int& i) {

	if (i>text.size() - 1 || text[i] == "NULL") {
		return Binary_Tree<Item_Type>();
	}
	else {
		std::string txt = text[i];
		//i = i + 1;
		Binary_Tree<Item_Type> left = read_binary_tree(text, ++i);
		//i = i + 1;
		Binary_Tree<Item_Type> right = read_binary_tree(text, ++i);
		return Binary_Tree<Item_Type>(txt, left, right);
	}
}

template<typename Item_Type>
Binary_Tree<Item_Type> Binary_Tree<Item_Type>::
read_binary_tree(std::istream& in) {
	std::string next_line;
	getline(in, next_line);
	if (next_line == "NULL") {
		return Binary_Tree<Item_Type>();
	}
	else {
		Item_Type the_data;
		std::istringstream ins(next_line);
		ins >> the_data;
		Binary_Tree<Item_Type> left = read_binary_tree(in);
		Binary_Tree<Item_Type> right = read_binary_tree(in);
		return Binary_Tree<Item_Type>(the_data, left, right);
	}
}

#endif

