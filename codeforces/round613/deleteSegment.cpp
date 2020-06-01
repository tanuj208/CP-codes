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

void make_segTree(vector<ll>& arr, vector<ll>& segTree, ll s,ll e,ll i)
{
	if(s==e)
		return;
	ll mid=(s+e)/2;
	make_segTree(arr, segTree, s,mid,(i<<1));
	make_segTree(arr, segTree, mid+1,e,(i<<1)+1);
	ll x1=segTree[(i<<1)];
	ll x2=segTree[(i<<1)+1];
	ll ans=x1+x2;
	if((arr[mid]==0 && x1!=0) || (arr[mid+1]==0 && x2!=0))
		ans++;
	segTree[i]=ans;
	return;
}

void make_segTree2(vector<ll>& arr, vector<ll>& segTree2, ll s,ll e,ll i)
{
	// cout<<s<<" "<<e<<" "<<i<<endl;
	if(s==e)
		return;
	ll mid=(s+e)/2;
	make_segTree2(arr, segTree2, s,mid,(i<<1));
	make_segTree2(arr, segTree2, mid+1,e,(i<<1)+1);
	ll x1=segTree2[(i<<1)];
	ll x2=segTree2[(i<<1)+1];
	ll ans=x1+x2;
	if((arr[mid]==1 && x1!=0) || (arr[mid+1]==1 && x2!=0))
		ans++;
	segTree2[i]=ans;
	return;
}

ll query(vector<ll>& arr, vector<ll>& segTree, vector<ll>& segTree2, ll s,ll e,ll i,ll l, ll r)
{
	if(e<l || s>r)
		return segTree[i];
	if(l<=s && e<=r)
		return segTree2[i];
	ll mid=(s+e)/2;
	ll q1=query(arr, segTree, segTree2, s,mid,(i<<1),l,r);
	ll q2=query(arr, segTree, segTree2, mid+1,e,(i<<1)+1,l,r);
	ll ans=q1+q2;
	ll val1=arr[mid];
	ll val2=arr[mid+1];
	if(mid>=l && mid<=r)
		val1--;
	if(mid+1>=l && mid+1<=r)
		val2--;
	if((val1==0 && q1!=0) || (val2==0 && q2!=0))
		ans++;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<pii> seg;
		set<ll> tmp;
		set<ll> ttt;
		ll i;
		for(i=0;i<n;i++)
		{
			ll l,r;
			cin>>l>>r;
			seg.pb(mp(l,r));
			tmp.insert(l);
			tmp.insert(r);
			if(l==r)
				ttt.insert(l);
		}
		ll baseAns=sz(ttt);
		map<ll,ll> get_idx;
		ll idx=0;
		for(auto it=tmp.begin();it!=tmp.end();it++)
		{
			get_idx[*it]=idx;
			idx++;
		}
		if(idx==1)
		{
			cout<<1<<endl;
			continue;
		}
		vector<ll> main_arr(idx+5,0);
		for(i=0;i<sz(seg);i++)
		{
			ll l=seg[i].ff;
			ll r=seg[i].ss;
			l=get_idx[l];
			r=get_idx[r];
			main_arr[l]++;
			main_arr[r]--;
		}
		for(i=1;i<=idx;i++)
			main_arr[i]+=main_arr[i-1];
		for(i=0;i<idx-1;i++)
			cerr<<main_arr[i]<<" ";
		cerr<<endl;
		ll N=idx-1;
		vector<ll> segTree(4*idx+5, 0);
		vector<ll> segTree2(4*idx+5, 0);
		make_segTree(main_arr, segTree, 0, N-1, 1);
		make_segTree2(main_arr, segTree2, 0, N-1, 1);
		ll ans=LLONG_MIN;

		bool edge_case=true;
		for(i=0;i<idx-1;i++)
			if(main_arr[i]!=1)
				edge_case=false;
		for(i=1;i<4*idx;i++)
			cout<<segTree2[i]<<" ";
		cout<<endl;
		for(i=0;i<n;i++)
		{
			ll l=seg[i].ff;
			ll r=seg[i].ss;
			l=get_idx[l];
			r=get_idx[r];
			if(l==r)
				continue;
			ll x;
			if(edge_case && l==0 && r==idx-1)
				x=-1;
			else
				x=query(main_arr, segTree, segTree2, 0, N-1, 1, l, r-1);
			// cout<<l<<" "<<r<<endl;
			ans=max(ans, x);
			// cout<<x<<" ";
		}
		// cout<<endl;
		cout<<ans+1+baseAns<<endl;
	}
	return 0;
}