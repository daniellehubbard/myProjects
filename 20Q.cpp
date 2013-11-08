//Programmer: Danielle Hubbard
//November 6, 2012
//This is a simple 20 questions program that accesses the QA Tree class
//to play a game with a user. 


#include "qatree.h"

//requires:user input
//ensures: returns true iff user enters Y or y
//checks: none
bool GetYesOrNo();

//requires: none
//ensures: prints intro message to screen
//checks: none
void Intro();

//requires: none
//ensures: prints exit message to screen
//checks: none
void Exit();

//requires: none
//ensures: asks user if they want to play a game by printing message
//to screen
//checks: none
void PlayAgain();

//requires: t is created
//ensures: knowledge is loaded into tree by calling class functions
//checks: none
void InitialKnowledge(QATree &t);

//requires: t's cursor is pointing to an item
//ensures: item is printed to the screen
//checks: none
void GetNext(QATree &t);

//requires: user input, tree t is created
//ensures: interacts with user to get more questions
//checks: none
void PlayGame(QATree &t);

//requires: tree t is created
//ensures: adds new knowledge to tree if it did not previously have it
//checks: none
void AmIRight(QATree &t);

//requires: tree t is created
//ensures: tree is saved to an output file if user desires
//checks: none
void StoreTree(QATree &t);


int main()
{
	Intro();
	QATree game;
	string item;
	
	//ask to load tree
	InitialKnowledge(game);
	PlayAgain();
	//while user still wants to play
	while(GetYesOrNo())
	{
		//move cursor back to root of tree
		game.ShiftToRoot();
		//interacts with user
		PlayGame(game);
		//checks if game is right
		AmIRight(game);
		PlayAgain();
		
	}
	//asks user to save tree
	StoreTree(game);
	Exit();


	system ("pause");
	return 0;


}


void Intro()
{
	cout << "Welcome to 20 Questions!" << endl;

}
void Exit()
{
	cout << "Thank you for playing!" << endl;
}
void PlayAgain()
{
	cout << "Do you have something in mind? Please enter Y for yes and N for no" << endl;
}

bool GetYesOrNo()
{
	bool yesanswer=false;
	char answer;
	cin >> answer;
	//if user gives a yes answer to a question
	if(answer == 'Y' || answer == 'y')
	{
		yesanswer=true;
	}

	//returns true iff user enters y or Y
	return yesanswer;

}

void InitialKnowledge(QATree &t)
{

	cout << "Would you like to load a QA database from a previous game? (Y or N)" << endl;
	//if user agrees to load database
	if(GetYesOrNo())
	{
		t.LoadQATree();
	}

}

void GetNext(QATree &t)
{
	string item;
	t.RetrieveItem(item);
	//prints next item in tree
	cout << item;

}


void PlayGame(QATree &t)
{
	//if there are no more questions, make a guess
	if(!t.MoreQuestions())
	{
		cout << "Is it a ";
		GetNext(t);
		cout << "?" << endl;
	}
	//ask questions
	else
	{
		GetNext(t);
		if(GetYesOrNo())
		{
			t.ProcessYesAnswer();
		}
		else
		{
			t.ProcessNoAnswer();
		}

		//recursive call after shifting
		PlayGame(t);
	}

}

void AmIRight(QATree &t)
{
	string guess;
	string user;
	string question;
	//right answer
	if(GetYesOrNo())
	{
		cout << "Yay! I'm smart!" << endl;

	}
	//wrong answer
	else
	{
		//collect information to add new knowledge
		t.RetrieveItem(guess);
		cout << "Darn, you've stumped me! Please help me learn so I won't be fooled again!" << endl;
		cout << "What were you thinking of?" << endl;
		cin >> user;
		cout << "What question can I use to differentiate between a " << guess << " and a " << user << "?" << endl;
		cin.get();
		getline(cin, question);
		cout << "Is the answer to that question yes or no for a(n) " << user << "?" << endl;
		//if user answers yes
		if(GetYesOrNo())
		{
			t.AddNewKnowledge(question, user, guess);
		}
		//if user answers no
		else
		{
			t.AddNewKnowledge(question, guess, user);
		}
		cout << "Thank you!!" << endl;
	}

}

void StoreTree(QATree &t)
{
	cout << "Would you like to save this database for future games?" << endl;
	//if user agrees to save database
	if(GetYesOrNo())
	{
		t.SaveQATree();
		cout << "Thank you! New knowledge is saved." << endl;
	}

}