// EMB-ISSUE: enum_underlying_access
// Test file for rule: The underlying value of an enum should be accessed through std::to_underlying

#include <utility> // For std::to_underlying in C++23

enum class Color { Red, Green, Blue };
enum Unscoped { A, B, C };

void test_violation() {
    Color c = Color::Red;
    
    // EMB-ISSUE: enum_underlying_access
    int val1 = static_cast<int>(c); 

    // EMB-ISSUE: enum_underlying_access
    int val2 = (int)c;

    Unscoped u = A;
    
    // EMB-ISSUE: enum_underlying_access
    int val3 = static_cast<int>(u);
}

void test_compliant() {
    Color c = Color::Red;
    
    // Check if C++23 is available (mocking compliance for this test)
    #if __cplusplus >= 202302L
    auto val = std::to_underlying(c); // Compliant in C++23
    #endif
}
