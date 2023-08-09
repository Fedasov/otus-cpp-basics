// Двунаправленный список
#pragma once
#include <iostream>
#include <string>
#include <cstdarg>

template<typename T>
class MyList_bid {
public:
    MyList_bid() : first_v(nullptr), last_v(nullptr), m_last(nullptr), m_size(0), data(NULL){}

    struct Node {
        Node() : next(nullptr), prev(nullptr) {}
        Node* next; // указатель на следующий элемент Node
        Node* prev; // указатель на предыдущий элемент Node
        T data; // пользовательские данные (хранимый объект)
    };

    void push_back(T value) {
        Node* new_node = new Node{}; // создание нового узла
        new_node->prev = m_last; // предыдущим элементом станет последний
        new_node->next = nullptr; // следующего элемента пока нет
        new_node->data = value; // сохраняем пользовательские данные
        this->last_v = new_node;
        if (m_last == nullptr) {
            this->first_v = new_node;
        } else {
            m_last->next = new_node;
        }

        m_last = new_node; // обновляем указатель на последний
        m_size++; // обновляем размер
    }

    void erase(int n_index, ...) {
        va_list args;
        va_start(args, n_index);
        int index = n_index;

        Node* my_node = this->first_v;
        Node* help_ptr;
        int k = 0;
        for (int i=0; i < this->m_size; i++) {
            if (i == index-1) {
                k++;
                if(my_node == this->first_v) {
                    this->first_v = my_node->next;
                    help_ptr = my_node->next;
                    help_ptr->prev = nullptr;
                } else if (my_node == this->last_v) {
                    this->last_v = my_node->prev;
                } else {
                    help_ptr = my_node->prev;
                    help_ptr->next = my_node->next;
                    my_node->next->prev = help_ptr; 
                } 
                delete my_node;
                my_node = help_ptr;
                index = va_arg(args, int);
                if(my_node == this->first_v) {
                    continue;
                }
            }
            my_node=my_node->next;
        } 
        va_end(args);
        m_size = m_size - k;
    }

    void insert(int index, T num) {
        Node* my_node = this->first_v;
        if (index == m_size) {
            push_back(num);
        } else {
            for (int j = 0; j < this->m_size; j++) {
                if (j == index) {
                    Node* help_ptr = new Node{};
                    help_ptr->prev = my_node->prev;
                    help_ptr->data = num;
                    help_ptr->next = my_node;
                    if (my_node == this->first_v) {
                        my_node->prev = help_ptr;
                        this->first_v = help_ptr;
                        break;
                    }
                    my_node->prev->next = help_ptr;
                    my_node->prev = help_ptr;
                    break;
                }
                my_node=my_node->next;
            } 
        }
        m_size++;
    }

    // Node* begin() {
    //     auto& s = this->first_v;
    //     return s;
    // }

    // // int& operator*(Node& my_node) {
    // //     return my_node->data;
    // // }
    // int& operator*(MyList_bid::Node *iter)
    // {
    //     std::cout <<"razumenovanie"<< std::endl;
    //     int c = 39;
    //     int& k = c;
    //     return k;
    // }

    T& operator[](int count)
    {
        Node* my_node = this->first_v;
        for (int i=0; i < count; i++)
            my_node=my_node->next;
        return my_node->data;
    }

    size_t size() {
        return m_size;
    }
private:
    Node* last_v;
    Node* first_v;
    size_t m_size;
    Node* m_last;
    T data;
};