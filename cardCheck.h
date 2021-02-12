#ifndef CARDCHECK_H
#define CARDCHECK_H

using namespace std;

void cardCheck(char rank[], char suit[])
{
	//grabs 5 cards from player
	
	for (int i = 0; i < NUM; i++)
	{
		bool badinput = true;

		//checking for bad cards
		while (badinput)
		{
			cin >> rank[i] >> suit[i];
			bool goodinput = Input(rank[i], suit[i]);

			//checks for repeat cards
			bool doublecard = false;
			for (int count = 0; count < i; count++)
			{
				if (rank[count] == rank[i] && suit[count] == suit[i])
					doublecard = true;
			}
			if (goodinput == false)
				cout << "Bad Card. Please Reenter Another Card:\n";
			else if (doublecard == true)
				cout << "Card Already Entered. Please Reenter Another Card: \n";
			else
				badinput = false;
		}

	}
}

#endif