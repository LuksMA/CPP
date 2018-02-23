### Basic Assertions 

These assertions do basic true/false condition testing.

| **Fatal assertion** | **Nonfatal assertion** | **Verifies** |
|:--------------------|:-----------------------|:-------------|
| `ASSERT_TRUE(`_condition_`)`;  | `EXPECT_TRUE(`_condition_`)`;   | _condition_ is true |
| `ASSERT_FALSE(`_condition_`)`; | `EXPECT_FALSE(`_condition_`)`;  | _condition_ is false |

Remember, when they fail, `ASSERT_*` yields a fatal failure and
returns from the current function, while `EXPECT_*` yields a nonfatal
failure, allowing the function to continue running. In either case, an
assertion failure means its containing test fails.

### Binary Comparison 

This section describes assertions that compare two values.

| **Fatal assertion** | **Nonfatal assertion** | **Verifies** |
|:--------------------|:-----------------------|:-------------|
|`ASSERT_EQ(`_val1_`, `_val2_`);`|`EXPECT_EQ(`_val1_`, `_val2_`);`| _val1_ `==` _val2_ |
|`ASSERT_NE(`_val1_`, `_val2_`);`|`EXPECT_NE(`_val1_`, `_val2_`);`| _val1_ `!=` _val2_ |
|`ASSERT_LT(`_val1_`, `_val2_`);`|`EXPECT_LT(`_val1_`, `_val2_`);`| _val1_ `<` _val2_ |
|`ASSERT_LE(`_val1_`, `_val2_`);`|`EXPECT_LE(`_val1_`, `_val2_`);`| _val1_ `<=` _val2_ |
|`ASSERT_GT(`_val1_`, `_val2_`);`|`EXPECT_GT(`_val1_`, `_val2_`);`| _val1_ `>` _val2_ |
|`ASSERT_GE(`_val1_`, `_val2_`);`|`EXPECT_GE(`_val1_`, `_val2_`);`| _val1_ `>=` _val2_ |

In the event of a failure, Google Test prints both _val1_ and _val2_.

`ASSERT_EQ()` does pointer equality on pointers. If used on two C strings, it
tests if they are in the same memory location, not if they have the same value.
Therefore, if you want to compare C strings (e.g. `const char*`) by value, use
`ASSERT_STREQ()` , which will be described later on. In particular, to assert
that a C string is `NULL`, use `ASSERT_STREQ(NULL, c_string)` . However, to
compare two `string` objects, you should use `ASSERT_EQ`.

Macros in this section work with both narrow and wide string objects (`string`
and `wstring`).

### String Comparison 

The assertions in this group compare two **C strings**. If you want to compare
two `string` objects, use `EXPECT_EQ`, `EXPECT_NE`, and etc instead.

| **Fatal assertion** | **Nonfatal assertion** | **Verifies** |
|:--------------------|:-----------------------|:-------------|
| `ASSERT_STREQ(`_str1_`, `_str2_`);`    | `EXPECT_STREQ(`_str1_`, `_str2_`);`     | the two C strings have the same content |
| `ASSERT_STRNE(`_str1_`, `_str2_`);`    | `EXPECT_STRNE(`_str1_`, `_str2_`);`     | the two C strings have different content |
| `ASSERT_STRCASEEQ(`_str1_`, `_str2_`);`| `EXPECT_STRCASEEQ(`_str1_`, `_str2_`);` | the two C strings have the same content, ignoring case |
| `ASSERT_STRCASENE(`_str1_`, `_str2_`);`| `EXPECT_STRCASENE(`_str1_`, `_str2_`);` | the two C strings have different content, ignoring case |

Note that "CASE" in an assertion name means that case is ignored.

`*STREQ*` and `*STRNE*` also accept wide C strings (`wchar_t*`). If a
comparison of two wide strings fails, their values will be printed as UTF-8
narrow strings.

A `NULL` pointer and an empty string are considered _different_.

# Simple Tests 

To create a test:
  1. Use the `TEST()` macro to define and name a test function, These are ordinary C++ functions that don't return a value.
  1. In this function, along with any valid C++ statements you want to include, use the various Google Test assertions to check values.
  1. The test's result is determined by the assertions; if any assertion in the test fails (either fatally or non-fatally), or if the test crashes, the entire test fails. Otherwise, it succeeds.

```
TEST(test_case_name, test_name) {
 ... test body ...
}
```


`TEST()` arguments go from general to specific. The _first_ argument is the
name of the test case, and the _second_ argument is the test's name within the
test case. Both names must be valid C++ identifiers, and they should not contain underscore (`_`). A test's _full name_ consists of its containing test case and its
individual name. Tests from different test cases can have the same individual
name.

### Examples:
* [Sample #1](../SampleCase1/) shows the basic steps of using Google Test to test C++ functions.
* Sample #2 shows a more complex unit test for a class with multiple member functions.
* Sample #3 uses a test fixture.
* Sample #4 is another basic example of using Google Test.
* Sample #5 teaches how to reuse a test fixture in multiple test cases by deriving sub-fixtures from it.
* Sample #6 demonstrates type-parameterized tests.
* Sample #7 teaches the basics of value-parameterized tests.
* Sample #8 shows using Combine() in value-parameterized tests.
* Sample #9 shows use of the listener API to modify Google Test's console output and the use of its reflection API to inspect test results.
* Sample #10 shows use of the listener API to implement a primitive memory leak checker.

### Reference:   
https://github.com/google/googletest   
https://www.ibm.com/developerworks/aix/library/au-googletestingframework.html  
https://github.com/google/googletest/blob/master/googletest/docs/Primer.md   
https://github.com/google/googletest/blob/master/googletest/docs/Samples.md   
