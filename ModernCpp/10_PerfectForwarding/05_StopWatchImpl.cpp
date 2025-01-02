#include <chrono>
#include <iostream>
#include <thread>
#include <utility>
#include <functional>

// StopWatch class to measure execution time
class StopWatch {
public:
    // Constructor to start the timer
    StopWatch() : start(std::chrono::system_clock::now()) {}
    // Destructor to stop the timer and print elapsed time
    ~StopWatch() {
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << elapsed.count() << " seconds..." << std::endl;
    }

private:
    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point end;
};

// Function to simulate a delay
void foo(int n) {
    std::this_thread::sleep_for(std::chrono::seconds(n));
}

// Template function to measure execution time of a function
template <class F, class... T>
decltype(auto) chronometry(F&& f, T&&... arg) {
    StopWatch sw; // Create a StopWatch object to measure time
    return std::invoke(std::forward<F>(f), std::forward<T>(arg)...); // Forward arguments to the function
}

int main() {
    chronometry(foo, 2); // Measure execution time of foo with argument 2
}
