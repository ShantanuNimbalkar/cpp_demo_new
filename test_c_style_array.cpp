// EMB-ISSUE: c_style_array
void test_c_style_array() {
    int arr[10]; // Non-Compliant
    
    // EMB-ISSUE: c_style_array
    float f_arr[] = {1.0f, 2.0f}; // Non-Compliant
}

class MyClass {
    // EMB-ISSUE: c_style_array
    char buffer[256]; // Non-Compliant
};

void test_compliant() {
    // Compliant code should use std::array or std::vector
    // std::array<int, 10> std_arr;
    // std::vector<float> vec;
}

int main(int argc, char* argv[]) { // Compliant: argv is usually exception
    return 0;
}
