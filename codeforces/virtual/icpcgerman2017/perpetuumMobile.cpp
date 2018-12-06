// #ifndef CIRCUIT_FINDER_H
// #define CIRCUIT_FINDER_H
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

typedef std::list<int> NodeList;

template<int N>
class CircuitFinder
{
  vector<NodeList> AK;
  vector<int> Stack;
  vector<bool> Blocked;
  vector<NodeList> B;
  int S;

  void unblock(int U);
  bool circuit(int V);
  void output();

public:
  CircuitFinder(int Array[N][N])
    : AK(N), Blocked(N), B(N) {
    for (int I = 0; I < N; ++I) {
      for (int J = 0; J < N; ++J) {
        if (Array[I][J]) {
          AK[I].push_back(Array[I][J]);
        }
      }
    }
  }

  void run();
};

template<int N>
void CircuitFinder<N>::unblock(int U)
{
  Blocked[U - 1] = false;

  while (!B[U - 1].empty()) {
    int W = B[U - 1].front();
    B[U - 1].pop_front();

    if (Blocked[W - 1]) {
      unblock(W);
    }
  }
}

template<int N>
bool CircuitFinder<N>::circuit(int V)
{
  bool F = false;
  Stack.push_back(V);
  Blocked[V - 1] = true;

  for (int W : AK[V - 1]) {
    if (W == S) {
      output();
      F = true;
    } else if (W > S && !Blocked[W - 1]) {
      F = circuit(W);
    }
  }

  if (F) {
    unblock(V);
  } else {
    for (int W : AK[V - 1]) {
      auto IT = std::find(B[W - 1].begin(), B[W - 1].end(), V);
      if (IT == B[W - 1].end()) {
        B[W - 1].push_back(V);
      }
    }
  }

  Stack.pop_back();
  return F;
}
map<pii,double> xx;

template<int N>
void CircuitFinder<N>::output()
{
//   std::cout << "circuit: ";
//   for (auto I = Stack.begin(), E = Stack.end(); I != E; ++I) {
//     std::cout << *I << " -> ";
//   }
// std::cout << *Stack.begin() << std::endl;
  ll prev=*Stack.begin();
  double aa=1;
  auto I=Stack.begin();
  I++;
  for (auto E = Stack.end(); I != E; ++I) {
    ll cur=*I;
    aa=aa*xx[mp(prev,cur)];
    prev=cur;
  }
    ll cur=*Stack.begin();
    aa=aa*xx[mp(prev,cur)];
    if(aa>=1)
    {
      cout<<"inadmissible\n";
      exit(0);
    }
}

template<int N>
void CircuitFinder<N>::run()
{
  Stack.clear();
  S = 1;

  while (S < N) {
    for (int I = S; I <= N; ++I) {
      Blocked[I - 1] = false;
      B[I - 1].clear();
    }
    circuit(S);
    ++S;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n,m;
  cin>>n>>m;
  int ad[1000][1000];
  vector<ll> sizee(805,0);
  ll i,j;
  for(i=0;i<=800;i++)
    for(j=0;j<=800;j++)
      ad[i][j]=0;
  for(i=0;i<m;i++)
  {
    ll a,b;
    double c;
    cin>>a>>b>>c;
    xx[mp(a,b)]=c;
    ad[a-1][sizee[a]]=b;
    sizee[a]++;
  }
  CircuitFinder<1000> CF(ad);
  CF.run();
  cout<<"admissible\n";
  return 0;
}