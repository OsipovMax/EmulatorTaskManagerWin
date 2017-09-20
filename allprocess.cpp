#include "allprocess.h"
#include <iostream>
#include <ostream>

AllProcess::AllProcess ( ) { }

size_t AllProcess::size( ){
    return arr.size();
}

Proces AllProcess::operator [ ] (size_t offset){
    return arr[offset];
}

 Proces AllProcess::front( ){
    return arr.front( );
}

 Proces AllProcess::back( ){
    return arr.back( );
}


void AllProcess::Add(const Proces intIn){
    arr.push_back(intIn);
}

void AllProcess::remove(size_t pos){
    arr.erase(arr.begin() + pos);
}

