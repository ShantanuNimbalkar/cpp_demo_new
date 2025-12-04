// Test file for delete_pointer_type rule (RSPEC-2808)

struct Incomplete; // Forward declaration

struct Complete {
    int x;
};

void test_void_pointer(void* p) {
    // EMB-ISSUE: delete_pointer_type
    delete p; // Violation: Deleting void* is undefined behavior
}

void test_incomplete_type(Incomplete* p) {
    // EMB-ISSUE: delete_pointer_type
    delete p; // Violation: Deleting pointer to incomplete type
}

void test_compliant(Complete* c, int* i) {
    // OK
    delete c;
    delete i;
    
    Complete* c_arr = new Complete[5];
    delete[] c_arr;
}
