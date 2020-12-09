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
		if ((stream_min.size() + stream_max.size()) % 2 == 0)//��ǰ��Ϊż��
		{
			true_item = *iter;
			if (stream_max.size() != 0 && true_item < *stream_max.begin())//����ֱ�Ӳ��뵽��С�ѣ�Ҫ�Ƚ��бȽ�
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
			if (stream_min.size() != 0 && true_item > *stream_min.begin())//����ֱ�Ӳ��뵽��С�ѣ�Ҫ�Ƚ��бȽ�
			{
				stream_min.push_back(true_item);
				push_heap(stream_min.begin(), stream_min.end(), std::greater<int>());

				true_item = *stream_min.begin();

				
				pop_heap(stream_min.begin(), stream_min.end(), std::greater<int>());
				stream_min.pop_back();//��ߵ�˳������,pop_heap�ǰѶѶ�Ԫ�طŵ�vector��ĩβ����ʱ�ſ��԰�pop_back��ȥ������

			}

			stream_max.push_back(true_item);
			push_heap(stream_max.begin(), stream_max.end(), std::less<int>());


		}
	}

		if ((stream_min.size() + stream_max.size()) % 2 == 0)//��ǰ��Ϊż��
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