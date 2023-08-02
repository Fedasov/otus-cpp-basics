#pragma once
#include "stat.h"

class Min : public IStatistics {
public:
	Min();
	void update(double next);
	double eval();
	const char * name();

private:
	double m_min;
};