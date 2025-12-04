// Test for empty_throw_outside_catch (RSPEC-1039)

void f() {
    // Non-Compliant: throw; used outside of a catch block
    // EMB-ISSUE: empty_throw_outside_catch
    throw;
}

void g() {
    try {
        // ...
    } catch (...) {
        // Compliant: throw; used inside a catch block to re-throw
        throw; 
    }
}

void h() {
    // Non-Compliant: Nested inside a lambda, but lexically the lambda body isn't a catch block
    auto lambda = []() {
        // EMB-ISSUE: empty_throw_outside_catch
        throw; 
    };
    
    try {
        lambda();
    } catch(...) {
        // Compliant
        throw;
    }
}

void i() {
    try {
        // ...
    } catch (int i) {
        if (i > 0) {
            // Compliant: Nested inside if, but ancestor is catch
            throw;
        }
    }
}
