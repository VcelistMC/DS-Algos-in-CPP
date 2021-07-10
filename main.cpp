#include <iostream>
#include "BTNode.h"
using namespace std;


int main()
{   
    BTNode n1(12);
    BTNode n2(13);
    BTNode n3(12);

    n1 == n2;
    cout << (n1 == n3) << endl;
    cout << (n1 > n2) << endl;
    cout << (n3 < n1) << endl;
} 