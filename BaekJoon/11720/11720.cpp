#include<iostream>

int main()
{
    int n = 0;
    std::cin >> n;

    int result = 0;
    for(int i = 0; i < n; ++i)
    {
        char c;
        std::cin >> c;
        result += (c - '0');
    }

    std::cout << result << std::endl;
}