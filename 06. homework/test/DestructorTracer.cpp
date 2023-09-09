//
// Created by raulett on 28.07.2023.
//

#include <cstdio>
#include "DestructorTracer.h"

size_t DestructorTracer::constructor_count = 0;
size_t DestructorTracer::destructor_count = 0;
DestructorTracer::DestructorTracer() {
    constructor_count++;
}
DestructorTracer::~DestructorTracer() {
    destructor_count++;
}