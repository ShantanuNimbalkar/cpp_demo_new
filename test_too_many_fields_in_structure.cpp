// EMB-ISSUE: too_many_fields_in_structure
// Test for RSPEC-1820: Structures should not have too many fields

struct SmallStruct {
    int a;
    int b;
};

// Assuming default threshold is 20
struct LargeStruct { // EMB-ISSUE: too_many_fields_in_structure
    int f1;
    int f2;
    int f3;
    int f4;
    int f5;
    int f6;
    int f7;
    int f8;
    int f9;
    int f10;
    int f11;
    int f12;
    int f13;
    int f14;
    int f15;
    int f16;
    int f17;
    int f18;
    int f19;
    int f20;
    int f21; // 21st field triggers the violation
};

class CompliantClass {
    int data[100]; // Arrays count as 1 field
public:
    void method1(); // Methods are not counted
};
