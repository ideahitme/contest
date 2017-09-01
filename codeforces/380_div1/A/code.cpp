#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll time_estim(const vector<ll> &x, ll t, ll s, ll cand){
  ll ans = 0;
  ll cur = 0;
  ll k = x.size();

  for(ll i = 0; i <= k && x[i] <= s; i++){
    ll next;
    if (i == k || x[i] >= s) {
      next = s;
    } else {
      next = x[i];
    }
    
    ll diff = next - cur;
    if (cand < diff) return -1;
    ll fast = min(cand-diff, diff);
    ll slow = diff - fast;
    ll total_time = fast + slow*2;
    ans += total_time;    
    cur = next;
  }
  if (cur != s) {
    ll diff = s - cur;
    if (cand < diff) return -1;
    ll fast = min(cand-diff, diff);
    ll slow = diff - fast;
    ll total_time = fast + slow*2;
    ans += total_time;    
  }
  if (ans > t) {
    return -1;
  }
  return ans;
} 
int main(){
  ios::sync_with_stdio(false);
  ll n,k,s,t;
  cin >> n >> k >> s >> t;

  vector<pll> c(n);
  vector<ll> x(k);
  ll min_c = 1e9+1;
  ll max_c = -1;

  for(ll i = 0; i < n; i++) {
    cin >> c[i].first >> c[i].second;
    if (c[i].second > max_c) max_c = c[i].second;    
    if (c[i].second < min_c) min_c = c[i].second;
  }
  for(ll i = 0; i < k; i++){
    cin >> x[i];
  }
  sort(x.begin(), x.end());

  ll l = min_c;
  ll r = max_c;
  ll mid;
  while(l < r){
    mid = (l+r)/2;
    if (time_estim(x, t, s, mid) == -1) {
      l = mid + 1;
    } else { 
      r = mid;
    }
  }
  if (time_estim(x,t,s,l) == -1) {
    cout << -1 << endl;
    return 0;
  }
  ll min_p = 1e12;
  for(ll i = 0; i < n; i++){
    if (c[i].second >= l && c[i].first < min_p) {
      min_p = c[i].first;
    }
  } 
  if (min_p == 1e12) cout << -1 << endl;
  else cout << min_p << endl;
  return 0;
}
