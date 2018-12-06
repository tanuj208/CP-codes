#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

typedef long long ll;
typedef pair<int,int> pii;

const int lt=100005;
int mod=1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	int i;
	cin>>n>>m;
	string x,y;
	cin>>x>>y;
	bitset<100005> R,P,S,r,p,s,a,b,c;
	for(i=0;i<n;i++)
	{
		if(x[i]=='R')
			R.set(i);
		else if(x[i]=='P')
			P.set(i);
		else
			S.set(i);
	}
	for(i=0;i<m;i++)
	{
		if(y[i]=='R')
			r.set(i);
		else if(y[i]=='P')
			p.set(i);
		else
			s.set(i);
	}
	int ans=0;
	for(i=0;i<n;i++)
	{
		a=P&s;
		b=S&r;
		c=R&p;
		ans=max(ans,(int)a.count()+(int)b.count()+(int)c.count());
		R>>=1,P>>=1,S>>=1;
	}
	cout<<ans<<endl;
	return 0;
}