#include <string>
#include <iostream>
#include <fstream>
#include "BTNode.h"
#include "Binary_Tree.h"
#include <stdio.h>
#include <cctype>
#include <map>
using namespace std;

int main()
{
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
	for (map<char, string>::iterator it = myTree.begin(); it != myTree.end(); it++)
	{
		cout << it->first << " => " << it->second << endl;
		//cout << it->second.size() << endl;
	}
	
	Tree.insert(myTree);
	//Tree.read_tree(myTree);

	
	infile.close();
	system("pause");
	return 0;
}
