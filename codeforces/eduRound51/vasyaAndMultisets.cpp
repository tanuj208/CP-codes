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
	ll n;
	cin>>n;
	vector<ll> s;
	vector<ll> cnt(105,0);
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		s.pb(val);
		cnt[val]++;
	}
	ll unq=0,flag=0;
	for(i=1;i<=100;i++)
	{
		if(cnt[i]==1)
			unq++;
		if(cnt[i]>=3)
			flag=1;
	}
	if(unq%2==1 && flag == 0)
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	if(unq%2==1)
		flag=0;
	else
		flag =1;
	ll x=unq/2;
	for(i=0;i<n;i++)
	{
		if(flag==0 && cnt[s[i]]>=3)
		{
			flag=1;
			cout<<"A";
		}
		else if(cnt[s[i]]>=2)
		{
			cout<<"B";
		}
		else if(cnt[s[i]]==1 && x!=0)
		{
			cout<<"A";
			x--;
		}
		else if(cnt[s[i]]==1 && x==0)
			cout<<"B";
	}
	cout<<"\n";
	return 0;
}