//
// Created by Elizaveta Gribacheva on 13.10.2025.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = arr[i] * prefix[i-1];
    }

    vector<int> postfix(n);
    postfix[n-1] = arr[n-1];
    for (int k = n-2; k >= 0; --k) {
        postfix[k] = arr[k] * postfix[k+1];
    }
    vector<int> result(n);
    result[0] = postfix[1];
    result[n-1] = prefix[n-2];

    for (int j = 1; j < n-1; j++) {
        result[j] = prefix[j-1] * postfix[j+1];
    }
    for (int k = 0; k < n; k++) {
        cout << result[k] << ", ";
    }

    return 0;
}
