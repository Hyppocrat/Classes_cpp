#include <iostream>
using namespace std;

int* find_min(int *arr_begin, int *arr_end){
    int *min_ptr = arr_begin;
    while( arr_begin < arr_end ){
        if(*min_ptr > *arr_begin){
            min_ptr = arr_begin;
        }
        ++arr_begin;
    }
    return min_ptr;
}

int find_min_value(int *arr_begin, int *arr_end){
    return *find_min(arr_begin, arr_end);
}


int main() {
    int a[10] = {3,5,2,1,5,0,2,8,4,1};
    return 0;
}
