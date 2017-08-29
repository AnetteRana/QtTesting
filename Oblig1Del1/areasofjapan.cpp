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

ostream &operator << (ostream &output, AreasOfJapan &obj) // out
{
    output << "Area: " << obj.name << ", population: " << obj.population << endl;
    return output;
}

istream &operator >> (istream &input, AreasOfJapan &obj) // in
{
    input >> obj.name >> obj.population;
    return input;
}




