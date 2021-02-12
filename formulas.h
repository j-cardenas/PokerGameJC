#ifndef FORMULAS_H
#define FORMULAS_H
using namespace std;

const int NUM = 5; //Number of cards in hand
const int PLYR = 2; //Number of players

void cardCheck(char[], char[]);
bool Input(char, char);
bool aceCheck(char[]);
void Sort(int[]);
void swap(int&, int&);
int numConvert(char, bool);
bool checkStraight(int[]);
bool checkFlush(char[]);
bool checkRoyal(bool, bool, int[]);
int checkPairs(char[]);
void convertAce(int[][NUM]);
void Display(string, int, int, int[], char[], char[]);
int handStrength(bool, bool, bool, int);
int highCard(int[], int);
int Kickers(int[][NUM], int[]);
string convertSuit(char);
string cardInfo(int, int, int[], char[]);
void Winner(string[], int[][NUM], int[], int[]);

void cardCheck(char rank[], char suit[])
{
	//grabs 5 cards from player
	cout << "Enter the 5 cards in your hand\n";
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
//checks for unauthorized cards
bool Input(char rank, char suit)
{
	bool rankgood;
	bool suitgood;

	switch (rank)
	{
	case '2':
		rankgood = true;
	case '3':
		rankgood = true;
	case '4':
		rankgood = true;
	case '5':
		rankgood = true;
	case '6':
		rankgood = true;
	case '7':
		rankgood = true;
	case '8':
		rankgood = true;
	case '9':
		rankgood = true;
	case 'T':
		rankgood = true;
	case 'J':
		rankgood = true;
	case 'Q':
		rankgood = true;
	case 'K':
		rankgood = true;
	case 'A':
		rankgood = true;
		break;
	default:
		rankgood = false;
		break;
	}

	switch (suit)
	{
	case 'D':
		suitgood = true;
	case 'C':
		suitgood = true;
	case 'S':
		suitgood = true;
	case 'H':
		suitgood = true;
		break;
	default:
		suitgood = false;
		break;
	}
	return (rankgood && suitgood);
}

bool aceCheck(char rank[])
{
	for (int i = 0; i < NUM; i++)
	{
		if ((rank[i] - 48) > 5 && rank[i] != 'A')
		{
			return false;
		}
	}
	return true;
}

int numConvert(char rank, bool lowAce)
{
	switch (rank)
	{
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case 'T':
		return 10;
	case 'J':
		return 11;
	case 'Q':
		return 12;
	case 'K':
		return 13;
	case 'A':
	{
		if (lowAce)
		{
			return 1;
		}
		return 14;
	}
	default:
		return 0;
	}
}

void convertAce(int numRank[][NUM])
{
	for (int count = 0; count < PLYR; count++)
	{
		for (int i = 0; i < NUM; i++)
		{
			if (numRank[count][i] == 1)
			{
				numRank[count][i] = 14;
			}
		}
	}
}

void Sort(int rank[])
{
	int highcard;
	int index;

	for (highcard = NUM - 1; highcard > 0; highcard--)
	{
		for (index = 0; index < highcard; index++)
		{
			if (rank[index] < rank[index + 1])
			{
				swap(rank[index], rank[index + 1]);
			}
		}
	}
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

bool checkStraight(int rank[])
{
	int maxcard = rank[0];
	int mincard = rank[0];
	bool straight = true;
	int count = 1;

	while (straight)
	{
		straight = false;
		for (int i = 1; i < NUM; i++)
		{
			if ((maxcard + 1) == rank[i])
			{
				maxcard = rank[i];
				straight = true;
				count++;
			}
			else if ((mincard - 1) == rank[i])
			{
				mincard = rank[i];
				straight = true;
				count++;
			}
		}
	}

	if (count == 5)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

bool checkFlush(char suit[])
{
	bool flush = true;

	for (int i = 0; i < (NUM - 1); i++)
	{
		if (suit[i] != suit[(i + 1)])
		{
			flush = false;
		}
	}

	return (flush);
}

bool checkRoyal(bool check, bool check2, int rank[])
{
	if (check == true && check2 == true)
	{
		for (int i = 0; i < NUM; i++)
		{
			if (rank[i] == 14)
				return true;
		}
	}
	return false;
}

int checkPairs(char rank[])
{
	int numPair = 0;

	for (int i = 0; i < (NUM - 1); i++)
	{
		if (rank[i] == rank[(i + 1)])
		{
			numPair++;
		}
	}
	for (int i = 0; i < (NUM - 2); i++)
	{

		if (rank[i] == rank[(i + 2)])
		{
			numPair++;
		}
	}
	for (int i = 0; i < (NUM - 3); i++)
	{

		if (rank[i] == rank[(i + 3)])
		{
			numPair++;
		}
	}
	for (int i = 0; i < (NUM - 4); i++)
	{

		if (rank[i] == rank[(i + 4)])
		{
			numPair++;
		}
	}
	return (numPair);
}

int highCard(int rank[], int cardtype)
{
	if (cardtype == 10) //Royal Flush
	{
		return 14;
	}
	else if (cardtype == 9 || cardtype == 5)//Straight Flush, Straight
	{
		if (rank[1] == 5)
			return rank[1];
		else
			return(rank[0]);
	}
	else if (cardtype == 6 || cardtype == 1) //Flush & HighCard
	{
		return(rank[0]);
	}
	else if (cardtype == 8 || cardtype == 7 || cardtype == 4) //Four of a Kind, Full House & Three of a Kind
	{
		return rank[2];
	}
	else if (cardtype == 3) //Two Pair
	{
		return rank[1];
	}
	else if (cardtype == 2) //Pair
	{
		for (int i = 0; i < (NUM - 1); i++)
		{
			if (rank[i] == rank[i + 1])
				return rank[i];
		}
	}
	return 0;
}

int Kickers(int rank[][NUM], int cardtype[])
{
	if (cardtype[0] == 6 || cardtype[0] == 1) //Flush & HighCard
	{
		for (int i = 1; i < NUM; i++)
		{
			if (rank[0][i] < rank[1][i])
			{
				return 2;
			}
			else if (rank[0][i] > rank[1][i])
			{
				return 1;
			}
		}

		return 0;
	}
	else if (cardtype[0] == 3) //Two Pair
	{
		if (rank[0][3] < rank[1][3])
		{
			return 2;
		}
		else if (rank[0][3] > rank[1][3])
		{
			return 1;
		}
		else if (rank[0][3] == rank[1][3])
		{
			int finalkicker[PLYR];

			for (int i = 0; i < PLYR; i++)
			{
				if (rank[i][0] != rank[i][1])
				{
					finalkicker[i] = rank[i][0];
				}
				else if (rank[i][3] != rank[i][4])
				{
					finalkicker[i] = rank[i][4];
				}
				else
				{
					finalkicker[i] = rank[i][2];
				}
			}

			if (finalkicker[0] < finalkicker[1])
			{
				return 2;
			}
			else if (finalkicker[0] > finalkicker[1])
			{
				return 1;
			}
			else if (finalkicker[0] == finalkicker[1])
			{
				return 0;
			}
			return 0;
		}
	}
	else if (cardtype[0] == 2) //Pair
	{
		int index[PLYR];

		for (int i = 0; i < PLYR; i++)
		{
			index[i] = 0;
		}

		for (int i = 0; i < (NUM - 2); i++)
		{
			for (int count = 0; count < PLYR; count++)
			{
				if (rank[count][i + index[count]] == rank[count][i + index[count] + 1])
				{
					index[count] += 2;
				}
			}

			if (rank[0][i + index[0]] < rank[1][i + index[1]])
			{
				return 2;
			}
			else if (rank[0][i + index[0]] > rank[1][i + index[1]])
			{
				return 1;
			}
		}
		return 0;
	}

	return 0;
}

string convertSuit(char suit)
{
	switch (suit)
	{
	case 'D':
		return "Diamonds";
	case 'H':
		return "Hearts";
	case 'C':
		return "Clubs";
	case 'S':
		return "Spades";
	default:
		return "0";
	}
}

string convertRank(int highcard)
{
	switch (highcard)
	{
	case 2:
		return "2";
	case 3:
		return "3";
	case 4:
		return "4";
	case 5:
		return "5";
	case 6:
		return "6";
	case 7:
		return "7";
	case 8:
		return "8";
	case 9:
		return "9";
	case 10:
		return "T";
	case 11:
		return "J";
	case 12:
		return "Q";
	case 13:
		return "K";
	case 14:
	case 1:
		return "A";
	default:
		return "E";
	}
}

string cardInfo(int cardtype, int highcard, int rank[], char suit[])
{
	if (cardtype == 10) //Royal Flush
	{
		return convertSuit(suit[0]);
	}
	else if (cardtype == 9) //Straight Flush
	{
		return convertSuit(suit[0]) + ", " + convertRank(highcard) + " High";
	}
	else if (cardtype == 8) //Four of a Kind
	{
		return convertRank(highcard) + "'s";
	}
	else if (cardtype == 7) //Full House
	{
		string message;
		int full = 0;

		if (rank[1] == rank[2])
		{
			full = rank[3];
		}
		else if (rank[2] == rank[3])
		{
			full = rank[1];
		}

		message = convertRank(highcard) + "'s full of " + convertRank(full);
		return message + "'s";
	}
	else if (cardtype == 6) //Flush
	{
		return convertSuit(suit[0]) + ", " + convertRank(highcard) + " High";
	}
	else if (cardtype == 5) //Straight
	{
		return convertRank(highcard) + " High";
	}
	else if (cardtype == 4) //Three of a Kind
	{
		return convertRank(highcard) + "'s";
	}
	else if (cardtype == 3) //Two Pair
	{
		string message;

		message = convertRank(highcard) + "'s and " + convertRank(rank[3]);
		return message + "'s";
	}
	else if (cardtype == 2) //Pair
	{
		return convertRank(highcard) + "'s";
	}
	else //High Card
	{
		return convertRank(highcard) + " High";
	}
}

int handStrength(bool straight, bool royal, bool flush, int numPair)
{
	int cardtype;

	if (straight == true && royal == true && flush == true)
	{
		cardtype = 10;
	}
	else if (straight == true && flush == true)
	{
		cardtype = 9;
	}
	else if (numPair == 6)
	{
		cardtype = 8;
	}
	else if (numPair == 4)
	{
		cardtype = 7;
	}
	else if (flush == true)
	{
		cardtype = 6;
	}
	else if (straight == true)
	{
		cardtype = 5;
	}
	else if (numPair == 3)
	{
		cardtype = 4;
	}
	else if (numPair == 2)
	{
		cardtype = 3;
	}
	else if (numPair == 1)
	{
		cardtype = 2;
	}
	else
	{
		cardtype = 1;
	}

	return cardtype;
}

void Display(string name, int cardtype, int highcard, int numRank[], char rank[], char suit[])
{
	cout << name << ":";
	for (int count = 0; count < NUM; count++)
	{
		cout << " " << rank[count] << suit[count];
	}
	cout << ": ";

	if (cardtype == 10)
	{
		cout << "ROYAL FLUSH, ";
	}
	else if (cardtype == 9)
	{
		cout << "STRAIGHT FLUSH, ";
	}
	else if (cardtype == 8)
	{
		cout << "FOUR OF A KIND, ";
	}
	else if (cardtype == 7)
	{
		cout << "FULL HOUSE, ";
	}
	else if (cardtype == 6)
	{
		cout << "FLUSH, ";
	}
	else if (cardtype == 5)
	{
		cout << "STRAIGHT, ";
	}
	else if (cardtype == 4)
	{
		cout << "THREE OF A KIND, ";
	}
	else if (cardtype == 3)
	{
		cout << "TWO PAIR, ";
	}
	else if (cardtype == 2)
	{
		cout << "PAIR, ";
	}
	else
	{
		cout << "HIGH CARD, ";
	}

	cout << cardInfo(cardtype, highcard, numRank, suit) << endl;
}

void Winner(string name[], int rank[][NUM], int highcard[], int cardtype[])
{
	int winner;

	if (cardtype[0] < cardtype[1])
	{
		winner = 2;
	}
	else if (cardtype[0] > cardtype[1])
	{
		winner = 1;
	}
	else if (cardtype[0] == cardtype[1])
	{
		if (highcard[0] < highcard[1])
		{
			winner = 2;
		}
		else if (highcard[0] > highcard[1])
		{
			winner = 1;
		}
		else if (highcard[0] == highcard[1])
		{
			winner = Kickers(rank, cardtype);
		}
	}

	cout << endl;

	if (winner == 2)
	{
		cout << name[1] << " Wins! !" << endl;
	}
	else if (winner == 1)
	{
		cout << name[0] << " Wins! !" << endl;
	}
	else if (winner == 0)
	{
		cout << "Tie-split pot! !" << endl;
	}
}


#endif