#include <iostream>
#include <fstream> // read / write to file
#include "areasofjapan.h"



using namespace std;

template <class T>
void SortFunction() // take in array, return array?
{

}

void writeToFile (AreasOfJapan a)
{
    ofstream myfile;
    myfile.open ("Sorted.txt");
    myfile << a;
    myfile.close();
}



/////////////////
int main()
{

    AreasOfJapan myArray [10];

    /*
    int i = 0;
    // read from file
    string line;
    ifstream myfile ("AreasOfJapan.txt");
    while ( std::getline (myfile,line) )
    {
        //std::cout << line << '\n';
        myArray[i] = line;
        i++;
    }
    myfile.close();
    cout << "i: " << i << endl;
    */

    //int tiltall = std::stoi( "985" ); // string to number

    ifstream myfile ("AreasOfJapan.txt");
    string word;
    int i = 0;
    while (myfile >> word)
    {
        cin >> myArray[i]; //word stoi(word);

        i++;
    }

    myfile.close();




    AreasOfJapan test1("First", 5000);
    AreasOfJapan test2("Second", 1000);

    //cin >> test2;

    // biggest
    if (test1<test2)
    {
        cout << test2;
        cout << test1;
        writeToFile(test2);
        writeToFile(test1);
    }
    else
    {
        cout << test1;
        cout << test2;
        writeToFile(test1);
        writeToFile(test2);
    }


    return 0;
}
