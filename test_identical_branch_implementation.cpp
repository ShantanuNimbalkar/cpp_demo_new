// Test file for identical_branch_implementation rule
// Two branches in a conditional structure should not have exactly the same implementation.

void doSomething() {}
void doSomethingElse() {}

void test_if_identical() {
    int x = 5;
    
    // EMB-ISSUE: identical_branch_implementation
    if (x > 0) {
        doSomething();
    } else {
        doSomething();
    }
}

void test_if_different() {
    int x = 5;
    if (x > 0) {
        doSomething();
    } else {
        doSomethingElse();
    }
}

void test_ternary_identical() {
    int x = 5;
    // EMB-ISSUE: identical_branch_implementation
    int y = (x > 0) ? 10 : 10;
}

void test_ternary_different() {
    int x = 5;
    int y = (x > 0) ? 10 : 20;
}
