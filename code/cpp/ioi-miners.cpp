/*input
6
MBMFFB
16
MMBMBBBBMMMMMBMB
*/		
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

int n;
int a[100005];
int dp[2][4][4][4];

int ore(int a,int b,int c){
	int cnt = 0;
	if(a == 1 or b == 1 or c == 1) cnt ++;
	if(a == 2 or b == 2 or c == 2) cnt ++;
	if(a == 3 or b == 3 or c == 3) cnt ++;
	return cnt;
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	REP(i,n+5) a[i] = 0;
	REP(i,2) REP(j,4) REP(k,4) REP(l,4) dp[i][j][k][l] = 0;
	REP(i,n){
		char c; cin >> c;
		if(c == 'M') a[i+1] = 1;
		else if(c == 'B') a[i+1] = 2;
		else a[i+1] = 3;
	}
	FORD(i,n,1){
		REP(j,4){
			REP(k,4){
				REP(l,4){
					int x1 = ore(a[i],a[i-1],j)+dp[(i+1)%2][a[i-1]][k][l];
					int x2 = ore(a[i],k,l)+dp[(i+1)%2][k][a[i-1]][j];
					dp[i%2][j][k][l] = max(x1,x2);
				}
			}
		}
	}
	cout << dp[1][0][0][0];
}
