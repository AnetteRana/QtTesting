#include <iostream>
#include <fstream> // read / write to file
#include "areasofjapan.h"



using namespace std;

template <class T>
void SortFunction(T a[])
{
    // bubble sort
    int elements = 10;
    T temp;
    int i, j;
    for (i = 0; i < elements; i++)
    {
        for (j = i+1; j < elements-1; j++)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;

            }
        }
    }

}

void writeToFile (AreasOfJapan a[])
{
    ofstream myfile;
    myfile.open ("Sorted.txt");
    for (int i = 0; i < 10; i++) // loops ten times - hardcoded
    {
        myfile << a[i] << endl;
    }
    myfile.close();
}

void readFromFile(AreasOfJapan a[])
{
    // fil til array
    ifstream myfile ("AreasOfJapan.txt");
    string word;
    int i = 0;
    int y;
    int k = 0;

    while (!myfile.eof())
    {
        for (int j = 0; j < 2; j++)
        {
            // ved oddetall - les inn populasjon
            if (i%2)
            {
                myfile >> word ;
                y = stoi(word);
                a[k].SetPop(y);
            }
            // ved partall - les inn navn
            else
            {
                myfile >> word ;
                a[k].SetName(word);
            }

            i++;
        }
        k++;
    }
    myfile.close();
}

/////////////////
int main()
{  

    AreasOfJapan myArray [10];

    readFromFile(myArray);
    SortFunction(myArray);
    writeToFile(myArray);

    cout << "Have a nice day:)\n";
    return 0;
}
