/*
JTSK-320112
a3 p4.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

struct linked_list{
    int val;
    struct linked_list *next;
};
struct linked_list* push_back(struct linked_list *myll, int val);
struct linked_list* push_front(struct linked_list *myll, int val);
struct linked_list* pop_front(struct linked_list *myll);
struct linked_list* dispose_linked_list(struct linked_list *myll);
void print_linked_list(struct linked_list *myll);