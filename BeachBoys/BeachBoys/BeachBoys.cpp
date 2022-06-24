#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<fstream>
#include<cctype>
#include <algorithm>
#include <string>
#define MIN 6
#define MAX 20
#define END cout << endl;
#define BOOLEAN (char) - (int) + (long)

using namespace std;
struct Album
{
    string albumName;
    string song[MAX], bandMembers[MAX];
    int  songcount = 0, bandcount;
};
Album albums[MIN];
void printSort();
void callSort();                             // These functions allow me to
void Song_selectionSort(Album& albums);     //  look to the left and look to
void Album_bubbleSort(Album arr[], int ac);//   the right at the same time.
int DatafilCount(string line, int count)
{
    int ac = 0;                            // Reads and throws data from file
    fstream file("datafil (BeachBoys).txt");//  into data members. To make use of
    while (getline(file, line))           //   parameters, it returns the
    {                                 //    album count to be used later.

        if (line[0] != '=')
        {
            albums[ac].albumName = line; // album name
            getline(file, line);
            albums[ac].bandcount = 0;
            while (line.length() > 0)
            {
                albums[ac].bandMembers[albums[ac].bandcount] = line;
                albums[ac].bandcount++;                         // band Members
                getline(file, line);
            }
            getline(file, line);
            albums[ac].songcount = 0;
            while (line[0] != '=')
            {
                albums[ac].song[albums[ac].songcount] = line; // song titles
                albums[ac].songcount++;
                getline(file, line);
            }
        }
        ac++;
    }
    return ac;
}
int main()
{
    string str, line;
    int count = 0, ac = DatafilCount(str, count);
    printSort();
}
void callSort() // calls both sort functions in a single function
{
    for (int ac = 0; ac < MIN; ac++)
    {
        Album_bubbleSort(albums, ac);
        Song_selectionSort(albums[ac]);
    }
}
void printSort() // Prints each album
{
    callSort();
    for (int i = 0; i < MIN - 1; i++)
    {
        END;
        cout << albums[i].albumName << endl;
        if (albums[i].bandcount > 0)
            for (int j = 0; j < albums[i].bandcount; j++)
                cout << albums[i].bandMembers[j] << ", ";
        END;
        for (int j = 0; j < albums[i].songcount; j++)
            cout << albums[i].song[j] << endl;
    }
}
void Song_selectionSort(Album& albums) // Sorts the songs by album
{
    for (int i = albums.songcount - 1; i >= 1; i--)
    {
        int maxIndex = i;
        for (int j = 0; j < i; j++)
            if (albums.song[j].substr(MIN - 2) >= albums.song[maxIndex].substr(MIN - 2))
                maxIndex = j;
        swap(albums.song[i], albums.song[maxIndex]);
    }
}
void Album_bubbleSort(Album arr[], int ac) // Sorts the album buy album name
{                                         // Fun fact:(char)-(int)+(long)-1 = 1
    int i, j;
    int swapped;
    for (i = 0; i < ac - 1; i++)
    {
        swapped = BOOLEAN - 2; // This is a fun way to do T/F. It
        for (j = 0; j < ac - i - 1; j++)           //  also makes my code blindingly
        {                                    //   unique.
            if (arr[j].albumName > arr[j + 1].albumName)
            {
                swap(arr[j], arr[j + 1]);
                swapped = BOOLEAN - 1; // assigns to true
            }
        }
        if (swapped == BOOLEAN - 2) // assigns to false
            break;
    }
}
