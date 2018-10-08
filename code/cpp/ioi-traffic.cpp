#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
#define pb push_back
#define INF 1000000000
#define mp make_pair
#define MOD 1000000007
#define F first
#define S second
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPD(i,n) for(int i=(n);i>=0;i--)
#define FORD(i,a,b) for(int i=(a);i>=b;i--)
#define all(v) v.begin(),v.end()
#define itr ::iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define remin(a,b) (a) = min((a),(b))
#define remax(a,b) (a) = max((a),(b))

int n,a[2000005];
vi adj[2000005];
int tot[2000005];
int dp[2000005];

void dfs(int s,int cur,int p){
	dp[s] = cur;
	for(auto x:adj[s]){
		if(x==p)continue;
		dfs(x,cur+tot[s]-tot[x],s);
		remax(dp[s],tot[x]); 
	}
}

void dfs2(int s,int p){
	tot[s] = a[s];
	for(auto x:adj[s]){
		if(x==p) continue;
		dfs2(x,s);
		tot[s]+=tot[x];
	}
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	REP(i,n) cin >> a[i];
	REP(i,n-1){
		int u,v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs2(0,-1);
	dfs(0,0,-1);
	int ind = 0,ans = dp[0];
	REP(i,n){;
		if(dp[i] < ans){
			ans = dp[i];
			ind = i;
		}
	}
	cout << ind;
}
