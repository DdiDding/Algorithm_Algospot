#include <bits/stdc++.h>
using namespace std;
static const int MAX = 987654321;

int GetHard(const string& s)
{
	//���̵� 1 �˻�
	char std = s[0];
	bool isPass = true;
	for (int i = 1; i < s.size() && isPass; ++i)
	{
		if (std != s[i]) isPass = false;
	}
	if (isPass == true) return 1;

	//���̵� 2 �˻�
	isPass = true;
	int sign = s[0] < s[1] ? 1 : -1;
	for (int i = 0; i < s.size() - 1 && isPass; ++i)
	{
		if (s[i] + sign != s[i + 1]) isPass = false;
	}
	if (isPass == true) return 2;

	//���̵� 4 �˻�
	isPass = true;
	bool bSwitch = false;
	char stdarr[2]; stdarr[0] = s[0]; stdarr[1] = s[1];
	for (int i = 2; i < s.size() && isPass; ++i)
	{
		if (stdarr[bSwitch] != s[i]) isPass = false;
		bSwitch = !bSwitch;
	}
	if (isPass == true) return 4;

	//���̵� 5 �˻�
	isPass = true;
	int diff = s[1] - s[0];
	for (int i = 1; i < s.size() - 1 && isPass; ++i)
	{
		if (s[i] + diff != s[i + 1]) isPass = false;
	}
	if (isPass == true) return 5;

	//������ ���̵��� 10
	return 10;
}

//���� S�� �ּ� ���̵��� ��ȯ�Ѵ�.
int solve(string s)
{
	//������� : ������ �ڸ��� 2������ ��, 5������ ��
	if (s.size() <= 2)  return MAX;
	if (s.size() <= 5)  return GetHard(s);

	//�ƴ϶�� 3, 4, 5�� �ɰ���.
	int front, back, ret = MAX;
	for (int i = 3; i <= 5; ++i)
	{
		if (3 <= s.size() - i)
		{
			front = solve(s.substr(0, i));
			back = solve(s.substr(i));
			//cout << s.substr(0, i) << "(" << front << ")�� " << s.substr(i) << "(" << back << ")�� ���� ��� " << front + back << "�� ���Խ��ϴ�\n";
			ret = min(ret, front + back);
		}
	}
	
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	string s; s.reserve(10'005);
	while(t--)
	{
		string str; cin >> str;
		cout << "����" << solve(str) << '\n';
	}

	return 0;
}

/*
������ 3 ~ 5�ڸ��� ���� �� �ִ�.
�κ� ������ ���̵� ���� ���ض�

https://algospot.com/judge/problem/read/PI


*/