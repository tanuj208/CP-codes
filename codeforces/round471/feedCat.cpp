#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double hh,mm;
	cin>>hh>>mm;
	double h,d,c,n;
	cin>>h>>d>>c>>n;
	if(hh>=20)
	{
		double x=(ceil(h/n))*(c*0.8);
		printf("%.10lf\n",x);
		return 0;
	}
	double temp1=(ceil(h/n))*c;
	double time=(20-hh-1)*60+(60-mm);
	double hunger=h+(time)*d;
	double temp2=(ceil(hunger/n))*(c*0.8);
	double x=min(temp1,temp2);
	printf("%.10lf\n",x);
	return 0;
}