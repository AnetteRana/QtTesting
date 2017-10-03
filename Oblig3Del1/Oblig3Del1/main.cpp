#include <hash_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//hash<int> h;

class MyClass {
public:
    int key;
    string s;
    size_t operator() (const MyClass& t)
    {
        return t.key % 11;
    }
    bool operator == (const MyClass& t2) const { return key == t2.key; }
};

// definere egen hashfunksjon ... Overlaster STD::hash
namespace std {
template<>
class hash<MyClass>
{
public:
    size_t operator() (const MyClass& t) const
    {
        return t.key % 11;
    }
    bool operator() (const MyClass& t1, const MyClass& t2)
    {
        return t1.key == t2.key;
    }
};
}


int main()
{
    //unordered_set<MyClass> unorderedSetForTest;
    unordered_multiset<MyClass> unorderedSetForTest;
    //unordered_set<MyClass>::iterator iteratorForUnorderedSetForTest;
    unordered_multiset<MyClass>::iterator iteratorForUnorderedSetForTest;
    MyClass t;


    // lage pseudo-random objekter (manuelt)
    t.key = 7; t.s = "seven";
    unorderedSetForTest.insert(t);
    t.key = 10; t.s = "ten";
    unorderedSetForTest.insert(t);
    t.key = 9; t.s = "nine";
    unorderedSetForTest.insert(t);
    t.key = 8; t.s = "eight";
    unorderedSetForTest.insert(t);
    t.key = 7; t.s = "seven2";
    unorderedSetForTest.insert(t);
    t.key = 8; t.s = "eight2";
    unorderedSetForTest.insert(t);
    t.key = 3; t.s = "three";
    unorderedSetForTest.insert(t);
    t.key = 7; t.s = "seven3";
    unorderedSetForTest.insert(t);
    t.key = 9; t.s = "nine2";
    unorderedSetForTest.insert(t);
    t.key = 4; t.s = "four";
    unorderedSetForTest.insert(t);
    t.key = 4; t.s = "four2";
    unorderedSetForTest.insert(t);
    t.key = 1; t.s = "one";
    unorderedSetForTest.insert(t);
    cout << "12 object inserted to set.\n";
    cout << "Size = " << unorderedSetForTest.size() << endl;

    t.key = 4;
    cout << "How many with key 4: " << unorderedSetForTest.count(t) << endl;
    iteratorForUnorderedSetForTest = unorderedSetForTest.find(t);
    t = *iteratorForUnorderedSetForTest;
    cout << t.key << " " << t.s << endl;


    return 0;
}

