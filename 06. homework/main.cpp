#include <iostream>
#include "my_containers/My_vector.h"
#include "my_containers/My_list.h"

/*
1. создание объекта контейнера для хранения объектов типа int
2. добавление в контейнер десяти элементов (0, 1 … 9)
3. вывод содержимого контейнера на экран
        ожидаемый результат: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
4. вывод размера контейнера на экран
        ожидаемый результат: 10
5. удаление третьего (по счёту), пятого и седьмого элементов
6. вывод содержимого контейнера на экран
        ожидаемый результат: 0, 1, 3, 5, 7, 8, 9
7. добавление элемента 10 в начало контейнера
8. вывод содержимого контейнера на экран
        ожидаемый результат: 10, 0, 1, 3, 5, 7, 8, 9
9. добавление элемента 20 в середину контейнера
10. вывод содержимого контейнера на экран
        ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9
11. добавление элемента 30 в конец контейнера
12. вывод содержимого контейнера на экран
        ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30
*/



void demonstrate_my_vector(){
    My_vector my_vector = My_vector<int>();
    for(int i = 0; i < 10; i++){
        my_vector.push_back(i);
    }

    std::cout << "initial vector output: " << std::endl;
    for(size_t i = 0; i<my_vector.arr_size(); i++){
        std::cout << my_vector[i] << ",";
    }
    std::cout << std::endl;

    std::cout << "my vector size: " << std::endl;
    std::cout << std::to_string(my_vector.arr_size()) << std::endl;
    size_t el_to_erase[] = {3, 5, 7};
    size_t j = 0;
    for (size_t i : el_to_erase){
        my_vector.erase(i-j-1);
        j++;
    }
    std::cout << "vector after erase 3, 5, 7 elements: " << std::endl;
    for(size_t i = 0; i<my_vector.arr_size(); i++){
        std::cout << my_vector[i] << ",";
    }
    std::cout << std::endl;

    std::cout << "vector after add element 10 at index 0: " << std::endl;
    my_vector.insert(10, 0);
    for(size_t i = 0; i<my_vector.arr_size(); i++){
        std::cout << my_vector[i] << ",";
    }
    std::cout << std::endl;

    std::cout << "vector after add element 20 at middle: " << std::endl;
    my_vector.insert(20, my_vector.arr_size()/2);
    for(size_t i = 0; i<my_vector.arr_size(); i++){
        std::cout << my_vector[i] << ",";
    }
    std::cout << std::endl;

    std::cout << "push back element 30 at the end of vector " << std::endl;
    my_vector.push_back(30);
    for(size_t i = 0; i<my_vector.arr_size(); i++){
        std::cout << my_vector[i] << ",";
    }
    std::cout << std::endl;

    std::cout << "copy vector " << std::endl;

    My_vector my_vector_2 = My_vector<int>();
    std::cout << "new vector create:" << std::endl;
    for(int i = 0; i < 10; i++){
        my_vector_2.push_back(i);
    }
    for(int i = 0; i < 10; i++){
        std::cout << my_vector_2[i] << ",";
    }
    std::cout << std::endl;
    My_vector copy_vector{my_vector_2};
    std::cout << "copied vector" << std::endl;
    for(int i = 0; i < 10; i++){
        std::cout << copy_vector[i] << ",";
    }
    std::cout << std::endl;

}


void demonstrate_my_list(){
    My_list my_list = My_list<int>();
    for(int i = 0; i < 10; i++){
        my_list.push_back(i);
    }

    std::cout << "initial list output: " << std::endl;
    for(size_t i = 0; i<my_list.arr_size(); i++){
        std::cout << my_list[i] << ",";
    }
    std::cout << std::endl;

    std::cout << "my list size: " << std::endl;
    std::cout << std::to_string(my_list.arr_size()) << std::endl;
    size_t el_to_erase[] = {3, 5, 7};
    size_t j = 0;
    for (size_t i : el_to_erase){
        my_list.erase(i-j-1);
        j++;
    }
    std::cout << "vector list erase 3, 5, 7 elements: " << std::endl;
    for(size_t i = 0; i<my_list.arr_size(); i++){
        std::cout << my_list[i] << ",";
    }
    std::cout << std::endl;

    std::cout << "vector after add element 10 at index 0: " << std::endl;
    my_list.insert(10, 0);
    for(size_t i = 0; i<my_list.arr_size(); i++){
        std::cout << my_list[i] << ",";
    }
    std::cout << std::endl;

    std::cout << "vector after add element 20 at middle: " << std::endl;
    my_list.insert(20, my_list.arr_size()/2);
    for(size_t i = 0; i<my_list.arr_size(); i++){
        std::cout << my_list[i] << ",";
    }
    std::cout << std::endl;

    std::cout << "push back element 30 at the end of vector " << std::endl;
    my_list.push_back(30);
    for(size_t i = 0; i<my_list.arr_size(); i++){
        std::cout << my_list[i] << ",";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "------Vector test -------\n" << std::endl;
    demonstrate_my_vector();
    std::cout << "------List test -------" << std::endl;
    std::cout << std::endl;
    demonstrate_my_list();
    return 0;
}

