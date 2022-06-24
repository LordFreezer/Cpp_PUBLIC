/*
* Chad Marshall
*
* Programing 2 Dr Mcdaniel
*
* Due nov 5th 2019
*
* Packet Traverser W/ linked lists
*
* This program takes packets from
*   a text file and decrypts a messege
*   by organizing by sequence number
*   and applying string manipulation
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class node
{
public:
    string data;
    node* next;
};
int main()
{
    int pos;
    string info, temp, noPackNum, noDot, newLine, newLine2;

    node* head = NULL, * p;

    // retrieves data and sorts it as it is read
    ifstream file("packetData.cpp");
    while (getline(file, info))
    {
        p = new node;
        p->data = info;
        p->next = head;
        head = p;
        for (p = head; p->next; p = p->next)
            if (p->data > p->next->data)
                swap(p->data, p->next->data);
    }
    file.close();

    // deals with "=+"
    p = head;
    while (p)
    {
        // raw sorted data stored in a string var
        temp = p->data;
        // removed packet sequence number
        noPackNum = temp.substr(4, temp.length());
        // removed the period
        noDot = noPackNum.erase(noPackNum.length() - 1, 1);
        // position of first '=' char
        pos = noDot.find("=+");
        if (pos >= 0)
        {
            // swaps first '=+' with '\n'
            newLine = noDot.replace(pos, 2, "\n");
            p->data = newLine;
            // cout << p -> data;
        }
        else
            p->data = noDot;
        // cout << p -> data;
        p = p->next;
    }

    // deals with everything else
    p = head;
    while (p)
    {
        newLine = p->data;
        pos = newLine.find("=");
        if (pos >= 0)
        {
            // swaps first '=' with '\n'
            newLine2 = newLine.replace(pos, 1, "\n");
            p->data = newLine2;
        }
        p = p->next;
    }
    p = head;
    while (p)
    {
        newLine = p->data;

        pos = newLine.find("+");
        if (pos >= 0)
        {
            // swaps first '+' with '""'
            newLine2 = newLine.replace(pos, 1, "");
            p->data = newLine2;
            cout << p->data;
        }
        else
            cout << p->data;
        p = p->next;
    }
}
