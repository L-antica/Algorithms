#include <iostream>
#include <vector>
using namespace std;
//单链表
class NodeList
{
private:
    int value;
    NodeList *next;

public:
    NodeList() : value(0), next(nullptr) {}
    NodeList(int value) : value(value), next(nullptr) {}
    virtual ~NodeList() {}
    void Create(int len)
    {
        if (len <= 0)
            return;
        NodeList *flag = this;
        for (int i = 0; i < len; i++)
        {
            flag->next = new NodeList();
            cin >> flag->next->value;
            flag = flag->next;
        }
    }
    void Print()
    {
        NodeList *flag = this->next;
        if (flag == nullptr)
        {
            cout << "EMPTY NODELIST" << endl;
            return;
        }
        while (flag)
        {
            cout << flag->value;
            flag = flag->next;
        }
        cout << endl;
    }

    //p103 1.3.20删除第k个节点
    bool Delete(int k)
    {

        NodeList *p = new NodeList();
        p = this->next;
        if (k == 1)
        {
            this->next = p->next;
            free(p);
            p = nullptr;
            return true;
        }
        for (int i = 2; i < k; i++)
        {
            p = p->next;
            if (p->next == nullptr)
                return false;
        }
        NodeList *m = p->next;
        p->next = m->next;
        free(m);
        m = nullptr;
        return true;
    }

    //p103 1.3.21 查找
    static bool find(int key, NodeList *head)
    {
        head = head->next;
        while (head)
        {
            if (head->value == key)
            {
                return true;
            }
            head = head->next;
        }
        return false;
    }

    //p103 1.3.24 删除该节点后的所有节点
    static void RemoveAfter(NodeList *head)
    {
        if (head == nullptr || head->next == nullptr)
            return;
        NodeList *p = head->next;
        head->next = nullptr;
        while (p)
        {
            NodeList *m = p;
            p = p->next;
            free(m);
        }
    }

    //p103 1.3.25 在node1节点后插入node2
    static void InsertAfter(NodeList *node1, NodeList *node2)
    {
        if (node1 == nullptr || node2 == nullptr)
            return;
        node2->next = node1->next;
        node1->next = node2;
    }

    //p103 1.3.26 删除链表中所有value的key的节点
    static void Remove(NodeList *head, int key)
    {
        while (head->next)
        {
            if (head->next->value == key)
            {
                NodeList *p = head->next;
                head->next = p->next;
                free(p);
            }
            else
            {
                head = head->next;
            }
        }
    }

    //p103 1.3.27 返回最大值，非递归
    static int Max(NodeList *head)
    {
        int max = 0;
        while (head)
        {
            max = head->value > max ? head->value : max;
            head = head->next;
        }
        return max;
    }

    //p103 1.3.28 返回最大值 递归
    static int MaxRecursion(NodeList *head)
    {
        if (head == nullptr)
            return 0;
        int max = MaxRecursion(head->next);
        return max > head->value ? max : head->value;
    }

    //p103 1.3.30 链表倒置，非递归
    static NodeList *Reverse(NodeList *head)
    {
        NodeList *first = nullptr;
        NodeList *reverse = head->next;
        while (reverse)
        {
            NodeList *second = reverse->next;
            reverse->next = first;
            first = reverse;
            reverse = second;
        }
        head->next = first;
        return head;
    }
    //p103 1.3.30 链表倒置，递归
    static NodeList *ReverseRecursion(NodeList *head)
    {
        if (head->next != nullptr)
        {
            head->next = ReverseHelper(head->next);
        }

        return head;
    }
    static NodeList *ReverseHelper(NodeList *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        if (head->next == nullptr)
        {
            return head;
        }
        NodeList *cur = ReverseHelper(head->next);
        head->next->next = head;
        head->next = nullptr;
        return cur;
    }
};
//单链表测试
void NodeListTest()
{
    NodeList *head = new NodeList();
    head->Create(5);
    head->Print();
    //head->Delete(4);
    //cout << NodeList::find(0, head);
    //NodeList::RemoveAfter(head);
    //NodeList::InsertAfter(head, new NodeList(9));
    //NodeList::Remove(head, 3);
    head->Print();
}
//p104 1.3.32 Steque
class Steque
{
private:
    int value;
    Steque *head;
    Steque *last;
    Steque *next;

public:
    Steque() : head(nullptr), last(nullptr), next(nullptr), value(0)
    {
    }
    Steque(int val) : head(nullptr), last(nullptr), next(nullptr), value(val)
    {
    }
    //建立Steque 输入长度。返回Steque指针
    void Enqueue(int val)
    {
        if (last == nullptr)
        {
            last = new Steque(val);
            head = last;
            last->head = head;
            last->last = last;
        }
        else
        {
            last->next = new Steque(val);
            last->next->head = head;
            last->last = last->next;
            last = last->next;
        }
    }

    void Print()
    {
        Steque *flag = head;
        while (flag)
        {
            cout << flag->value;
            flag = flag->next;
        }
        cout << endl;
    }
};

void StequeTest()
{
    Steque *ste = new Steque();
    ste->Enqueue(1);
    ste->Print();
    ste->Enqueue(2);
    ste->Print();
}

int main()
{
    StequeTest();
    //NodeListTest();
    system("pause");
    return 0;
}