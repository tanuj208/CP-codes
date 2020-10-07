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

double get_time_taken(ll prev_pos, ll new_pos, ll vel)
{
	ll total_dist = abs(new_pos - prev_pos);
	double t = (double)total_dist / (double)vel;
	return t;
}

void print_ans(double x)
{
	printf("%.10lf\n", x);
	return;
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
		ll n,l;
		cin>>n>>l;
		vector<ll> a;
		ll i;
		for(i=0;i<n;i++)
		{
			ll vl;
			cin>>vl;
			a.pb(vl);
		}
		vector<double> b;
		double t1 = 0;
		ll vel = 1;
		ll pos = 0;
		for(i=0;i<sz(a);i++)
		{
			double time_taken = get_time_taken(pos, a[i], vel);
			vel++;
			pos = a[i];
			t1 += time_taken;
			b.pb(t1);
		}

		t1 = 0;
		vel = 1;
		pos = l;
		for(i=sz(a)-1;i>=0;i--)
		{
			double time_taken = get_time_taken(pos, a[i], vel);
			vel++;
			pos = a[i];
			t1 += time_taken;
			b.pb(t1);
		}
		double rel_dist = l;
		ll rel_vel = 2;
		double cur_time = 0;
		sort(all(b));
		// for(i=0;i<sz(b);i++)
		// 	cout<<b[i].ff<<" "<<b[i].ss<<endl;
		bool found = false;
		for(i=0;i<sz(b);i++)
		{
			double time_diff = b[i]-cur_time;
			double dist_cov = rel_vel*time_diff;
			if(dist_cov > rel_dist)
			{
				double additional_time = rel_dist/rel_vel;
				double ans = cur_time + additional_time;
				print_ans(ans);
				found = true;
				break;
			}
			else if(dist_cov < rel_dist)
			{
				rel_dist -= dist_cov;
				cur_time = b[i];
				rel_vel++;
			}
			else
			{
				print_ans(b[i]);
				found = true;
				break;
			}
		}
		if(!found)
		{
			double additional_time = rel_dist/rel_vel;
			double ans = additional_time + cur_time;
			print_ans(ans);
		}
	}
	return 0;
}
