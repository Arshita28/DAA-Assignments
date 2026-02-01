#include <bits/stdc++.h>
using namespace std;

int maxGoodSubsequenceLength(vector<int> &A) {
    int N = A.size();
    sort(A.begin(), A.end());

    int maxLen = 0;
    int i = 0;

    for (int j = 0; j < N; j++) {
        while (A[j] - A[i] > 10) {
            i++;
        }
        maxLen = max(maxLen, j - i + 1);
    }
    return maxLen;
}

int main() {
    int N;
    cout << "Enter number of elements: ";
    cin >> N;

    vector<int> A(N);
    cout << "Enter the array: ";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << "Maximum length of good subsequence: " 
         << maxGoodSubsequenceLength(A) << endl;

    return 0;
}

