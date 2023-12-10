#include <bits/stdc++.h>
#include "func.h"

extern "C"
{
    double S(double stor1, double stor2)
    {
        //std::cout << "2312312313\n";
        return stor1 * stor2;
    }
}

extern "C"
{
    int* sort(int* mas, int size)
    {
        int* v = new int[size];

        v = mas;

        for (int i = 0; i < size; i++)
        {
            v[i] = mas[i];
        }

        bool f = true;

        while (f)
        {
            f = false;
            for (int i = 1; i < size; i++)
            {
                if (v[i - 1] > v[i])
                {
                    std::swap(v[i-1], v[i]);
                    f = true;
                }
            }
        }

        return v;
    }
}