#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, maxArr = -1;
  cin >> n;
  int irons[1005];
  int ironsSum[1005];
  long long res = 0;

  ironsSum[0] = 0;

  for (int i = 0; i <= 1000; i++) {
    irons[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> x;
    maxArr = x > maxArr ? x : maxArr;
    irons[x]++;
  }
  for (int i = 1; i <= 1000; i++) {
    ironsSum[i] = ironsSum[i - 1] + irons[i];
  }

  for (int i = 1; i <= maxArr; i++)
    for (int j = i + 1; j <= maxArr; j++)
      for (int k = j + 1; k <= maxArr; k++) {
        if (i + j > k && j + k > i && i + k > j && i && j && k){
        //   cout << i << " - " << j << " - " << k << endl;
          res += irons[i] * irons[j] * irons[k];
        }
      }
  // for (int i = 1; i <= maxArr; i++)
  //   for (int j = i + 1; j <= maxArr; j++) {
  //     int minC = max(i, j) - min(i, j) + 1;
  //     int maxC = max(i, j) + min(i, j) - 1;
  //     if (minC == min(i, j) || maxC == max(i, j))
  //       continue;
  //     //cout << minC << " - " << maxC << " = " << (ironsSum[maxC > maxArr ?
  //     maxArr : maxC] - ironsSum[minC - 1]) << endl; res += (ironsSum[maxC >
  //     maxArr ? maxArr : maxC] - ironsSum[minC - 1]); if (minC < i && i <
  //     maxC) {
  //       res--;
  //     }
  //     if (minC < j && j < maxC) {
  //       res--;
  //     }
  //   }
  cout << res << endl;
  return 0;
}