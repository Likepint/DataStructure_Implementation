#include "Stack.h"

int main()
{
    MyStack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;   // - 출력: 30
    cout << "Size: " << s.size() << endl; // - 출력: 3

    while (!s.empty())
    {
        cout << "Pop: " << s.top() << endl;

        s.pop();
    }

    return 0;
}
