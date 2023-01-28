#include <iostream>
#include <string>
#include <vector>
std::string likes(const std::vector<std::string> &names)
{
	std::string res;
	switch(names.size())
	{
		case(0):		
			res = "no one likes ";
			break;
		case(1):
			res = names[0] + " likes ";
			break;
		case(2):
			res = names[0] + " and " + names[1] + " like ";
			break;
		case(3):
			res = names[0] + ", " + names[1] + " and " + names[2] + " like ";
			break;
		default:
			res = names[0] + ", " + names[1] + " and " + std::to_string(names.size() - 2) + " others like ";
			break;
	}
	res += "this";
	return res;
}
int main()
{
	std::vector<std::string> names = {"gbhjuh", "uiyhjkn", "bhjkij", "uibjuibu", "ojkknbju"};
	std::cout << likes(names) << std::endl;
	return 0;
}
