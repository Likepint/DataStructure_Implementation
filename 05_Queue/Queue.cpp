#include "Queue.h"

// 테스트 코드
int main()
{
    MyQueue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    std::cout << "Front: " << q.front() << std::endl; // 1
    std::cout << "Back: " << q.back() << std::endl;   // 3

    while (!q.empty())
    {
        std::cout << "Pop: " << q.front() << std::endl;

        q.pop();
    }

    return 0;
}
