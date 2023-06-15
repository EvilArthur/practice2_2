#include <iostream>
#define SIZE 999
template<typename T>
void ownMemcopy(T* dst, T* src, const int& len) {
    int i, m;
    int byteSizeArray = sizeof(T) * SIZE;
    unsigned long long* wdst = (unsigned long long*)dst;    // текущая позиция в буфере назначения (т.е. на каком байте мы находимся в новом массиве)
    unsigned long long* wsrc = (unsigned long long*)src;    // текущая позиция в источнике(т.е. на каком байте мы находимся в старом массиве)
    char* pointerDst, * pointerSrc;

    m = (byteSizeArray) / sizeof(long long);                // получаем целое количество байт, которое нужно перенести ( длину нашего массива в байтах / 8 байт (т.е. long long)
    for (i = 0; i < m; i++)                                 // копируем основную часть блоками по 8 байт
        *(wdst++) = *(wsrc++);                              // (в зависимости от платформы)

    pointerDst = (char*)wdst;
    pointerSrc = (char*)wsrc;

    m = (byteSizeArray) % sizeof(long long);                // получаем колличество оставшихся байт, которое нужно перенести ( длину нашего массива в байтах % 8 байт (делим и смотрим остаток)
    for (i = 0; i < m; i++)                                 // остаток копируем побайтно (аналогично предыдущему)
        *(pointerDst++) = *(pointerSrc++);
}


int main() {
    int array[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int newArray[SIZE] = { 0 };
    int len = 10;

    ownMemcopy(newArray, array, len);
    for (int i = 0; i < len; i++) {
        std::cout << newArray[i] << " ";
    }
    return 0;
}