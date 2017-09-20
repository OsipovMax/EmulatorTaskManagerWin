#include "proces.h"

void Proces::setName(const std::string& Name) {
    this->Name = Name;
}
void Proces::setCentralProcess(float CentralProcess) {

        this->CentralProcess = CentralProcess;
}
void Proces::setMemory(float Memory) {
        this->Memory = Memory;
}
void Proces::setDisc(float Disc) {
        this->Disc = Disc;
}
void Proces::setNetwork(float Network){
    this->Network= Network;
}


std::string Proces::getName ( ) const {
    return Name;
}
float Proces::getCentralProcess() const {
    return CentralProcess;
}
float Proces::getMemory()  const {
    return Memory;
}
float Proces::getDisc()  const {
    return Disc;
}
float Proces::getNetwork()  const {
    return Network;
}

std::istream& operator >> (std::istream& is, Proces& ExpProces ) {
    return (is >> ExpProces.Name >>  ExpProces.CentralProcess >> ExpProces.Memory  >> ExpProces.Disc >> ExpProces.Network);
}
std::ostream& operator << (std::ostream& on, Proces& ExpProces ) {
    return (on << ExpProces.Name <<  ExpProces.CentralProcess << ExpProces.Memory  << ExpProces.Disc << ExpProces.Network);
}
