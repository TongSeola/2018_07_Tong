#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int luhn(string &tar)
{
    int checksum(0);
    int stl(tar.size());
    int isjjak(2);
    for(int i = stl - 2; i >= 0; --i)
    {
        int stringed = tar[i] - '0';
        if(isjjak % 2 == 0)
        {
            checksum += stringed * 2 >= 10 ? stringed * 2 - 9 : stringed * 2;
        }
        else
        {
            checksum += stringed;
        }
        ++isjjak;
    }
    int checker((tar[stl - 1] - '0') + checksum);
    if(checker % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int validcompany(string &target)
{
    if(target[0] == '3')
    {
        return target.size() == 15 || target.size() == 14;
    }
    else if(target[0] == '4')
    {
        return target.size() == 13 || target.size() == 16;
    }
    else if(target[0] == '5')
    {
        return target.size() == 16;
    }
    else if(target[0] == '6')
    {
        return target.size() == 16;
    }
    else
    {
        return 0;
    }
}

int main()
{
    vector<int> cnums;
    vector<int>::iterator x;

    fstream f; f.open("input.txt"); if(f.fail()) {exit(1);}
    int t; f >> t;
    for(int i = 0; i < t; ++i)
    {
        string ip; f >> ip;
        short sl(ip.size());
        for(int j = 0; j < sl; ++j)
        {
            cnums.push_back(ip[j] - 48);
        }
        // x = cnums.end();
        // cout << luhn(ip) << " " << validcompany(ip) << "\n";
        // cout << cnums[cnums.size() - 1] << "\n";
        if(luhn(ip) && validcompany(ip))
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
        cnums.clear();
    }
    f.close();
}
