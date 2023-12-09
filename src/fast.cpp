#include <iostream>
#include "func.h"

int main()
{
    std::cout << "This program is linking libraries during compilation. Instructions: " << '\n'
              << "\"1\" - calculate square of figure" << '\n'
              << "\"2\" - sorting array" << '\n'
              << "\"-1\" - exit" << '\n'
              << "Input instruction: ";

    int option;
    std::cin >> option;

    while (option != -1) 
    {
        switch (option) 
        {
            case -1:
                exit(0);
            case 1:
                float A, B;
                std::cin >> A >> B;
                std::cout << "The square is: " << S(A, B) << '\n'
                          << "Input instruction: ";
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
                std::cout << '\n' << "Input instruction: ";
                std::cin >> option;
                //delete [] mas;
                //delete [] m;
                
                break;
        }
    }
    return 0;
}