#include "areasofjapan.h"


AreasOfJapan::AreasOfJapan(std::string inName, int inPop)
{

    name = inName;
    population = inPop;
    // overload inn/out
    //std::ostream& operator>> (std::ostream& os, const string& obj)
//    {
//        return os;
//    }



}


AreasOfJapan::printValues()
{
    std::cout << name << std::endl << population;
}

//AreasOfJapan::print()
//{
//// read from file
//string line;
//ifstream myfile ("AreasOfJapan.txt");
//while ( getline (myfile,line) )
//{
//    cout << line << '\n';
//}
//myfile.close();
//}
