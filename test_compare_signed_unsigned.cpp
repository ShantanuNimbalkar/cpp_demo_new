// EMB-ISSUE: compare_signed_unsigned
// Test file for rule: compare_signed_unsigned

#include <utility>

void test_comparisons() {
    int s = -1;
    unsigned int u = 1;

    // EMB-ISSUE: compare_signed_unsigned
    if (s < u) { // Problematic: -1 converts to large unsigned
        // ...
    }

    // EMB-ISSUE: compare_signed_unsigned
    if (u == s) {
        // ...
    }

    // EMB-ISSUE: compare_signed_unsigned
    if (s >= u) {
        // ...
    }
}

void compliant_code() {
    int s = -1;
    unsigned int u = 1;

    // C++20 std::cmp_* functions handle this safely
    if (std::cmp_less(s, u)) {
        // ...
    }

    if (std::cmp_equal(u, s)) {
        // ...
    }
    
    // Same types are fine
    int s2 = 2;
    if (s < s2) {}
    
    unsigned int u2 = 2;
    if (u < u2) {}
}
