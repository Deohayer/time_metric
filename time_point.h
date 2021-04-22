#ifndef DEOHAYER_TIME_POINT
#define DEOHAYER_TIME_POINT

#include <chrono>

class time_point
{
private:
    using time_point_t = std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds>;

    time_point_t _point;

    explicit time_point(const time_point_t& p)
        : _point(p)
    {
    }

public:
    time_point() = default;

    time_point(const time_point& other) = default;

    time_point(time_point&& other) = default;

    ~time_point() = default;

    time_point& operator=(const time_point& other) = default;

    time_point& operator=(time_point&& other) = default;

    unsigned long long int operator-(const time_point& latter) const
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(this->_point - latter._point).count();
    }

    static time_point current_point()
    {
        return time_point(std::chrono::high_resolution_clock::now());
    }
};

#endif
