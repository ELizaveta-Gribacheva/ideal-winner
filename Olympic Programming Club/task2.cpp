//
// Created by Elizaveta Gribacheva on 13.10.2025.
//
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

int main() {
    cin.sync_with_stdio();
    cin.tie(0);
    int a,b,c;
    cin >> a;
    cin>> b;
    cin >> c;

    unordered_set<int> mp;
    unordered_set<int> ab;

    while (a != 0) {
        int last = a%10;
        a = a/10;
        mp.insert(last);
    }

    while (b != 0) {
        int last = b%10;
        b = b/10;
        auto got = mp.find(last);
        if (got != mp.end()) ab.insert(last);
    }
set<int> an;
    while (c != 0) {
        int last = c%10;
        c = c/10;
        auto got = ab.find(last);
        if (got != ab.end()) an.insert(last);
    }
    for (auto& i : an) {
        cout << i;
    }
return 0;
}