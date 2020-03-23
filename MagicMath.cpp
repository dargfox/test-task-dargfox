#include "MagicMath.h"

MagicMath::MagicMath(int expAmount)
{
    this->min = 99999999;
    this->max = -99999999;
    this->avg = 0;
    this->med = 0;
    this->sum = 0;
    this->ammount = 0;
    this->incrTmp = new std::vector<int>();
    this->decrTmp = new std::vector<int>();
    this->incr = new std::vector<int>();
    this->decr = new std::vector<int>();
}

MagicMath::~MagicMath()
{
    delete this;
}

void MagicMath::clear()
{
    this->min = 99999999;
    this->max = -99999999;
    this->avg = 0;
    this->med = 0;
    delete this->incr;
    delete this->decr;
    this->incrTmp = new std::vector<int>();
    this->decrTmp = new std::vector<int>();
    this->incr = new std::vector<int>();
    this->decr = new std::vector<int>();
    this->sum = 0;
    this->ammount = 0;
}

int MagicMath::send(int number)
{
    this->currNum = number;
    this->sum+=number;
    this->ammount++;
    calcMax();
    calcMin();
    calcMed();
    calcIncr();
    calcDecr();
}

int MagicMath::getMin() {return this->min;}

int MagicMath::getMax() {return this->max;}

std::vector<int>* MagicMath::getIncr() {return this->incr;}

std::vector<int>* MagicMath::getDecr() {return this->decr;}

float MagicMath::getAvg() 
{
    this->calcAvg();
    return this->avg;    
}

float MagicMath::getMed()
{
    return this->med;
}

//Calculation functions//

int MagicMath::calcMin()
{
    if(currNum<min) {return (min = currNum);}
}

int MagicMath::calcMax()
{
    if(currNum>max) {return (max = currNum);}
}

float MagicMath::calcAvg()
{
    if(ammount>0) { return avg = sum/ammount;}
}

float MagicMath::calcMed()
{
    if(this->expAmount%2 == 1 && ammount == ceil(expAmount/2.0))
    { med = currNum; }
    else if 
    (this->expAmount%2 == 0 &&
        (ammount == ceil(expAmount/2.0) ||
         ammount-1 == ceil(expAmount/2.0))
    )
    { med += currNum/2.0;}
}

std::vector<int>* MagicMath::calcIncr() {
    if(incrTmp->empty() || currNum >= incrTmp->back())
    {
        incrTmp->push_back(currNum);
    } else if (currNum < incrTmp->back())
    {
        if(incr->size() < incrTmp->size())
        {
            delete incr;
            incr = incrTmp;
            incrTmp = new std::vector<int>();
        } else {
            incrTmp->clear();
        }
    } 
}

std::vector<int>* MagicMath::calcDecr() {
    if(decrTmp->empty() || currNum <= decrTmp->back())
    {
        decrTmp->push_back(currNum);
    } else if (currNum > decrTmp->back())
    {
        if(decr->size() < decrTmp->size())
        {
            delete decr;
            decr = decrTmp;
            decrTmp = new std::vector<int>();
        } else {
            decrTmp->clear();
        }
    } 
}

