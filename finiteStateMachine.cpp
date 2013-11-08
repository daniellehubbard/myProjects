//Danielle Hubbard
//CMPS 3233
//Dr. Halverson
//November 5, 2013
//This program is a deterministic finite state machine for 
//a language with even length strings and at least 2 different characters

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

int main()
{
	ifstream infile;
	ofstream outfile;
	string fileName;
	string next;
	int state;
	int size=0;
	int count;
	int k=0;
	
	//get filename
	cout << "Please enter the name of your file." << endl;
	cin >> fileName;
	
	infile.open(fileName);
	outfile.open("output.txt");

	//read strings until end of file
	while(!infile.eof())
	{
		//begin in state 1
		state = 1;
		count = 0;

		//read in the string
		getline(infile, next);

		//get length of string
		size = next.size();

		//if empty string
		if(size==0)
		{
			state = 1;
		}
		
		//iterates through every character of string
		while(count < size)
		{
			//switch based on state character is sent to
			switch(state)
			{
				//state 1
				case 1: if(next[count] == 'a')
						{
							state = 2;
						}
						else if(next[count] == 'b')
						{
							state = 6;
						}
						else if(next[count] == 'c')
						{
							state = 8;
						}
						//character not in language sent to trap state
						else
						{
							state = 10;
						}
						break;
				//state 2
				case 2: if(next[count] == 'a')
						{
							state = 3;
						}
						else if(next[count] == 'b' || next[count] == 'c')
						{
							state = 5;
						}
						else
						{
							state = 10;
						}
						break;
				//state 3
				case 3: if(next[count] == 'a')
						{
							state = 2;
						}
						else if(next[count] == 'b' || next[count] == 'c')
						{
							state = 4;
						}
						else
						{
							state = 10;
						}
						break;
				//state 4
				case 4: if(next[count] == 'a' || next[count] == 'b' || next[count] == 'c')
						{
							state = 5;
						}
						else
						{
							state = 10;
						}
						break;
				//state 5
				case 5:	if(next[count] == 'a' || next[count] == 'b' || next[count] == 'c')
						{
							state = 4;
						}
						else
						{
							state = 10;
						}
						break;
				//state 6
				case 6:	if(next[count] == 'a' || next[count] == 'c')
						{
							state = 5;
						}
						else if(next[count] == 'b')
						{
							state = 7;
						}
						else
						{
							state = 10;
						}
						break;
				//state 7
				case 7:	if(next[count] == 'a' || next[count] == 'c')
						{
							state = 4;
						}
						else if(next[count] == 'b')
						{
							state = 6;
						}
						else
						{
							state = 10;
						}
						break;
				//state 8
				case 8:	if(next[count] == 'a' || next[count] == 'b')
						{
							state = 5;
						}
						else if(next[count] == 'c')
						{
							state = 9;
						}
						else
						{
							state = 10;
						}
						break;
				//state 9
				case 9:	if(next[count] == 'a' || next[count] == 'b')
						{
							state = 4;
						}
						else if(next[count] == 'c')
						{
							state = 8;
						}
						else
						{
							state = 10;
						}
						break;
				//state 10
			    case 10: state = 10;
			}

			count++;
		}

		//if count is 0, first string read in 
		if(k == 0)
		{
			outfile << "\n    Danielle Hubbard   \n" << endl;
			outfile << "\n Accepted & Rejected strings  \n" << endl;
		}

		//if count is 31, all of Danielle string's read in 
		if(k == 31)
		{
			outfile << "\n\n  Dr. Halverson's Strings  \n" << endl;
		}

		//if state is 5, string ended in accepting state
		if(state == 5)
		{
			outfile << left << setw(20) << next << setw(10) << ": Accept" << endl;
		}
		//string ended in rejecting state
		else
		{
			if(size == 0)
			{
				next = "Empty String";
			}

			outfile << left << setw(20) << next << setw(10) << ": Reject" << endl;
		}

		k++;
	
	}

	infile.close();
	outfile.close();

	return 0;
}

