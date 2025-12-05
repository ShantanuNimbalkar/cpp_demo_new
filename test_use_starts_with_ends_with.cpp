// Test file for use_starts_with_ends_with (RSPEC-6178)
#include <string>
#include <iostream>

void test_starts_with_ends_with() {
    std::string s = "Hello World";
    std::string prefix = "Hello";
    std::string suffix = "World";

    // EMB-ISSUE: use_starts_with_ends_with
    if (s.find(prefix) == 0) {
        // Non-compliant: Use starts_with
    }

    // EMB-ISSUE: use_starts_with_ends_with
    if (s.rfind(suffix) == (s.length() - suffix.length())) {
        // Non-compliant: Use ends_with
    }

    // EMB-ISSUE: use_starts_with_ends_with
    if (s.substr(0, 5) == "Hello") {
        // Non-compliant: Use starts_with
    }

    // Compliant (C++20)
    // if (s.starts_with(prefix)) { }
    // if (s.ends_with(suffix)) { }
}
