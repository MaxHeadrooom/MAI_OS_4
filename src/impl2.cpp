#include <bits/stdc++.h>
#include "func.h"

extern "C"
{
    double S(double stor1, double stor2)
    {
        //std::cout << "2312312313\n";
        return stor1 * stor2 / 2;
    }
}

extern "C"
{
    void _sort(int* arr, int first, int last) 
    {
        int i = first, j = last, pivot = arr[(first + last) / 2];
        do 
        {
            while (arr[i] < pivot)
                i++;
            while (arr[j] > pivot)
                j--;
    
            if(i <= j) 
            {
                if (arr[i] > arr[j]) 
                {
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
                i++;
                j--;
            }
        } while (i <= j);
    
        if (i < last)
            _sort(arr, i, last);
        if (first < j)
            _sort(arr, first, j);
    }

    int* sort(int* array, int size) 
    {
        int* result = new int[size];
        for (int i = 0; i < size; i++) 
        {
            result[i] = array[i];
        }

        _sort(result, 0, size - 1);

        return result;
    }

}