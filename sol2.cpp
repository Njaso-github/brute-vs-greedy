#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

/*
the result of the greedy algorithm to this problem is not the minimum length of path
but it's time complexity is just O(n * n), it is way faster than the DFS algorithm
which has a time complexity of n!, and it is not useful at all
*/

bool vis[3505];
long double inf = 1e9;
int path[3505];

long double cdis(long double x1, long double y1, long double x2, long double y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

struct location {
  long double x, y;
}pos[3505];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> pos[i].x >> pos[i].y;
  }
  long double ans = 0;
  long double me_x, me_y;
  cin >> me_x >> me_y;
  pos[0] = {me_x, me_y};
  for (int i = 1; i <= n; i++) {
    long double min_dis = inf;
    for (int j = 1; j <= n; j++) {
      long double dis = cdis(me_x, me_y, pos[j].x, pos[j].y);
      if (dis < min_dis && !vis[j]) {
        min_dis = dis;
        path[i] = j;
      }
    }
    vis[path[i]] = 1;
    ans += min_dis;
    me_x = pos[path[i]].x;
    me_y = pos[path[i]].y;
  }
  cout << fixed << setprecision(6) << ans << endl;
  for (int i = 0; i < n; i++) {
    cout << fixed << setprecision(0) << "(" << pos[path[i]].x << ", " << pos[path[i]].y << ") --> " << fixed << setprecision(6) << "|" << cdis(pos[path[i]].x, pos[path[i]].y, pos[path[i + 1]].x, pos[path[i + 1]].y) << "| ";
  }
  cout << fixed << setprecision(0) << "(" << pos[path[n]].x << ", " << pos[path[n]].y << ")" << endl;
  return 0;
}