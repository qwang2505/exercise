#include "LinkedList.h"

#include <iostream>

using namespace std;

LinkedList::LinkedList(DestroyFunc func)
{
    this->_size = 0;
    this->_head = NULL;
    this->_tail = NULL;
    this->_destroy = func;
}

LinkedList::~LinkedList()
{
    ListNode* node = this->_head;
    ListNode* next = NULL;
    while (node != NULL)
    {
        next = node->next;
        void* data = node->data;
        if (this->_destroy)
        {
            this->_destroy(data);
        }
        delete node;
        node = next;
    }
    this->_size = 0;
    this->_head = NULL;
    this->_tail = NULL;
}

/**
 * 在指定节点之后插入一个节点。如果指定节点为NULL，则将新节点插入到链表尾部
 */
bool LinkedList::insert(ListNode* node, void* data)
{
    ListNode* n = new ListNode();
    n->data = data;

    // 如果节点为空，插入到尾部
    if (node == NULL)
    {
        node = this->_tail;
    }
    // 空链表，插入节点，更新头/尾指针
    if (node == NULL)
    {
        this->_head = n;
        this->_tail = n;
        this->_size++;
        return true;
    }
    ListNode* next = node->next;
    if (next == NULL)
    {
        node->next = n;
        this->_tail = n;
        this->_size++;
    }
    else
    {
        node->next = n;
        n->next = next;
        this->_size++;
    }
    return true;
}

/**
 * 删除指定节点的下一个节点，并将其数据放在data中。返回值：
 * -1: 删除失败
 * 0: 删除成功
 * 1: 节点不存在
 */
int LinkedList::removeNext(ListNode* node, void** data)
{
    ListNode* next = node->next;
    if (next == NULL)
    {
        return 1;
    }
    ListNode* next2 = next->next;
    next->next = NULL;
    *data = next->data;
    node->next = next2;
    if (node->next == NULL)
    {
        this->_tail = node;
    }
    delete next;
    next = NULL;
    this->_size--;
    return 0;
}

int LinkedList::size()
{
    return this->_size;
}

ListNode* LinkedList::head()
{
    return this->_head;
}

ListNode* LinkedList::tail()
{
    return this->_tail;
}

bool LinkedList::isHead(ListNode* node)
{
    return this->_head == node;
}

bool LinkedList::isTail(ListNode* node)
{
    return this->_tail == node;
}

void* LinkedList::data(ListNode* node)
{
    return node->data;
}

int main(int argc, char** argv)
{
    LinkedList* list = new LinkedList(NULL);
    cout << "size: " << list->size() << endl;
    list->insert(NULL, (void*)"first data");
    cout << "size: " << list->size() << endl;
    ListNode* head = list->head();
    cout << (char*)head->data << endl;
    ListNode* tail = list->tail();
    cout << (char*)tail->data << endl;

    list->insert(head, (void*)"second data");
    cout << "size: " << list->size() << endl;
    tail = list->tail();
    cout << "tail: " << (char*)tail->data << endl;

    list->insert(head, (void*)"third data");
    cout << "size: " << list->size() << endl;
    head = list->head();
    cout << "head: " << (char*)head->data << endl;
    tail = list->tail();
    cout << "tail: " << (char*)list->data(tail) << endl;

    ListNode* temp = list->head();
    cout << endl << "datas: " << endl;
    while (temp != NULL)
    {
        cout << (char*)list->data(temp) << "->";
        temp = temp->next;
    }
    cout << endl << endl;

    cout << "is head, should be true: " << list->isHead(head) << endl;
    cout << "is tail, should be false: " << list->isTail(head) << endl;
    cout << "is tail, should be true: " << list->isTail(tail) << endl;

    cout << endl;
    void* data = NULL;
    cout << "remove head next: " << list->removeNext(list->head(), &data) << endl;
    cout << "removed data: " << (char*)data << endl;
    cout << "size: " << list->size() << endl;
    cout << "head data: " << (char*)list->head()->data << endl;
    cout << "tail data: " << (char*)list->tail()->data << endl;

    cout << endl;
    list->insert(head, (void*)"third data");
    cout << "size: " << list->size() << endl;
    head = list->head();
    cout << "head: " << (char*)head->data << endl;
    tail = list->tail();
    cout << "tail: " << (char*)list->data(tail) << endl;

    cout << "remove tail: " << list->removeNext(list->head()->next, &data) << endl;
    cout << "removed data: " << (char*)data << endl;
    cout << "size: " << list->size() << endl;
    cout << "head data: " << (char*)list->head()->data << endl;
    cout << "tail data: " << (char*)list->tail()->data << endl;

    cout << endl;
    cout << "list address: " << list << endl;
    delete list;
    list = NULL;
    cout << "list address after delete: " << list << endl;
}
