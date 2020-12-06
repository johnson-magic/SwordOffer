#include <iostream>
#include <ctime>

// exch array[i] and array[j]
void Exch(int *array, int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

//find j, and make array[i] <= array[j], when 0 <=i <= j-1
//            make array[i] >= array[j], when j < j+1 < len -1
int Partition(int * array, int len, int lo, int hi)
{
	int i = lo;
	int j = hi+1 ;//后撤一步
	while (true)
	{
		while (array[++i] <= array[lo] && i < hi);//停在“大”数字，或者递减数组，一直到hi
		while (array[--j] >= array[lo] && j > lo);//停在“小”数字，或者递增数组，一直到lo

		if (i >= j) break;//此处i和j的最终停止范围，j<i,除非数组本身递减此时i=j
		Exch(array, i, j);
	}
	Exch(array, j, lo);//此处i和j不等价，因为99%的情形下,j=i-1;1%的情形始,i=j=hi(递减)
	return j;
	
}

void RandShuffle(int *array, int lo, int hi)
{
	for (int i = 0; i <= hi - lo; i++)
	{   
		int sed = time(0);//用时间来作为一种随机函数的seed，可以避免rand伪随机。
		srand(sed);
		int rand_number = rand();
		std::cout << rand_number << std::endl;
		int switch_flag = rand_number % 2;
		if (switch_flag)
		{
			int temp = array[lo + i];
			array[lo + i] = array[hi - i];
			array[hi - i] = temp;
		}
	}
}

int QuickSort(int *array, int len, int lo, int hi)
{
	if (lo >= hi)
		return 1;//递归终止条件，递归子问题的数组已经变成一个元素，此时就可以return了。

	RandShuffle(array, lo, hi);//每一次打乱递归子数组的顺序，使得达到一种均衡效率。

	//递归调用必须有一个父问题---》(简单)子问题的过程
	int target = Partition(array, len, lo, hi);
	QuickSort(array, len, lo, target - 1);
	QuickSort(array, len, target + 1, hi);

	return 1;
}

int main(int argv, char * argc)
{

	int array[5] = { 0, 4, 3, 2, 1};
	int len = sizeof(array) / sizeof(int);
	
	//数组输入检查
	if (array == nullptr || len < 1)
	{
		return -1;
	}

	//主体
	int lo = 0;
	int hi = len - 1;
	QuickSort(array, len, lo, hi);

	//结果输出
	for (int i = 0; i < len; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}