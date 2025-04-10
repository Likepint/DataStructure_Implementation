#include <iostream>

using namespace std;

// Node 구조체 정의
template <typename T>
struct Node
{
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

// Queue 클래스 정의
template <typename T>
class MyQueue
{
private:
    Node<T>* frontNode; // 큐의 앞쪽 (pop 대상)

    Node<T>* rearNode;  // 큐의 뒤쪽 (push 대상)

    int count;          // 큐의 크기

public:
    MyQueue() : frontNode(nullptr), rearNode(nullptr), count(0) {}

    ~MyQueue()
    {
        while (!empty())
            pop();
    }

    // 큐에 원소 추가
    void push(T val)
    {
        Node<T>* newNode = new Node<T>(val);

        if (empty())
            frontNode = rearNode = newNode;
        else
        {
            rearNode->next = newNode;
            rearNode = newNode;
        }

        count++;
    }

    // 큐에서 원소 제거
    void pop()
    {
        if (empty()) return;

        Node<T>* temp = frontNode;

        frontNode = frontNode->next;

        delete temp;

        count--;

        if (frontNode == nullptr)
            rearNode = nullptr;
    }

    // 맨 앞 원소 반환
    T front() const
    {
        if (empty())
            throw std::runtime_error("Queue is empty!");

        return frontNode->data;
    }

    // 맨 뒤 원소 반환
    T back() const
    {
        if (empty())
            throw std::runtime_error("Queue is empty!");

        return rearNode->data;
    }

    // 큐가 비었는지 확인
    bool empty() const
    {
        return count == 0;
    }

    // 큐의 크기 반환
    int size() const
    {
        return count;
    }

};
