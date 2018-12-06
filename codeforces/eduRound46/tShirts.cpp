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
	map<string,ll> x1,x2;
	ll i;
	for(i=0;i<n;i++)
	{
		string s;
		cin>>s;
		x1[s]++;
	}
	for(i=0;i<n;i++)
	{
		string s;
		cin>>s;
		x2[s]++;
	}
	map<string,ll> xx;
	for(auto it=x1.begin();it!=x1.end();it++)
	{
		string s=it->first;
		if(x2.find(s)!=x2.end())
		{
			if(x1[s]>x2[s])
			{
				xx[s]=x1[s]-x2[s];
				x2.erase(s);
			}
			else if(x1[s]<x2[s])
				x2[s]-=x1[s];
			else
				x2.erase(s);
		}
		else
			xx[s]=x1[s];
	}
	ll time=0;
	for(auto it=xx.begin();it!=xx.end();it++)
	{
		string s=it->first;
		ll left=it->second;
		time+=left;
	}
	cout<<time<<endl;
	return 0;
}