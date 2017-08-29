#include <iostream>
//#include <fstream> // read / write to file
#include "areasofjapan.h"


using namespace std;

template <class T>
void SortFunction()
{

}



/////////////////
int main()
{

    AreasOfJapan myArray [10];



AreasOfJapan test1("First", 1000);
AreasOfJapan test2("Second", 2000);

cin >> test2;

// biggest
if (test1<test2)
{
    cout << test2;
    cout << test1;
}
else
{
    cout << test1;
    cout << test2;
}




//int tiltall = std::stoi( "985" ); // string to number


    return 0;
}
