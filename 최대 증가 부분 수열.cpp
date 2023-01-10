#include <bits/stdc++.h>
using namespace std;

int s[505];
int dp[505];

//s[n]���� ������ �ִ������κ� ������ ����
int solve(int n)
{
	//�������
	if (n == 0) return dp[n] = 1;

	//�޸����̼�
	if (dp[n] != -1) return dp[n];

	//�� ���������� �ڽź��� ���� ������ LIS�� Ȯ���ϸ� ���� ������Ʈ�Ѵ�.
	//�ּ� ��(����)�� 1�̴�.
	int ret = 1;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] < s[n]) ret = max(ret, (dp[i] = solve(i)) + 1);
	}
	return dp[n] = ret;
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
		for (int i = 0; i < n; ++i)
		{
			cin >> s[i];
		}
		memset(dp, -1, sizeof(dp));

		int ret = 0;
		for (int i = 0; i < n; ++i)
		{
			ret = max(ret, solve(i));
		}

		cout << ret << '\n';
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

//������ ���
//�ð� ���⵵ = O(2^n)
/*
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
*/

//�� ��Ÿ���� ���
/*
//s[n]���� ������ �ִ������κ� ������ ����
int solve(int n)
{
	if (n == 0) return 1;

	int ret = 1;
	//s[0] ~ s[n - 1] < s[n] ��
	for (int i = 0; i < n; ++i)
	{
		if (s[i] < s[n]) ret = max(ret, solve(i) + 1);
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
		for (int i = 0; i < n; ++i)
		{
			cin >> s[i];
		}

		cout << solve(n - 1) << '\n';
	}
	return 0;
}
*/

//�� ��Ÿ���� DP
//�ð� ���⵵ : O(n^2)
/*
#include <bits/stdc++.h>
using namespace std;

int s[505];
int dp[505];

//s[n]���� ������ �ִ������κ� ������ ����
int solve(int n)
{
	if (n == 0) return dp[n] = 1;

	if (dp[n] != -1) return dp[n];

	int ret = 1;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] < s[n]) ret = max(ret, (dp[i] = solve(i)) + 1);
	}
	return dp[n] = ret;
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
		for (int i = 0; i < n; ++i)
		{
			cin >> s[i];
		}
		memset(dp, -1, sizeof(dp));

		int ret = 0;
		for (int i = 0; i < n; ++i)
		{
			ret = max(ret, solve(i));
		}

		cout << ret << '\n';
	}
	return 0;
}
*/