#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

struct ListNode
{
    void* data;
    ListNode* next;
};

typedef void (*DestroyFunc)(void*);

class LinkedList
{
    public:
        LinkedList(DestroyFunc func);
        ~LinkedList();
        bool insert(ListNode* node, void* data);
        int removeNext(ListNode* node, void** data);
        int size();
        ListNode* head();
        ListNode* tail();
        bool isHead(ListNode* node);
        bool isTail(ListNode* node);
        void* data(ListNode* node);
    private:
        int _size;
        ListNode* _head;
        ListNode* _tail;
        DestroyFunc _destroy;
};

#endif
