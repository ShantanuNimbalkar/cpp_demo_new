// EMB-ISSUE: assert_trivially_true
#include <cassert>
#include <iostream>

void test_trivially_true() {
    // Non-compliant: Integer literal != 0
    assert(1); // EMB-ISSUE: assert_trivially_true
    
    // Non-compliant: Bool literal true
    assert(true); // EMB-ISSUE: assert_trivially_true
    
    // Non-compliant: Integer literal usually used for always-true
    assert(42); // EMB-ISSUE: assert_trivially_true
}

void test_compliant(int x) {
    // Compliant: Actual conditions
    assert(x > 0);
    
    // Compliant: 0 (false) is valid for forcing failure/unreachable code
    assert(0);
    assert(false);
}
