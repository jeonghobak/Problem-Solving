// 문제출처 : https://school.programmers.co.kr/learn/courses/30/lessons/49993

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<char> skill_Learned;
map<char, char> prevSkillTable;

static bool IsValidTree(const string& skillTree, const string& orderedSkill)
{
	for (const char& skill : skillTree)
	{
		// 선행 스킬이 존재하는 스킬만 선행 스킬 습득 여부 확인
		if (orderedSkill.find(skill) != string::npos)
		{
			if (skill == orderedSkill[0])
			{
				skill_Learned.push_back(skill);
			}
			else
			{
				const char prevSkill = prevSkillTable[skill];
				const auto resultIt = find(skill_Learned.begin(), skill_Learned.end(), prevSkill);

				// 선행 스킬을 습득한 경우, 현재 스킬(선행스킬이 필요한)도 습득한 것으로 체크.
				if (resultIt != skill_Learned.end())
				{
					skill_Learned.push_back(skill);
				}
				else
				{
					return false;
				}
			}
		}
	}

	return true;
}

int solution(string skill, vector<string> skill_trees) 
{
	int answer = 0;

	for (int i = 1; i < skill.size(); ++i)
	{
		prevSkillTable[skill[i]] = skill[i - 1];
	}

	skill_Learned.reserve(30);

	for (const string& skillTree : skill_trees)
	{
		if (true == IsValidTree(skillTree, skill))
		{
			++answer;
		}
		skill_Learned.clear();
	}

	return answer;
}