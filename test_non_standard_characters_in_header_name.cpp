// Test file for non_standard_characters_in_header_name (RSPEC-955)

// Compliant
#include <iostream>
#include "my_header.h"
#include "path/to/header.h"

// Non-Compliant
// EMB-ISSUE: non_standard_characters_in_header_name
#include "path\to\header.h"

// EMB-ISSUE: non_standard_characters_in_header_name
#include "header'name.h"

// EMB-ISSUE: non_standard_characters_in_header_name
#include "header//comment.h"

// EMB-ISSUE: non_standard_characters_in_header_name
#include "header/*comment.h"

void foo() {
    // Code body not relevant for this PP check
}
