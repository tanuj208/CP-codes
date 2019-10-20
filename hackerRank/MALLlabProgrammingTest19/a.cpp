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


struct lex_compare {
	bool operator() (const pair<int,int> &lhs, const pair<int,int> &rhs)
	{
		return lhs.first * (1+rhs.second) > (1+lhs.second) * rhs.first;
	}
};

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

bool comp(pair<int,int> a, pair<int,int> b)
{
    if(a.first * b.second > b.first * a.second)
        return true;
    else
        return false;
}

pair<int, int> cur_min(multiset<pair<int,int>, lex_compare> x)
{
    auto it=x.end();
    it--;
    return *it;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	multiset<pair<int,int>, lex_compare> aa;
	ll n;
	ll i;
	ll m;
	vector<ll> radius;
	cin>>n;
	for(i=0;i<n;i++)
	{
		ll a;
		cin>>a;
		radius.pb(a);
	}
	cin>>m;
    sort(radius.begin(),radius.end());
    multiset<pair<int,int>, lex_compare> x;
    if(n>m)
    {
        for(i=n-m;i<n;i++)
        {
            int rad= radius[i];
            x.insert(make_pair(rad*rad, 1));
        }
    }
    else
    {
        for(i=0;i<radius.size();i++)
        {
            int rad = radius[i];
            x.insert(make_pair(rad*rad, 1));
        }
    }
    int cur_size = radius.size();
    while(cur_size < m)
    {
        pair<int,int> tmp = *(x.begin());
        x.erase(x.begin());
        tmp.second ++;
        x.insert(tmp);
        cur_size ++;
    }
    pair<int,int> ans = cur_min(x);
    while(true)
    {
        pair<int,int> tmp = *(x.begin());
        tmp.second++;
        if(!comp(tmp, ans))
            break;
        x.erase(x.begin());
        if((ll)x.size()>0)
        {
        	auto it=x.find(ans);
	        x.erase(it);
        }
        x.insert(tmp);
        ans = cur_min(x);
    }
    double anss = (double)(ans.first) / (double)(ans.second);	
    anss *= 3.14159265359;
    char str[40];
    sprintf(str, "%.4f", anss); 
    cout<<str<<endl;
	return 0;
}		