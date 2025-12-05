// Test file for nested_try_catch (RSPEC-1141)

void valid_try_catch() {
    try {
        // do something
    } catch (...) {
        // handle error
    }
}

void invalid_nested_try_catch() {
    try {
        // EMB-ISSUE: nested_try_catch
        try {
            // do something
        } catch (...) {
            // nested catch
        }
    } catch (...) {
        // outer catch
    }
}

void invalid_deeply_nested() {
    try {
        try { // This one is nested in the first
             // EMB-ISSUE: nested_try_catch
            try {
                // do something
            } catch (...) {}
        } catch (...) {}
    } catch (...) {}
}
