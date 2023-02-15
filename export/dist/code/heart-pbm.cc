#include <iostream>
#include <cmath>
using namespace std;
auto f = [](int i, int j) {
  double x = j / 100.0 - 3;
  double y = i / 100.0 - 2;
  return pow(pow(x, 2) + pow(y, 2) - 1, 3) + \
             pow(x, 2) * pow(y, 3) < 0;
};

const int N = 500, M = 500;

int main() {
  cout << "P3\n" << M << " "<< N << "\n" << 255 << "\n";
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << (f(i, j) ? "255 0 0\n" : "255 255 255\n");
    }
  }
  return 0;
}