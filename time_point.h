#ifndef DEOHAYER_TIME_POINT
#define DEOHAYER_TIME_POINT

#include <chrono>

class time_point
{
private:
    using time_point_t = std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds>;

    time_point_t _point;

    explicit time_point::time_point(const time_point_t& p)
        : _point(p)
    {
    }

public:
    time_point::time_point() = default;

    time_point::time_point(const time_point& other) = default;

    time_point::time_point(time_point&& other) = default;

    time_point::~time_point() = default;

    time_point& time_point::operator=(const time_point& other) = default;

    time_point& time_point::operator=(time_point&& other) = default;

    unsigned long long int time_point::time_span(const time_point& former, const time_point& latter)
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(latter._point - former._point).count();
    }

    time_point time_point::make_point()
    {
        return time_point(std::chrono::high_resolution_clock::now());
    }
};

#endif
