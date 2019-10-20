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

int GetCeilIndex(vector<ll> arr, vector<int>& T, int l, int r, 
                 int key) 
{ 
    while (r - l > 1) { 
        int m = l + (r - l) / 2; 
        if (arr[T[m]] >= key) 
            r = m; 
        else
            l = m; 
    } 
  
    return r; 
} 
  
vector<ll> LongestIncreasingSubsequence(vector<ll> arr, ll n) 
{ 
  
    vector<int> tailIndices(n, 0); // Initialized with 0 
    vector<int> prevIndices(n, -1); // initialized with -1 
    ll i;
    for(i=0;i<n;i++)
    {
    	if(arr[i]>0)
    	{
    		tailIndices[0]=i;
    		break;
    	}
    }
    // cout<<tailIndices[0]<<endl;
    // cout<<i<<endl;

    int len = 1; // it will always point to empty location 
    ll lastWalePos;
    for (; i < n; i++) { 
        if (arr[i] < arr[tailIndices[0]] && arr[i]>0) { 
            // new smallest value 
            tailIndices[0] = i;
        } 
        else if (arr[i] > arr[tailIndices[len - 1]]) { 
            // arr[i] wants to extend largest subsequence 
            prevIndices[i] = tailIndices[len - 1]; 
            // cout<<"F1"<<tailIndices[len-1]<<endl;
            tailIndices[len++] = i; 
        } 
        else { 
            // arr[i] wants to be a potential condidate of 
            // future subsequence 
            // It will replace ceil value in tailIndices 
            int pos = GetCeilIndex(arr, tailIndices, -1, 
                                   len - 1, arr[i]);
            // cout<<pos<<" "<<tailIndices[pos]<<endl;
			if(pos==0)
				continue;
            prevIndices[i] = tailIndices[pos - 1]; 
            // cout<<"F2"<<tailIndices[pos-1]<<" "<<pos<<endl;
            tailIndices[pos] = i;
        } 
    }
    // cout<<"F"<<tailIndices[0]<<endl;
  
    vector<ll> ans;
    for (int i = n-1; i >= 0; i = prevIndices[i])
    {
    	// cout<<i<<endl;
    	ans.pb(i);
    }

    sort(all(ans));

    vector<ll> ans2;
    for(i=0;i<sz(ans);i++)
    {
    	ans2.pb(ans[i]);
    	if(ans[i]==n-1)
    		break;
    }

    // for(i=0;i<sz(ans);i++)
    // 	cout<<ans2[i]<<" ";
    // cout<<endl;
    return ans2;
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
		ll n,k;
		cin>>n>>k;
		vector<ll> a;
		ll i;
		ll curSum=0;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			curSum+=val;
			a.pb(curSum);
		}
		if(curSum<k)
		{
			cout<<"NO\n";
			continue;
		}
		vector<ll> v= LongestIncreasingSubsequence(a, n);
	    if(sz(v)<k)
	    {
	    	cout<<"NO\n";
	    	continue;
	    }
	    cout<<"YES\n";
	    ll cur=-1;
	    for(i=0;i<k-1;i++)
	    {
	    	cout<<v[i]-cur<<" ";
	    	cur=v[i];
	    }
	    cout<<v[sz(v)-1]-cur<<endl;
	}
	return 0;
}