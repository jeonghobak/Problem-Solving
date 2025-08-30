/* 문제 출처 : https://www.acmicpc.net/problem/1546 */

#include<iostream>

int main()
{
	int n = 0;
	std::cin >> n;

	double sum_n = 0.0;
	int max_m = 0.0;
	for (size_t i = 0; i < n; i++)
	{
		double inputData = 0.0;
		std::cin >> inputData;
		
		sum_n += inputData;
		if (max_m < inputData)
		{
			max_m = inputData;
		}
	}

	double finalResult = ((sum_n / max_m) * 100) / n;
	std::cout << finalResult << std::endl;
}