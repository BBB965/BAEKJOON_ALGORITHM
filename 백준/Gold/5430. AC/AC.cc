#include <iostream>
#include <deque>
#include <string>
using namespace std;

int T, n;
deque <int> dq;
bool isBack;
string p, arrN;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		isBack = true;
		cin >> p;
		cin >> n;
		cin >> arrN;
		string temp = "";
		string answer = "";

		for (int i = 1; i < arrN.size(); i++)
		{
			if (arrN[i] == ']' && temp != "") dq.push_back(stoi(temp));
			if (arrN[i] == ',')
			{
				dq.push_back(stoi(temp));
				temp = "";
			}
			if (arrN[i] >= '0' && arrN[i] <= '9') temp += arrN[i];
		}

		for (int i = 0; i < p.length(); i++)
		{
			if (p[i] == 'R') isBack = 1 - isBack;
			else
			{
				if (dq.empty())
				{
					answer = "error";
					break;
				}
				else if (isBack) dq.pop_front();
				else if (!isBack) dq.pop_back();
			}
		}
		if (answer != "error")
		{
			answer = "[";
			if (dq.size() == 0) answer = "[]";
			else if (isBack) 
			{
				for (int i = 0; i < dq.size() - 1; i++)
				{
					answer += to_string(dq[i]);
					answer += ',';
				}
				answer += to_string(dq[dq.size() - 1]);
				answer += ']';
			}
			else if (!isBack) {
				for (int i = dq.size() - 1; i > 0; i--)
				{
					answer += to_string(dq[i]);
					answer += ',';
				}
				answer += to_string(dq[0]);
				answer += ']';
			}
		}
		cout << answer << "\n";
		dq.clear();
	}
}