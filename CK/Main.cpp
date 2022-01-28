#include "File.h"
#include "Folder.h"

#include "OpNode.h"
#include "NumNode.h"

#include <iostream>

using namespace std;

int main()
{
    Folder fo1("Folder1");
    Folder fo2("Folder2");

    fo2.add(&fo1);

    cout << fo1.size() << '\n';
    cout << fo2.size() << '\n';

    // OpNode op1('+');
    // op1.add_left(NumNode(1));
    // op1.add_right(NumNode(2));
    // cout << op1.evaluate() << '\n';

    // OpNode op2('-');
    // op2.add_left(NumNode(3));
    // op2.add_right(op1);

    // cout << op2.evaluate() << '\n';
    return 0;
}