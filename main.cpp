#include <iostream>
#include <stdio.h>
#include <string>
#include "FileReader.h"
#include "MagicMath.h"

using namespace std;
int main(int argc,char* argv[])
{
    int numToSend = 0;
    for(int i = 0; i<argc; i++)
    {
        if(i>0){
            try{
                FileReader* fr = new FileReader(argv[i]);
                MagicMath* mm = new MagicMath(fr->getRows());
                string str = "ffff";
                while(fr->nextLine())
                {
                    try{
                        numToSend = std::stoi(fr->getCurrLine());
                        mm->send(numToSend);
                    } catch (exception intExp) {
                        cout<<"Int exception: "<<intExp.what()<<endl;
                    }
                }
                fr->close();
                cout<<endl
                    <<"Min = "<<mm->getMin()<<endl;
                cout<<"Max = "<<mm->getMax()<<endl;
                cout<<"Med = "<<mm->getMed()<<endl;
                cout<<"Avg = "<<mm->getAvg()<<endl;

                std::vector<int> vecForMath;
                vecForMath = *mm->getIncr();
                cout<<"Incr = [";
                for(int i=0; i<vecForMath.size(); i++)
                { cout<<vecForMath.at(i)<<',';}
                cout<<"]"<<endl;
                vecForMath = *mm->getDecr();
                cout<<"Decr = [";
                for(int i=0; i<vecForMath.size(); i++)
                { cout<<vecForMath.at(i)<<',';}
                cout<<"]"<<endl;
                
                delete fr,mm;
            } catch (exception ex) {
                cout<<"Cant open file "<<argv[i]<<endl;
                cout<<"Exception: "<<ex.what();
            }
           
        }
    }   
}

