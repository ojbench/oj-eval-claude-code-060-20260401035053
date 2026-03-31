#include <vector>

template <typename T>
class Expectation {
private:
    T value;
    bool result;
    bool negate;

public:
    Expectation(const T& val) : value(val), result(true), negate(false) {}

    // Comparison operators
    // Only <, ==, and = are guaranteed to be overloaded
    Expectation& ge(const T& other) {
        if (result) {
            bool condition = !(value < other); // a >= b is !(a < b)
            result = result && (negate ? !condition : condition);
        }
        return *this;
    }

    Expectation& gt(const T& other) {
        if (result) {
            bool condition = (other < value); // a > b is b < a
            result = result && (negate ? !condition : condition);
        }
        return *this;
    }

    Expectation& le(const T& other) {
        if (result) {
            bool condition = (value < other) || (value == other); // a <= b is (a < b) || (a == b)
            result = result && (negate ? !condition : condition);
        }
        return *this;
    }

    Expectation& lt(const T& other) {
        if (result) {
            bool condition = (value < other);
            result = result && (negate ? !condition : condition);
        }
        return *this;
    }

    // Equality checks
    Expectation& toBe(const T& other) {
        if (result) {
            bool condition = (value == other);
            result = result && (negate ? !condition : condition);
        }
        return *this;
    }

    Expectation& toBeOneOf(const std::vector<T>& vec) {
        if (result) {
            bool found = false;
            for (const T& item : vec) {
                if (value == item) {
                    found = true;
                    break;
                }
            }
            result = result && (negate ? !found : found);
        }
        return *this;
    }

    // Negation
    Expectation& Not() {
        negate = !negate;
        return *this;
    }

    // Boolean conversion
    operator bool() const {
        return result;
    }
};

template <typename T>
Expectation<T> expect(const T& value) {
    return Expectation<T>(value);
}
