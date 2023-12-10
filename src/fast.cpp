#include <iostream>
#include "func.h"

int main()
{
    std::cout << "Программа подгружает библиотеки во время выполнения. Инструкции: " << '\n'
              << "\"1\" - вычислить площадь фигуры" << '\n'
              << "\"2\" - отсортировать массив" << '\n'
              << "\"-1\" - выход" << '\n'
              << "Введите инструкцию: ";

    int option;
    std::cin >> option;

    while (option != -1) 
    {
        switch (option) 
        {
            case -1:
                break;
            case 1:
                float A, B;
                std::cin >> A >> B;
                std::cout << "Площадь фигуры: " << S(A, B) << '\n'
                          << "Введите инструкцию: ";
                std::cin >> option;
                break;

            case 2:
                int size;
                std::cin >> size;

                int *m = new int[size];

                for (int i = 0; i < size; i++)
                {
                    std::cin >> m[i];
                }

                int* mas = sort(m, size);

                for (int i = 0; i < size; i++)
                {
                    std::cout << mas[i] << " ";
                }
                std::cout << '\n' << "Введите инструкцию: ";
                std::cin >> option;
                //delete [] mas;
                //delete [] m;
                
                break;
        }
    }
    return 0;
}