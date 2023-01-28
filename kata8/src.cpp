#include <iostream>
#include <string>
int pow(int vl1, int vl2)
{
	int res = 1;
	for(int i = 0; i < vl2; ++i)
	{
		res *= vl1;
	}
	return res;
}
char sNum[4] = {'I', 'X', 'C', 'M'};
char mNum[3] = {'V', 'L', 'D'};
char bNum[3] = {'X', 'C', 'M'};
uint getVl(char vl)
{
	uint buff = 0;
	bool found = 0;
	for(int i = 0; i < 4; ++i)
        if(sNum[i] == vl)        
        {
        	buff = pow(10, i);
                found = 1;            
        	break;
        }
        if(!found)
        {
        	for(int i = 0; i < 3; ++i)
        	if(mNum[i] == vl)        
                {
//              	std::cout << "fuck" << std::endl; 
                	buff = 5 * pow(10, i);
                        found = 1;
                        break;
                }
        }
	return buff;
}
class RomanHelper
{
public:
	static std::string toRoman(uint n)
	{
		uint ref = n;
		uint ct = 0;
		std::string res;
		while (ref != 0)
		{
			ref /= 10;
			++ct;
		}
//		std::cout << "here" << std::endl;
		ref = n;
		int buff;
		for(int i = 1; i <= ct; ++i)
		{
//			std::cout << "here1" << std::endl;
			buff = ref / pow(10, ct - i) % 10;
//			std::cout << "here2" << std::endl;
			if(buff < 4)
				for(int j = 0; j < buff; ++j)
					res.push_back(sNum[ct - i]);
			else if(buff <= 5)
			{
				for(int j = 0; j < 5 - buff; ++j)
					res.push_back(sNum[ct - i]);
				res.push_back(mNum[ct - i]);
			}
			else if(buff > 5 && buff < 9)
			{
				res.push_back(mNum[ct - i]);
				for(int j = 0; j <  buff - 5; ++j)
					res.push_back(sNum[ct - i]);
			}
			else if(buff >= 9)
			{
				for(int j = 0; j < 10 - buff; ++j)
					res.push_back(sNum[ct - i]);
				res.push_back(bNum[ct - i]);
			}
//			for(int j = 0; j < res.size(); ++j)	std::cout << res[j] << std::endl; 
		}
		return res;
	}
	static uint fromRoman(std::string rn)
	{
		uint res = 0;
		uint buff = 0;
		bool found = 0;
		bool buffReady = 0;
		bool done = 0;
		int scp = 0;
		int cp = 10000;
		int prL = 0;
		int dubC = 0;
		bool dubf = 0;
		uint pv = 0;
		uint cv = 0; 
		while(!done)
		{
			cv = getVl(rn[scp]);
			std::cout << cv << " ";

			buff += cv;
//			std::cout << buff << std::endl;
			if(scp == rn.size() - 1)	done = 1;
			if(cv < cp)			
			{
				cp = cv;
				dubC = 0;
			}
			else if(cv == cp)			++dubC;
			else if(cv > cp)
			{
				for(int i = 0; i < dubC + 1; ++i)
				{
					buff -= pv * 2;
					std::cout << buff << " ";
				}
				dubC = 0;
				cp = cv;
			}
			std::cout << buff << std::endl;

			pv = cv;
			++scp;
		}
		return buff;
	}
};
int main()
{
//	std::cout << pow(10, 5) << std::endl;
//	std::cout << getVl('D') << std::endl;
	std::string shit = RomanHelper::toRoman(3999);
	std::cout << shit << std::endl;
	std::cout << std::endl;
	std::cout << RomanHelper::fromRoman("MCMLXXXIX") << std::endl;
	return 0;
}
