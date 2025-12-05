// Test for use_fold_expressions (RSPEC-6008)
// Fold expressions should be used instead of recursive template instantiations

template <typename T>
auto sum(T t) { return t; }

// EMB-ISSUE: use_fold_expressions
template <typename T, typename... Args>
auto sum(T t, Args... args) { 
    return t + sum(args...); // Recursive instantiation
}

// Compliant: Fold expression (C++17)
template <typename... Args>
auto sum_fold(Args... args) {
    return (... + args);
}

// EMB-ISSUE: use_fold_expressions
template<typename T, typename... Args>
bool all(T t, Args... args) {
    return t && all(args...);
}

// Compliant
template<typename... Args>
bool all_fold(Args... args) {
    return (args && ...);
}
