#include <bits/stdc++.h>
using namespace std;

//s�� �ִ� ���� �κ� ������ ��ȯ�Ѵ�.
int solve(const vector<int>& s)
{
	//�������
	if (s.empty() == true) return 0;

	//�� �ڸ����� �����Ͽ� �ڽ� ���� ū ���� ���� �κ� ������ �����.
	int ret = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		vector<int> t;
		for (int j = i + 1; j < s.size(); ++j)
		{
			if (s[i] < s[j]) t.push_back(s[j]);
		}

		ret = max(ret, solve(t) + 1);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	while (t--)
	{
		//1. Get input value & Initialize dp table
		int n; cin >> n;
		vector<int> s; s.resize(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> s[i];
		}
		
		cout << solve(s) << '\n';
	}
	return 0;
}

/*
�κ� ���� (���� ���� x)
�� ���� = ���� �κ� ����
�� �� ���� �� ���̸� ����ض�.

��ȭ��
52436785
11223453


*/

//���
