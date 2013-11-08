//Danielle Hubbard


#include "QATree.h"
#include <iostream>
#include <fstream>
using namespace std;

QATree::QATree ()
{
	//just add one node and let the user know what the tree contains
	CreateFirstNode ("Dog");
	cout << "Your QATree contains the single answer: Dog" << endl;
}

//this function is called by LoadQATree
void QATree::DoLoad (ifstream & infile, char dir)
{
	string category;
	string text;
	//question or answer
	infile >> category;
	infile.get();
	getline(infile,text);
	//if not end of file and a question
	if(!infile.eof() && (category != "Answer"))
	{
		//create first node if tree is empty
		if(IsEmpty())
		{
			CreateFirstNode(text);
		}
		//add to left side of tree
		else if(dir == 'L')
		{
			AddLeft(text);
			ShiftLeft();
		}
		//add to right side of tree
		else
		{
			AddRight(text);
			ShiftRight();
		}
		//build left subtree
		DoLoad(infile, 'L');
		//build right subtree
		DoLoad(infile, 'R');
		//move back up tree
		if(HasParent())
		{
			ShiftUp();
		}
		

	}
	//if answer
	else if(category == "Answer")
	{
		//add to left
		if(dir == 'L')
		{
			AddLeft(text);
		
		}
		//add to right
		else if(dir == 'R')
		{
			AddRight(text);
	
		}
	}

	

} 

void QATree::LoadQATree ()
{
	
	//open input file
	ifstream infile;
	char infilename[40];
	cout << "Enter the name of an QAT file to load from: ";
	cin>> infilename;
	infile.open(infilename);

	//QAT is not empty, make it so
	ClearTree();

	
    //Load the QAT 
	DoLoad(infile, 'L');

    //close file 
	infile.close();

} 

//This is a local function called by SaveQATree
void QATree::DoSave (ofstream &outfile)
{
	string item;

	//get the node information 
	RetrieveItem(item);

	//leaf?
	if(HasNoChildren())
	{
	   //process a leaf (answer)
		outfile << "Answer\n";
		outfile << item << endl;

	}
	//otherwise
	else
	//process question
	{
		outfile << "Question\n";
		outfile << item << endl;

		//save left subtree
		if(HasLeftChild())
		{
			ShiftLeft();
			DoSave(outfile);
			ShiftUp();
		}

		//save right subtree
		if(HasRightChild())
		{
			ShiftRight();
			DoSave(outfile);
			ShiftUp();
		}

	}

	
 }


void QATree::SaveQATree ()
{
	//open output file
	ofstream outfile;
	char outfilename[40];
	cout << "Enter the name of an QAT file to save to: ";
	cin>> outfilename;
	outfile.open(outfilename);

	//Reset and Save QAT 
	ShiftToRoot();
	DoSave (outfile);

	//close file 
	outfile.close();
} 


void QATree::ProcessYesAnswer ()
{
  //1 line
	ShiftLeft();
}

void QATree::ProcessNoAnswer ()
{
  ShiftRight();
}

bool QATree::MoreQuestions ()
{
	bool more = false;
	//if cursor is not pointing to a leaf
	if(!HasNoChildren())
	{
		more = true;
	}

	return more;

}

void QATree::AddNewKnowledge (string question, string yesTxt, string noTxt)
{
	//if cursor points to a leaf
	if(HasNoChildren())
	{
		//change item cursor is pointing to
		ChangeItem(question);
		//add left side
		AddLeft(yesTxt);
		//add right side
		AddRight(noTxt);
	}
	//cursor has children, so knowledge can't be added
	else
	{
		cout << "Cannot add new knowledge, cursor is not at leaf\n";
	}
	
	//3 lines
}

