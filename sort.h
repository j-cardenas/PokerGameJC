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