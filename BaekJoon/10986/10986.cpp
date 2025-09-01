/* 문제 출처 : https://www.acmicpc.net/problem/10986 */
#include<iostream>

int arr[1000001];
long sums[1000001];
long remainHistory[1000];

long Combi(long x)
{
	long ret = 0;

	if (1 < x)
	{
		ret =  (x * (x - 1)) / 2;
	}

	return ret;
}

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	long result = 0;
	
	int N = 0;
	int M = 0;
	std::cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> arr[i];
		sums[i] = sums[i - 1] + arr[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		const int remain = (sums[i] % M);
		
		if (remain == 0)
		{
			result += 1;
		}
		
		remainHistory[remain] += 1;
	}

	for (int i = 0; i < M; ++i)
	{
		const auto combiCnt = Combi(remainHistory[i]);
		result += combiCnt;
	}

	std::cout << result << '\n';
}