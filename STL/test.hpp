#include <iostream>
#include <assert.h>
using namespace std;
// list容器的实现
namespace key
{

    template <class T>
    struct list_node
    {
        list_node<T> *next;
        list_node<T> *prev;
        T data;

        list_node(const T &x = T()) : next(nullptr), prev(nullptr), data(x) {}
    };

    template <class T, class Ref = T &, class Ptr = T *>
    struct _list_iterator
    {
        typedef list_node<T> node;
        typedef _list_iterator<T, Ref, Ptr> self;
        node *_node;

        _list_iterator(node *n) : _node(n) {}

        Ref operator*()
        {
            return _node->data;
        }

        Ptr operator->()
        {
            return &_node->data;
        }

        self &operator++()
        {
            _node = _node->next;
            return *this;
        }

        self operator++(int)
        {
            self tmp(*this);
            _node = _node->next;
            return tmp;
        }

        self &operator--()
        {
            _node = _node->prev;
            return *this;
        }

        self operator--(int)
        {
            self tmp(*this);
            _node = _node->prev;
            return tmp;
        }

        bool operator!=(const self &s)
        {
            return _node != s._node;
        }

        bool operator==(const self &s)
        {
            return _node == s._node;
        }
    };

    template <class T>
    class list
    {
        typedef list_node<T> node;

    public:
        // 非常量迭代器
        typedef _list_iterator<T, T &, T *> iterator;
        typedef _list_iterator<T, const T &, const T *> const_iterator; // 常迭代器

        iterator begin()
        {
            return iterator(_head->next);
        }

        //  防止权限扩大
        const_iterator begin() const
        {
            return const_iterator(_head->next);
        }

        iterator end()
        {
            return iterator(_head);
        }

        const_iterator end() const
        {
            return const_iterator(_head);
        }

        // 构造函数
        list()
        {
            _head = new node;
            _head->next = _head;
            _head->prev = _head;
        }

        // 插入  复用
        void insert(iterator pos, const T &s)
        {

            node *cur = pos._node;
            node *prev = cur->prev;

            node *new_node = new node(s);

            prev->next = new_node;
            new_node->prev = prev;
            new_node->next = cur;
            cur->prev = new_node;
        }

        void push_back(const T &s)
        {
            insert(end(), s);
        }

        void push_front(const T &s)
        {
            insert(begin(), s);
        }

        void pop_back()
        {
            erase(--end());
        }

        // 复用
        void erase(iterator pos)
        {
            assert(pos != end());

            node *prev = pos._node->prev;
            node *next = pos._node->next;

            prev->next = next;
            next->prev = prev;
            delete pos._node;
        }
        void pop_front()
        {
            erase(begin());
        }

    private:
        node *_head;
    };
    void print_list(const list<int> &lt);
} // namespace key
