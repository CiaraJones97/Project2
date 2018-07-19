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
	//Vector for making a full and complete Binary Tree
	vector<string> nodestuff{ "XX", "XX", "XX", "XX", "XX", "NULL", "NULL", "XX", "NULL", "NULL", "XX", "XX", "NULL", "NULL", "XX", "NULL", "NULL", "XX", "XX", "XX","NULL", "NULL", "XX", "NULL", "NULL", "XX", "XX", "NULL", "NULL", "XX", "NULL", "NULL", "XX","XX", "XX", "XX", "NULL", "NULL", "XX", "NULL", "NULL", "XX", "XX", "NULL", "NULL", "XX", "NULL", "NULL", "XX", "XX", "XX", "NULL", "NULL", "XX", "NULL", "NULL", "XX", "XX", "NULL", "NULL", "XX", "NULL", "NULL" };
	map<char, string> myTree;
	string myString;

	Binary_Tree<string> Tree; //Tree is an object of Binary_Tree
	
	//Input the text file 
	ifstream infile;
	infile.open("morse.txt");

	//Take the data from the text file and put it into a map
	while (infile)
	{
		infile >> myString;
		char key = myString[0];
		string value = myString.substr(1, -1);
		myTree[key] = value;
	}
	
	//Put the information from the map into the Binary Tree
	Tree.insert(myTree, nodestuff);

	//Output the decoded and encoded messages
	cout <<"Decoded equals: "<< Tree.Decode("_.. ___ _.__ ___ .._ _._ _. ___ .__ _.. ._ .__ ._ .") << endl;
	cout <<"Encoded equals: " << Tree.Encode("Hello", myTree)<< endl;
	
	infile.close();
	system("pause");
	return 0;
}
