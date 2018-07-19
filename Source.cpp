#include <string>
#include <iostream>
#include <fstream>
#include "BTNode.h"
#include "Binary_Tree.h"
#include <stdio.h>
#include <cctype>
#include <map>
#include <vector>
using namespace std;

int main()
{
	vector<string> nodestuff{ "XX", "XX", "XX", "XX", "XX", "NULL", "NULL", "XX", "NULL", "NULL", "XX", "XX", "NULL", "NULL", "XX", "NULL", "NULL", "XX", "XX", "XX","NULL", "NULL", "XX", "NULL", "NULL", "XX", "XX", "NULL", "NULL", "XX", "NULL", "NULL", "XX","XX", "XX", "XX", "NULL", "NULL", "XX", "NULL", "NULL", "XX", "XX", "NULL", "NULL", "XX", "NULL", "NULL", "XX", "XX", "XX", "NULL", "NULL", "XX", "NULL", "NULL", "XX", "XX", "NULL", "NULL", "XX", "NULL", "NULL" };
	map<char, string> myTree;
	string myString;

	Binary_Tree<string> Tree; //Tree is an object of Binary_Tree
	
	ifstream infile;
	infile.open("morse.txt");

	while (infile)
	{
		infile >> myString;
		char key = myString[0];
		/*cout << key << endl;*/
		string value = myString.substr(1, -1);
		/*cout << value << endl;*/
		myTree[key] = value;
	}
	
	//cout << myTree['a'] << endl;

	
	Tree.insert(myTree, nodestuff);
	//Tree.read_tree(myTree);
	cout <<"Decoded equals: "<< Tree.Decode(".._. .._ _._. _._") << endl;
	cout <<"Encoded equals: " << Tree.Encode("ad", myTree)<< endl;
	
	infile.close();
	system("pause");
	return 0;
}
