#include <iostream>
#include <vector>
std::pair<std::size_t, std::size_t> two_sum(const std::vector<int> &numbers, int target)
{
	int cv = 0;
	for(std::size_t i = 0; i < numbers.size(); ++i)
	{
		for(std::size_t j = 0; j < numbers.size(); ++j)
		{
			if(j == i)	continue;
			else		if(numbers[i] + numbers[j] == target)	return {i, j};
		}
	}
	return {0, 0};
}
int main()
{
	std::pair<std::size_t, std::size_t> buff = two_sum({1, 2, 3}, 4);
	std::cout << buff.first << buff.second << std::endl;
	return 0;
}
