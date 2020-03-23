#include "FileReader.h"
#include <fstream>
#include <unistd.h>

void checkProgress(int size,int& currSize)
{
    while(currSize < size)
    {
        std::cout<<"\rProgress:   [";
        for(int i = 0; i<round(10*currSize/size)+1; i++)
        { std::cout<<'|';}
        for(int i = 0; i<10-1-round(10*currSize/size); i++)
        { std::cout<<' ';}
        std::cout<<']';
        printf(" %.2f%%",(1000.0*currSize/size)/10.0);
        usleep(2000);
    }
    std::cout<<"\rCOMPLETED: ";
    return;
}

FileReader::FileReader(char *filePath)
{
    std::cout<<"File "<<filePath<<" has been opened."<<std::endl;
    this->size = findFileSize(filePath);
    this->currLine = "";
    this->currPos = 0;
    this->file = new std::ifstream(filePath);
    this->rows = countRows();
    this->progbar = std::thread(checkProgress,this->size,std::ref(currPos));
}

int FileReader::findFileSize(char* filePath)
{
    FILE* fileForSize = fopen(filePath,"r");
    int fileBeg = ftell(fileForSize);
    fseek(fileForSize,0,SEEK_END);
    int fileEnd = ftell(fileForSize);
    fclose(fileForSize);
    delete fileForSize;

    return (fileEnd-fileBeg);
}

std::string FileReader::getCurrLine()
{
    return currLine;
}

std::ifstream* FileReader::openfile(char* path)
{
    if(file!=NULL && file->is_open())
    {
        file->close();
        delete file;
    } else if (file != NULL) {
        delete file;
    }

    file = new std::ifstream(path);
    size = findFileSize(path);
    currPos = 0;
    currLine = "";
    rows = countRows();
    return file;
}

bool FileReader::nextLine()
{
    if(file!= NULL && file->is_open())
    {
        if(getline(*file,currLine))
        {            
            currPos = file->tellg();
            return true;
        }
        return false;
    }
    return false;
}

void FileReader::close()
{
    progbar.join();
    file->close();
}

//Private


int FileReader::countRows()
{
    if(this->file!=NULL && this->file->is_open())
    {
        std::string tmpLine;
        int tmp = this->file->tellg();
        this->rows = 0;
        file->seekg(0);
        while(!file->eof())
        {
            getline(*file,tmpLine);
            this->rows++;
        }
        this->rows--;
        file->clear();
        file->seekg(tmp);
    }
    return this->rows;
}

int FileReader::getRows() {return this->rows;}