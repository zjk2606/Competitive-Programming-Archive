#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
#define fi first
#define se second
#define sz(c)  ((int)(c).size())
#define all(c) (c).begin(), (c).end()
#define forn(i, m, n)  for (int i = m, nnnn = (n); i < nnnn; ++i)
#define pb  push_back
#define mp  make_pair
#define NIL 0
#define INF INT_MAX
#define int128 __int128_t
#define P 998244353

ll gcd(ll a, ll b) {
	return b ? gcd (b, a % b) : a;
}

vector<int> sieve;

void prime_sieve(int n){
	sieve.reserve(n+1);
	forn(i, 0, n+1) sieve[i] = i;
	forn(i, 2, n+1){
		if (sieve[i] == i){
			forn(j, 2, n/i+1){
				if (sieve[i*j] == i*j) sieve[i*j] = i;
			}
		}
	}
}
	
ll pow_mod(ll a, ll b, ll c){
	ll b_expo[63];
	b_expo[0] = a;
	for(int i = 1; i < 63; i++){
		b_expo[i] = (b_expo[i-1] * b_expo[i-1]) % c;
	}
	ll ans = 1;
	for(ll i = 62; i >= 0; i--){
		if (b >= ((ll)1 << i)){
			ans = (ans * b_expo[i]) % c;
			b-= ((ll)1 << i);
		}
	}
	return ans;
}

int msb(ll a){
	for(int i = 62; i >= 0; i--){
		if (a & ((ll)1 << i)) return i + 1;
	}
	return 0;
}

int msmb(ll a){
	for(int i = 62; i >= 0; i--){
		if (a & ((ll)1 << i)) {
			for(int j = i-1; j >= 0; j--){
				if (!(a & ((ll)1 << j))) return j+1;
			}
			return 0;
		}
	}
	return 0;
}
	
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	ll c = 0;
	pair<ll, ll> arr[n];
	forn(i, 0, n) {
		cin >> arr[i].fi >> arr[i].se;
	 	c+= arr[i].se;
	}
	sort(arr, arr+n);
	ll total = 0, curr = 0;
	while(curr != n-1){
		int next = curr;
		while (arr[curr].se + arr[curr].fi >= arr[next].fi + arr[next].se && next != n-1) next++;
		total += max((ll)0, arr[next].fi - arr[curr].se - arr[curr].fi);
		curr = next;
	}
	cout << total + c;



}