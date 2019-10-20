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


typedef long double ld;

ld dh,dl,dr,k;
ld func(ld x)
{
	return sqrt(x*x+dh*dh)/k+sqrt((dr-x)*(dr-x)+dl*dl);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ld l,r;
	while(1)
	{
		cin>>dh>>dl>>dr>>k;
		l=0;
		r=dr;
		if(dh==0)
			break;
		for(int i=0;i<1000;i++)
		{
			ld l1=(2*l+r)/3;
			ld l2=(l+2*r)/3;
			if(l1>l2)
				swap(l1,l2);
			if(func(l1)>func(l2))
				l=l1;
			else
				r=l2;
		}
		cout<<fixed<<setprecision(3)<<sqrt(l*l+dh*dh)+sqrt((dr-l)*(dr-l)+dl*dl)<<"\n";
	}
	return 0;
}