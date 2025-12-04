// Test file for constexpr_literal_operator (RSPEC-6621)

namespace test_literal_operators {

// EMB-ISSUE: constexpr_literal_operator
constexpr long double operator"" _deg_bad(long double deg) {
    return deg * 3.141592 / 180;
}

consteval long double operator"" _deg_good(long double deg) {
    return deg * 3.141592 / 180;
}

// Regular operators are fine
constexpr int operator+(int a, int b) {
    return a + b;
}

// Non-constexpr literal operators are not the target of this rule 
// (though they might be inefficient, this rule specifically targets constexpr -> consteval migration)
long double operator"" _deg_runtime(long double deg) {
    return deg * 3.141592 / 180;
}

class Distance {
public:
    constexpr Distance(long double m) : meters(m) {}
    long double meters;
};

// EMB-ISSUE: constexpr_literal_operator
constexpr Distance operator"" _m_bad(long double m) {
    return Distance(m);
}

consteval Distance operator"" _m_good(long double m) {
    return Distance(m);
}

} // namespace test_literal_operators
