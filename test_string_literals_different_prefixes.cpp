// EMB-ISSUE: string_literals_different_prefixes
// Test for RSPEC-817: String literals with different prefixes should not be concatenated

void test_mixed_concatenation() {
    const char* s1 = "Hello" "World"; // OK: Same prefix (none)
    const wchar_t* s2 = L"Hello" L"World"; // OK: Same prefix (L)
    
    // EMB-ISSUE: string_literals_different_prefixes
    const wchar_t* s3 = L"Hello" "World"; // Violation: L and none

    // EMB-ISSUE: string_literals_different_prefixes
    const char* s4 = "Hello" L"World"; // Violation: none and L

    // EMB-ISSUE: string_literals_different_prefixes
    const void* s5 = u8"UTF-8" L"Wide"; // Violation: u8 and L

    const char* multiline = "Line1"
                            "Line2"; // OK
                            
    // EMB-ISSUE: string_literals_different_prefixes
    const void* mixed_multiline = "Line1"
                                  L"Line2"; // Violation
}
