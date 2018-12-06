#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;


typedef long long ll;
typedef pair<ll,ll> pii;

ll mod=1000000007;

typedef struct x{
	int d,m,y;
}Date;

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

const int monthDays[12] = {31, 28, 31, 30, 31, 30, 
                           31, 31, 30, 31, 30, 31}; 
  
ll countLeapYears(Date d) 
{ 
    int years = d.y; 
  
    if (d.m <= 2) 
        years--; 
  
    return years / 4 - years / 100 + years / 400; 
} 

ll getDifference(Date dt1, Date dt2) 
{ 
    ll n1 = dt1.y*365 + dt1.d; 
    for (ll i=0; i<dt1.m - 1; i++) 
        n1 += monthDays[i]; 
  
    n1 += countLeapYears(dt1); 
  
  
    ll n2 = dt2.y*365 + dt2.d; 
    for (ll i=0; i<dt2.m - 1; i++) 
        n2 += monthDays[i]; 
    n2 += countLeapYears(dt2); 
  
    return (n2 - n1); 
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	vector<pii> bday;  // month then day
	for(i=0;i<n;i++)
	{
		string s;
		cin>>s>>s;
		pii b;
		b.first=stoi(s.substr(0,2));
		b.second=stoi(s.substr(3,2));
		bday.pb(b);
	}
	sort(bday.begin(),bday.end());
	ll mxdif=0;
	vector<pii> ans;
	for(i=1;i<n;i++)
	{
		Date d1,d2;
		d1.d=bday[i-1].second;
		d1.m=bday[i-1].first;
		d1.y=1999;
		d2.d=bday[i].second;
		d2.m=bday[i].first;
		d2.y=1999;
		ll x=getDifference(d1,d2);
		// cout<<x<<endl;
		if(mxdif < x)
		{
			ans.clear();
			ans.pb(bday[i]);
			mxdif=x;
		}
		else if(mxdif == x)
			ans.pb(bday[i]);
	}
	Date d1,d2;
	d1.d=bday[0].second;
	d1.m=bday[0].first;
	d2.d=bday[n-1].second;
	d2.m=bday[n-1].first;
	d1.y=2003;
	d2.y=2002;
	ll x=getDifference(d2,d1);
	// cout<<x<<endl;
	if(mxdif < x)
	{
		ans.clear();
		ans.pb(bday[0]);
	}
	else if(mxdif == x)
		ans.pb(bday[0]);
	pii anss;
	ll mnDiff=LLONG_MAX;
	for(i=0;i<sz(ans);i++)
	{
		Date cur;
		cur.d=28;
		cur.m=10;
		cur.y=2001;
		Date d1;
		d1.m=ans[i].first;
		d1.d=ans[i].second;
		if((d1.m==10 && d1.d>28) || (d1.m > 10))
			d1.y=2001;
		else
			d1.y=2002;
		x=getDifference(cur,d1);
		// cout<<ans[i].first<<" "<<x<<endl;
		if(mnDiff > x)
		{
			mnDiff = x;
			anss=ans[i];
		}
	}
	ll date=anss.second;
	ll month=anss.first;
	if(date!=1)
	{
		if(month<=9)
			cout<<"0"<<month<<"-";
		else
			cout<<month<<"-";
		if(date<=10)
			cout<<"0"<<date-1<<endl;
		else
			cout<<date-1<<endl;
	}
	else
	{
		if(month==1)
			cout<<"12-31\n";
		else
		{
			if(month<=10)
				cout<<"0"<<month-1<<"-";
			else
				cout<<month-1<<"-";
			cout<<monthDays[month-2]<<endl;
		}
	}
	return 0;
}