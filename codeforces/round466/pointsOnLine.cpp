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
	int n,d,val,i,j;
	vector<int> x;
	cin>>n>>d;
	for(i=0;i<n;i++)
	{
		cin>>val;
		x.pb(val);
	}
	sort(x.begin(),x.end());
	int range;
	int ans=INT_MAX;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			range=x[j]-x[i];
			if(range>d)
				break;
		}
		ans=min(ans,n-j+i);
	}
	cout<<ans<<endl;
	return 0;
}