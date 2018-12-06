#include <bits/stdc++.h>

using namespace std;

int min(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int main()
{
	int n,pos,l,r;
	cin>>n>>pos>>l>>r;
	if(l==1 && r==n)
	{
		cout<<0<<endl;
		return 0;
	}
	int ans=0;
	if(pos<=l)
	{
		ans+=l-pos;
		if(l!=1)
		{
			ans++;
		}
		if(r!=n)
		{
			ans+=r-l;
			ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(pos>=r)
	{
		ans+=pos-r;
		if(r!=n)
		{
			ans++;
		}
		if(l!=1)
		{
			ans+=r-l;
			ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(l==1)
	{
		ans+=r-pos;
		ans++;
		cout<<ans<<endl;
		return 0;
	}
	if(r==n)
	{
		ans+=pos-l;
		ans++;
		cout<<ans<<endl;
		return 0;
	}
	ans+=min(r-pos,pos-l);
	ans++;
	ans+=r-l;
	ans++;
	cout<<ans<<endl;
	return 0;
}