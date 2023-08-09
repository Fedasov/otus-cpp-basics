#include <iostream>
#include "serial_container.cpp"
#include "bidirectional_list.cpp"
#include "unidirectional_list.cpp"

int main() {
//    MyList_bid<int> values;                              // создание объекта двунаправленного списка
//    MyList_uni<int> values;                              // создание объекта однонаправленного списка
    MyContainer<int> values;                             // создание объекта последовательного контейнера

    for (int i = 0; i < 10; i++) {                  // добавление элементов в контейнер
        values.push_back(i);
    }

    // auto iter = values.begin();
    // std::cout << iter->data << std::endl;
    // int c = *iter;
    // std::cout << c << std::endl;

    for (int i = 0; i < values.size(); i++) {       // вывод содержимого контейнера
        std::cout << " " << values[i];
    }
    std::cout << std::endl;

    std::cout << values.size() << std::endl;        // вывод размера контейнера

    values.erase(3, 5, 7);                          // удаление элементов. Для удобства пользвателя сделан ввод порядковых номеров без списков

    for (int i = 0; i < values.size(); i++) {       // вывод содержимого контейнера
        std::cout << " " << values[i];
    }
    std::cout << std::endl;

    values.insert(0, 10);                           // добавление 10 в начало контейнера
    for (int i = 0; i < values.size(); i++) {       // вывод содержимого контейнера
        std::cout << " " << values[i];
    }
    std::cout << std::endl;

    values.insert((int)values.size()/2, 20);         // добавление 20 в середину контейнера
    for (int i = 0; i < values.size(); i++) {       // вывод содержимого контейнера
        std::cout << " " << values[i];
    }
    std::cout << std::endl;

    values.insert((int)values.size(), 30);           // добавление 30 в конец контейнера
    for (int i = 0; i < values.size(); i++) {       // вывод содержимого контейнера
        std::cout << " " << values[i];
    }
    std::cout << std::endl;

    return 0;
}


// int main() {
//     MyContainer values;                         // создание объекта

//     for (int i = 0; i < 10; i++) {              // добавление элементов в контейнер
//         values.push_back(i);
//     }

//     for (int i = 0; i < values.size(); i++) {   // вывод содержимого контейнера
//         std::cout << " " << values[i];
//     }
//     std::cout << std::endl;

//     std::cout << values.size() << std::endl;    // вывод размера контейнера

//     values.erase(3, 5, 7);                      // удаление элементов. Для удобства пользвателя сделан ввод порядковых номеров без списков

//     for (int i = 0; i < values.size(); i++) {   // вывод содержимого контейнера
//         std::cout << " " << values[i];
//     }
//     std::cout << std::endl;

//     values.insert(0, 10);                       // добавление 10 в начало контейнера
//     for (int i = 0; i < values.size(); i++) {   // вывод содержимого контейнера
//         std::cout << " " << values[i];
//     }
//     std::cout << std::endl;

//     values.insert(values.size()/2, 20);         // добавление 20 в середину контейнера
//     for (int i = 0; i < values.size(); i++) {   // вывод содержимого контейнера
//         std::cout << " " << values[i];
//     }
//     std::cout << std::endl;

//     values.insert(values.size(), 30);           // добавление 30 в конец контейнера
//     for (int i = 0; i < values.size(); i++) {   // вывод содержимого контейнера
//         std::cout << " " << values[i];
//     }
//     std::cout << std::endl;

//     return 0;
// }