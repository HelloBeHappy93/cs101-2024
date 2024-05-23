#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class myString
{
    private:
        string m_str;
    public:
        myString(string s)
        {
            m_str = s;
        }
};

class ReadClass
{
    private:
        int counting;
        int i;
        char n[] = "class";
        char count[10][100];

    public:
    void showClass()
    {
        ifstream in;
        string Class;
        in.open("main.cpp");
        if(in.fail())
        {
            cout << "Error opening a file" << endl;
            in.close();
        }
        while(getline(in,Class)==n)
        {
            counting++;
            count[i][] = Class;
            i++;
        }
        if(getline(in,Class)!=n)
        {
            cout << counting << " class in main.cpp" << endl;
            for (int j = 0; j++;j<(i+1))
            {
                cout << count[j][] << endl;
            }
        }
    }
};

int main()
{
    ReadClass rfile;
    rfile.showClass();
    return 0;
}
