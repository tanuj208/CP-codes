#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

string chara="abcdefghijklmnopqrstuvwxyz";
vector<ll> arr;
vector<ll> ad[30];
queue<ll> q;

ll val(char c)
{
	return (ll)c-(ll)'a';
}

ll present(ll i)
{
	ll j;
	for(j=0;j<sz(arr);j++)
		if(arr[j]==i)
			return 1;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,i,j;
	cin>>n;
	string s,prevs;
	cin>>s;
	prevs=s;
	ll flag=0;
	ll inDegree[26]={0};
	//ad[i][j]==1 means ith alphabet is before jth alphabet
	for(i=1;i<n;i++)
	{
		cin>>s;
		for(j=0;j<min(sz(prevs),sz(s));j++)
		{
			if(prevs[j]==s[j])
				continue;
			else
			{
				ad[val(prevs[j])].pb(val(s[j]));
				inDegree[val(s[j])]++;
				break;
			}
		}
		if(sz(prevs)>sz(s) && j==sz(s))
		{
			flag=1;
			break;
		}
		prevs=s;
	}
	if(flag==1)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	flag=0;
	for(i=0;i<26;i++)
	{
		if(sz(ad[i])>0)
			flag=1;
	}
	if(flag==0)
	{
		cout<<chara<<endl;
		return 0;
	}
	for(i=0;i<26;i++)
	{
		if(sz(ad[i])>0 && inDegree[i]==0)
			q.push(i);
	}
	while(!q.empty())
	{
		ll x=q.front();
		for(i=0;i<sz(ad[x]);i++)
		{
			inDegree[ad[x][i]]--;
			if(inDegree[ad[x][i]]==0)
				q.push(ad[x][i]);
		}
		arr.pb(x);
		q.pop();
	}
	for(i=0;i<26;i++)
	{
		if(inDegree[i]>0)
		{
			cout<<"Impossible"<<endl;
			return 0;
		}
	}
	for(i=0;i<sz(arr);i++)
		cout<<chara[arr[i]];
	for(i=0;i<26;i++)
	{
		if(present(i)==0)
			cout<<chara[i];
	}
	cout<<endl;
	return 0;
}