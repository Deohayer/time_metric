#ifndef DEOHAYER_TIME_METRIC
#define DEOHAYER_TIME_METRIC

#include "time_point.h"

template <typename Func>
decltype(auto) measure_execution_time(Func f)
{
	auto t1 = mystl::time_point::make_point();
	f();
	auto t2 = mystl::time_point::make_point();
	return mystl::time_point::time_span(t1, t2);
}

#endif