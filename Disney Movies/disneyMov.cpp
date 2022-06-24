/*
Chad Marshall
Programming 2
due: 9/24/2019
Disney Movie Sorts
This program reads in from an inout file and sorts the movies by title,
then sorts the voice actors 
*/
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
void callSort();
void printSort();
struct Movie
{
  string movieName, date, directors;
  string actor[10];
  int  actorcount = 0;
};
Movie movies[6];
void Actor_bubbleSort(Movie& albums);
void Movie_bubbleSort(Movie arr[], int ac);
int DatafilCount(string line, int count)
{
  string str = ":";
  int ac = 0;                          // Reads and throws data from file
  ifstream file ("DisneyDatafil.cpp"); // into data members. To make use of
  while(getline(file, line))           // parameters, it returns the
  {   
      movies[ac].movieName = line; // movie name 
      getline(file, line);
      movies[ac].date = line;      // date movie came out
      getline(file, line);
      movies[ac].directors = line; // director
      movies[ac].actorcount = 0;
      while (getline(file, line) && line[0] != '=') // actor names
      {
        movies[ac].actor[movies[ac].actorcount] = line; 
        movies[ac].actorcount++;
      }
    ac++;
  }
  return ac;
}
void callSort() // calls both sort functions in a single function
{
  for(int ac = 0; ac < 6; ac++)
  {
    Movie_bubbleSort(movies, ac);
    Actor_bubbleSort(movies[ac]);
  }
}
void printSort() // Prints each album
{
  callSort();
  for(int i = 0; i < 6; i++)
  {
    cout << endl << movies[i].movieName << endl
         << movies[i].date << endl << movies[i].directors << endl;
    for (int j = 0; j < movies[i].actorcount + 1; j++)
      cout << movies[i].actor[j] << endl;
  }
}
int main()
{
  string str;
  int count = 0, ac = DatafilCount(str, count);
  printSort();

}
void Actor_bubbleSort(Movie&  movies)
{
  int i, j, swapped, pos, pos2;
  for(i = 0; i < movies.actorcount - 1; i++)
  {
    swapped = 0;
    for(j = 0; j < movies.actorcount-i-1; j++)
    {
      pos = movies.actor[j].find(" ");
      pos2 = movies.actor[j+1].find(" ");
      if(movies.actor[j].substr(pos + 1) >= movies.actor[j+1].substr(pos2 + 1))
      {
        swap(movies.actor[j], movies.actor[j+1]);
        swapped = 1;
      }
    }
    if(swapped == 0)
      break;
  }
}
void Movie_bubbleSort(Movie arr[], int ac) // Sorts the movie by movie name
{                                         // Fun fact:(char)-(int)+(long)-1 = 1
   int i, j;
   int swapped;
   for(i = 0; i < ac - 1; i++)
   {
     swapped = 0; 
     for(j = 0; j < ac-i-1; j++)                                        
       if(arr[j].movieName > arr[j + 1].movieName)
       {
         swap(arr[j], arr[j + 1]);
         swapped = 1; // assigns to true
       }
    if(swapped == 0) // assigns to false
      break;
  }
}
