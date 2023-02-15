#include <bits/stdc++.h>
using namespace std;

int test_cases, lines;
char time_complexity[100];
int max_complexity, cur_complexity, err;
enum state { HOLD, REJECT, ACCEPT } stk[110];
int top;
int stk_c[110];
bool vis[30];

int calc(char time_complexity[]) {
  int l = 0, r = 0;
  int len = strlen(time_complexity);
  for (int i = 0; i < len; i++) {
    if (time_complexity[i] == '(' || time_complexity[i] == '^')
      l = i;
    if (time_complexity[i] == ')')
      r = i;
  }
  if (time_complexity[l] == '(')
    return 0;
  return atoi(strstr(time_complexity + l + 1, time_complexity + r + 1));
}

inline void init() {
  top = err = max_complexity = cur_complexity = 0;
  memset(vis, 0, sizeof(vis));
  memset(stk_c, 0, sizeof(stk_c));
  cin >> lines >> time_complexity;
  calc(time_complexity);
}

inline void show_result() {
  if (err || top || (lines & 1))
    puts("ERR");
  else if (max_complexity == calc(time_complexity))
    puts("Yes");
  else
    puts("No");
}

int main() {
  cin >> test_cases;
  while (test_cases--) {
    init();
    for (int i = 1; i <= lines; i++) {
      char op, x, a[10], b[10];
      cin >> op;
      if (op == 'F') {
        cin >> x >> a >> b;
        if (vis[x - 'a']) {
          err = 1;
          top++;
          continue;
        }
        if (stk[top] == REJECT) {
          stk[++top] = REJECT;
          continue;
        }
        stk_c[++top] = x - 'a';
        vis[x - 'a'] = 1;
        if (a[0] != 'n' && b[0] != 'n')
          stk[top] = static_cast<state>(atoi(a) > atoi(b));
        else {
          stk[top] = static_cast<state>(((a[0] != 'n') << 1) | (b[0] != 'n'));
          if (stk[top] == ACCEPT)
            cur_complexity++;
        }
        max_complexity = max(max_complexity, cur_complexity);
      } else {
        if (!top) {
          err = 1;
          continue;
        }
        if (stk[top] == ACCEPT)
          cur_complexity--;
        vis[stk_c[top--]] = 0;
      }
    }
    show_result();
  }
  return 0;
}