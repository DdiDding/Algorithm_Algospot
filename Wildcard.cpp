#include <bits/stdc++.h>
using namespace std;

//w�� s�� ��Ī�� �Ǵ��� bool���� ��ȯ
bool solve(string w, string s)
{
	int pos;
	for (pos = 0; pos < w.size(); ++pos)
	{
		if (w[pos] == '?') continue;
		else if (w[pos] == '*')
		{
			for (int skip = 0; pos + skip <= s.size(); ++skip)
			{
				if (solve(w.substr(pos + 1), s.substr(pos + skip)) == true) return true;
			}
		}

		if (w[pos] != s[pos]) return false;
	}

	if (pos == s.size()) return true;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	vector<string> s;
	
	while (t--)
	{
		string w; cin >> w;
		int n; cin >> n;
		s.resize(n,"");
		for(int i = 0; i < n; ++i)
		{
			cin >> s[i];
		}


		vector<string> ret;
		for (auto & d : s)
		{
			if (solve(w, d) == true) ret.push_back(d);
		}

		sort(ret.begin(), ret.end(), less<string>());
		cout << "����\n";
		for (auto & d : ret)
		{
			cout << d << '\n';
		}
		cout << "��'\n";
	}
	return 0;
}

/*
���� �̸��� �Ϻθ����� ���� �̸��� �����ϴ� ���
?Ȥ�� *Ư�� ���� ����

?�� � ���ڿ� ���ص� ��ġ�Ѵ�.
*�� 0 ���� �̻��� � ���ڿ����� ��ġ�Ѵ�. (��� �ȴٴ¶�)

���ϵ�ī�� ���ڿ� w
���ϸ��� ���� n

*/