#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define pb push_back
#define mp make_pair
#define MAXN (ll)(1e6+10)

int gcd(int a, int b)
{
	if( b==0 ) return a;
	return gcd(b,a%b);
}

void solve(){
	int n;
	cin >> n;

	int ar[MAXN];
	int br[MAXN];
	for(int i=0;i<n;i++)
		cin >> ar[i], br[i]=ar[i];
	
	for(int i=n-1;i>=0;)
		if(ar[i]!=-1)
		{
			int st = ar[i]-1;
			int j = i-1;
			
			while(st!=0 && j>=0 && (ar[j]==-1 || ar[j]==st)) 
				ar[j] = st, st--, j--;
			if(j>=0 && st!=0) {cout << "impossible\n"; return;}
			i = j;
		}
		else i--;
	
	int i=0;
	while(ar[i]==-1 && i<n) i++;
	
	for(;i<n;i++)
		if(ar[i]==-1) ar[i]=ar[i-1]+1;
	
	vector<int> v;
	for(i=1;i<n;i++)
		if(ar[i]==1 && ar[i-1]!=-1) 
			v.pb(ar[i-1]);
	
	if(v.size()==0) {cout << "inf\n"; return;}
	
	int g = v[0];
	for(i=1;i<v.size();i++) g = gcd(g, v[i]);
	
//	cout << g << endl;
	int a=0;
	while(ar[a]==-1 && a<n) a++;
	for(i=a;i<n;i++)
		ar[i]=(i-a)%g+1;
	
	bool f=1;
	for(i=0;i<n;i++) 
		if(br[i]!=-1 && ar[i]!=br[i]) 
		{
			cout << "impossible\n";
			return;
		}
	cout << g << endl;
//	for(i=0;i<n;i++) cout << ar[i] << " "; cout << endl;
}

int main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
