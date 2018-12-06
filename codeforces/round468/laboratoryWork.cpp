#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define lp(var,start,end) for(ll var=start;var<end;++var)
#define sz(a) (int)(a).size()

ll n;
ll msr[100005];
ll dp[200005];
ll x=0;
ll s=0;
ll countt[100006]={0};
ll mn;
ll md;
ll mx;
ll aa,bb,cc;	
ll coun=0;

ll ans(ll sum)
{
	if(coun==n && sum!=0)
		return INT_MAX;
	if(sum==0 && coun==n)
		return x;
	if(dp[sum]!=-1)
		return dp[sum];
	ll temp1,temp2,temp3;
	ll tempmn=mn,tempmd=md,tempmx=mx;
	ll tempcnt=coun;
	if(mn<aa)
	{
		mn++;
		tempmn++;
		coun++;
		temp1=1+ans(sum-(msr[0]+100000));
	}
	else
	{
		coun++;
		temp1=ans(sum-(msr[0]+100000));
	}
	mn=tempmn;
	md=tempmd;
	mx=tempmx;
	coun=tempcnt;
	if(md<bb)
	{
		md++;
		tempmd++;
		coun++;
		temp2=1+ans(sum-(msr[0]+100000)-1);
	}
	else
	{
		coun++;
		temp2=ans(sum-(msr[0]+100000)-1);
	}
	mn=tempmn;
	md=tempmd;
	mx=tempmx;
	coun=tempcnt;
	if(mn<cc)
	{
		mx++;
		coun++;
		tempmx++;
		temp3=1+ans(sum-(msr[0]+100000)-2);
	}
	else
	{
		coun++;
		temp3=ans(sum-(msr[0]+100000)-2);
	}
	mn=tempmn;
	md=tempmd;
	mx=tempmx;
	coun=tempcnt;
	dp[sum]=min(temp1,min(temp2,temp3));
	return dp[sum];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	mn=0;
	md=0;
	mx=0;
	cin>>n;
		ll i,j;
	for(i=0;i<=200005;i++)
		dp[i]=-1;
	for(i=0;i<n;i++)
	{
		cin>>msr[i];
		s+=msr[i];
		countt[msr[i]]++;
	}
	aa=countt[msr[0]];
	bb=countt[msr[0]+1];
	cc=countt[msr[0]+2];
	sort(msr,msr+n);
	cout<<ans(s+100000)<<endl;
	return 0;
}