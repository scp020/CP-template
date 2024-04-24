#include "DS/PersistentDSU.h"
#include "IO/FastIO.h"

int main() {
    OY::PerDSU::Table<uint32_t, 1000> u(10);
    cout << u << '\n';

    auto u2 = u.copy();
    u2.unite_by_size(1, 2);
    u2.unite_by_size(1, 3);
    u2.unite_by_size(2, 4);
    cout << u2 << '\n';

    auto u3 = u2.copy();
    u3.unite_by_size(6, 7);
    u3.unite_by_size(8, 9);
    u3.unite_by_size(7, 8);
    cout << u3 << '\n';

    auto u4 = u.copy();
    u4.unite_by_size(1, 7);

    cout << u << '\n';
    cout << u2 << '\n';
    cout << u3 << '\n';
    cout << u4 << '\n';
}
/*
#输出如下
[(0,1), (1,1), (2,1), (3,1), (4,1), (5,1), (6,1), (7,1), (8,1), (9,1)]
[(0,1), (2,4), (2,4), (2,4), (2,4), (5,1), (6,1), (7,1), (8,1), (9,1)]
[(0,1), (2,4), (2,4), (2,4), (2,4), (5,1), (9,4), (9,4), (9,4), (9,4)]
[(0,1), (1,1), (2,1), (3,1), (4,1), (5,1), (6,1), (7,1), (8,1), (9,1)]
[(0,1), (2,4), (2,4), (2,4), (2,4), (5,1), (6,1), (7,1), (8,1), (9,1)]
[(0,1), (2,4), (2,4), (2,4), (2,4), (5,1), (9,4), (9,4), (9,4), (9,4)]
[(0,1), (7,2), (2,1), (3,1), (4,1), (5,1), (6,1), (7,2), (8,1), (9,1)]

*/