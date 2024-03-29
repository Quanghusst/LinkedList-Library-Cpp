#include <iostream>
#include "LinkedList.h"
using namespace std;

int main () 
{
    LinkedList<int> arr;
    for (int i = 0; i < 5; i++)
    {
        arr.pushFront(i+1);
    }
    cout << arr << endl;
    cout << "==========\n";
    arr.insertBefore(arr.getNodeAt(0), 100);
    cout << arr << endl;

    return 0;
}