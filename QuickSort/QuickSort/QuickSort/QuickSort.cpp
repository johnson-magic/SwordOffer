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
	int j = hi+1 ;//��һ��
	while (true)
	{
		while (array[++i] <= array[lo] && i < hi);//ͣ�ڡ������֣����ߵݼ����飬һֱ��hi
		while (array[--j] >= array[lo] && j > lo);//ͣ�ڡ�С�����֣����ߵ������飬һֱ��lo

		if (i >= j) break;//�˴�i��j������ֹͣ��Χ��j<i,�������鱾��ݼ���ʱi=j
		Exch(array, i, j);
	}
	Exch(array, j, lo);//�˴�i��j���ȼۣ���Ϊ99%��������,j=i-1;1%������ʼ,i=j=hi(�ݼ�)
	return j;
	
}

void RandShuffle(int *array, int lo, int hi)
{
	for (int i = 0; i <= hi - lo; i++)
	{   
		int sed = time(0);//��ʱ������Ϊһ�����������seed�����Ա���randα�����
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
		return 1;//�ݹ���ֹ�������ݹ�������������Ѿ����һ��Ԫ�أ���ʱ�Ϳ���return�ˡ�

	RandShuffle(array, lo, hi);//ÿһ�δ��ҵݹ��������˳��ʹ�ôﵽһ�־���Ч�ʡ�

	//�ݹ���ñ�����һ��������---��(��)������Ĺ���
	int target = Partition(array, len, lo, hi);
	QuickSort(array, len, lo, target - 1);
	QuickSort(array, len, target + 1, hi);

	return 1;
}

int main(int argv, char * argc)
{

	int array[5] = { 0, 4, 3, 2, 1};
	int len = sizeof(array) / sizeof(int);
	
	//����������
	if (array == nullptr || len < 1)
	{
		return -1;
	}

	//����
	int lo = 0;
	int hi = len - 1;
	QuickSort(array, len, lo, hi);

	//������
	for (int i = 0; i < len; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}