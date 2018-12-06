#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll min(ll a, ll b)
{
	if(a<b)
		return a;
	else
		return b;
}

int main()
{
	ll n,p;
	cin>>n>>p;
	string s;
	cin>>s;
	ll i;
	ll moves=0;
	// cout<<'d'-'a'<<endl;
	ll right=(n/2)-1;
	ll left=0;
	ll flag=0;
	for(i=0;i<n/2;i++)
	{
		moves+=min(abs(s[i]-s[n-1-i]),26-abs(s[i]-s[n-1-i]));
		// cout<<s[i]<<s[n-1-i];
		if(s[i]==s[n-i-1] && flag==0)
			left++;
		else
			flag=1;
		// cout<<left<<endl;
		// cout<<moves<<endl;
	}
	flag=0;
	for(i=(n/2)-1;i>=0;i--)
	{
		if(s[i]==s[n-i-1] && flag==0)
			right--;
		else
			flag=1;
	}
	// cout<<left<<" "<<right<<endl;
	if(right==-1 && left==n/2)
	{
		cout<<"0"<<endl;
		return 0;
	}
	p--;
	if(p>=n/2)
		p=n-p-1;
	// cout<<left<<" "<<right<<endl;
	moves+=(right-left)+min(abs(p-right),abs(left-p));
	cout<<moves<<endl;
	return 0;
}