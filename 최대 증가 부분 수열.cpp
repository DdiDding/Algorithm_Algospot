#include <bits/stdc++.h>
using namespace std;

int s[505];

//n��° ���� �������� ������ �ִ� ���� �κ� ������ ��ȯ�Ѵ�.
int solve(int n)
{
	//�������
	if (n == 1) return 1;

	//��� �帧
	if (s[n - 1] < s[n]) return solve(n - 1) + 1;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> s[i];
		}

		int ret = 0;
		for (int i = 0; i <= n; ++i)
		{
			ret = max(ret, solve(n));
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
f(1) = 1
f(2) = if( s(1) < s(2) )	true	: f(1) + 1
							false	: 1
f(n) = if( s(n - 1) < s(n) ) true : f(n - 1 ) + 1
							 false: 1


*/