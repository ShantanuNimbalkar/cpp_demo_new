// Test file for function_block_scope
// Functions should not be declared at block scope.

namespace user_code {

void valid_global_func(); // OK: Global scope

void outer_func() {
    int x = 0;
    
    // EMB-ISSUE: function_block_scope
    void inner_func(); // Non-Compliant: Block scope declaration
    
    inner_func();
    
    if (x == 0) {
        // EMB-ISSUE: function_block_scope
        void nested_inner_func(int); // Non-Compliant: Nested block scope
        nested_inner_func(x);
    }
}

// OK: Function definition at namespace scope
void another_valid_func() {
}

struct MyStruct {
    void member_func(); // OK: Class scope
};

} // namespace user_code
