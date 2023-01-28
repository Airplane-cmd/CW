#include <iostream>
bool validateSolution(const uint board[9][9])
{
	int sum = 0;
	int sum1 = 0;
	int sum2 = 0;
	for(int i = 0; i < 9; ++i)
	{
		for(int j = 0; j < 9; ++j)
		{
			sum += board[i][j];
		}
		if(sum != 45)	
		{		
			return 0;
		}
		sum = 0;
	}
	for(int i = 0; i < 9; ++i)
	{
		for(int j = 0; j < 9; ++j)
		{
			sum += board[j][i];
		}
		if(sum != 45)	
		{		
			return 0;
		}
		sum = 0;
	}
	for(int i = 0; i < 9; ++i)
	{

		for(int j = 0; j < 9; ++j)
		{
		
			if(j < 3)			sum += board[i][j];
			else if(j >= 3 && j < 6)	sum1 += board[i][j];
			else				sum2 += board[i][j];

		}
//		std::cout << sum << " " << sum1 << " " << sum2 << std::endl;

		if(i % 3 == 2)			
		{
			if(sum != 45 || sum1 != 45 || sum2 != 45)	return 0;
			sum = 0;
			sum1 = 0;
			sum2 = 0;
			if(i == 9)	break;
		}
	}
	return 1;
}
int main()
{

	uint whatEver[9][9]= {{5, 3, 4, 6, 7, 8, 9, 1, 2}, 
                             {6, 7, 2, 1, 9, 5, 3, 4, 8},
                             {1, 9, 8, 3, 4, 2, 5, 6, 7},
                             {8, 5, 9, 7, 6, 1, 4, 2, 3},
                             {4, 2, 6, 8, 5, 3, 7, 9, 1},
                             {7, 1, 3, 9, 2, 4, 8, 5, 6},
                             {9, 6, 1, 5, 3, 7, 2, 8, 4},
                             {2, 8, 7, 4, 1, 9, 6, 3, 5},
                             {3, 4, 7, 2, 8, 6, 1, 7, 9}}; 
	std::cout << validateSolution(whatEver) << std::endl;
	return 0;
}

