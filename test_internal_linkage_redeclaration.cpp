// Test file for internal_linkage_redeclaration
// If a function has internal linkage then all re-declarations shall include the static storage class specifier.

// Compliant: explicit static on both declaration and definition
static void compliant_func();
static void compliant_func() {}

// Non-Compliant: Definition missing static
static void non_compliant_def();
// EMB-ISSUE: internal_linkage_redeclaration
void non_compliant_def() {}

// Non-Compliant: Re-declaration missing static
static void non_compliant_redecl();
// EMB-ISSUE: internal_linkage_redeclaration
void non_compliant_redecl(); 
static void non_compliant_redecl() {} // Definition ok here

namespace {
    // Anonymous namespaces imply internal linkage, but the rule specifically
    // targets functions where 'static' was used initially.
    void anon_ns_func() {}
}

// External linkage (default) - ignored
void external_func();
void external_func() {}
