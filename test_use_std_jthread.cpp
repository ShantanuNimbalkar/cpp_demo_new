// Test for use_std_jthread
// EMB-ISSUE: use_std_jthread

#include <thread>
#include <vector>

// Mocking std::jthread for pre-C++20 compilers if needed for testing context
namespace std {
    class jthread {};
}

void non_compliant() {
    // EMB-ISSUE: use_std_jthread
    std::thread t1([]{}); 
    
    // EMB-ISSUE: use_std_jthread
    std::thread t2; 
}

void compliant() {
    std::jthread jt1;
    
    // Other types are fine
    std::vector<int> v;
}

struct Wrapper {
    // EMB-ISSUE: use_std_jthread
    static std::thread static_t;
};
