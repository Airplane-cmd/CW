#include <iostream>
#include <string>
#include <array>
std::string format_duration(long unsigned int secs)
{
	std::array<std::string, 5> words = {"seconds", "minutes", "hours", "days", "years"};
	std::array<int, 5> time;
	int num = 60;
	int vlbl = -1;//
	std::string res;
	switch(secs)
	{
		case(0):
			res = "now";
			return res;
			break;
		default:
			for(int i = 0; i < words.size(); ++i)
			{
				switch(i)
				{
					case(2):
						num = 24;
						break;
					case(3):
						num = 365;
						break;
				}
				time[i] = secs % num;
//				std::cout << secs << " % " << num << " = " << secs % num << std::endl;
				if(time[i] != 0)	++vlbl;
				secs /= num;
			}
			break;
	}
	for(int i = time.size() - 1; i > -1; --i)
	{
		std::string word = words[i];
		if(time[i] != 0)	
		{
			if(time[i] == 1)	word.pop_back();
			res += std::to_string(time[i]) + " " + word;
			if(vlbl > 1)
			{
				res += ", ";
			}
			else if(vlbl == 1)
			{
				res += " and ";
			}
			--vlbl;
		}
	}
	return res;
}
int main()
{
	std::cout << format_duration(1136000*60) << std::endl;
}

