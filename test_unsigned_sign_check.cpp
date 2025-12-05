// Test file for unsigned_sign_check (RSPEC-1768)
// The sign of an unsigned variable should not be tested.

void test_unsigned_check(unsigned int u, unsigned long ul) {
    // EMB-ISSUE: unsigned_sign_check
    if (u < 0) { 
        // Always false
    }

    // EMB-ISSUE: unsigned_sign_check
    if (u >= 0) { 
        // Always true
    }

    // EMB-ISSUE: unsigned_sign_check
    if (0 > ul) { 
        // Equivalent to ul < 0
    }

    // EMB-ISSUE: unsigned_sign_check
    if (0 <= ul) { 
        // Equivalent to ul >= 0
    }
}

void compliant_unsigned_check(unsigned int u) {
    // Valid checks
    if (u > 0) { }
    if (u == 0) { }
    if (u <= 0) { } // Checks if u is 0
}

void test_signed_check(int i) {
    // Signed integers can be negative, so these are valid
    if (i < 0) { }
    if (i >= 0) { }
}
