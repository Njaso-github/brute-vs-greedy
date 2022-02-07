#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int n, path[15], ans[15];
long double min_dis = 1234567891, dis = 0, now_x = 0, now_y = 0;
bool vis[15];

struct location {
  long double x, y;
}pos[15];

long double cdis(long double x1, long double y1, long double x2, long double y2) {
  return sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
}

void save() {
  if (dis < min_dis) {
    min_dis = dis;
    for (int i = 1; i <= n; i++) {
      ans[i] = path[i];
    }
  }
}

void dfs(int i) {
  for (int j = 1; j <= n; j++) {
    if (!vis[j]) {
      vis[j] = 1;
      path[i] = j;
      long double mark = cdis(now_x, now_y, pos[j].x, pos[j].y);
      dis += mark;
      long double mark_x = now_x;
      long double mark_y = now_y;
      now_x = pos[j].x;
      now_y = pos[j].y;
      if (i == n) save();
      else dfs(i + 1);
      vis[j] = 0;
      now_x = mark_x;
      now_y = mark_y;
      dis -= mark;
    }
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> pos[i].x >> pos[i].y;
  }
  cin >> now_x >> now_y;
  pos[0].x = now_x; pos[0].y = now_y;
  dfs(1);
  cout << fixed << setprecision(6) << min_dis << endl;
  for (int i = 0; i < n; i++) {
    cout << fixed << setprecision(0) << "(" << pos[ans[i]].x << ", " << pos[ans[i]].y << ") --> " << fixed << setprecision(6) << "|" << cdis(pos[ans[i]].x, pos[ans[i]].y, pos[ans[i + 1]].x, pos[ans[i + 1]].y) << "| ";
  }
  cout << fixed << setprecision(0) << "(" << pos[ans[n]].x << ", " << pos[ans[n]].y << ")" << endl;
  return 0;
}