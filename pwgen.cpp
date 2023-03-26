#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <vector>

using namespace std;

const int MAX_THREAD = 10;

void generateWordlist(int threadIndex, int totalThreads)
{
    string chars = "abcdefghijklmnopqrstuvwxyz0123456789";
    vector<int> indices(7);

    // Open the file
    ofstream file("wordlist_" + to_string(threadIndex) + ".txt");

    if (file.is_open())
    {
        for (int i1 = 0; i1 < chars.size(); i1++)
        {
            if (threadIndex != i1 % totalThreads)
                continue;
            indices[0] = i1;
            for (int i2 = 0; i2 < chars.size(); i2++)
            {
                indices[1] = i2;
                for (int i3 = 0; i3 < chars.size(); i3++)
                {
                    indices[2] = i3;
                    for (int i4 = 0; i4 < chars.size(); i4++)
                    {
                        indices[3] = i4;
                        for (int i5 = 0; i5 < chars.size(); i5++)
                        {
                            indices[4] = i5;
                            for (int i6 = 0; i6 < chars.size(); i6++)
                            {
                                indices[5] = i6;
                                for (int i7 = 0; i7 < chars.size(); i7++)
                                {
                                    indices[6] = i7;
                                    // Output the word
                                    string word = "";
                                    for (int i = 0; i < 7; i++)
                                    {
                                        word += chars[indices[i]];
                                    }
                                    file << word << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Close the file
    file.close();
}

int main()
{
    vector<thread> threads;

    // Spawn threads
    for (int i = 0; i < MAX_THREAD; i++)
    {
        threads.push_back(thread(generateWordlist, i, MAX_THREAD));
    }

    // Join threads
    for (int i = 0; i < MAX_THREAD; i++)
    {
        threads[i].join();
    }

    return 0;
}