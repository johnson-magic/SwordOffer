#include <iostream>

void Exch(int *array, int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
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

	Exch(array, lo, j);

	return j;
}

int main1()
{
	int array[] = { 8, 3, 2, 4, 5, 1, 7 };
	int k = 3;
	int len = sizeof(array) / sizeof(int);

	if (array == nullptr || len <= 0)
		return -1;

	int lo = 0;
	int hi = len - 1;

	
	int target = Partition(array, lo, hi);


	while (target != k - 1)
	{
		if (target > k - 1)
		{
			lo = lo;
			hi = target - 1;
			target = Partition(array, lo, hi);
		}
		else
		{
			lo = target + 1;
			hi = hi;
			target = Partition(array, lo, hi);
		}
	}

	for (int i = 0; i < k; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	system("pause");
	return 0;

}