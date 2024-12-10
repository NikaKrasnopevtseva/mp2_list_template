// реализация пользовательского приложения
#include "list.h"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    List<int> list;

    list.InsertToHead(1);
    list.InsertToHead(2);
    list.InsertToHead(3);

    std::cout << "Список: " << list.ToString() << std::endl;

    list.Delete(2);

    std::cout << "После удаления 2: " << list.ToString() << std::endl;

    list.Inverse();

    std::cout << "После инверсии: " << list.ToString() << std::endl;

    list.Clean();

    std::cout << "После очистки: " << list.ToString() << std::endl;

    return 0;
}
