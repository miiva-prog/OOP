#include <iostream>
#include <string.h>

using namespace std;

struct node{
    int value;
    node *next;
};

class list{
    protected:
        node *head = nullptr;

    public:
        virtual void create(int value)
        {
            head = new node;

            if(head != nullptr){
                head->value = value;
                head->next = nullptr;
            }else{
                return;
            }
        }

        virtual void add(int value)
        {
            node *li = new node;

            if(li != nullptr){
                li->value = value;
                li->next = nullptr;
            }
            
            if(head == nullptr){
                head = li;
            }else{
                node *cur = head;

                while(cur->next != nullptr)
                    cur = cur->next;
                    
                cur->next = li;   
            }
        }

        virtual node* lookup(int value)
        {
            if(head == nullptr)
                return nullptr;

            node *li = head;

            while(li->next != nullptr){
                if(li->value == value)
                    return li;

                li = li->next;
            }

            return nullptr;
        }

        void delete_node_list(int value)
        {
            node *li = lookup(value);
            node *li2;  
            
            while(li->next != nullptr){
                li->value = li->next->value;
                li2 = li;
                li = li->next;
            }

            li2->next = nullptr;

            delete li2->next;
        }

        virtual void delete_all()
        {
            while(head->next != nullptr){
                delete head;
                head = head->next;
            }
        }

        virtual void print()
        {
            node *li = head;

            while(li != nullptr){
                cout << li->value << endl;
                li = li->next;
            }
        }  
};

class stack:public list{
    public:
        void create(int value) override
        {
            head = new node;

            if(head != nullptr){
                head->next = nullptr;
                head->value = value;
            }else{
                return;
            }
        };

        void add(int value) override
        {
            node *stack = new node;

            stack->value = value;
            stack->next = head;
            head = stack;
        }

        node* lookup(int value) override
        {
            node *stack = head;

            while(stack->next != nullptr){
                if(stack->value != value)
                    return stack;

                stack = stack->next;
            }

            return nullptr;
        }

        void delete_node_stack()
        {
            node *stack = head;

            head = head->next;

            delete stack;
        };

        node* extract_stack()
        {
            node* stack = head;

            head = head->next;

            return stack;
        }

        void delete_all() override
        {
            while(head->next != nullptr){
                delete head;
                head = head->next;
            }
        }

        node* get_stack()
        {
            return head;
        }

        void print() override
        {
            node *stack = head;

            while(stack != nullptr){
                cout << stack->value << endl;
                stack = stack->next;
            }
        }
};

class queue:public list{
    public:
        void create(int value) override
        {
            head = new node;
            
            if(head != nullptr){
                head->value = value;
                head->next = nullptr;
            }else{
                return;
            }
        };

        void add(int value) override
        {
            node *queue = new node;

            if(queue == nullptr)
                return;

            queue->value = value;
            queue->next = head;
            head = queue;
        }

        node* lookup(int value)
        {
            node* queue = head;

            while(queue->next != nullptr){
                if(queue->value == value)
                    return queue;
                
                queue = queue->next;
            }

            return nullptr;
        }

        void delete_node_queue()
        {
            node *queue = head;

            head = head->next;

            delete queue;
        }

        node* extract_queue()
        {
            node *queue = head;

            head = head->next;

            return queue;
        }

        void print_queue()
        {
            node *queue = head;

            while(queue != nullptr){
                cout << queue->value << '\n';
                queue = queue->next;
            }
        }
};

int main()
{
    list lis;

    cout << "List\n";

    lis.create(5);
    lis.add(10);
    lis.add(15);
    lis.add(20);
    lis.add(25);
    lis.add(30);
    lis.add(35);
    lis.print();

    cout << "======================\n";

    lis.delete_node_list(15);
    lis.print();

    cout << "======================\n";
    
    lis.delete_node_list(25);
    lis.print();

    cout << "\nQueue\n";

    queue qu;

    qu.create(5);
    qu.add(10);
    qu.add(15);
    qu.delete_node_queue();
    qu.add(20);
    qu.add(25);
    qu.print_queue();

    cout << "\nStack\n";

    stack st;

    st.create(5);
    st.add(10);
    st.add(15);
    st.add(20);
    st.add(25);
    st.delete_node_stack();
    st.add(30);
    st.print();

    return 0;
}