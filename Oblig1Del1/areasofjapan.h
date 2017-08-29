#ifndef AREASOFJAPAN_H
#define AREASOFJAPAN_H

#include <iostream>


class AreasOfJapan
{
public:
    AreasOfJapan(std::string, int);
    printValues();
private:
    std::string name;
    int population;
};

#endif // AREASOFJAPAN_H
