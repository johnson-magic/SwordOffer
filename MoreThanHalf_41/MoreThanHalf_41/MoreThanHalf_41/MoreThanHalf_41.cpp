#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> stream = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	std::vector<int> stream_min = {};
	std::vector<int> stream_max = {};

	

	for (auto iter = stream.begin(); iter != stream.end(); iter++)
	{
		int true_item;
		if ((stream_min.size() + stream_max.size()) % 2 == 0)//当前流为偶数
		{
			true_item = *iter;
			if (stream_max.size() != 0 && true_item < *stream_max.begin())//不能直接插入到最小堆，要先进行比较
			{
				stream_max.push_back(true_item);
				push_heap(stream_max.begin(), stream_max.end(), std::less<int>());

				true_item = *stream_max.begin();

				
				pop_heap(stream_max.begin(), stream_max.end(), std::less<int>());
				stream_max.pop_back();

			}

			stream_min.push_back(true_item);
			push_heap(stream_min.begin(), stream_min.end(), std::greater<int>());

		}
		else
		{
			true_item = *iter;
			if (stream_min.size() != 0 && true_item > *stream_min.begin())//不能直接插入到最小堆，要先进行比较
			{
				stream_min.push_back(true_item);
				push_heap(stream_min.begin(), stream_min.end(), std::greater<int>());

				true_item = *stream_min.begin();

				
				pop_heap(stream_min.begin(), stream_min.end(), std::greater<int>());
				stream_min.pop_back();//这边的顺序不能乱,pop_heap是把堆顶元素放到vector的末尾，此时才可以把pop_back出去！！！

			}

			stream_max.push_back(true_item);
			push_heap(stream_max.begin(), stream_max.end(), std::less<int>());


		}
	}

		if ((stream_min.size() + stream_max.size()) % 2 == 0)//当前流为偶数
		{
			std::cout << (*stream_max.begin() + *stream_min.begin()) / 2 << std::endl;
		}
		else
		{
			std::cout << *stream_min.begin() << std::endl;
		}

		system("pause");
		return 0;
}