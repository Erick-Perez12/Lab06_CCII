#include <iostream>
#include "LinkedList.h"
#include "Node.h"

int main() {
    LinkedList<string> l1;
    l1.pushBack("man");
    l1.pushBack("za");
    l1.pushBack("ni");
    l1.pushBack("ta");
    l1.print();
    cout<<endl;

    LinkedList<char> l2;
    l2.pushBack('h');
    l2.pushBack('o');
    l2.pushBack('l');
    l2.pushBack('a');
    l2.print();
    cout<<endl;

    LinkedList<int> l3;
    l3.pushBack(1);
    l3.pushBack(12);
    l3.pushBack(42);
    l3.pushBack(32);
    l3.print();
    cout<<endl;

    l1.insert_pos("ta",1);
    l1.popBack();
    l1.popFront();
    l1.pushFront("ok");
    l1.insert_pos("ma",2);

    l2.insert_pos('c',1);//01=ogef  2=oegf
    l2.popBack();
    l2.popFront();
    l2.insert_pos('e',3);

    l3.insert_pos(3,3);//01=ogef  2=oegf
    l3.popBack();
    l3.popFront();
    l3.insert_pos(15,2);

    LinkedList<int> l4;
    l4.pushBack(1);
    l4.pushBack(12);
    l4.pushBack(42);
    l4.pushBack(32);
    l4.pushFront(14);
    l4.popBack();
    l4.delete_pos(3);
    cout<<l4<<endl;

    for (Iterator2<string> it=l1.begin();it!=l1.end();it++){
        std::cout<<"("<<*it<<")";
    }
    cout<<endl;

    for (Iterator2<char> it=l2.begin();it!=l2.end();it++){
    std::cout<<"("<<*it<<")";
    }
    cout<<endl;

    for (Iterator2<int> it=l3.begin();it!=l3.end();it++){
        std::cout<<"("<<*it<<")";
    }
    cout<<endl;

    LinkedList<int> l5 = l3;
    cout<<l5<<endl;

    /*LinkedList<int> l6;
    l6=std::move(l4);
    cout<<l6<<endl;*/

    /*Iterator2<int> it=l3.begin();
    cout<<"b:"<<*(it++)<<endl;
    cout<<*(++it)<<endl;*/

    //cout<<l1<<endl;


    /*
    //l1.popBack();
    //l1.print();
	*/
    return 0;
}