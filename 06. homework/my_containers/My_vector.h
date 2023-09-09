//
// Created by raulett on 06.07.2023.
//

#ifndef HW06_CONTAINERS_MY_VECTOR_H
#define HW06_CONTAINERS_MY_VECTOR_H

#include <cstdlib>
#include <iostream>

template <typename T>
class My_vector {
public:

    My_vector(){
        this->arr_ptr = new T[10];
        this->reserved_size = 10;
    }
    explicit My_vector(T element) {
        arr_ptr = new T[10];
        arr_ptr[size] = element;
        reserved_size = 10;
        size++;
    }

    template <typename ...Tail>
    explicit My_vector(T head, Tail... tail){
        arr_ptr = new T[10];
        arr_ptr[size] = head;
        reserved_size = 10;
        size++;
        push_back(tail...);
    }

    My_vector(const My_vector& rhs):My_vector(rhs){}

    My_vector(My_vector& rhs):My_vector(){
        for(size_t i = 0; i<rhs.arr_size(); i++){
            push_back(rhs[i]);
        }
    }

    My_vector(My_vector&& rhs) noexcept {
        arr_ptr = rhs.arr_ptr;
        rhs.arr_ptr = nullptr;
        size = rhs.size;
        reserved_size = rhs.reserved_size;
        rhs.size = 0;
        rhs.reserved_size = 0;
    }

    My_vector& operator=(My_vector rhs){
        if (this != &rhs){
            arr_ptr = new T[rhs.reserved_size];
            size = rhs.size;
            reserved_size = rhs.reserved_size;
            for (int i=0; i < size; i++){
                arr_ptr[i] = rhs.arr_ptr[i];
            }
        }
    }

    T operator[](size_t i){
        if (i < size){
            return arr_ptr[i];
        } else{
            throw std::out_of_range("index is out of array range");
        }
    }


    struct iterator{
    public:
        explicit iterator(T* curr_el):current_element(curr_el){}

        void next(){
            current_element = current_element+1;
        }

        T get(){
            return *current_element;
        }

        T operator*(){
            return *current_element;
        }
        bool operator<(iterator rhs){
            return current_element<rhs.current_element;
        }
    private:
        T* current_element;
    };

    iterator begin(){
        if (size>0){
            iterator it{&arr_ptr[0]};
            return it;
        } else{
            throw std::out_of_range("there is no elements in container");
        }
    }

    iterator end(){
        if (size>0){
            iterator it{&arr_ptr[size]};
            return it;
        } else{
            throw std::out_of_range("there is no elements in container");
        }
    }

    size_t arr_size(){
        return size;
    }

    void push_back(T el){
        if (size == reserved_size){
            reserve_size(reserved_size + reserved_size/2);
        }
        arr_ptr[size] = el;
        size++;
    }

    template <typename ...Tail>
    void push_back(T el, Tail... tail){
        push_back(el);
        push_back(tail...);
    }
    void insert(T element, size_t index){
        if (index > size){
            return;
        }
        if (index == size){
            push_back(element);
            return;
        }
        if (((size+1+size/2) > reserved_size) || (size == reserved_size)) {
            T *temp = new T[(size + 1) + size / 2];
            for (size_t i = 0; i < index; i++) {
                temp[i] = arr_ptr[i];
            }
            temp[index] = element;

            for (int i = 1; index + i < size + 1; i++){
                temp[index + i] = arr_ptr[index + i - 1];
            }
            reserved_size = (size + 1) + size / 2;
            delete[] arr_ptr;
            arr_ptr = temp;
        } else {
            for (size_t i = size - 1; i >= index; i--){
                arr_ptr[i+1] = arr_ptr[i];
            }
            arr_ptr[index] = element;
        }
        size++;
   }

    bool erase(size_t index){
        /*Удаляет элемент по индексу, на вход принимает индекс удаляемого элемента. Возвращает bool, true если успешно*/
        if (index >= size){
            return false;
        }
        for(size_t i = index; i < size-1; i++){
            arr_ptr[i] = arr_ptr[i+1];
        }
        size--;
        return true;
    }

    void reserve_size(size_t new_size){
        if (new_size > size) {
            T *temp = new T[new_size];
            reserved_size = new_size;
            for (size_t i = 0; i < size; i++) {
                temp[i] = arr_ptr[i];
            }
            delete[] arr_ptr;
            arr_ptr = temp;
        } else {
            return;
        }
    }

    void crop_reserved_size(){
        /*Подрезает зарезервированную память до размера хранимых данных, для экономии памяти.*/
        reserve_size(size);
    }

    bool is_empty(){
        if (size == 0){
            return true;
        } else{
            return false;
        }
    }

    ~My_vector(){
        delete[] arr_ptr;
    }
private:
    size_t size = 0;
    size_t reserved_size = 0;
    T* arr_ptr = nullptr;

};


#endif //HW06_CONTAINERS_MY_VECTOR_H
