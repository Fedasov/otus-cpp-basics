// Последовательный контейнер 
#pragma once
#include <iostream>
#include <string>
#include <cstdarg>

template<typename T>
class MyContainer {
public:
    MyContainer() : m_data{nullptr}, m_size(0), capacity(1) {}

    MyContainer push_back(T num) {
        if (capacity == m_size) {
            capacity = (int)(capacity * kaf_capacity) + 1;
        }
		T* new_memory = new T[capacity];
		for (size_t i = 0 ; i < m_size; i++) {
			new_memory[i] = m_data[i];
		}
        new_memory[m_size] = num;
		delete[] m_data;
		m_data = new_memory;
		m_size = m_size + 1;
		return *this;
    }


    MyContainer erase(int n_index, ...) {                 //передаем список значений. В main пользователь может вызвать любой набор цифр
        va_list args;
        va_start(args, n_index);
        int index = n_index;
        T *new_memory = new T[capacity];
        int k = 0;
        for (int i = 0, j = 0; i < m_size; i++, j++) {
            if (i == index-1) {
                k++;
                index = va_arg(args, int);
                j--;
                continue;
            }
            new_memory[j] = m_data[i];
        }
        delete[] m_data;
        for (int j = 0; j < m_size - k; j++) {
            m_data[j] = new_memory[j];
        }
        m_size = m_size - k;
        return *this;
    }

    MyContainer insert(int index, T num) {
        if (capacity == m_size) {
            capacity = (int)(capacity * kaf_capacity) + 1;
        }
		T* new_memory = new T[capacity];
		for (size_t i = 0, j = 0; i < m_size; i++, j++) {
            if (j == index) {
                new_memory[j] = num;
                i--;
                continue;
            }
			new_memory[j] = m_data[i];
		}
        if (index == m_size) {
            new_memory[index] = num;
        }
		// delete[] m_data;
		m_data = new_memory;
		m_size = m_size + 1;
		return *this;
    }

    int &operator[] (int index) {
        return m_data[index];
    } 

    size_t size() {
        return m_size;
    }
    
private:
    int capacity; 
    double kaf_capacity = 1.5;
    T *m_data;
    size_t m_size;
};





// class DynamicString {
// public:
// 	DynamicString() : m_data{nullptr}, m_size{0} {}

// 	explicit DynamicString(const char *str) : DynamicString{} {
// 		if (str == nullptr)
// 			return;
// 		size_t length = str.length();
// 		if (!length)
// 			return;
// 		m_data = new char[length + 1];

// 		for (size_t i = 0; i < length; ++i) {
// 			m_data[i] = str[i];
// 		}
// 		m_data[length] = '\0';
// 		m_size = length;
// 	}

// 	DynamicString(const DynamicString &other) : DynamicString{other.data()} {}

// 	~DynamicString() {
// 		delete[] m_data;
// 	}

// 	size_t size() const { return m_size; }
// 	char *data() const { return m_data; }

// 	DynamicString &operator+=(const char *str) {
// 		if (str == nullptr)
// 			return *this;

// 		size_t length = std::strlen(str);
// 		if (!length)
// 			return *this;

// 		char *new_memory = new char[length + m_size + 1];

// 		for (size_t i = 0; i < m_size; ++i) {
// 			new_memory[i] = m_data[i];
// 		}

// 		for (size_t i = 0; i < length; ++i) {
// 			new_memory[m_size + i] = str[i];
// 		}

// 		new_memory[m_size + length] = '\0';

// 		delete[] m_data;

// 		m_data = new_memory;
// 		m_size = m_size + length;

// 		return *this;
// 	}

// 	DynamicString &operator+=(const DynamicString &str) {
// 		return *this += str.data();
// 	}

// private:
// 	char *m_data;
// 	size_t m_size;
// };

// void MyContainter::push_back(T value) {
//     T* new_region = new T[m_size + 1]; // новая область памяти
//     for (size_t i = 0; i < m_size; ++i) {
//         new_region[i] = m_region[i]; // копирование элементов
//     }
//     new_region[m_size] = value; // добавление нового элемента
//     delete [] m_region; // удаление старой области
//     m_region = new_region; // сохранение новой в мембер
//     m_size += 1; // обновление информации о размере
// }