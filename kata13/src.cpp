#include <iostream>
#include <vector>
#include <string>
std::vector<std::string> get_pins(std::string observed)
{
	std::vector<std::vector<int>> posDigs = {{0, 8}, {1, 2, 4}, {1, 2, 3, 5}, {2, 3, 6}, {1, 4, 5, 7}, {2, 4, 5, 6, 8}, {3, 5, 6, 9}, {4, 7, 8}, {0, 5, 7, 8, 9}, {6, 8, 9}}; 
	std::vector<std::string> res;
	std::vector<int> cnts(observed.size());
	std::vector<int> itrs(observed.size());
	std::vector<char> lttrs(observed.size());
	int range = 1;
//	bool filled = 0;
	for(int i = 0; i < observed.size(); ++i)
	{
		range *= posDigs[observed[i] - 48].size();
		cnts[i] = posDigs[observed[i] - 48].size();
	}
//	itrs[observed.size() - 1] = -1;
	for(int i = 0; i < range; ++i)
	{
		std::string subStr;
		for(int j = observed.size() - 1; j > -1; --j)
		{
			if(j == observed.size() - 1)
			{
				if(itrs[j] < cnts[j] - 1 && i != 0)
				{
				
					//++itrs[j];
					++itrs[j];
				}
				else if(observed.size() != 1)
				{
					++itrs[j - 1];
					itrs[j] = 0;
				}
//				lttrs[j] = posDigs[observed[j] - 48][itrs[j]];
//				subStr.insert(0, 1, lttrs[j]);
			}
			else
			{
				if(itrs[j] == cnts[j])
				{
					if(j != 0)	++itrs[j - 1];
					itrs[j] = 0;
				}
			}
			lttrs[j] = posDigs[observed[j] - 48][itrs[j]] + 48;
			subStr.insert(0, 1, lttrs[j]);
			
		}
//		std::cout << subStr << std::endl;
//		if(i > posDigs[observed[0] - 48].size())
		res.push_back(subStr);
	}	
//	std::cout << range << std::endl;
	return res;
	
}

int main()
{
	std::string str = "1";
	std::vector<std::string> blob = get_pins(str);
	std::cout << blob.size() << std::endl;
	for(int i = 0; i < blob.size(); ++i)	std::cout << blob[i] << std::endl;
	return 0;
}
