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
	ll a1,a2,a3,a4;
	cin>>a1>>a2>>a3>>a4;
	ll tmp1=a1,tmp2=a2,tmp3=a3,tmp4=a4;
	ll i;
	string ans="";
	if(abs(a3-a4)>1)
	{
		cout<<"-1\n";
		return 0;
	}
	ll flag=0;
	if(a3>a4)
		ans+='4',a1--;
	else if(a4>a3)
		ans+='7',a2--;
	else
		ans+='4',a1--,flag=1;
	while(a3!=0 || a4!=0)
	{
		if(ans[sz(ans)-1]=='4')
			ans+='7',a3--,a2--;
		else
			ans+='4',a4--,a1--;
	}
	if((a1<0 || a2<0) && flag==1)
	{
		a1=tmp1;
		a2=tmp2;
		a3=tmp3;
		a4=tmp4;
		ans="";
		ans+='7',a2--;
		while(a3!=0 || a4!=0)
		{
			if(ans[sz(ans)-1]=='4')
				ans+='7',a3--,a2--;
			else
				ans+='4',a4--,a1--;
		}
	}
	if(a1<0 || a2<0)
	{
		cout<<"-1\n";
		return 0;
	}
	for(i=0;i<sz(ans);i++)
	{
		if(ans[i]=='4')
			while(a1!=0)
				cout<<'4',a1--;
		cout<<ans[i];
		if(i==sz(ans)-1 || i==sz(ans)-2)
			if(ans[i]=='7')
				while(a2!=0)
					cout<<'7',a2--;
	}
	cout<<endl;
	return 0;
}