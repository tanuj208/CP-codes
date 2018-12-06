#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n>>k;
	vector<ll> a;
	ll i,val,j=0;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	if(n==1)
	{
		cout<<"1 "<<a[0]<<endl;
		return 0;
	}
	sort(a.begin(),a.end());
	ll ans=0,ansNum,sum=0,len=1;
	for(i=1;i<n;i++)
	{
		sum=sum+len*(a[i]-a[i-1]);
		len++;
		while(sum>k && j<=i)
		{
			sum-=a[i]-a[j];
			j++;
			len--;
		}
		if(ans<len)
		{
			ans=len;
			ansNum=a[i];
		}
	}
	cout<<ans<<" "<<ansNum<<endl;
	return 0;
}