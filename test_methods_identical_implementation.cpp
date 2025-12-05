// Test file for methods_identical_implementation rule (RSPEC-4144)
// This file tests detection of identical method implementations.

#include <iostream>

class IdenticalMethods {
public:
    void methodOne(int a) {
        int x = a * 2;
        std::cout << x << std::endl;
        x++;
    }

    // EMB-ISSUE: methods_identical_implementation
    void methodTwo(int b) {
        int x = b * 2;
        std::cout << x << std::endl;
        x++;
    }
    
    // Trivial methods should be ignored (less than 2 statements)
    int getA() { return 1; }
    int getB() { return 1; } // Should NOT flag this
    
    void complexDifference(int a) {
        int x = a * 2;
        std::cout << "Different" << std::endl; // String changed
        x++;
    }
};

class DifferentClass {
public:
    // EMB-ISSUE: methods_identical_implementation
    void methodThree(int c) {
        int x = c * 2;
        std::cout << x << std::endl;
        x++;
    }
};
