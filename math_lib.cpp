#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll m, ll n) {
    return n != 0 ? gcd(n, m % n) : m;
}

ll lcm(ll m, ll n) {
    // If both m and n are large numbers, the result is overflow without parentheses.
    return m * (n / gcd(m, n));
}

bool is_prime(ll n) {
    if (n < 2) {
        return false;
    } else if (n == 2) {
        return true;
    } else if (n % 2 == 0) {
        return false;
    }
 
    for (ll i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

map<int, int> prime_factorization(int n) {
    map<int, int> m;
    int x = n;
    int d = 2;
    while (x > 1) {
        if (x % d == 0) {
            m[d]++;
            x /= d;
        } else {
            d++;
        }
    }
    return m;
}

vector<ll> divisors(ll n) {
    vector<ll> v;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            v.push_back(i);
            if (i * i != n) {
                v.push_back(n / i);
            }
        }
    }
    return v;
}

int main() {
    // expected: 4
    cout << gcd(8, 12) << endl;
    // expected: 24 
    cout << lcm(8, 12) << endl;
    // expected: 1000000000000000000 
    cout << lcm(1000000000000000000, 500000000000000000) << endl;

    // expected: 2 3 5 7 11 13 17 19....
    for (int i = 1; i <= 100; i++) {
        if (is_prime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;

    // expected: 1 10 2 5
    auto v = divisors(10);
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}
