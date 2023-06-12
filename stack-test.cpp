
#include "stack.h"

using namespace std;

int main(int argc, char* argv[])
{
    cout << "creating pancakes..." << endl;
    Stack<int> pancakes;

    cout << "currently empty? " << pancakes.empty() << endl;

    cout << "pushing 1, 2, 3" << endl;
    pancakes.push(1);
    pancakes.push(2);
    pancakes.push(3);

    cout << "currently empty? " << pancakes.empty() << endl;

    cout << "size? " << pancakes.size() << endl;

    cout << "entering while loop..." << endl;
    
    while (!pancakes.empty()){
        cout << "popping: " << pancakes.top() << " ";
        pancakes.pop();
    }

    cout << "currently empty? " << pancakes.empty() << endl;

    return 0;
}