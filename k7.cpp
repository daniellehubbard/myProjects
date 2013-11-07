//Danielle Hubbard
//Computer Security
//June 29, 2013
//This program generates a password with a random
//number generator, and then uses exhaustive search
//to find the password and displays the number of iterations required.


#include<iostream>
#include"stdlib.h"
#include<string>
#include<time.h>



using namespace std;

const int k=7;

unsigned long FindPassword(char pass[]);


int main()
{
	
	unsigned long num;
	char X;
	char password[k];

	srand(time(NULL));
	//generate password
	for(int i=0;i<k;i++)
	{
		password[i] = (rand() %26) + 'A';
		cout << password[i];
	}

	

	
	num = FindPassword(password);
	cout << "Cracking the password of " << k << " characters took ";
	cout << num << " iterations." << endl;

	
	return 0;
}


unsigned long FindPassword(char pass[])
{
	
	bool right=false;
	int count=1;
	int i=k-1;
	string guess="AAAAAAA";
	
	//circulates and increments letters from left to right

	while((right == false) && (guess[0] <90))
	{
		while((right == false) && (guess[1] < 90))
		{
			while((right == false) && (guess[2] <90))
			{
				while((right == false) && (guess[3] <90))
				{
					while((right == false) && (guess[4] <90))
					{
						while((right == false) && (guess[5]<90))
						{
							while((right==false) && (guess[6] <90))
							{

								if(guess.compare(0,k,pass,k) == 0)
								{
									right = true;
								}
								else
								{
									guess[i]++;
									count++;
								}


							}
							if(right == false)
							{
								guess[6]=guess[6]-25;
								guess[5]++;
							}
						}

						if(right == false)
						{
							guess[5]=guess[5]-25;
							guess[4]++;
						}

			
			
					}

						if(right == false)
						{
							guess[4]=guess[4]-25;
							guess[3]++;
						}

				}

				if(right == false)
				{
					guess[3]=guess[3]-25;
					guess[2]++;
				}
			}
		
				if(right == false)
				{
					guess[2]=guess[2]-25;
					guess[1]++;
				}
		}

		if(right == false)
		{
			guess[1]=guess[1]-25;
			guess[0]++;
		}

	}
		

	return count;
}
