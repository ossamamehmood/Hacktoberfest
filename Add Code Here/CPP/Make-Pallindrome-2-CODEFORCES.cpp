#include<iostream>
#include<vector>
#include<string>

using namespace std;

void solution(void) {
	string s, temp, ans;
	int l;
	cin >> l;
	cin >> s;
	temp = s;
	reverse(temp.begin(), temp.end());
	int j = 0;
	for (int i = 0; i < s.length()/2; i++)
	{
		if (temp[i+j] == s[i]) {
			ans.push_back(s[i]);
		}
		else
		{
			if (s[i] == temp[i + 1]&&i+1<=s.length()/2) {
				j++;
				ans.push_back(s[i]);
			}
		}
	}
	//if (s.length() % 2 == 1)
		//ans.push_back(s[s.length() / 2 ]);

	cout << "ans " << ans << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t > 0) {
		solution();
		t--;
	}

	return 0;
}