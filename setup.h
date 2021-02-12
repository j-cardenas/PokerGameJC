#ifndef SETUP_H
#define SETUP_H
#include "formulas.h"
using namespace std;



void setup (){
bool play = true;
	while (play == true)
	{
		string name[PLYR];
		char suit[PLYR][NUM];
		char rank[PLYR][NUM];
		char answer;
		bool lowAce[PLYR];
		int numRank[PLYR][NUM];
		int numPair[PLYR];
		bool straight[PLYR];
		bool flush[PLYR];
		bool royal[PLYR];
		int cardtype[PLYR];
		int highcard[PLYR];

		//Obtains name of players.
		for (int i = 0; i < PLYR; i++)
		{
			cout << "Player "<<i+1<<" what is your name?  ";
			getline(cin, name[i]);
			cout <<endl;
		}

		
		for (int i = 0; i < PLYR; i++)
		{
			cardCheck(rank[i], suit[i]);
			lowAce[i] = aceCheck(rank[i]);

			for (int count = 0; count < NUM; count++)
			{
				numRank[i][count] = numConvert(rank[i][count], lowAce[i]);
			}

			numPair[i] = checkPairs(rank[i]);
			straight[i] = checkStraight(numRank[i]);
			flush[i] = checkFlush(suit[i]);
			royal[i] = checkRoyal(straight[i], flush[i], numRank[i]);
		}

		for (int i = 0; i < PLYR; i++)
		{
			cardtype[i] = handStrength(straight[i], royal[i], flush[i], numPair[i]);
		}

		convertAce(numRank);

		for (int i = 0; i < PLYR; i++)
		{
			Sort(numRank[i]);
			highcard[i] = highCard(numRank[i], cardtype[i]);
		}

		for (int i = 0; i < PLYR; i++)
		{
			Display(name[i], cardtype[i], highcard[i], numRank[i], rank[i], suit[i]);
		}

		Winner(name, numRank, highcard, cardtype);

		bool error = true;
		while (error == true)
		{
			cout << "Play Again? (Y/N)\n";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				play = true;
				error = false;
			}
			else if (answer == 'n' || answer == 'N')
			{
				play = false;
				error = false;
			}
			else
			{
				cout << "ERROR: Please Type Again\n";
				error = true;
			}
		}
		cin.ignore();
	}

}
  #endif 
