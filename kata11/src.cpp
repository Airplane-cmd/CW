#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
/*auto pow
{
	[](unsigned __int128 vl1, int vl2)
	{
		unsigned __int128 lres1 = 1;
		for(int i = 0; i < vl2; ++i)	lres1 *= vl1;
		return lres1;
	}
};
auto toString
{
	[pow](__int128 val)
	{
		unsigned __int128 ref = val;
		std::string res;
		int c = 0;
		while(ref != 0)
		{
//				res.push_back(ref % 10);
			ref /= 10;
			++c;
		}
		ref = val;
		for(int i = c; i > 0; --i)
		{
			res.push_back((ref / pow(10, i-1)) % 10 + 48);
		}
		if(c == 0)	res.push_back('0');
//				std::reverse(res.begin(), res.end());
		return res;
	}
};
auto to_int
{
	[pow, toString](const std::string &str)
	{
		unsigned __int128 lres2 = 0;
		for(int i = 0; i < str.size(); ++i)
		{
			lres2 += (str[i] - 48) * pow(10, str.size() - i - 1);
		}
//			std::cout << toString(lres2) << std::endl;
		return lres2;
	}
};
class int256_t
{
private:
	unsigned __int128 m_first;
	unsigned __int128 m_second;
	std::string m_firstS;
	std::string m_secondS;

public:
	int256_t(const int256_t &val) : m_first{val.m_first}, m_second{val.m_second}, m_firstS{0}, m_secondS{0}{};
	int256_t(const std::string &val) : m_first{0}, m_second{0} 
	{
		int s1{0}, s2{0};
		if(val.size() >= 39)
		{
			s2 = 39;
			s1 = val.size() - 39;
		}
		else 
		{
			s1 = val.size();
			s2 = 0;
		}
		for(int i = s1; i < val.size(); ++i)	m_firstS.push_back(val[i]);
		for(int i = 0; i < s1; ++i)		m_secondS.push_back(val[i]);
		m_first = to_int(m_firstS);
		m_second = to_int(m_secondS);
	}
	
};
std::string sum(const std::string &vl1, const std::string &vl2)
{
	std::string minNum = "";
	std::string imin = "";
	std::string imax = "";
	std::string res = "";
	int firstNum = 0;
	int secondNum = 0;
	int actNum = 0;
	if(vl1.size() >= vl2.size())
	{
		imax = vl1;
		imin = vl2;
	}
	else
	{
		imax = vl2;
		imin = vl1;
	}			
	for(int i = 0; i < imax.size() - imin.size(); ++i)	minNum.push_back('0');
	minNum += imin;
//	std::cout << imax << ", " << minNum << std::endl;
	for(int i = 0; i < imax.size(); ++i)
	{
		if(imax[i] != '0')
		{
			firstNum = i;
			break;
		}
		firstNum = i;
	}
	for(int i = 0; i < minNum.size(); ++i)	
	{
		if(minNum[i] != '0')
		{
			secondNum = i;
			break;
		}
		secondNum = i;
	}
	actNum = (firstNum <= secondNum) ? firstNum : secondNum;
//	std::cout << firstNum << ", " << secondNum << std::endl;	
//	std::cout << "act: " << actNum << std::endl;
//	std::cout << imax << " + " << minNum << " = ";
	int resI(0), bufI(0);
	for(int i = imax.size() - 1; i >= 0; --i)
	{
		resI = bufI + imax[i] + minNum[i] - 96;
		bufI = resI / 10;
		resI %= 10;
		if(i >= actNum) res.insert(0, 1, resI + 48);
		resI = 0;
		if(i == 0 && bufI != 0)
		{
//			const char insBuf = bufI + 48;
			res.insert(0, 1, bufI + 48);
		}
	}
//	std::cout << res << std::endl;
	return res;
}*/
std::string multiply(const std::string &vl1, const std::string &vl2)
{
	auto sum
	{
		[](const std::string &vl1, const std::string &vl2)
		{
			std::string minNum = "";
			std::string imin = "";
			std::string imax = "";
			std::string res = "";
			int firstNum = 0;
			int secondNum = 0;
			int actNum = 0;
			if(vl1.size() >= vl2.size())
			{
				imax = vl1;
				imin = vl2;
			}
			else
			{
				imax = vl2;
				imin = vl1;
			}			
			for(int i = 0; i < imax.size() - imin.size(); ++i)	minNum.push_back('0');
			minNum += imin;
//	std::cout << imax << ", " << minNum << std::endl;
			for(int i = 0; i < imax.size(); ++i)
			{
				if(imax[i] != '0')
				{
					firstNum = i;
					break;
				}
				firstNum = i;
			}
			for(int i = 0; i < minNum.size(); ++i)	
			{
				if(minNum[i] != '0')
				{
					secondNum = i;
					break;
				}
				secondNum = i;
			}
			actNum = (firstNum <= secondNum) ? firstNum : secondNum;
//	std::cout << firstNum << ", " << secondNum << std::endl;	
//	std::cout << "act: " << actNum << std::endl;
//	std::cout << imax << " + " << minNum << " = ";
			int resI(0), bufI(0);
			for(int i = imax.size() - 1; i >= 0; --i)
			{
				resI = bufI + imax[i] + minNum[i] - 96;
				bufI = resI / 10;
				resI %= 10;
				if(i >= actNum) res.insert(0, 1, resI + 48);
				resI = 0;
				if(i == 0 && bufI != 0)
				{
//			const char insBuf = bufI + 48;
					res.insert(0, 1, bufI + 48);
				}
			}
//	std::cout << res << std::endl;
			return res;
		}
	};
	std::string imin = "";
	std::string imax = "";
	std::string res = "";
	if(vl1.size() >= vl2.size())
	{
		imax = vl1;
		imin = vl2;
	}
	else
	{
		imax = vl2;
		imin = vl1;
	}
	int resI(0), buf(0);
	std::string bufS{""};
	for(int i = imin.size() - 1; i >= 0; --i)
	{
		for(int j = imax.size() - 1; j >= 0; --j)
		{
			resI = (imax[j] - 48) * (imin[i] - 48);// + buf;
//			std::cout << resI << std::endl;
//			resI %= 10;
//			buf = resI / 10;
//			resI %= 10;
			bufS = std::to_string(resI);
//			std::cout << resI << ",";
			for(int k = 0; k < (int(imax.size() - 1 - j) + int(imin.size() - 1 - i)); ++k)
			{
				bufS.push_back('0');
//				std::cout << "0";
			}
			bufS = sum(bufS, std::to_string(buf));

//			std::cout << std::endl;
			res = sum(res, bufS);
//			std::cout << " " <<bufS << std::endl;
			if(i == 0 && j == 0 && buf != 0)
			{
//				const char insBuf = buf + 48;
				res.insert(0, 1, buf + 48);
			}
		}
	}
	return res;
}

