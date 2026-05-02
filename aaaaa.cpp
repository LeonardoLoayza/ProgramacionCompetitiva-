
#include <iostream>
struct CNode
{
    CNode(int v)
    {   value = v; next = 0;    }
    int value;
    CNode* next;
};


template<class C> 
struct Asc{
	bool operator()(C a, C b){
		return a < b; 
	}
};
template<class C> 
struct Desc {
	bool operator()(C a, C b) {
		return a > b; 
	}
};

template <class T, class C>
class CSortedList
{
	
public:
	
    CSortedList();
    bool find(C x, CNode**& p);
    bool ins(C x);
    bool rem(C x);
    void print();
	T cmp; 
private:
    CNode* head;
};



template <class T, class C>
CSortedList<T,C>::CSortedList()
{   head = 0;   }


template <class T, class C>
bool CSortedList<T,C>::find(C x, CNode**& p)
{
    p = &head;
    while( *p && cmp((*p)->value, x))
        p = &( (*p)->next );
    return *p && (*p)->value == x;
}


template <class T, class C>
bool CSortedList<T,C>::ins(C x)
{
    CNode** p;
    if ( find(x, p) ) return 0;
    CNode* t = new CNode(x);
    t->next = *p;
    *p = t;
    return 1;
}

template <class T, class C>
bool CSortedList<T,C>::rem(C x)
{
    CNode** p;
    if ( !find(x, p) ) return 0;
    CNode* t = *p;
    *p = t->next;
    delete t;
    return 1;
}

template <class T, class C>
void CSortedList<T, C>::print()
{
    for ( CNode* t = head; t; t = t->next )
        std::cout<< t->value << " ";
    std::cout<<"\n";
}

int main()
{
	Asc<int> a;
	Desc<int> b;
	
    CSortedList<Asc<int>  , int> l;
    l.ins(3); l.ins(14); l.ins(7); l.ins(11);
    l.print();

    
}
