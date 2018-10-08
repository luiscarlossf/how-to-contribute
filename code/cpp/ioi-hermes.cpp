/*input
5
8 3
7 -7
8 1
-2 1
6 -5
*/		
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

int n;
// dp[i][j][0] = min length traveled to reach x = a[i].F y = j
// dp[i][j][1] = min length traveled to reach x = j y = a[i].S
pii a[20005];
int dp[2][2005][2];

signed main(){
	cin >> n;
	a[0] = {0,0};
	REP(i,n) cin >> a[i+1].F >> a[i+1].S;
	REP(i,n+1) a[i].F += 1000,a[i].S += 1000;
	REP(j,2005){
		dp[0][j][0] = abs(1000-j);
		dp[0][j][1] = abs(1000-j);
	}
	int ans = 1000000000;
	FOR(i,1,n+1){
		REP(j,2001){
			dp[i%2][j][0] = 
				min(dp[(i-1)%2][j][0]+abs(a[i].F-a[i-1].F),
				abs(j-a[i-1].S)+dp[(i-1)%2][a[i].F][1]);
			dp[i%2][j][1] = 
				min(dp[(i-1)%2][a[i].S][0]+abs(j-a[i-1].F),
				abs(a[i].S-a[i-1].S)+dp[(i-1)%2][j][1]);
			if(i == n) remin(ans,min(dp[i%2][j][0],dp[i%2][j][1]));
		}
	}
	cout << ans << endl;
}

