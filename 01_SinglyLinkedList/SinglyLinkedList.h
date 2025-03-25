#pragma once

#include <iostream>

using namespace std;

// 단일 연결 리스트의 노드 구조체
template <typename T>
struct SNode
{
    T data;         // 노드에 저장할 데이터
    SNode* next;    // 다음 노드를 가리키는 포인터

    // 생성자: 데이터 초기화 및 다음 포인터를 nullptr로 설정
    SNode(T val) : data(val), next(nullptr)
    {
    }
};

// 단일 연결 리스트 클래스
template <typename T>
class SinglyLinkedList
{
private:
    SNode<T>* head;     // 리스트의 첫 번째 노드를 가리키는 포인터

public:
    // 생성자: head를 nullptr로 초기화하여 빈 리스트 생성
    SinglyLinkedList() : head(nullptr)
    {
    }

    // 소멸자: 모든 노드를 삭제하여 메모리 해제
    ~SinglyLinkedList()
    {
        while (head != nullptr)     // head가 nullptr가 될 때까지 반복
        {
            SNode<T>* temp = head;  // 현재 head 노드를 임시로 저장

            head = head->next;      // head를 다음 노드로 이동

            delete temp;            // 저장된 노드 삭제
        }
    }

    // 리스트 끝에 노드 추가
    void append(T data)
    {
        SNode<T>* newNode = new SNode<T>(data); // 새 노드 생성

        if (head == nullptr)                    // 리스트가 비어있으면
        {
            head = newNode;                     // head를 새 노드로 설정

            return;
        }

        SNode<T>* current = head;               // 순회용 포인터

        while (current->next != nullptr)        // 마지막 노드까지 이동
            current = current->next;

        current->next = newNode;                // 마지막 노드의 next를 새 노드로 연결
    }

    // 리스트 처음에 노드 추가
    void prepend(T data)
    {
        SNode<T>* newNode = new SNode<T>(data); // 새 노드 생성

        newNode->next = head;                   // 새 노드의 next를 기존 head로 설정

        head = newNode;                         // head를 새 노드로 업데이트
    }

    // 특정 값의 노드 삭제
    void deleteNode(T data)
    {
        if (head == nullptr) return;            // 리스트가 비어있으면 종료

        if (head->data == data)                 // head 노드가 삭제 대상이면
        {
            SNode<T>* temp = head;              // head를 임시 저장

            head = head->next;                  // head를 다음 노드로 이동

            delete temp;                        // 저장된 노드 삭제

            return;
        }

        SNode<T>* current = head;               // 순회용 포인터

        while (current->next != nullptr and current->next->data != data) // 삭제 대상 탐색
            current = current->next;

        if (current->next != nullptr)           // 삭제 대상이 존재하면
        {
            SNode<T>* temp = current->next;     // 삭제할 노드를 임시 저장

            current->next = temp->next;         // 다음 노드로 연결

            delete temp;                        // 노드 삭제
        }
    }

    // 리스트 출력
    void printList()
    {
        SNode<T>* current = head;               // 순회용 포인터

        while (current != nullptr)              // 리스트 끝까지 순회
        {
            cout << current->data << " -> ";    // 현재 노드 데이터 출력

            current = current->next;            // 다음 노드로 이동
        }

        cout << "nullptr" << endl;              // 끝 표시
    }
};
