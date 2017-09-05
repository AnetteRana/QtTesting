#ifndef AREASOFJAPAN_H
#define AREASOFJAPAN_H

#include <iostream>

using namespace std;


class AreasOfJapan
{
public:
    AreasOfJapan();
    AreasOfJapan(std::string, int);
    bool operator<(AreasOfJapan); // less than
    friend ostream &operator << (ostream &output, AreasOfJapan &obj); // out
    friend istream &operator >> (istream &input, AreasOfJapan &obj); // in
    void SetName(string);
    void SetPop(int);

private:
    string name;
    int population;
};



#endif // AREASOFJAPAN_H
