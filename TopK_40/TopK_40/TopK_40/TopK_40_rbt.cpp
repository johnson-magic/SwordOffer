#include <iostream>
#include <set>
#include <vector>
#include <functional>//std::greater

int main()
{
	std::vector<int> array = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int k = 4;
	std::multiset<int, std::greater<int>> container;
	container.clear();

	for (auto iter = array.begin(); iter != array.end(); iter++)
	{
		if (container.size() < k)
		{
			container.insert(*iter);
		}
		else
		{
			std::multiset<int, std::greater<int>>::iterator max_value = container.begin();
			if (*max_value > *iter)
			{
				container.erase(max_value);
				container.insert(*iter);
			}
		}
	}

	for (auto iter = container.begin(); iter != container.end(); iter++)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	system("pause");
	return 0;
	
}