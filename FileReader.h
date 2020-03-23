#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <math.h>
#include <thread>

class FileReader{
    public:
    FileReader(char*);
    std::ifstream *openfile(char*);
    std::string getCurrLine();
    bool nextLine();
    int getRows();
    void close();


    private:
    int size;
    int currPos;
    int rows;
    std::string currLine;
    std::ifstream *file;
    std::thread progbar;
    int countRows();
    int findFileSize(char*);
};

