#ifndef PROCES_H
#define PROCES_H
#include <string>
#include <iostream>

class Proces
{
public:
        Proces( ) : Name(""), CentralProcess(0), Memory(0), Disc(0), Network (0) {}
        ~Proces( ) =default;
        Proces(const std::string& Name, float CentralProcess, float Memory, float Disc, float Network) :
            Name(Name), CentralProcess(0), Memory(0), Disc(0), Network(0) {
            setCentralProcess(CentralProcess);
            setMemory(Memory);
            setDisc(Disc);
            setNetwork(Network);
        }

        std::string getName( ) const;
        float getCentralProcess( ) const;
        float getMemory( ) const;
        float getDisc( ) const;
        float getNetwork( ) const;

        void setName(const std::string& Name);
        void setCentralProcess(float);
        void setMemory(float);
        void setDisc(float);
        void setNetwork(float);

        friend std::istream& operator >> (std::istream&, Proces&);
        friend std::ostream& operator<<(std::ostream&,Proces&);
private:
        std::string Name;
        float  CentralProcess,Memory,Disc,Network;

};
#endif // PROCES_H
