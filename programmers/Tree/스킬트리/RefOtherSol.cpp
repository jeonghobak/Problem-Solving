// 문제출처 : https://school.programmers.co.kr/learn/courses/30/lessons/49993

#include <string>
#include <vector>

using namespace std;

/**
 * 다른 사람 풀이 분석하여 다시 푼 결과
 * `선행 스킬이 필요한 스킬만 별도로 나열한 경우, 선행 스킬 리스트와 일치하는가?` 관점에 집중
 */
int solution(string skill, vector<string> skill_trees) 
{
	int answer = 0;

	string learnSkill;
	learnSkill.reserve(30);

	for (const string& sTree : skill_trees)
	{
		for (const char& s : sTree)
		{
			if (skill.find(s) != string::npos)
			{
				learnSkill.push_back(s);
			}
		}

		bool isMatch = true;
		for (int i = 0; i < learnSkill.size(); ++i)
		{
			if (learnSkill[i] != skill[i])
			{
				isMatch = false;
				break;
			}
		}

		if (true == isMatch)
		{
			answer += 1;
		}
		
		learnSkill.clear();
	}

	return answer;
}