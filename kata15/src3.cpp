#include <vector>
#include <iostream>
std::vector<unsigned long long> cache(1000);
//cache[0] = 1;
unsigned long long exp_sum(int vl)
{
//	std::vector<unsigned long long> cash(1000);
	cache[0] = 1;
	if(vl == -1)	return 0;
	if(cache[vl] != 0)	
	{	
		std::cout << vl << ": " << cache[vl] << std::endl;
		return cache[vl];
	}
	unsigned long long res = 0;
	int orange = 1;
	int blue = 1;
	bool neg = 0;
	int index = 0;
	while(index < vl)
	{
		res += (neg * (-1) + !neg * 1) * (exp_sum(vl - index - orange) + exp_sum(vl - index - orange - blue));
		index += orange + blue;
		orange += 2;
		blue += 1;
		neg = !neg;
		
	}
	cache[vl] = res;
	return res;
}
int main()
{
	for(int i = 0; i < 1000; ++i)
	{
		cache[i] = 0;
	}
	std::cout << exp_sum(200) << std::endl;
	return 0;
}
