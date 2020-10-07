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

int SumMax(int input1, int input2)
{
	// Write code here
	vector<int> div_cnt(input1+1, 1);
	int i;
	for(i = 2; i <= input1+1; i++)
		for(int j = i; j <= input1+1; j+=i)
			div_cnt[j]++;
	deque<int> q;
	int ans = 0;
	for(i=1;i<=input2;i++)
	{
		while(!q.empty() && div_cnt[q.back()] < div_cnt[i])
			q.pop_back();
		q.push_back(i);
	}
	ans += div_cnt[q.front()];
	for(i=input2+1;i<=input1;i++)
	{
		if(q.front() == i - input2)
			q.pop_front();
		while(!q.empty() && div_cnt[q.back()] < div_cnt[i])
			q.pop_back();
		q.push_back(i);
		ans += div_cnt[q.front()];
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll p,m;
	cin>>p>>m;
	cout<<SumMax(p, m)<<endl;
	return 0;
}
