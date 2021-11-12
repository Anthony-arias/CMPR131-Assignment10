// optionThree.h

#ifndef OPTION_THREE_LOCK
#define OPTION_THREE_LOCK
#include <iostream>
#include <fstream>
#include <string>
#include "input.h"
#include "bTree.h"
#include "binary_tree_node.h"
using namespace std;

binary_tree_node<string>* default_tree();
void play(binary_tree_node<string>* current_ptr);
void askAndMove(binary_tree_node<string>*& current_ptr);
void learn(binary_tree_node<string>* leaf_ptr);
void writeTreeToFile(binary_tree_node<string>* ptr, ostream& outs);
void readTreeFromFile(binary_tree_node<string>*& ptr, istream& ins);
bool inquire(string prompt);

//Precondition: NA
//Postcondition: returns a pointer to the root node of a taxonomic tree containing a few default questions and answers
binary_tree_node<string>* default_tree()
{
	binary_tree_node<string>* root_ptr;
	binary_tree_node<string>* child_ptr;

	const string root_question("Is it a mammal?");
	const string left_question("Does it have stripes?");
	const string right_question("Is it a bird?");
	const string animal1("zebra");
	const string animal2("lion");
	const string animal3("eagle");
	const string animal4("gila monster");

	// Create the root node
	root_ptr = new binary_tree_node<string>(root_question);

	// Create and attach the left subtree
	child_ptr = new binary_tree_node<string>(left_question);
	child_ptr->setLeft(new binary_tree_node<string>(animal1));
	child_ptr->setRight(new binary_tree_node<string>(animal2));
	root_ptr->setLeft(child_ptr);

	// Create and attach the right subtree
	child_ptr = new binary_tree_node<string>(right_question);
	child_ptr->setLeft(new binary_tree_node<string>(animal3));
	child_ptr->setRight(new binary_tree_node<string>(animal4));
	root_ptr->setRight(child_ptr);

	return root_ptr;
}

//Precondition: current_ptr is a pointer to the root node of a populated binary tree of strings
//Postcondition: plays a guessing game with the user. If the computer fails to guess the animal the user is thinking of, a new question and answer will be added to the tree.
void play(binary_tree_node<string>* current_ptr)
{
	cout << "\n\tThink of an animal, then press any key to continue.\n\n";
	system("pause");

	while (!current_ptr->isLeaf())
		askAndMove(current_ptr);
	cout << ("\n\tMy guess is " + current_ptr->getData() + ". ");
	if (!inquire("\n\tAm I right? (Y/Yes or N/No): "))
	{
		learn(current_ptr);
		cout << "\n\tThanks for teaching me a thing or two.\n\n";
	}
	else
		cout << "\n\tI knew it all along!\n";
}

//Precondition: current_ptr is a pointer to the root node of a populated binary tree of strings
//Postcondition: prints a question, prompts user for a yes or no answer, then moves the pointer throughout the tree accordingly
void askAndMove(binary_tree_node<string>*& current_ptr)
{
	cout << "\n\t" << current_ptr->getData();
	if (inquire("\n\tPlease answer (Y/Yes or N/No): "))
		current_ptr = current_ptr->getLeft();
	else
		current_ptr = current_ptr->getRight();
}

//Precondition: leaf_ptr is a pointer to a current leaf of the tree containing the animal that was incorrectly guessed
//Postcondition: prompts user for the correct animal, asks user for a question to relate to the animal, then adds new information to the tree accordingly
void learn(binary_tree_node<string>* leaf_ptr)
{
	string guess_animal; // the animal that was just guessed
	string correct_animal; // the animal that the user was thinking of
	string new_question; // question to distinguish the two animals

	cin.ignore();

	// set strings for guessed animal, correct animal, and a new question.
	guess_animal = leaf_ptr->getData();
	correct_animal = inputString("\n\tI give up. What are you?: ", true);

	cout << "\n\tPlease type a yes/no question that will distinguish a " << correct_animal << " from a " << guess_animal << ".";
	new_question = inputString("\n\tYour question: ", true);

	// put new question in current node and add two new children.
	leaf_ptr->setData(new_question);
	cout << "\n\tAs a " << correct_animal << ", " << new_question;
	if (inquire("\n\tPlease answer (Y/Yes or N/No): "))
	{
		leaf_ptr->setLeft(new binary_tree_node<string>(correct_animal));
		leaf_ptr->setRight(new binary_tree_node<string>(guess_animal));
	}
	else
	{
		leaf_ptr->setLeft(new binary_tree_node<string>(guess_animal));
		leaf_ptr->setRight(new binary_tree_node<string>(correct_animal));
	}
}

//Precondition: ptr is a pointer to the root node of a populated binary tree of strings, and outs is a reference to the file to be written to
//Postcondition: writes data from tree to file in a pre-order traversal format, where '*' represents a null node
void writeTreeToFile(binary_tree_node<string>* ptr, ostream& outs)
{
	if (ptr == nullptr) //stopping case, null pointer
		outs << "#\n"; //represents null node
	else
	{
		//pre-order traversal
		outs << ptr->getData() << '\n';
		writeTreeToFile(ptr->getLeft(), outs);
		writeTreeToFile(ptr->getRight(), outs);
	}
}

//Precondition: ptr is a pointer to an empty binary tree of strings
//Postcondition: reads data from file into tree
void readTreeFromFile(binary_tree_node<string>*& ptr, istream& ins)
{
	string current;
	if (ins.eof()) //stopping case 1, eof
	{
		return;
	}
	else
	{
		getline(ins, current, '\n');

		if (current == "#") //stopping case 2, null node
			return;
		else
		{
			//pre-order traversal
			ptr = new binary_tree_node<string>(current);
			readTreeFromFile(ptr->getLeft(), ins);
			readTreeFromFile(ptr->getRight(), ins);
		}
	}
}

//Precondition: N/A
//Postcondition: prints prompt, then retrieves a yes or no answer from the user. If the user responds yes, returns true, else if the user responds no, returns false.
bool inquire(string prompt)
{
	char answer = inputChar(prompt, 'Y', 'N');
	if (toupper(answer) == 'Y')
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif
