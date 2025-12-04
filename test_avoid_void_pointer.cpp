// Test for avoid_void_pointer
// 'void *' should not be used in typedefs, member variables, function parameters or return type

// EMB-ISSUE: avoid_void_pointer
typedef void* MyVoidHandle; 

// EMB-ISSUE: avoid_void_pointer
typedef const void* MyConstVoidHandle;

struct DataHolder {
    int id;
    // EMB-ISSUE: avoid_void_pointer
    void* rawData;
};

// EMB-ISSUE: avoid_void_pointer
void* getRawData() {
    return nullptr;
}

// EMB-ISSUE: avoid_void_pointer
void setRawData(void* data) {
}

// Compliant examples
typedef int* IntPtr;
struct SafeHolder {
    int* safeData;
};
void* internal_handler(); // Ignore system headers logic usually handled in visitor, strict check here catches it.
