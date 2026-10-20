#ifndef MY_LAB10_H
#define MY_LAB10_H

#include <string>

// Считывает файл построчно в динамический массив и возвращает его размер через count
std::string* readFileToDynamicArray(const std::string& filename, int& count);

// Очищает строки массива от комментариев // непосредственно в памяти
void removeCommentsFromMemory(std::string* lines, int count);

// Записывает динамический массив строк в новый текстовый файл
void writeArrayToFile(const std::string& filename, std::string* lines, int count);

#endif // MY_LAB10_H