/**********************************************************
 * Author:      sugarfreeoh
 * Date:        4 March 2016
 * Description: Give numbers x and n, where n is a power
 *              of 2, print out the smallest multiple of n
 *              which is >= to x. Do not use the % or /
 *********************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream inputFile;

    inputFile.open(argv[1]);

    if(inputFile.is_open())
    {
        string data;
        string sX;
        string sN;

        int x;
        int n;

        int charLocation;

        while(getline(inputFile,data))
        {
            int tempN = 0;
            stringstream ss;

            charLocation = data.find(',');

            sX = data.substr(0,charLocation);
            sN = data.substr(charLocation+1,data.size()-charLocation-1);

            ss << sX;
            ss >> x;

            ss.str("");
            ss.clear();

            ss << sN;
            ss >> n;

            //cout << "x:" << x << ",";
            //cout << "n:" << n << endl;

            tempN = n;

            if(n < x)
            {
                int count = 1;

                while(tempN < x)
                {
                    tempN = n*count;
                    ++count;
                }
            }

            cout << tempN << endl;
        }

        inputFile.close();
    }
    else
    {
        cout << "Error opening input file" << endl;
    }

    return 0;
}
