#include <dlfcn.h>
#include <iostream>

auto main() -> int {
    std::cout << "This program is linking libraries during runtime. Instructions: " << std::endl
              << "\"0\" - change implementation" << std::endl
              << "\"1\" - calculate square of figure" << std::endl
              << "\"2\" - translate number from decimal to other system" << std::endl
              << "\"-1\" - exit" << std::endl
              << "Input instruction: ";

    int option;
    std::cin >> option;

    int impl = 1;
    auto handle = dlopen("libimpl1.dylib", RTLD_LAZY);

    char* error;
    error = dlerror();
    if (error) {
        std::cerr << error << std::endl;
        return 1;
    }

    float (*square)(float, float);
    square = reinterpret_cast<decltype(square)>(dlsym(handle, "square"));
    error = dlerror();
    if (error) {
        std::cerr << error << std::endl;
        return 1;
    }

    char* (*translation)(long);
    translation = reinterpret_cast<decltype(translation)>(dlsym(handle, "translation"));
    error = dlerror();
    if (error) {
        std::cerr << error << std::endl;
        return 1;
    }

    while (option != -1) {
        switch (option) {
            case 0:
                dlclose(handle);
                error = dlerror();
                if (error) {
                    std::cerr << error << std::endl;
                    return 1;
                }

                switch (impl) {
                    case 1:
                        impl = 2;
                        handle = dlopen("libimpl2.dylib", RTLD_LAZY);
                        break;

                    case 2:
                        int impl = 1;
                        handle = dlopen("libimpl1.dylib", RTLD_LAZY);
                        break;
                }

                char* error;
                error = dlerror();
                if (error) {
                    std::cerr << error << std::endl;
                    return 1;
                }

                square = reinterpret_cast<decltype(S)>(dlsym(handle, "square"));
                error = dlerror();
                if (error) {
                    std::cerr << error << std::endl;
                    return 1;
                }

                translation = reinterpret_cast<decltype(translation)>(dlsym(handle, "translation"));
                error = dlerror();
                if (error) {
                    std::cerr << error << std::endl;
                    return 1;
                }

                std::cout << "Implementation switched" << std::endl
                          << "Input instruction: ";
                std::cin >> option;
                break;

            case 1:
                float A, B;
                std::cin >> A >> B;
                std::cout << "The square is: " << square(A, B) << std::endl
                          << "Input instruction: ";
                std::cin >> option;
                break;

            case 2:
                long num;
                std::cin >> num;
                std::cout << "The num in other system is: " << translation(num) << std::endl
                          << "Input instruction: ";
                std::cin >> option;
                break;

            default:
                option = -1;
        }
    }

    dlclose(handle);
    error = dlerror();
    if (error) {
        std::cerr << error << std::endl;
        return 1;
    }
    return 0;
}