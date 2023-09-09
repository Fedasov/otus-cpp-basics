//
// Created by raulett on 28.07.2023.
//

#ifndef HW06_CONTAINERS_DESTRUCTORTRACER_H
#define HW06_CONTAINERS_DESTRUCTORTRACER_H


#include <cstddef>

struct DestructorTracer {
    static size_t destructor_count;
    static size_t constructor_count;
    DestructorTracer();
//    DestructorTracer(const DestructorTracer&) = default;
//    DestructorTracer(DestructorTracer&&) = default;
    ~DestructorTracer();
};


#endif //HW06_CONTAINERS_DESTRUCTORTRACER_H
