#include <iostream>
#include <string>
#include "ReadFile.h"

using namespace std;
int main(int argc,char *argv[]) {
    ReadFile readFile; // Reads and writes files
    cout << argv[1] << "--" << argv[2] << endl;
    readFile.ReadInput(argv[1],argv[2]);
    return 0;
}
