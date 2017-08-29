#include "areasofjapan.h"


AreasOfJapan::AreasOfJapan(std::string inName, int inPop)
{

    name = inName;
    population = inPop;


    // overload out operator
//    std::ostream& operator<< (ostream& os, const Date& dt)
//    {
//        os << dt.mo << '/' << dt.da << '/' << dt.yr;
//        return os;
//    }

    // overload in operator

    // overload + operator


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