int main()
{
	srand(time(0));
//	std::string str = "drytfugi";
//	str.insert(0, "1");
//	std::cout << sum("0000", "0100") << std::endl;
//	std::cout << multiply("43", "56") << std::endl;
//	__int128 c = 1;
//	while(c * c == to_int(multiply(toString(c), toString(c))))	c = c + 1;
//	std::cout << bool(c * c == to_int(multiply(toString(c), toString(c)))) << std::endl;
//	std::cout << toString(c * c) << " != " << multiply(toString(c), toString(c)) << std::endl;
//
//	std::string a{"586084767876545678987654567890987654567898765456789876545687654567898765456789876544567898765434567876545678765678765678765678765678765678765678765678765678765678i987656789876567898765434567876545677656765676563622772837728372827"}, b{"7586374672263726736377876567899876567898765456789876545678987654567876543456789876543456789876545678987654567876545676545665456545654567654345678765434567898765434567876543456787654345678765434564"};
	int c = 0;
	while(c < 100)
	{
		int b = rand() % 300;
		std::string first = "";
		std::string second = "";
		for(int i = 0; i < b; ++i)	first.push_back(char(rand() % 10 + 48));
		b = rand() % 300;
		for(int i = 0; i < b; ++i)	second.push_back(char(rand() % 10 + 48));
		std::cout << c + 1 << ": " <<  first << " * " << second << " = " << multiply(first, second) << std::endl;
		std::cout << std::endl;
		++c;
	}
//	std::cout << multiply(a, b) << std::endl;

//	std::cout << sum(a, b) << std::endl;
//	int n = 4;
//	std::cout << std::to_string(n) << std::endl;
//
//	std::cout << multiply(a, b) << std::endl;
//	unsigned __int128 fj = pow(2, 128) - 1;
//
//	std::cout << toString(fj) << std::endl;
//	std::cout << std::string("340282366920938463463374607431768211456").size() << std::endl;
//	std::cout << "444625839871840560024489175424316205566214109298" << std::endl;
//	printf(multiply(a, b));
//	if(multiply(a, b) == "2830869077153280552556547081187254342445169156730")	std::cout << "1";
	return 0;
}
