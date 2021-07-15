#include <iostream>
//#include <iomanip>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Name {
    char* mp;
public:
    Name(const char* p);
    ~Name();
    void display();
    void reverse();
};

Name::Name(const char* p) 
{
    mp = new char[strlen(p) + 1];
    strcpy(mp, p);
}

Name::~Name()
{
    delete[] mp;
}

void Name::display()
{
    cout << mp << endl;
}

void Name::reverse()
{
    int n = strlen(mp);
    for (int i = 0; i < n / 2; i++) {
        char tmp = mp[i];
	mp[i] = mp[n - 1 - i];
	mp[n - 1 - i] = tmp;
    }
}

int main()
{
    Name myname("nese");
    myname.display();
    myname.reverse();
    myname.display();
    return 0;
}
