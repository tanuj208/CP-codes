#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define lp(var,start,end) for(ll var=start;var<end;++var)
#define sz(a) (int)(a).size()

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n>>k;
	string s,t;
	cin>>s;
	t=s;
	map<char,ll> hash;
	// sort(t,t+n);
	ll i;
	for(i=0;i<n;i++)
	{
		hash[t[i]]=1;
	}
	if(k>n)
	{
		auto it=hash.begin();
		for(i=0;i<k-n;i++)
		{
			t+=it->first;
		}
		cout<<t<<endl;
		return 0;
	}
	i=k-1;
	auto itt=hash.end();
	itt--;
	// cout<<s[i]<<endl;
	auto largestchar=itt->first;
	while(s[i]==largestchar)
		i--;
	// cout<<i<<endl;
	// cout<<largestchar<<endl;
	// cout<<s[i]<<endl;
	auto it=hash.find(s[i]);
	it++;
	t[i]=it->first;
	i++;
	ll j;
	for(j=i;j<k;j++)
	{
		t[j]=hash.begin()->first;
	}
	t=t.substr(0,k);
	cout<<t<<endl;
	// for(auto it=hash.begin();it!=hash.end();it++)
	// {
	// 	cout<<it->first<<" "<<it->second<<endl;
	// }
	return 0;
}