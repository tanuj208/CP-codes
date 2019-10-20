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
vector<ll> a;
ll n;
map<ll,ll> mapping;
vector<ll> ans(1e5+5);
vector<ll> segTree(4*1e5+5, LLONG_MAX);

ll query(ll s,ll e,ll i,ll l,ll r)
{
	// if(l==0 && r==1)
	// 	cout<<s<<" "<<e<<" "<<i<<endl;
	if(e<l || s>r)
		return LLONG_MAX;
	if(l<=s && e<=r)
		return segTree[i];
	ll mid=(s+e)/2;
	ll q1=query(s,mid,(i<<1),l,r);
	ll q2=query(mid+1,e,(i<<1)+1,l,r);
	return min(q1,q2);
}

void update(ll s, ll e, ll i, ll ind, ll val)
{
	if(s==e && s==ind)
	{
		segTree[i] = val;
		return;
	}
	if(e<ind || s>ind)
		return;
	ll mid=(s+e)/2;
	update(s,mid,(i<<1),ind, val);
	update(mid+1,e,(i<<1)+1,ind,val);
	segTree[i] = min(segTree[i<<1], segTree[(i<<1)+1]);
	if(val==-1)
		// cout<<s<<" "<<e<<" "<<i<<" "<<segTree[i]<<" "<<segTree[9]<<" "<<(i<<1+1)<<endl;
	return;
}

bool valid(ll a,ll b)
{
	if(a%2==0 && b<a/2)
		return true;
	if(a%2==1 && b<=a/2)
		return true;
	return false;
}

ll get_bigger_num(stack<pii>& st, ll val, ll idx)
{
	while(!st.empty() && st.top().ff < val)
		st.pop();
	ll ans=st.top().ss;
	st.push(mp(val, idx));
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	ll i;
	ll mx=LLONG_MIN;
	ll mxIdx;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
		if(val>mx)
		{
			mx=val;
			mxIdx = i;
		}
	}
	vector<ll> tmp=a;
	sort(all(tmp));
	if(tmp[n-1]%2==0)
	{
		if(tmp[0]>=tmp[n-1]/2)
		{
			for(i=0;i<n;i++)
				cout<<-1<<" ";
			cout<<endl;
			return 0;
		}
	}
	else
	{
		if(tmp[0]>tmp[n-1]/2)
		{
			for(i=0;i<n;i++)
				cout<<-1<<" ";
			cout<<endl;
			return 0;
		}
	}
	ll cnt=0;
	for(i=0;i<n;i++)
	{
		if(mapping.find(tmp[i])==mapping.end())
		{
			mapping[tmp[i]]=cnt;
			cnt++;
		}
	}
	ll mxAns=1;
	i=mxIdx+1;
	i%=n;
	while(true)
	{
		if(valid(mx, a[i]))
			break;
		mxAns++;
		i++;
		i%=n;
	}
	ans[mxIdx]=mxAns;
	ll tmpVal=1;
	ll j=mxIdx-1;
	i=mxIdx-1;
	if(i==-1)
		i=n-1;

	stack<pii> getMx;
	getMx.push(mp(mx, mxIdx));


	for(;i!=mxIdx;i--)
	{
		ll coolness = a[i];
		ll ii = get_bigger_num(getMx, coolness, i);
		if(ii<i)
			ans[i] = ans[ii]+(ii-j);
		else
			ans[i] = ans[ii]+(ii-i);
		ll half_val;
		if(coolness%2==0)
			half_val=coolness/2-1;
		else
			half_val=coolness/2;


		auto it=mapping.upper_bound(half_val);
		if(it==mapping.begin())
		{
			ans[i]=min(ans[i], tmpVal+mxAns);
			tmpVal++;
			// cout<<j<<" "<<coolness<<" "<<mapping[coolness]<<endl;
			update(0, n-1, 1, mapping[coolness], j);
			j--;
			if(i==0)
				i=n;
			continue;
		}
		it--;
		half_val = it->second;
		// cout<<half_val<<endl;
		ll q=query(0,n-1,1,0,half_val);
		// cout<<q<<endl;
		if(q==LLONG_MAX)
			ans[i] = min(ans[i], tmpVal+mxAns);
		else
			ans[i] = min(ans[i], q-j);
		tmpVal++;
		update(0, n-1, 1, mapping[coolness], j);
		j--;
		if(i==0)
			i=n;
	}

	for(i=0;i<n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;

	return 0;
}