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
	ll n;
	cin>>n;
	vector<int> num;
	ll i,val;
	for(i=0;i<n;i++)
	{
		cin>>val;
		num.pb(val);
	}
	if(n==1)
	{
		cout<<"-1\n";
		return 0;
	}
	if(n==2)
	{
		if(num[0]==num[1])
		{
			cout<<"1\n";
			cout<<num[0]<<endl;
			return 0;
		}
		if((num[0]-num[1])%2==0)
		{
			cout<<"3\n";
			ll mx=max(num[0],num[1]);
			ll mn=min(num[0],num[1]);
			cout<<mn-(mx-mn)<<" "<<(mn+mx)/2<<" "<<mx+(mx-mn)<<endl;
		}
		else
		{
			cout<<"2\n";
			ll mx=max(num[0],num[1]);
			ll mn=min(num[0],num[1]);
			cout<<mn-(mx-mn)<<" "<<mx+(mx-mn)<<endl;
		}
		return 0;
	}
	sort(num.begin(),num.end());
	ll flag=0;
	ll superflag=1;
	ll diff=min(num[1]-num[0],num[2]-num[1]);
	ll j;
	ll allSame=0;
	for(i=0;i<n-1;i++)
	{
		if(num[i]!=num[i+1])
			allSame=1;
	}
	if(allSame==0)
	{
		cout<<"1\n";
		cout<<num[0]<<endl;
		return 0;
	}
	for(i=1;i<n;i++)
	{
		if((num[i]-num[i-1])!=diff && flag==0)
		{
			superflag=0;
			if((num[i]-num[i-1])==2*diff)
			{
				flag=1;
				j=i;
			}
			else
				break;
		}
		else if((num[i]-num[i-1])!=diff && flag==1)
		{
			superflag=0;
			flag=0;
			break;
		}
	}
	if(superflag==1)
	{
		cout<<"2\n";
		cout<<num[0]-diff<<" "<<num[n-1]+diff<<endl;
		return 0;
	}
	if(flag==0)
	{
		cout<<"0\n";
		return 0;
	}
	cout<<"1\n";
	cout<<num[j]-diff<<endl;
	return 0;
}