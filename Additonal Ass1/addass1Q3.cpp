#include <bits/stdc++.h>
using namespace std;
int median(vector<int> &v){
	sort(v.begin(),v.end());
	return v[v.size()/2];
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    int ops = N - 2; 
    while (ops--) {
        vector<int> medians;
        for(int len = 3; len <= A.size(); len += 2) {
            for(int start = 0; start + len <= A.size(); start++) {
                vector<int> sub(A.begin() + start, A.begin() + start + len);
                medians.push_back(median(sub));
            }
        }
        //erasing the minimum median
        int minMed = *min_element(medians.begin(), medians.end());
        for(int i = 0; i < A.size(); i++) {
            if(A[i] == minMed) {
                A.erase(A.begin() + i);
                break;
            }
        }
    }
    cout << A[0] + A[1] << endl;
    return 0;
}

