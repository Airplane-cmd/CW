#include <iostream>
//#include <cmath>
#include <vector>
bool narcissistic(int value)
{
	auto pow
	{
		[](int vl1, int vl2)
		{
			int res = 1;
			for(int i = 0; i < vl2; ++i)	res *= vl1;
			return res;
		}
	};
	int n = 0;
	int vl = value;
	int res = 0;
	while(vl > 0)
	{
		vl /= 10;
//		std::cout << vl << std::endl;
		++n;
	}
	vl = value;
//	std::cout << n << std::endl;
	for(int i = 0; i <= n; ++i)
	{
//		res += value%(static_cast<int>(pow(10,(n-i))))%10*pow(10, n);
		res += pow(vl / static_cast<int>(pow(10, (n-i)))%10, n);
//		std::cout << res << std::endl;
	}
//	std::cout << res << std::endl;
	return (res == value)?1:0;
}
int main()
{
//	narcissistic(153);
	std::vector<int> naci;
	for(int i = 0; i < 1000000000; ++i)
	{
		if(i %  == 0)		std::cout << i << std::endl;

		if(narcissistic(i))	naci.push_back(i);
	}
	for(int it : naci)	std::cout << it << " ";
	std::cout << std::endl;
	return 0;
}
