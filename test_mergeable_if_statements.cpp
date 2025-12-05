// Test for mergeable_if_statements (RSPEC-1066)
// Mergeable "if" statements should be combined.

void doSomething();

void test_mergeable_if() {
    int x = 1;
    int y = 2;
    int z = 3;

    // Non-Compliant: Nested if with braces
    // EMB-ISSUE: mergeable_if_statements
    if (x > 0) {
        if (y > 0) {
            doSomething();
        }
    }

    // Non-Compliant: Nested if without braces
    // EMB-ISSUE: mergeable_if_statements
    if (x > 0)
        if (y > 0)
            doSomething();

    // Compliant: Merged
    if (x > 0 && y > 0) {
        doSomething();
    }

    // Compliant: Outer if has else
    if (x > 0) {
        if (y > 0) {
            doSomething();
        }
    } else {
        doSomething();
    }

    // Compliant: Inner if has else
    if (x > 0) {
        if (y > 0) {
            doSomething();
        } else {
            doSomething();
        }
    }

    // Compliant: Outer if has multiple statements
    if (x > 0) {
        doSomething();
        if (y > 0) {
            doSomething();
        }
    }
}
