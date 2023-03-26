#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ofstream outputFile;
    outputFile.open("password.txt");

    for (int i = 0; i <= 9; i++)
    {
        for (int j = 97; j <= 122; j++)
        {
            for (int k = 97; k <= 122; k++)
            {
                for (int l = 97; l <= 122; l++)
                {
                    for (int m = 97; m <= 122; m++)
                    {
                        for (int n = 97; n <= 122; n++)
                        {
                            for (int o = 97; o <= 122; o++)
                            {
                                string pass = to_string(i) + (char)j + (char)k + (char)l + (char)m + (char)n + (char)o;
                                outputFile << pass << endl;
                            }
                        }
                    }
                }
            }
        }
    }
}