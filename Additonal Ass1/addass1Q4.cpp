#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    long long specialty = 0;

    for (int l = 0; l < n; l++) {
        unordered_map<int, int> leftFreq;
        int cnt = 0;

        // Count greater elements on the left including l
        for (int i = l; i >= 0; i--) {
            if (A[i] > A[l]) cnt++;
            leftFreq[cnt]++;
        }

        // Count greater elements on the right
        cnt = 0;
        bool isSpecial = false;

        for (int i = l + 1; i < n; i++) {
            if (A[i] > A[l]) cnt++;
            if (leftFreq.count(k - cnt)) {
                isSpecial = true;
                break;
            }
        }

        // Case: subarray entirely on the left
        if (leftFreq.count(k)) isSpecial = true;

        if (isSpecial)
            specialty += A[l];
    }

    cout << specialty << endl;
    return 0;
}

