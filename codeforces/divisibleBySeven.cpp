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
	cin>>s;
	ll i;
	ll rem=0;
	ll arr[5]={1,8,6,9};
	ll done[5]={0};
	ll l=0;
	for(i=0;i<sz(s);i++)
	{
		ll x=(ll)s[i]-(ll)'0';
		if(x==0)
			continue;
		ll j;
		ll flag=0;
		for(j=0;j<4;j++)
		{
			if(arr[j]==x && done[j]==0)
				done[j]=1,flag=1;
		}
		if(flag==1)
			continue;
		ll xx=rem*10+x;
		rem=xx%7;
		cout<<s[i];
		l++;
	}
	if(rem==0)
		cout<<"1869";
	else if(rem==1)
		cout<<"6891";
	else if(rem==2)
		cout<<"8196";
	else if(rem==3)
		cout<<"1689";
	else if(rem==4)
		cout<<"1986";
	else if(rem==5)
		cout<<"1968";
	else if(rem==6)
		cout<<"1698";
	l+=4;
	for(i=l;i<sz(s);i++)
		cout<<"0";
	cout<<endl;
	return 0;
}