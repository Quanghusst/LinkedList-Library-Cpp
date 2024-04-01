#include <iostream>
#include "D:\0.C++\ThuVienTaoSan\DoublelyLinkedList.h"
using namespace std;

int main () 
{
    DLinkedList<int> arr;
    for (int i = 0; i < 5 ; i++)
    {
        arr.pushBack(i+1);
    }
    cout << arr << endl;
	
	LinkedList<int> arr1;
    for (int i = 0; i < 5 ; i++)
    {
        arr1.pushBack(i+1);
    }
    cout << arr1 << endl;
    return 0;
}