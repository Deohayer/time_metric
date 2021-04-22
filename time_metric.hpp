#ifndef DEOHAYER_TIME_METRIC
#define DEOHAYER_TIME_METRIC

#include "time_point.hpp"

template <typename Func>
decltype(auto) measure_execution_time(Func f)
{
	auto t1 = time_point::current_point();
	f();
	auto t2 = time_point::current_point();
	return t2 - t1;
}

#endif