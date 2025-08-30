// 문제 출처 : https://www.acmicpc.net/problem/11659
#include<iostream>

int sumNums[100001];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    int M = 0;
    std::cin >> N >> M;

    for(int i = 1; i <= N; ++i)
    {
        int inputNum = 0;
        std::cin >> inputNum;
        sumNums[i] = sumNums[i-1] + inputNum;        
    }

    for(int lgIndex = 0; lgIndex < M; ++lgIndex)
    {
        int st = 0;
        int ed = 0;
        std::cin >> st >> ed;
        std::cout << sumNums[ed] - sumNums[st-1] <<"\n";
    }
}