// 문제 출처 : https://www.acmicpc.net/problem/11660

#include<iostream>
constexpr int MAX_N = 1024;
int arr[MAX_N + 1][MAX_N + 1];
int d[MAX_N + 1][MAX_N + 1];

int main()
{
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int N = 0;
	int M = 0;
	std::cin >> N >> M;

	for (int x = 1; x <= N; ++x)
	{
		for (int y = 1; y <= N; ++y)
		{
			std::cin >> arr[x][y];
		}
	}

	for (int x = 1; x <= N; ++x)
	{
		for (int y = 1; y <= N; ++y)
		{
			d[x][y] = d[x - 1][y] + d[x][y - 1] - d[x - 1][y - 1] + arr[x][y];
		}
	}

	for (int i = 1; i <= M; ++i)
	{
		int x1 = 0;
		int y1 = 0;
		int x2 = 0;
		int y2 = 0;
		std::cin >> x1 >> y1 >> x2 >> y2;		

		const int curResult = d[x2][y2] - d[x1 - 1][y2] - d[x2][y1 - 1] + d[x1 - 1][y1 - 1];
		std::cout << curResult << "\n";
	}
}