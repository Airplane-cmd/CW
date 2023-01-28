//133 41
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <unistd.h>
unsigned long long exp_sum(int vl)
{
	switch(vl)
	{
		case(0):
			return 1;
			break;
		case(1):
			return 1;
			break;
		case(2):
			return 2;
			break;			
		case(3):
			return 3;
			break;
		case(4):
			return 5;
			break;
		case(5):
			return 7;
			break;
		case(6):
			return 11;
			break;
		case(7):
			return 15;
			break;
		case(8):
			return 22;
			break;
		case(9):
			return 30;
			break;
		case(10):
			return 42;
			break;
		case(11):
			return 56;
			break;
		case(12):
			return 77;
			break;
		case(13):
			return 101;
			break;
		case(14):
			return 135;
			break;
		case(15):
			return 176;
			break;
		case(16):
			return 231;
			break;
		case(17):
			return 297;
			break;
		case(18):
			return 385;
			break;
		case(19):
			return 490;
			break;
		case(20):
			return 627;
			break;
		case(21):
			return 792;
			break;
		case(22):
			return 1002;
			break;
		case(23):
			return 1255;
			break;
		case(24):
			return 1575;
			break;
		case(25):
			return 1958;
			break;
		case(26):
			return 2436;
			break;
		case(27):
			return 3010;
			break;
		case(28):
			return 3718;
			break;
		case(29):
			return 4565;
			break;
		case(30):
			return 5604;
			break;
		case(31):
			return 6842;
			break;
		case(32):
			return 8349;
			break;
		case(33):
			return 10143;
			break;
		case(34):
			return 12310;
			break;
		case(35):
			return 14883;
			break;
		case(36):
			return 17977;
			break;
		case(37):
			return 21637;
			break;
		case(38):
			return 26015;
			break;
		case(39):
			return 31185;
			break;
		case(40):
			return 37338;
			break;


	}
	int res = 0;
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
	return res;
}
int main()
{
	int line(0), vl(0), cntr(0);
	std::string s_line, s_vl;
	std::fstream src;
	std::ofstream temp;
	temp.open("temp.cpp");
	std::string str;
	std::string save;
	std::string save1;
	src.open("src.cpp", std::ios::in | std::ios::out | std::ios::app);
	src.seekg(2, std::ios::beg);
	getline(src, str);
//	std::cout << str << std::endl;
	bool ws = 0;
	for(int i = 0; i < str.size(); ++i)
	{
		if(str[i] == ' ')
		{
			ws = 1;
			continue;
		}
		if(!ws)			s_line.push_back(str[i]);
		else			s_vl.push_back(str[i]);
	}
//	std::cout << s_line << " " << s_vl << std::endl;
//	for(int i = 0; i < s_line.size(); i++)		line += (s_line[i] - 48) * pow(10, s_line.size() - i - 1);
	line = std::stoi(s_line);
//	for(int i = 0; i < s_vl.size(); i++)		vl += (s_vl[i] - 48) * pow(10, s_line.size() - i - 1);
	vl = std::stoi(s_vl);
	src.seekg(0, std::ios::beg);
	while(getline(src, str))
	{
		std::cout << str << std::endl;
		if(cntr >= line)
		{
//			src.seekp(0, std::ios::cur);
			save += str + '\n';
		}
		else
		{
			save1 += str + '\n';
		}
		++cntr;
	}
	cntr = 0;
//	temp.seekg(0, std::ios::beg);
	temp << save1;
	std::cout << save1 << std::endl;
	temp << "		case(" << s_vl << "):\n";
	temp << "			return " << std::to_string(exp_sum(vl)) << ";\n";
	temp << "			break;\n";
	temp << save;
	temp.close();
	std::ofstream final("final.cpp");
	final << "//" << std::to_string(line + 3) << " " << std::to_string(vl + 1) << '\n';
	std::ifstream fuck("temp.cpp");
	while(getline(fuck, str))
	{
		if(cntr > 0)
		{
			final << str << '\n';
		}
		++cntr;
	}
	std::remove("src.cpp");
	std::rename("final.cpp", "src.cpp");
//	usleep(1000000);
//	std::system("g++ src.cpp -o bin");
//	usleep(1000000);
//	std::system("./bin");
	return 0;
}


		
