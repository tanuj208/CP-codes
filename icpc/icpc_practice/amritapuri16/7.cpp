#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define pll pair<ll,ll> 
#define vpll vector<pll>
#define all(X) X.begin(),X.end()
#define endl "\n"

const ll N=1e5+5;
string s;
ll p[N];
ll solve(ll l,ll r)
{
	ll c=0,f=0;
	if(p[l]==r)f=1;
	ll a=0;
	if(f==1)
	{
		lp(i,l,(r-l+1)/2+l)
		{
			if(p[i]==r-i+l)a++;
			else break;
		}
	}

	if((r-l+1)/2==a)
	{
		return a;
	}
	ll ret=0;
	c=0;
	ll p=l+a;
	lp(i,l+a,r+1-a)
	{
		if(s[i]=='(')c++;
		else c--;
		if(c==0)
		{
			ret^=solve(p,i);
			p=i+1;
		}
	}
	return a+ret;
}
int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		cin >> s;
		vll v;
		lp(i,0,s.size())
		{
			if(s[i]=='(')v.pb(i);
			else
			{
				ll x=v[v.size()-1];
				p[i]=x;
				p[x]=i;
				v.pop_back();
			}
		}
		ll x=solve(0,s.size()-1);
		if(x==0)
			cout<<"Bob"<<endl;
		else
			cout<<"ATM"<<endl;
	}
}