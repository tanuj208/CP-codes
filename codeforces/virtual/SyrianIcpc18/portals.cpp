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

string s;

bool found(ll idx, bool inc, char otherChar)
{
	while(true)
	{
		if(idx < 0 || idx >= sz(s))
			return false;
		if(s[idx]=='#')
			return false;
		if(s[idx]==otherChar || s[idx]=='o')
			return true;
		if(inc)
			idx++;
		else
			idx--;
	}
}

bool edgeCase(ll idx, char otherChar)
{
	if(idx < 0 || idx >= sz(s))
		return false;
	if(s[idx]==otherChar || s[idx]=='o')
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	ifstream inFile;
    inFile.open("portals.in");
	inFile>>t;
	while(t--)
	{
		ll n;
		inFile>>n;
		inFile>>s;
		ll stIdx, enIdx;
		ll i;
		for(i=0;i<sz(s);i++)
		{
			if(s[i]=='s')
				stIdx=i;
			else if(s[i]=='e')
				enIdx=i;
		}

		ll cnt1=0,cnt2=0;
		if(edgeCase(stIdx+1, 'e'))
			cnt1=INT_MAX;
		else if(found(stIdx+1, true, 'e'))
			cnt1++;

		if(edgeCase(stIdx-1, 'e'))
			cnt1=INT_MAX;
		else if(found(stIdx-1, false, 'e'))
			cnt1++;

		if(edgeCase(enIdx+1, 's'))
			cnt2=INT_MAX;
		else if(found(enIdx+1, true, 's'))
			cnt2++;

		if(edgeCase(enIdx-1, 's'))
			cnt2=INT_MAX;
		else if(found(enIdx-1, false, 's'))
			cnt2++;
		ll ans=min(cnt1, cnt2);
		if(ans>=INT_MAX)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}