#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

vector<int> v;
int n;

int valid(int x)
{
	int i;
	for(i=0;i<n;i++)
		if(v[i]<(i/x))
			return 0;
	return 1;
}

int ans(int l, int r)
{
	if(l>=r && valid(l)==1)
		return l;
	else if(l>=r && valid(l)!=1)
		return l+1;
	int mid=(l+r)/2;
	if(valid(mid)==1)
		r=mid-1;
	else
		l=mid+1;
	return ans(l,r);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	int val,i;
	for(i=0;i<n;i++)
	{
		cin>>val;
		v.pb(val);
	}
	sort(v.begin(),v.end());
	cout<<ans(1,100)<<endl;
	return 0;
}