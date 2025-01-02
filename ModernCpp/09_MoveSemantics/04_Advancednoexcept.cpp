#include <string>
#include <utility>

template <typename T>
class Object {
    int n;
    std::string s;
    T t;

public:
    // Default constructor
    Object() = default;

    // Copy constructor
    Object(const Object& other)
        : n(other.n), s(other.s), t(other.t) {}

    // Move constructor
    // Type T may have exception
    // 1) noexcept( expression ) => if expression has excpetion or not
    // 2) f() noexcept(true) => function f() has no exception
    Object(Object&& other) noexcept(noexcept(t(std::move(other.t))))
        : n(other.n),
          s(std::move(other.s)),
          t(std::move(other.t)) {}

    // alternative
    // Object(Object&& other) noexcept( std::is_nothrow_move_constructible_v<T> )

};

int main() {
}
