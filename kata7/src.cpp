#include <iostream>
#include <vector>
#include <string>
bool substr(const std::string &sub, const std::string &str)
{
//	char *buff = new char[sub.size()];
	bool res = 1;
	for(int i = 0; i < int(str.size() - sub.size()) + 1; ++i)
	{
		for(int j = i; j < int(i + sub.size()); ++j)
		{
			res = 1;
//			std::cout << str.size() - sub.size() << std::endl;
			if(str[j] != sub[j - i])
			{
//				std::cout << "str[" << j << "](" << str[j] << ") != sub[" << j - i << "]" << sub[j - i] << std::endl;
				res = 0;
				break;
			}
			else
			{
//				std::cout << "str[" << j << "](" << str[j] << ") == sub[" << j - i << "]" << sub[j - i] << std::endl;
				
			}
		}
		if(res == 1) 	return 1;		
	}
	return 0;
}
class WhichAreIn
{
public:
	static std::vector<std::string> inArray(std::vector<std::string> &arr1, std::vector<std::string> &arr2)
	{
//		std::cout << "not segfault here" << std::endl; 
		std::vector<std::string> res;
		for(int i = 0; i < arr1.size(); ++i)
		{
			for(int j = 0; j < arr2.size(); ++j)
			{
//				std::cout << arr1[i] << ", " << arr2[j];
				if(substr(arr1[i], arr2[j]))
				{
					res.push_back(arr1[i]);
					break;//std::cout << " wtf" << std::endl;
				}
//				else std::cout << std::endl;
			}
		}
		return res;
	}
};
int main()
{
//	std::string la = {"*(*&^&*&^%"};
//	std::string als = {"&*"};
//	std::cout << substr(als, la) << std::endl;
//	std::vector<std::string> larr = {"%^&*", "arp", "%^&*("};
//	std::vector<std::string> rarr = {"@#$%^&*(", "^&*()", "harp", "^&*()", "a(*&^"};
//	std::vector<std::string> ass = WhichAreIn::inArray(larr, rarr);
	std::vector<std::string> arr5 = { "cod", "code", "wars", "ewar", "pillow", "bed", "phht" };
        std::vector<std::string> arr6 = { "lively", "alive", "harp", "sharp", "armstrong", "codewars" };
        std::vector<std::string> sol3 = { "cod", "code", "ewar", "wars" };
        std::vector<std::string> ans3 = WhichAreIn::inArray(arr5, arr6);
	for(int i = 0; i < ans3.size(); ++i)	std::cout << ans3[i] << " ";
	std::cout << std::endl;
	return 0;
}
