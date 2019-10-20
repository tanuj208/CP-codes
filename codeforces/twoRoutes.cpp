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

// priority_queue <ll,vector<ll>,greater<ll> > p;

typedef int ll;
typedef pair<ll,ll> pii;

ll mod=1000000007;
ll ans=INT_MAX;

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

ll n,m;
ll visited[505];
bool ad[505][505];

void bfs(bool ch)
{
	queue<pair<ll,ll> > q;
	q.push(mp(1, 0));
	while(!q.empty())
	{
		ll x = q.front().ff;
		ll tm = q.front().ss;
		q.pop();
		if(x==n)
		{
			ans=tm;
			break;
		}
		if(visited[x]==1)
			continue;
		visited[x] = 1;
		ll i,j;
		if(x.ff != n && x.ss != n)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(!ad[x.ff][i] || ad[x.ss][j] || i == j || visited[i][j] == 1)
						continue;
					q.push(mp(mp(i, j), tm+1));
				}
			}
		}
		else if(x.ff == n)
		{
			for(i=1;i<=n;i++)
			{
				if(ad[x.ss][i] || visited[n][i] == 1)
					continue;
				q.push(mp(mp(n, i), tm+1));
			}
		}
		else
		{
			for(i=1;i<=n;i++)
			{
				if(!ad[x.ff][i] || visited[i][n] == 1)
					continue;
				q.push(mp(mp(i, n), tm+1));			
			}
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	ll i;
	memset(visited, 0, sizeof(visited));
	memset(ad, false, sizeof(ad));
	for(i=0;i<m;i++)
	{
		ll u,v;
		cin>>u>>v;
		ad[u][v] = true;
		ad[v][u] = true;
	}
	if(ad[1][n])
		bfs(false);
	else
		bfs(true);
	if(ans==INT_MAX)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
	return 0;
}