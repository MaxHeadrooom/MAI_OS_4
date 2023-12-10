#include <dlfcn.h>
#include <iostream>

int main() 
{
    std::cout << "Программа подгружает библиотеки во время выполнения. Инструкции: " << '\n'
              << "\"0\" - сменить реализацию" << '\n'
              << "\"1\" - вычислить площадь фигуры" << '\n'
              << "\"2\" - отсортировать массив" << '\n'
              << "\"-1\" - выход" << '\n'
              << "Введите инструкцию: ";

    int option;
    std::cin >> option;

    int impl = 1;
    auto handle = dlopen("./libimpl1.so", RTLD_LAZY);

    char* error;
    error = dlerror();
    if (error) {
        std::cerr << "Error loading libimpl1.so: " << error << '\n';
        return 1;
    }

    double (*S)(double, double);
    S = reinterpret_cast<decltype(S)>(dlsym(handle, "S"));
    error = dlerror();
    if (error) {
        std::cerr << "Error loading symbol 'S': " << error << '\n';
        return 1;
    }

    int* (*sort)(int*, int);
    sort = reinterpret_cast<decltype(sort)>(dlsym(handle, "sort"));
    error = dlerror();
    if (error) {
        std::cerr << "Error loading symbol 'sort': " << error << '\n';
        return 1;
    }

    while (option != -1) 
    {
        switch (option) 
        {
            case -1:
                break;
            case 0:
                dlclose(handle);
                error = dlerror();
                if (error) {
                    std::cerr << "Error closing library: " << error << '\n';
                    return 1;
                }

                switch (impl) {
                    case 1:
                        impl = 2;
                        handle = dlopen("./libimpl2.so", RTLD_LAZY);
                        std::cout << "Switched to libimpl2.so\n";
                        break;

                    case 2:
                        impl = 1;
                        handle = dlopen("./libimpl1.so", RTLD_LAZY);
                        std::cout << "Switched to libimpl1.so\n";
                        break;
                }

                error = dlerror();
                if (error) {
                    std::cerr << "Error loading new library: " << error << '\n';
                    return 1;
                }

                S = reinterpret_cast<decltype(S)>(dlsym(handle, "S"));
                error = dlerror();
                if (error) {
                    std::cerr << "Error loading symbol 'S': " << error << '\n';
                    return 1;
                }

                sort = reinterpret_cast<decltype(sort)>(dlsym(handle, "sort"));
                error = dlerror();
                if (error) {
                    std::cerr << "Error loading symbol 'sort': " << error << '\n';
                    return 1;
                }

                std::cout << "Реализация изменена" << '\n'
                          << "Введите инструкцию: ";
                std::cin >> option;
                break;

            case 1:
                double A, B;
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

    dlclose(handle);
    error = dlerror();
    if (error) {
        std::cerr << "Error closing library: " << error << '\n';
        return 1;
    }
    return 0;
}
