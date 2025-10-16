//
// Created by Elizaveta Gribacheva on 13.10.2025.
//
#include <iostream>
#include  <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> v;

    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0) {
            int sum = 0;
            int num = i;
            while (num != 0) {
                sum += num % 10;
                num /= 10;
            }
            v.emplace_back(sum,i);
        }
    }
    int sum = 0;
    int num = n;

    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }

    v.emplace_back(sum, n);
    sort(v.begin(), v.end(), [](
        const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
});

    cout << v[0].second;
    return 0;
}