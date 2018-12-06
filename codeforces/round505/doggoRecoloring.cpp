#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	ll n;
	cin>>n>>s;
	if(n==1)
	{
		cout<<"Yes\n";
		return 0;
	}
	vector<ll> cnt(30,0);
	ll i;
	for(i=0;i<n;i++)
		cnt[s[i]-'a']++;
	ll flag=0;
	for(i=0;i<26;i++)
		if(cnt[i]>1)
			flag=1;
	if(flag==0)
		cout<<"No\n";
	else
		cout<<"Yes\n";
	return 0;
}