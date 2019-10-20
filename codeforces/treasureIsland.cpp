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

ll n,m;
vector<string> s;
vector<vector<ll>> vis(n+5, vector<ll> (m+5, 0));

bool valid(ll i, ll j)
{
	if(i>=n || i<0 || j>=m || j<0 || s[i][j]=='#' || vis[i][j]==1)
		return false;
	else
		return true;
}

void bfs()
{
	queue<pii> q; // position and steps
	q.push(mp(0,0));
	ll i,j;
	bool ansOne = false;
	bool reached = false;
	vis[0][0]=1;
	while(!q.empty())
	{
		pii x1 = mp(0, 0);
		pii x2 = mp(n-1,m-1);
		if(q.front() == x2)
			reached = true;
		if(sz(q)==1 && q.front() != x1 && q.front() != x2)
			ansOne = true;
		pii pt = q.front();
		ll x=pt.ff;
		ll y=pt.ss;
		q.pop();
		if(valid(x+1, y))
		{
			q.push(mp(x+1, y));
			vis[x+1][y]=1;
		}
		if(valid(x, y+1))
		{
			q.push(mp(x, y+1));
			vis[x][y+1]=1;
		}
	}
	if(!reached)
		cout<<0<<endl;
	else if(ansOne)
		cout<<1<<endl;
	else
		cout<<2<<endl;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll i,j;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		string ss;
		cin>>ss;
		s.pb(ss);
	}
	bfs();
	return 0;
}