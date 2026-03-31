#include <iostream>
#include <string>
#include "src.hpp"

int main() {
    // Test 1: Basic range check with int
    int num = 200;
    if (expect(num).ge(114).lt(514).Not().toBe(321)) {
        std::cout << "Test 1 passed: " << num << " is in [114, 514) and != 321" << std::endl;
    } else {
        std::cout << "Test 1 failed" << std::endl;
    }

    // Test 2: Not in range
    int num2 = 600;
    if (!expect(num2).ge(114).lt(514)) {
        std::cout << "Test 2 passed: " << num2 << " is not in [114, 514)" << std::endl;
    } else {
        std::cout << "Test 2 failed" << std::endl;
    }

    // Test 3: toBe test
    int num3 = 100;
    if (expect(num3).toBe(100)) {
        std::cout << "Test 3 passed: " << num3 << " equals 100" << std::endl;
    } else {
        std::cout << "Test 3 failed" << std::endl;
    }

    // Test 4: Not toBe test
    int num4 = 100;
    if (expect(num4).Not().toBe(200)) {
        std::cout << "Test 4 passed: " << num4 << " != 200" << std::endl;
    } else {
        std::cout << "Test 4 failed" << std::endl;
    }

    // Test 5: Multiple Not().toBe() conditions
    int x = 3;
    if (expect(x).Not().toBe(1).toBe(2)) {
        std::cout << "Test 5 passed: " << x << " != 1 and != 2" << std::endl;
    } else {
        std::cout << "Test 5 failed" << std::endl;
    }

    // Test 6: toBeOneOf test
    std::vector<int> options = {1, 2, 3, 4, 5};
    int num5 = 3;
    if (expect(num5).toBeOneOf(options)) {
        std::cout << "Test 6 passed: " << num5 << " is in the vector" << std::endl;
    } else {
        std::cout << "Test 6 failed" << std::endl;
    }

    // Test 7: Not toBeOneOf test
    int num6 = 10;
    if (expect(num6).Not().toBeOneOf(options)) {
        std::cout << "Test 7 passed: " << num6 << " is not in the vector" << std::endl;
    } else {
        std::cout << "Test 7 failed" << std::endl;
    }

    // Test 8: String test
    std::string str = "hello";
    if (expect(str).toBe(std::string("hello"))) {
        std::cout << "Test 8 passed: string equals 'hello'" << std::endl;
    } else {
        std::cout << "Test 8 failed" << std::endl;
    }

    // Test 9: String comparison
    std::string str2 = "abc";
    if (expect(str2).lt(std::string("def")).gt(std::string("aaa"))) {
        std::cout << "Test 9 passed: 'abc' is between 'aaa' and 'def'" << std::endl;
    } else {
        std::cout << "Test 9 failed" << std::endl;
    }

    return 0;
}
