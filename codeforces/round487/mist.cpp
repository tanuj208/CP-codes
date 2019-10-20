#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
char mat[100][100];
ll i,j;

void insert(ll a,char b,char d)
{
	ll q,w;
	for(w=0;w<50;w++)
		mat[i][w]=d;
	if(a==0)
	{
		i++;
		return;
	}
	ll flag=0;
	for(q=i+1;q<50;q++)
	{
		flag++;
		for(w=0;w<50;w++)
		{
			if(w%2==0)
			{
				if(flag%2==1)
					mat[q][w]=b,a--;
				else
					mat[q][w]=d;
			}
			else
			{
				if(flag%2==1)
					mat[q][w]=d;
				else
					mat[q][w]=b,a--;
			}
			if(a==0)
				break;
		}
		if(a==0)
			break;
		q++;
		for(w=0;w<50;w++)
			mat[q][w]=d;
	}
	j=w+1;
	for(w=j;w<50;w++)
		mat[q][w]=d;
	for(w=0;w<50;w++)
		mat[q+1][w]=d;
	i=q+2;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	a--;
	b--;
	c--;
	d--;
	i=0;
	j=0;
	insert(a,'A','B');
	insert(b,'B','C');
	insert(c,'C','D');
	insert(d,'D','A');
	ll n=i;
	ll m=50;
	cout<<n<<" "<<m<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cout<<mat[i][j];
		cout<<endl;
	}
	return 0;
}