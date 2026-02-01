#include <bits/stdc++.h>
using namespace std;

bool candivide(vector<int> &A, int M, int maxOR) {
    int segments = 1;
    int currOR = 0;

    for (int x : A) {
        if (x > maxOR)
            return false;

        if ((currOR | x) <= maxOR) {
            currOR |= x;
        } else {
            segments++;
            currOR = x;
            if (segments > M)
                return false;
        }
    }
    return true;
}

int minimizemaxOR(vector<int> &A, int M) {
    int low = 0, high = 0;

    for (int x : A) {
        low = max(low, x);
        high |= x;
    }

    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (candivide(A, M, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int M, N;
    cout << "Enter number of segments and number of elements: ";
    cin >> M >> N;

    vector<int> A(N);
    cout << "Enter the array: ";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << minimizemaxOR(A, M);
    return 0;
}

