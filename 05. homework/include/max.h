#pragma once
#include "stat.h"

class Max : public IStatistics {
public:
	Max() : m_max{-DBL_MAX} {}

	void update(double next);
	double eval() ;
	const char * name();
private:
	double m_max;
};