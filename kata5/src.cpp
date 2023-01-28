#include <iostream>
#include <string>
char minNum[4] = {'I', 'X', 'C', 'M'};
char midNum[3] = {'V', 'L', 'D'};
char maxNum[3] = {'X', 'C', 'M'};
std::string solution(int number)
{
	int ref = number;
	int n = 0;
	std::string res;
	auto pow
	{
		[](int vl1, int vl2)
		{
			int res = 1;
			for(int i = 0; i < vl2; ++i)	res *= vl1;
			if(vl2 == 0)	return 1;
			return res;
		}
	};
	while(ref / 10 != 0)
	{
		ref /= 10;
		++n;
	}
	++n;
	std::cout << pow(10, 3) << std::endl;
	ref = number;
	int num = 0;
	for(int nIt = 1; nIt < n + 1; ++nIt)
	{
		if(nIt == 1)	num = ref / pow(10, n - nIt);
		else 		num = ref / pow(10, n - nIt) % 10;
		std::cout << num << std::endl;
//		ref %= pow(10, nIt);
		if(num <= 3)	for(int i = 0; i < num; ++i)	res += minNum[n - nIt];
		else if(num > 3 && num <= 5)
		{
			for(int i = 0; i < 5 - num; ++i)	res += minNum[n - nIt];
			res += midNum[n - nIt];
		}
		else if(num > 5 && num <= 8)
		{
			res += midNum[n - nIt];
			for(int i = 0; i < num - 5; ++i)	res += minNum[n - nIt];
		}
		else if(num > 8 && num <= 10)
		{
			for(int i = 0; i < 10 - num; ++i)	res += minNum[n - nIt];
			res += maxNum[n - nIt];
		}
	}
	return res;
}

int main()
{
	std::cout << solution(1875) << std::endl;
	return 0;
}
