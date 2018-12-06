#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll n;

ll func(string s)
{
	ll i;
	ll hashh[1000]={0};
	for(i=0;i<sz(s);i++)
	{
		ll x=(ll)s[i];
		hashh[x]++;
	}
	ll maximum=-1;
	for(i=0;i<=300;i++)
		maximum=max(maximum,hashh[i]);
	if(maximum==sz(s) && n==1)
		return maximum-1;
	maximum+=n;
	if(maximum>=sz(s))
		maximum=sz(s);
	return maximum;	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	string s1,s2,s3;
	cin>>s1>>s2>>s3;
	ll a=func(s1);
	ll b=func(s2);
	ll c=func(s3);
	ll arr[5]={a,b,c};
	sort(arr,arr+3);
	if(arr[2]==arr[1])
	{
		cout<<"Draw\n";
		return 0;
	}
	ll x=arr[2];
	if(x==a)
		cout<<"Kuro\n";
	else if(x==b)
		cout<<"Shiro\n";
	else if(x==c)
		cout<<"Katie\n";
	return 0;
}