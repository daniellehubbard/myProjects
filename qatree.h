//This class inherits from BTree 
//It is a binary tree specifically designed for a question 
//and answer game 

#include "BTree.h"
#include <string>
#include <fstream>
using namespace std;

class QATree : public BTree <string>
{

public:

QATree ();
/*precond:  QAT is not created
 postcond: QAT is created and is initialized to the single answer 'Dog'.
 checks:   none*/

void LoadQATree ();
/*precond:  QAT is created and is not empty
 postcond: The user is asked to select an input file containing a QA
           database representing a QATree in prefix notation.  The QA
           database will be read and QAT will be a tree representing the
           QA database
 checks:   none */

void SaveQATree ();
/*precond:  QAT is created and is not empty
 postcond: The user is asked to select an output file and the items in
           QAT will be written to the file as a QA databaes in prefix
           notation.  QAT's cursor will be at the root, otherwise QAT is
           not changed.
 checks:   QAT is not empty */

void ProcessYesAnswer ();
/*precond:  QAT is created and the cursor is not at a leaf and not at end
 postcond: QAT's cursor is advanced to the left child of the item, otherwise
           QAT is unchanged
 checks:   none  */

void ProcessNoAnswer ();
/*precond:  QAT is created and the cursor is not at a leaf and not at end
 postcond: QAT's cursor is advanced to the right child of the item, otherwise
           QAT is unchanged
 checks:   none  */

bool MoreQuestions ();
/*precond:  QAT is created
 postcond: MoreQuestions (QAT) = TRUE iff QAT is not a leaf
 checks:   none */

void AddNewKnowledge (string question, string yesTxt, string noTxt);
/*precond: QAT is created and QAT's cursor is at a leaf
 postcond: Item in the current node is changed to the question.
           left and right nodes are added using yesTxt and noTxt, respectively.
		   QAT is unchanged otherwise.
 checks:   QAT's cursor is at a leaf */

private:

void DoLoad (ifstream & infile,  char dir);
/*precond:  infile is open, char is 'L' or 'R'
  postcond: subtree of QAT is loaded from infile
  checks:   none */

void DoSave (ofstream &outfile);
/*precond:  QAT is created and is not empty
  postcond: subtree of QAT is saved to outfile
  checks:   none */

};
