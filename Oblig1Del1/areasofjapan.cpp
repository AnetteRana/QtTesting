#include "areasofjapan.h"



AreasOfJapan::AreasOfJapan()
{
    name = "Blank";
    population = 0;
}

AreasOfJapan::AreasOfJapan(std::string inName, int inPop)
{
    name = inName;
    population = inPop;
}

bool AreasOfJapan::operator<(AreasOfJapan a)
{
    if (population < a.population)
    {
        return true;
    }
    else
    {
        return false;
    }
}

ostream &operator << (ostream &output, AreasOfJapan &obj) // cout
{
    output << "Area: " << obj.name << ", population: " << obj.population << endl;
    return output;
}

istream &operator >> (istream &input, AreasOfJapan &obj) // cin // fungerer, men finner ikke bruk for
{
    input >> obj.name >> obj.population;
    return input;
}

void AreasOfJapan::SetName(string in)
{
    name = in;
}

void AreasOfJapan::SetPop(int in)
{
    population = in;
}




