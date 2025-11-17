#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "RPN.hpp"

// Test counter
static int testsPassed = 0;
static int testsFailed = 0;

// Helper function to run a test and check result
void runTest(const std::string& testName, const std::string& input, const std::string& expected) {
    std::cout << "Test: " << testName << " [" << input << "]" << std::endl;
    
    // Redirect stdout to capture output
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    
    bool exceptionThrown = false;
    std::string exceptionMsg;
    
    try {
        RPN rpn(input);
    } catch (std::exception& e) {
        exceptionThrown = true;
        exceptionMsg = e.what();
    }
    
    // Restore stdout
    std::cout.rdbuf(oldCout);
    
    std::string output = buffer.str();
    
    // Debug output
    std::cout << "  Expected: \"" << expected << "\"" << std::endl;
    std::cout << "  Got:      \"" << output << "\"" << std::endl;
    
    if (expected == "ERROR") {
        if (exceptionThrown) {
            std::cout << "  ✓ PASS (error correctly thrown: " << exceptionMsg << ")" << std::endl;
            testsPassed++;
        } else {
            std::cout << "  ✗ FAIL (expected error but got: " << output << ")" << std::endl;
            testsFailed++;
        }
    } else {
        if (exceptionThrown) {
            std::cout << "  ✗ FAIL (unexpected exception: " << exceptionMsg << ")" << std::endl;
            testsFailed++;
        } else if (output == expected) {
            std::cout << "  ✓ PASS" << std::endl;
            testsPassed++;
        } else {
            std::cout << "  ✗ FAIL" << std::endl;
            testsFailed++;
        }
    }
    std::cout << std::endl;
}

void testBasicOperations() {
    std::cout << "=== Testing Basic Operations ===" << std::endl;
    
    // Addition
    runTest("Addition 1+2", "1 2 +", "3\n");
    runTest("Addition 5+3", "5 3 +", "8\n");
    
    // Subtraction
    runTest("Subtraction 5-3", "5 3 -", "2\n");
    runTest("Subtraction 3-5", "3 5 -", "-2\n");
    
    // Multiplication
    runTest("Multiplication 4*5", "4 5 *", "20\n");
    runTest("Multiplication 7*7", "7 7 *", "49\n");
    
    // Division
    runTest("Division 8/4", "8 4 /", "2\n");
    runTest("Division 9/3", "9 3 /", "3\n");
}

void testComplexExpressions() {
    std::cout << "=== Testing Complex Expressions ===" << std::endl;
    
    // Subject examples
    runTest("Subject example 1", "8 9 * 9 - 9 - 9 - 4 - 1 +", "42\n");
    runTest("Subject example 2", "7 7 * 7 -", "42\n");
    runTest("Subject example 3", "1 2 * 2 / 2 * 2 4 - +", "0\n");
    
    // Multiple operations
    runTest("Complex 1", "1 2 + 3 +", "6\n");
    runTest("Complex 2", "1 2 3 + +", "6\n");
    runTest("Complex 3", "5 1 2 + 4 * + 3 -", "14\n");
}

void testEdgeCases() {
    std::cout << "=== Testing Edge Cases ===" << std::endl;
    
    // Zero operations
    runTest("Zero addition", "0 0 +", "0\n");
    runTest("Zero subtraction", "5 0 -", "5\n");
    runTest("Zero multiplication", "5 0 *", "0\n");
    
    // Negative results
    runTest("Negative result 1", "1 9 -", "-8\n");
    runTest("Negative result 2", "0 5 -", "-5\n");
    
    // Large results from small inputs
    runTest("Large result 1", "9 9 +", "18\n");
    runTest("Large result 2", "9 9 *", "81\n");
    runTest("Large result 3", "9 9 * 9 +", "90\n");
}

void testDivisionEdgeCases() {
    std::cout << "=== Testing Division Edge Cases ===" << std::endl;
    
    // Integer division
    runTest("Integer division 7/2", "7 2 /", "3\n");
    runTest("Integer division 5/2", "5 2 /", "2\n");
    runTest("Integer division 1/2", "1 2 /", "0\n");
}

void testErrorCases() {
    std::cout << "=== Testing Error Cases ===" << std::endl;
    
    // Empty input
    runTest("Empty input", "", "ERROR");
    
    // Single number (no operation)
    runTest("Single number", "5", "ERROR");
    
    // Single operator
    runTest("Single operator", "+", "ERROR");
    
    // Insufficient operands
    runTest("Insufficient operands 1", "1 +", "ERROR");
    runTest("Insufficient operands 2", "1 2 + +", "ERROR");
    
    // Too many operands
    runTest("Too many operands", "1 2 3 +", "ERROR");
    
    // Division by zero
    runTest("Division by zero", "5 0 /", "ERROR");
    
    // Invalid characters
    runTest("Invalid character", "1 2 a +", "ERROR");
    
    // Numbers >= 10 (depends on implementation)
    runTest("Multi-digit number", "10 5 +", "ERROR");
    
    // Brackets (not supported)
    runTest("Brackets", "(1 + 1)", "ERROR");
    
    // Decimal numbers (not supported)
    runTest("Decimal number", "1.5 2 +", "ERROR");
    
    // Invalid operator
    runTest("Invalid operator", "1 2 %", "ERROR");
}

void testWhitespaceHandling() {
    std::cout << "=== Testing Whitespace Handling ===" << std::endl;
    
    // Multiple spaces
    runTest("Multiple spaces 1", "1  2  +", "3\n");
    runTest("Multiple spaces 2", "1   2   +", "3\n");
    
    // Leading/trailing spaces
    runTest("Leading space", " 1 2 +", "3\n");
    runTest("Trailing space", "1 2 + ", "3\n");
    runTest("Both spaces", " 1 2 + ", "3\n");
}

void testOperatorOrder() {
    std::cout << "=== Testing RPN Operator Order ===" << std::endl;
    
    // RPN doesn't have precedence, but order matters
    runTest("Order 1", "2 3 + 4 *", "20\n");  // (2+3)*4
    runTest("Order 2", "2 3 4 * +", "14\n");  // 2+(3*4)
    runTest("Order 3", "8 4 / 2 -", "0\n");   // (8/4)-2
    runTest("Order 4", "8 4 2 - /", "4\n");   // 8/(4-2)
}

void testBoundaryValues() {
    std::cout << "=== Testing Boundary Values ===" << std::endl;
    
    // Single digits 0-9
    runTest("Min digit", "0 1 +", "1\n");
    runTest("Max digit", "9 1 -", "8\n");
    runTest("Both max", "9 9 +", "18\n");
    
    // Chain operations
    runTest("Long chain", "1 1 + 1 + 1 + 1 +", "5\n");
}

int main1() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║   RPN Calculator Unit Tests (C++98)   ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    std::cout << "\n";
    
    testBasicOperations();
    testComplexExpressions();
    testEdgeCases();
    testDivisionEdgeCases();
    testErrorCases();
    testWhitespaceHandling();
    testOperatorOrder();
    testBoundaryValues();
    
    std::cout << "╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║           TEST SUMMARY                 ║" << std::endl;
    std::cout << "╠════════════════════════════════════════╣" << std::endl;
    std::cout << "║  Passed: " << testsPassed << std::endl;
    std::cout << "║  Failed: " << testsFailed << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    
    if (testsFailed == 0) {
        std::cout << "\n✓ ALL TESTS PASSED!\n" << std::endl;
        return 0;
    } else {
        std::cout << "\n✗ SOME TESTS FAILED!\n" << std::endl;
        return 1;
    }
}