#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int number_of_students;
	cin >> number_of_students;

	vector<int> skills;
	map<int, ll> skillMap;

	int i,j,k;

	for(i = 0 ; i < number_of_students ; i++)
	{
		int val;
		cin >> val;
		skillMap[val]++;
	}

	for(auto it = skillMap.begin() ; it != skillMap.end() ; it++)
		skills.pb(it -> first);

	int sumValue;
	cin >> sumValue;
	ll ans = 0;
	for(i = 0 ; i < sz(skills) ; i++)
	{
		int j = i + 1;
		int k = sz(skills) - 1;

		while(j < k && k > i && j < sz(skills))
		{
			int x = skills[i] + skills[j] + skills[k];

			if(x == sumValue)
			{
				ans += skillMap[skills[i]] * skillMap[skills[j]] * skillMap[skills[k]];
				j++;
				k--;
			}

			else if(x > sumValue)
				k--;

			else
				j++;
		}
	}

	for(i = 0 ; i < sz(skills) ; i++)
	{
		ll temp = skillMap[skills[i]];
		if(temp >= 2)
		{
			for(j = 0 ; j < sz(skills) ; j++)
			{
				if(j == i)
					continue;
				if(2 * skills[i] + skills[j] == sumValue)
					ans += (temp * (temp - 1) * skillMap[skills[j]]) / 2;
			}
		}
	}

	if(sumValue % 3 == 0 && skillMap.find(sumValue/3) != skillMap.end() && skillMap[sumValue/3] >= 3)
	{
		ll temp = skillMap[sumValue/3];
		ans += (temp * (temp - 1) * (temp - 2)) / 6;
	}

	cout << ans << endl;
	return 0;
}