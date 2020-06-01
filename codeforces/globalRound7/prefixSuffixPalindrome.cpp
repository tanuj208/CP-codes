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

vector<ll> get_pal_substrs(string text) 
{ 
    ll N = sz(text); 
    N = 2*N + 1;
    vector<ll> L(N);
    L[0] = 0; 
    L[1] = 1; 
    ll C = 1;
    ll R = 2;
    ll i = 0;
    ll iMirror;
    ll maxLPSLength = 0; 
    ll maxLPSCenterPosition = 0; 
    ll start = -1; 
    ll end = -1; 
    ll diff = -1; 

    for (i = 2; i < N; i++)  
    { 
        iMirror  = 2*C-i; 
        L[i] = 0; 
        diff = R - i; 
        if(diff > 0) 
            L[i] = min(L[iMirror], diff); 
  
        while ( ((i + L[i]) < N && (i - L[i]) > 0) &&  
            ( ((i + L[i] + 1) % 2 == 0) ||  
            (text[(i + L[i] + 1)/2] == text[(i - L[i] - 1)/2] ))) 
        { 
            L[i]++; 
        } 
  
        if(L[i] > maxLPSLength)
        { 
            maxLPSLength = L[i]; 
            maxLPSCenterPosition = i; 
        } 
  
        if (i + L[i] > R)  
        { 
            C = i; 
            R = i + L[i]; 
        } 
    }
    return L;
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
		string s;
		cin>>s;
		vector<ll> a = get_pal_substrs(s);
		ll pr=0;
		ll i;
		ll n=sz(s);
		for(i=0;i<sz(s)/2;i++)
		{
			if(s[i]==s[n-1-i])
				pr++;
			else
				break;
		}
		ll ans=0;
		ll prl;
		// for(i=0;i<sz(a);i++)
		// 	cout<<a[i]<<" ";
		// cout<<endl;
		for(i=0;i<sz(a);i++)
		{
			// cout<<ans<<endl;
			if(i%2==0)
			{
				ll tmp=(i/2)-(a[i]/2);
				ll tmp2 = n-(i/2) - (a[i]/2);
				if(tmp<tmp2)
				{
					if(tmp<=pr)
					{
						if(ans <= 2*tmp+a[i])
						{
							ans=2*tmp+a[i];
							prl=tmp+a[i];
						}
					}
				}
				else
				{
					if(tmp2<=pr)
					{
						if(ans<2*tmp2+a[i])
						{
							ans=2*tmp2+a[i];
							prl=tmp2;
						}
					}
				}
			}
			else
			{
				ll tmp=((i-1)/2) - ((a[i]-1)/2);
				ll tmp2=n-1-((i-1)/2) - ((a[i]-1)/2);
				if(tmp<tmp2)
				{
					if(tmp<=pr)
					{
						if(ans<2*tmp+a[i])
						{
							ans=2*tmp+a[i];
							prl=tmp+a[i];
						}
					}
				}
				else
				{
					if(tmp2<=pr)
					{
						if(ans<2*tmp2+a[i])
						{
							ans=2*tmp2+a[i];
							prl=tmp2;
						}
					}
				}
			}
		}
		// cout<<ans<<" "<<prl<<endl;
		for(i=0;i<prl;i++)
			cout<<s[i];
		for(i=n-(ans-prl);i<n;i++)
			cout<<s[i];
		cout<<endl;
	}
	return 0;
}