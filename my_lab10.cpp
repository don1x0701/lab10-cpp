#include "my_lab10.h"
#include <iostream>
#include <fstream>

using namespace std;

std::string* readFileToDynamicArray(const std::string& filename, int& count) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка: не удалось открыть входной файл " << filename << endl;
        count = 0;
        return nullptr;
    }

    string line;
    count = 0;
    while (getline(file, line)) {
        count++;
    }

    file.clear(); // Сброс флагов ошибок потока (включая EOF)
    file.seekg(0); // Перемотка указателя чтения на начало файла

    std::string* lines = new std::string[count];
    for (int i = 0; i < count; i++) {
        getline(file, lines[i]);
    }
    file.close();
    return lines;
}

void removeCommentsFromMemory(std::string* lines, int count) {
    for (int i = 0; i < count; i++) {
        size_t pos = lines[i].find("//");
        if (pos != std::string::npos) {
            lines[i] = lines[i].substr(0, pos);
        }
    }
}

void writeArrayToFile(const std::string& filename, std::string* lines, int count) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка: не удалось создать выходной файл " << filename << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        file << lines[i] << endl;
    }
    file.close();
}