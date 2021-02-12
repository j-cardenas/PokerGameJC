//Checks if rank is an Ace (A)


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
