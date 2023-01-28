#include <iostream>
#include <string>
#include <vector>
#include <sstream>
std::string range_extraction(const std::vector<int> &args)
{
	std::string res;
	bool range = 0;
	std::stringstream buff;
	std::string strB;
	for(int i = 0; i < args.size(); ++i)
	{
//		if(i == 1)		std::cout << args[i] +2 << " == " << args[i + 1] + 1;
//		if(args[i] + 2 == args[i + 1] + 1)	std::cout << args[i] + 2 << " == " << args[i + 1] + 1;
//		else 		std::cout << args[i] + 2 << " != " << args[i + 1] + 1;
//		if(args[i + 1] + 1 == args[i + 2])	std::cout << " == " << args[i + 2] << std::endl;
//		else		std::cout << " != " << args[i + 2] << std::endl; 
		if(args[i] + 2 == args[i + 1] + 1 && args[i + 1] + 1 == args[i + 2] && !range)
		{
//			std::cout << (1) << std::endl;
			range = 1;
			buff.clear();
			buff << args[i];
			buff >> strB;
			res += strB;
		}
		if(range)
		{
			if(args[i] + 1 != args[i + 1])
			{
				std::cout << args[i] << ", " << args[i+1] << std::endl;
				range = 0;
				buff.clear();
				buff << args[i];
				buff >> strB;
				if(i != args.size() - 1)	res += '-' + strB + ',';
				else				res += '-' + strB; 
			}
//			else	std::cout << "fuck" << std::endl;

		}
		else 	
		{
			buff.clear();
			buff << args[i];
			buff >> strB;
			if(i != args.size() - 1)	res +=  strB + ',';
			else 				res += strB;
		}
	}
	return res;
}
int main()
{
	std::vector<int> nums = {-6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20};
	std::string str = range_extraction(nums);
	std::cout << str << std::endl;
	return 0;
}
