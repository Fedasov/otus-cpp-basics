#include <limits>
//#include "stat.h"
#include "max.h"

using namespace std;

void Max::update(double next) {
	if (next > m_max) {
			this->m_max = next;
	}
}

double Max::eval() const {
		return this->m_max;
	}

const char* Max::name() const {
		return "max";
	}

// class Max : public IStatistics {
// public:
// 	Max() : m_max{-DBL_MAX} {}

// 	void update(double next) override {
// 		if (next > m_max) {
// 			m_max = next;
// 		}
// 	}

// 	double eval() const {
// 		return m_max;
// 	}

// 	const char * name() const {
// 		return "max";
// 	}

// private:
// 	double m_max;
// };