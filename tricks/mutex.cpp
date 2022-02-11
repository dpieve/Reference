// If you want or not to use mutex
// You want to call a function that needs uses a mutex inside another function that uses a mutex
// Idea was shared by Chris

#include <mutex>
#include <thread>

class MutexLockPolicy {
    std::mutex mutex_;
    
public:
    std::unique_lock<std::mutex> make_guard() { return std::unique_lock<std::mutex>(mutex_); }
};

class NoopLockPolicy {
    struct NoopGuard {};
public:
    NoopGuard make_guard() { return NoopGuard{}; }
};

/// User code below
#include <vector>
#include <algorithm>

template <typename EltT, typename LockPolicy>
struct InnovativeContainer {
    void add(EltT const & e) {
        auto guard = lockPolicy_.make_guard();

        // whatever to add e to the data structure
        values_.push_back(e);
    }

    void erase(EltT const & e) {
        auto guard = lockPolicy_.make_guard();

        // whatever to erase e to the data structure
        auto iter = std::find(begin(values_), end(values_), e);
        if (iter != end(values_)) {
            values_.erase(iter);
        }
    }

    EltT const & back() {
        auto guard = lockPolicy_.make_guard();
        return values_.back();        
    }

private:
    LockPolicy lockPolicy_;
    std::vector<EltT> values_;
};


int single_threaded()
{
    InnovativeContainer<int, NoopLockPolicy> c;
    c.add(123);
    return c.back();
}

int multi_threaded() {
    InnovativeContainer<int, MutexLockPolicy> c;
    c.add(123);
    return c.back();    
}

int main() {
    single_threaded();
    multi_threaded();
}
