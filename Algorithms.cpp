#include "Sort.cpp"
#include <vector>

template <typename Item>
//单链表
class NodeList
{
private:
    Item value;

public:
    NodeList *next;
    NodeList() : value(0), next(nullptr) {}
    NodeList(Item value) : value(value), next(nullptr) {}
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
    static bool find(Item key, NodeList *head)
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
    static void Remove(NodeList *head, Item key)
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
        Item max = 0;
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
        Item max = MaxRecursion(head->next);
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
//单链表的测试函数
void NodeListTest()
{
    NodeList<char> *head = new NodeList<char>();
    head->Create(5);
    head->Print();
    // head->Delete(4);
    // head->Print();
    // cout << NodeList<char>::find(0, head);
    // NodeList<char>::RemoveAfter(head);
    head->Print();
    NodeList<char>::InsertAfter(head->next->next, new NodeList<char>('4'));
    head->Print();
    // NodeList<char>::Remove(head, 3);
    // head->Print();
}
//p104 1.3.32 Steque
template <typename Item>
class Steque
{
private:
    Item value;
    Steque *head;
    Steque *last;
    Steque *next;

public:
    Steque() : head(nullptr), last(nullptr), next(nullptr), value(0)
    {
    }
    Steque(Item val) : head(nullptr), last(nullptr), next(nullptr), value(val)
    {
    }

    //在Steque末尾插入
    void Enqueue(Item val)
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
            last = last->next;
        }
    }

    //在Steque头部插入
    void Push(Item val)
    {
        if (head == nullptr)
        {
            head = new Steque(val);
            last = head;
            last->head = head;
            last->last = last;
        }
        else
        {
            Steque *p = new Steque(val);
            p->next = head;
            head = p;
        }
    }
    //弹出Steque头部
    int Pop()
    {
        if (head == nullptr)
        {
            return 0;
        }
        else
        {
            Item num = head->value;
            head = head->next;
            return num;
        }
    }

    void Print()
    {
        Steque *flag = head;
        while (flag)
        {
            cout << flag->value << " ";
            flag = flag->next;
        }
        cout << endl;
    }
};
//Steque的测试函数
void StequeTest()
{
    Steque<double> *ste = new Steque<double>();
    ste->Enqueue(1.1);
    ste->Print();
    ste->Enqueue(2.2);
    ste->Print();

    ste->Enqueue(2.3);
    ste->Print();
    cout << ste->Pop() << endl;
    ste->Print();
    ste->Push(3.4);
    ste->Print();
    ste->Push(5.5);
    ste->Print();
    cout << ste->Pop() << endl;
    ste->Print();
}

int main()
{
    //StequeTest();
    //NodeListTest();

    vector<int> a = {3, 4, 1, 2, 5, 8, 6, 3, 7, 3, 5, 1, 9};
    Shell(a);
    show(a);
    system("pause");
    return 0;
}