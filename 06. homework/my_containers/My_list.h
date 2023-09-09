//
// Created by raulett on 08.07.2023.
//

#ifndef HW06_CONTAINERS_MY_LIST_H
#define HW06_CONTAINERS_MY_LIST_H
#include <cstdlib>
#include <iostream>

template <typename T>
class My_list {
public:

    My_list(){
        size = 0;
        first_el_ptr = nullptr;
        last_el_ptr = nullptr;
    }

    //Как можно сделать делегирование между константным и неконстантным копирующим конструктором?
    // чтобы не дублировать код
    My_list(const My_list &rhs):My_list(){
        auto it = rhs.begin();
        for(it = rhs.begin(); it.has_next(); it.next()){
            push_back(it.get());
        }
        push_back(it.get());
    }

    My_list(My_list &rhs):My_list(){
        auto it = rhs.begin();
        for(it = rhs.begin(); it.has_next(); it.next()){
            push_back(it.get());
        }
        push_back(it.get());
    }

    explicit My_list(T element) {
        first_el_ptr = new list_el{element};
        last_el_ptr = first_el_ptr;
        size++;
    }

    template <typename ...Tail>
    explicit My_list(T head, Tail... tail){
        first_el_ptr = new list_el{head};
        last_el_ptr = first_el_ptr;
        size++;
        push_back(tail...);
    }



    My_list(My_list&& rhs) noexcept {
        size = rhs.size;
        first_el_ptr = rhs.first_el_ptr;
        rhs.first_el_ptr = nullptr;
        last_el_ptr = rhs.last_el_ptr;
        rhs.last_el_ptr = nullptr;
        rhs.size = 0;
    }

    My_list& operator=(My_list rhs){
        if (this != &rhs){
            list_el* current_rhs_element = rhs.first_el_ptr;
            first_el_ptr = new list_el{rhs.first_el_ptr->el_data};
            size = 1;
            do{
                current_rhs_element = current_rhs_element->next_el;
                push_back(current_rhs_element->el_data);
            } while (current_rhs_element->next_el != nullptr);
        }
    }

    T operator[](size_t i){
        if (i < size){
            list_el* current_el = first_el_ptr;
            size_t j = 0;
            while (j < i){
                current_el = current_el->next_el;
                j++;
            }
            return current_el->el_data;
        } else {
            throw std::out_of_range("index is out of range");
        }
    }

    struct list_el{
        explicit list_el(T new_el){
            el_data = new_el;
        }
        ~list_el()= default;
        T el_data;
        list_el* next_el = nullptr;
    };


    struct iterator{
    public:
        explicit iterator(struct list_el* list_el_ptr){
            current_element = list_el_ptr;
        }
        void next(){
            if (current_element != NULL) {
                current_element = current_element->next_el;
            }
        }

        T get(){
            return current_element->el_data;
        }

        T operator*(){
            return current_element->el_data;
        }

        bool has_next(){
            if (current_element->next_el == nullptr){
                return false;
            } else{
                return true;
            }
        }

    private:
        struct list_el* current_element;
    };

    iterator begin(){
        if (size > 0){
            iterator it{first_el_ptr};
            return it;
        } else{
            throw std::out_of_range("there is no elements in container");
        }
    }

    list_el* end(){
        if (size>0){
            return nullptr;
        } else{
            throw std::out_of_range("there is no elements in container");
        }
    }

    size_t arr_size(){
        return size;
    }

    void push_back(T el){
        list_el* temp_el = new list_el(el);
        if (size == 0){
            first_el_ptr = temp_el;
            last_el_ptr = temp_el;
        } else {
            last_el_ptr->next_el = temp_el;
            last_el_ptr = temp_el;
        }
        size++;
    }

    template <typename ...Tail>
    void push_back(T el, Tail... tail){
        push_back(el);
        push_back(tail...);
    }

    void insert(T element, size_t index){
        list_el* new_el = new list_el(element);
        if (index == 0){
            new_el->next_el = first_el_ptr;
            first_el_ptr = new_el;
        } else {
            list_el* temp = first_el_ptr;
            for (size_t i = 1; i<index; i++) {
                temp = temp->next_el;
            }
            new_el->next_el = temp->next_el;
            temp->next_el = new_el;
        }
        size++;
    }

    bool erase(size_t index){
        if (index >= size){
            return false;
        }
        list_el* temp = first_el_ptr;
        list_el* next_temp_ptr = first_el_ptr->next_el;
        if (index == 0){
            first_el_ptr = next_temp_ptr;
            delete temp;
        } else {
            for (size_t i = 1; i < index; i++) {
                next_temp_ptr = next_temp_ptr->next_el;
                temp = temp->next_el;
            }
            temp->next_el = next_temp_ptr->next_el;
            delete[] next_temp_ptr;
        }
        size--;
        return true;
    }

    bool is_empty(){
        if (size == 0){
            return true;
        } else{
            return false;
        }
    }

    ~My_list(){
        if (first_el_ptr != nullptr) {
            list_el* temp = first_el_ptr;
            list_el* next_temp_ptr = first_el_ptr->next_el;
            while (temp != nullptr) {
                delete temp;
                temp = next_temp_ptr;
                if (temp != nullptr){
                    next_temp_ptr = temp->next_el;
                }
            }
        }
        size = 0;
        first_el_ptr = nullptr;
        last_el_ptr = nullptr;
    }


private:
    size_t size = 0;
    list_el* first_el_ptr = nullptr;
    list_el* last_el_ptr = nullptr;
};


#endif //HW06_CONTAINERS_MY_LIST_H
