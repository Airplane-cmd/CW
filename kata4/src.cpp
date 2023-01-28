#include <iostream>
#include <string>
//struct symbol
//{
//	std::string first;
//	char second;
//}
//symbol lit[36] = {
std::pair<std::string, char> lit[38] = {{".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'}, {".", 'E'}, {"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'}, {"..", 'I'}, {".---", 'J'}, {"-.-", 'K'}, {".-..", 'L'}, {"--", 'M'}, {"-.", 'N'}, {"---", 'O'}, {".--.", 'P'}, {"--.-", 'Q'}, {".-.", 'R'}, {"...", 'S'}, {"-", 'T'}, {"..-", 'U'}, {"...-", 'V'},{".--", 'W'}, {"-..-", 'X'}, {"-.--", 'Y'}, {"--..", 'Z'}, {".----", '1'}, {"..---", '2'}, {"...--", '3'}, {"....-", '4'}, {".....", '5'}, {"-....", '6'}, {"--...", '7'}, {"---..", '8'}, {"----.", '9'}, {"-----", '0'}, {"-.-.--", '!'}, {".-.-.-", '.'}};
std::pair<std::string, std::string> spcl[1] = {{"...---...","SOS"}};
std::string decodeMorse(std::string morseCode)
{
	morseCode += "   ";
	std::string decoded;
	std::string buff;
	int spcCntr = 0;
	bool fnd = 0;
	bool flag = 0;
	for(char it : morseCode)
	{
		if(it == ' ' && flag)		++spcCntr;
		else
		{
			flag = 1;
			spcCntr = 0;
//			buff.push_back(it);
		}
		if(spcCntr == 0 && flag)	buff.push_back(it);
		else if(spcCntr == 1)
		{
			fnd = 0;
			for(int i = 0; i < 38; ++i) 
			{
				if(buff == lit[i].first)
				{
					decoded.push_back(lit[i].second);
					buff.clear();
					fnd = 1;
					break;
				}
			}
			if(!fnd)
			{
				for(int i = 0; i < 1; ++i)
				{
					if(buff == spcl[i].first)
					{
						decoded += spcl[i].second;
						buff.clear();
						fnd = 1;
						break;
					}
				}
			}
		}
		else if(spcCntr == 3 && flag)	decoded.push_back(' ');
//		if(n == morseCode.size())	morseCode.push_back(' ');
//		++n;
	}
	decoded.pop_back();
	return decoded;
}
int main()
{
		std::cout << decodeMorse(".... . -.--   .--- ..- -.. .   ..-. ..- -.-. -.-   -.-- --- ..-   ...---...") << '|' << std::endl;
	return 0;
}

