#include <iostream>

int main()
{
	int l[] = {1, 3, 3, 4, 1, 2, 3, 1, 2, 1, 3, 3, 3, 3, 4, 3, 3, 3, 3, 4};
	int len = sizeof(l) / sizeof(int);

	if (l == nullptr || len == 0)
	{
		return -1;
	}
	
	int target = l[0];
	int count = 1;

	for (int i = 1; i < len; i++)
	{
		if (target == l[i])
		{
			count = count + 1;
		}
		else
		{
			count = count - 1;
		}

		if (count == 0)
		{
			target = l[i];
			count = 1;
		}
	}

	count = 0;
	for (int i = 0; i < len; i++)
	{
		if (l[i] == target)
		{
			count = count + 1;
		}
	}
	if (count >= (len + 1)/2)
		std::cout << "Target : "<<target<<" count: "<<count<< " len: "<< len;
	else
		return -1;

	system("pause");
	return 0;

}