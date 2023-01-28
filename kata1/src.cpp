#include <iostream>
#include <string>
std::string pigIt(std::string str)
{
	std::string rStr;
	char buff;
	for(int i = 0; i < str.size(); ++i)
	{
		bool flag = (str[i] == 32 || (str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123));

		auto cond
		{
			[](char ch)
			{
				return (ch == 32 || (ch > 64 && ch < 91) || (ch > 96 && ch < 123));
			}
		};
		if(flag)
		{
			if(str.size() == 1 && cond(str[0]))	rStr.push_back(str[0]);
			if(i == 0 || str[i - 1] == ' ' && !((i == str.size() - 1) && (str[i - 1] == ' ')))	buff = str[i];
			else if(str[i] == ' ' && cond(str[i - 1]))	
			{
				rStr.push_back(buff);	
				rStr += "ay ";
			}
			else if(i == str.size() - 1 && (str[i - 1] != ' '))	
			{
				rStr.push_back(str[i]);
				rStr.push_back(buff);	
				rStr += "ay";
			}
			else if((i == str.size() - 1) && (str[i - 1] == ' '))	
			{
				rStr.push_back(str[i]);
//				rStr.push_back(buff);	
				rStr += "ay";
			}
			else	rStr.push_back(str[i]);
		}
		else	rStr.push_back(str[i]);
		if(i == str.size() - 1)		std::cout << "flag: " << ((i == str.size() - 1) && (str[i - 1] == ' ')) << std::endl;
	}
	return rStr;
}
int main()
{
	std::cout << pigIt("s") << std::endl;
	return 0;
}

