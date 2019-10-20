#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define endl "\n"

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;


typedef long long ll;
typedef pair<ll,ll> pii;

ll mod=1000000007;

ll power(ll x, ll y) 
{
	ll temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%mod;
	else
		return (((x*temp)%mod)*temp)%mod; 
}


vector<pair<pii,pii> > pc(100005); // r , l, d, coins
vector<pair<pii,pii> > antemp(100005); // r , l, d, coins
ll dp[100005][305];
multiset<pii, greater<pii> > av; // coins, then d
set<pair<ll,pii> > temp;
pii data[100005]; // without any constrain, what would bob have chosen at time=i

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,k;
	cin>>n>>m>>k;
	ll i,j;
	for(i=1;i<=k;i++)
	{
		cin>>antemp[i].ff.ff>>antemp[i].ff.ss>>antemp[i].ss.ff>>antemp[i].ss.ss;
		pc[i].ff.ss=antemp[i].ff.ff;
		pc[i].ff.ff=antemp[i].ff.ss;
		pc[i].ss=antemp[i].ss;
	}
	sort(antemp.begin(),antemp.begin()+k);
	sort(pc.begin(),pc.begin()+k);
	reverse(pc.begin(),pc.begin()+k);
	ll cntr=1;

	for(i=1;i<=n;i++)
	{
		while(cntr<=k && antemp[cntr].ff.ff==i)
		{
			pii tt=mp(antemp[cntr].ss.ss,antemp[cntr].ss.ff);
			av.insert(tt);
			temp.insert(mp(antemp[cntr].ff.ss, tt));
			cntr++;
		}
		auto it=temp.begin();;
		while(sz(temp)!=0)
		{
			pair<ll,pii> tt=*it;
			if(tt.ff>=i)
				break;
			temp.erase(it);
			auto it2=av.find(tt.ss);
			av.erase(it2);
			it=temp.begin();
		}
		pii anss;
		if(sz(av)==0)
			anss=mp(0,i);
		else
		{
			pii tt=*av.begin();
			anss=tt;
		}
		data[i]=anss;
	}

	for(j=1;j<m;j++)
		dp[n][j]=0;
	dp[n][0]=data[n].ff;
	for(i=n-1;i>=1;i--)
	{
		pii dat=data[i];
		ll tt;
		if(dat.ss+1>n)
			tt=0;
		else
			tt=dp[dat.ss+1][0];
		dp[i][0]=dat.ff+tt;
		for(j=1;j<=m;j++)
		{
			if(dat.ss+1>n)
				tt=0;
			else
				tt=dp[dat.ss+1][j];
			dp[i][j]=min(dat.ff+tt,dp[i+1][j-1]);
		}
	}
	cout<<dp[1][m]<<endl;
	return 0;
}