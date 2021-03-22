#include <bits/stdc++.h>
using namespace std;

// 1-indexed, [1, n]
template<class T>
class BIT {
    T bit[MN];
    int n;
 
public:
    BIT() {
        n = MN;
        memset(bit, 0, sizeof(bit));
    }
 
    T sum(int i) {
        ++i;
        T s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
 
    void add(int i, T x) {
        ++i;
        while (i < n) {
            bit[i] += x;
            i += i & -i;
        }
    }
};

int main()
{
    BIT<int> T;
    T.add(x, 2);
    T.sum(x - 1);
}
