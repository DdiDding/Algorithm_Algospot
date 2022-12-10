#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<char> q;

//���� ���� Ʈ���� �� 4�и� string�� ���ϰ� �� �����Ͽ� ��ȯ�Ѵ�!
//�Һ��� : ���������� x�� ����.
string Solve(int lev)
{
	//base case : 1ĭ�϶�, �� ���� ��찡 �ִ�.
	//1)�ּҷ����϶��� 1ĭ, 2)�ּҷ����� ���� �ʾ��� ���� ��ĭ
	if (lev == 0 || q.size() == 1)
	{
		string ret(1, q.front()); q.pop();
		return ret;
	}

	//1. �� 4�и��� ���ڿ� ����
	string temp[4];
	for (int i = 0; i < 4; ++i)
	{
		temp[i] = q.front(); q.pop();
		if (temp[i] == "x") temp[i] += Solve(lev - 1);
	}

	//2. �� �ռ��� ��ȯ
	return temp[2] + temp[3] + temp[0] + temp[1];
}


int main()
{
	int n; cin >> n;
	while (n--)
	{
		//1. Input value
		queue<char> tq; q = tq;
		string ts; cin >> ts;
		for (auto & d : ts) q.push(d);

		//2. Do solve
		string ret(1, q.front()); q.pop();
		if (ret == "x") ret += Solve(20);
		cout << ret << "\n";
	}
	return 0;
}
/*
�־��� ������ �׻� 4���� �����Ѵ�.

2^N * 2^N�� ũ���� �׸���

��� �ȼ��� ���� ���� ��� = b
��� �ȼ��� ��	���� ��� = w
���� ���� �ƴ϶�� 4����� �� ���� �Ͽ� ��ģ��.
��ġ�� ������ [ x + ������� + ������� + �����ϴ� + �����ϴ� ]�̴�.

���Ϲ����� �� �ʿ� ����, ��ġ�� ������ �ٸ��� �ϸ� ���Ϲ��� ó�� ������ ������?
[x + �����ϴ� + �����ϴ� + ������� + ������� ]


*/
