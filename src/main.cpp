#include "Utils.h"
#include <iostream>

using namespace std;

void error(string msg, int n) {
    cout << endl << "ERROR: " << msg << " at character " << n << endl;
    exit(1);
}

int main(int argc, char* argv[]) {

    if(argc < 2)
    {
        cout << "File path argument expected!" << endl;
        return 1;
    }

    string src_string = utils::readfile(argv[1]);

    const char *source = src_string.c_str();
    int len = src_string.length();

    if(!len)
    {
        cout << "File is empty or does not exists!" << endl;
        return 1;
    }

    int array[10000] = {0}, looppos[100];
    int pos = 0, currentloop=-1;

    for(int n=0;n<len;n++)
    {
        switch (source[n]) {
            case '+': {
                array[pos]++;
                break;
            }
            case '-': {
                array[pos]--;
                break;
            }
            case '>': {
                pos++;
                break;
            }
            case '<': {
                if(pos == 0)
                    error("Negative position", n);
                pos--;
                break;
            }
            case '.': {
                putchar(array[pos]);
                break;
            }
            case ',': {
                array[pos] = getchar();
                break;
            }
            case '[': {

                if(array[pos]) {
                    currentloop++;
                    looppos[currentloop] = n;
                }
                else {
                    int ignoreloops = 1;

                    while(ignoreloops) {
                        n++;
                        if(n >= len)
                            error("Loop not closed",n);

                        if(source[n] == ']')
                            ignoreloops--;
                        else if(source[n] == '[')
                            ignoreloops++;
                    }
                }

                break;
            }
            case ']': {
                if(currentloop < 0)
                    error("Loop close without begin", n);

                if(array[pos])
                    n = looppos[currentloop] - 1;

                currentloop--;

                break;
            }
            default:
                break;
        }
    }

    if(currentloop > -1)
        error("Loop not closed",len);

    cout << endl;

    return 0;
}
