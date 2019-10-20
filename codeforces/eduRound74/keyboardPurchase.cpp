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

map<pair<char,char>, ll> freq;
vector<vector<char>> key;
vector<ll> idx(25, -1);
vector<ll> p(25, -1);
vector<pair<ll, pair<char, char>>> sort_freq;
ll n,m;
string s;
ll ans=LLONG_MAX;

ll par(ll x)
{
	if(p[x]==-1)
		return x;
	p[x] = par(p[x]);
	return p[x];
}

void insert_beg(char a, ll id)
{
	vector<char> tmp{a};
	for(ll i=0;i<sz(key[id]);i++)
		tmp.pb(key[id][i]);
	key[id]=tmp;
	return;
}

void print_key()
{
	ll i,j;
	for(i=0;i<sz(key);i++)
	{
		cout<<i<<" ";
		for(j=0;j<sz(key[i]);j++)
			cout<<key[i][j]<<" ";
		cout<<endl;
	}
}

ll get_slowness()
{
	ll i,j;
	string password = "";
	ll tmp_ans=0;
	for(i=0;i<sz(key);i++)
		for(j=0;j<sz(key[i]);j++)
			password+=key[i][j];
	for(i=1;i<sz(s);i++)
	{
		char a=s[i-1];
		char b=s[i];
		ll posa,posb;
		for(j=0;j<sz(password);j++)
		{
			if(password[j]==a)
				posa=j;
			if(password[j]==b)
				posb=j;
		}
		tmp_ans+=abs(posa-posb);
	}
	return tmp_ans;

}

void rec(ll i)
{
	if(i==sz(sort_freq))
	{
		ans=min(ans, get_slowness());
		return;
	}
	char a = sort_freq[i].ss.ff;
	char b = sort_freq[i].ss.ss;
	ll x1=a-'a';
	ll x2=b-'a';
	x1 = par(x1);
	x2 = par(x2);
	ll p_backup1 = p[x1];
	ll p_backup2 = p[x2];
	if(idx[x1]==-1 && idx[x2]==-1)
	{
		vector<char> empt{a,b};
		idx[x1]=sz(key);
		idx[x2]=sz(key);
		key.pb(empt);
		rec(i+1);
		idx[x1]=-1;
		idx[x2]=-1;
		key.pop_back();
	}
	else if(idx[x2]==-1)
	{
		key[idx[x1]].pb(b);
		p[x2]=x1;
		rec(i+1);
		key[idx[x1]].pop_back();
		vector<char> backup = key[idx[x1]];
		insert_beg(b, idx[x1]);
		rec(i+1);
		key[idx[x1]] = backup;
	}
	else if(idx[x1]==-1)
	{
		key[idx[x2]].pb(a);
		p[x1]=x2;
		rec(i+1);
		key[idx[x2]].pop_back();
		vector<char> backup = key[idx[x2]];
		insert_beg(a, idx[x2]);
		rec(i+1);
		key[idx[x2]] = backup;
	}
	else if(idx[x1]!=idx[x2])
	{
		ll aa = idx[x1];
		ll bb = idx[x2];

		vector<char> backupa = key[aa];
		vector<char> backupb = key[bb];
		ll j;
		for(j=0;j<sz(key[bb]);j++)
			key[aa].pb(key[bb][j]);
		p[x2]=x1;
		rec(i+1);

		key[aa] = backupa;
		key[bb] = backupb;
		for(j=0;j<sz(key[aa]);j++)
			key[bb].pb(key[aa][j]);
		p[x1]=x2;
		rec(i+1);

		key[aa] = backupa;
		key[bb] = backupb;
	}
	else
		rec(i+1);
	p[x1] = p_backup1;
	p[x2] = p_backup2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	cin>>s;
	ll i;
	for(i=1;i<n;i++)
	{
		if(s[i-1]<s[i])
			freq[mp(s[i-1], s[i])]++;
		else if(s[i-1]>s[i])
			freq[mp(s[i], s[i-1])]++;
	}
	for(auto it=freq.begin();it!=freq.end();it++)
		sort_freq.pb(mp(it->second, it->first));
	sort(all(sort_freq));
	reverse(all(sort_freq));
	if(sz(sort_freq)==0)
	{
		cout<<0<<endl;
		return 0;
	}
	rec(0);
	cout<<ans<<endl;

	return 0;
}