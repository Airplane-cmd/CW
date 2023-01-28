#include <iostream>
#include <vector>
std::vector<int> snail(const std::vector<std::vector<int>> &vctr)
{
	int len = vctr.size() * vctr[0].size();
	int side = vctr[0].size();
	int front = vctr.size();
	std::vector<int> res(side * front);
	bool right = 1;
	bool down = 0;
	bool left = 0; 
	bool top = 0;
	int it = 0;
	int i(0), j(0), itr(0);
	while(itr < len)
	{
		if(i == it + 1)
		{
			if(j == it)
			{
				right = 1;
//				std::cout << "right" << std::endl;
				top = 0;
				it++;
			}
		}
		if(i == it && j == vctr[0].size() - it - 1)
		{
			down = 1;
//			std::cout << "down" << std::endl;
			right = 0;
		}
		if(i == vctr.size() - it - 1)
		{
			if(j == it)
			{
				top = 1;
//				std::cout << "top" << std::endl;
				left = 0;
			}
			if(j == vctr[0].size() - it - 1)
			{
				left = 1;
//				std::cout << "left" << std::endl;
				down = 0;
			}
		}
//		std::cout << i << ", " << j << ": " << vctr[i][j] << std::endl;
		res[itr] = vctr[i][j];
		i -= top;
		i += down;
		j += right;
		j -= left;
		++itr;	
	}			
	return res;
}
int main()
{
	std::vector<std::vector<int>> first = 
	{
		{1, 2, 3},
		{8, 9, 4},
		{7, 6, 5}
	};
	std::vector<std::vector<int>> v = {{1,2,3,4}, {10,11,12,5}, {9,8,7,6}};
	std::vector<int> res;
	res = snail(v);
	for(int i = 0; i < res.size(); ++i)	std::cout << res[i] << " ";
	std::cout << std::endl;
	return 0;
}
