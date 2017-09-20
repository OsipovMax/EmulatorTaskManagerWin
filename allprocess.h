#ifndef ALLPROCESS_H
#define ALLPROCESS_H
#include <vector>
#include "proces.h"
using namespace std;

class AllProcess
{
public:
    AllProcess();
    Proces front();
    Proces back ();
    size_t size ( );
    Proces operator [] (size_t);
    void Add (const Proces);
    void remove (size_t);
    vector <Proces>::iterator begin (){
        return arr.begin();
    }
    vector <Proces>::iterator end(){
        return arr.end();
    }

private:
    vector<Proces> arr;
};

bool operator < (const Proces, const Proces);

#endif // ALLPROCESS_H
