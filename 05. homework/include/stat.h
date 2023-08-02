#pragma once 

class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next);
	virtual double eval();
	virtual const char * name();
};