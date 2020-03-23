#pragma once
#include <math.h>
#include <iostream>
#include <vector>

class MagicMath
{
private:
    int currNum;
    int max;
    int min;
    float med;
    float avg;
    float sum;
    int ammount;
    int expAmount;
    std::vector<int> *incrTmp;
    std::vector<int> *decrTmp;
    std::vector<int> *incr;
    std::vector<int> *decr;

    int calcMin();
    int calcMax();
    float calcMed();
    float calcAvg();
    std::vector<int>* calcIncr();
    std::vector<int>* calcDecr();
public:
    MagicMath(int);
    ~MagicMath();
    int send(int);
    int getMin();
    int getMax();
    float getMed();
    float getAvg();
    std::vector<int>* getIncr();
    std::vector<int>* getDecr();
    void setExpAmount(int);
    int getExpAmount();
    void clear();
};

