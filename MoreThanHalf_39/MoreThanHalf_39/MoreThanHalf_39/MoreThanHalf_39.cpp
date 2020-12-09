#include <iostream>
#include <ctime>

void Exch(int *array, int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void RandomShuffle(int *array, int lo, int hi)
{
	int seed = time(0);
	srand(seed);
	for (int i = lo; i <= hi; i++)
	{
		int exch_flag = rand() % 2;
		if (exch_flag)
		{
			Exch(array, lo + i, hi - i);
		}
	}
}
int Partition(int *array, int lo, int hi)
{
	int i = lo;
	int j = hi + 1;
	while (true)
	{
		while (array[++i] <= array[lo] && i < hi);
		while (array[--j] >= array[lo] && j > lo);
		
		if (i >= j)
			break;
		Exch(array, i, j);
	}
	Exch(array, j, lo);
	return j;
}




int main1(int argc, char * argv)
{
	int array[] = { 5, 5, 5, 5, 9, 0, 3, 2 };
	
	int lo = 0;
	int hi = sizeof(array) / sizeof(int)-1;

	if (array == nullptr && hi <= 0)
		return -1;

	int target = hi / 2;
	int return_value = Partition(array, lo, hi);

	while (return_value != target)
	{
		if (return_value > target)
		{
			lo = lo;
			hi = return_value-1;
			return_value = Partition(array, lo, hi);
		}
		else
		{
			lo = return_value+1;
			hi = hi;
			return_value = Partition(array, lo, hi);

		}

	}

	std::cout << return_value << array[return_value];
	system("pause");
	return 0;
}