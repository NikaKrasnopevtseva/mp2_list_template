#include "list.h"
#include <iostream>

using namespace std;
int main() {
    List<int> list;
    cout << "Created empty list? - " << list.isEmpty() << endl;
    list.InsertToTail(1);
    cout << "ViewHead -" << list.ViewHead() << endl;
    cout << "Which element does insert to tail? - " << list.ViewTail() << endl;
    list.InsertToTail(2);
    cout << "Which element does insert to tail? - " << list.ViewTail() << endl;
    list.InsertToTail(3);
    cout << "Which element does insert to tail? - " << list.ViewTail() << endl;
    cout << "list - " << list << endl;
    list.Delete(2);
    cout << "list after delete 2 - " << list << endl;
    cout << "Size? -" << list.GetSize() << endl;
    List<int> list2(4);
    cout << "Created empty list? - " << list2.isEmpty() << endl;
    cout << "Which element does exist in list2? - " << list2.ViewTail() << endl;
    cout << "list == list2? - " << (list == list2) << endl;
    cout << "list != list2? - " << (list != list2) << endl;
    list.Delete(3);
    list.Delete(1);
    list.InsertToTail(4);
    cout << "list == list2? - " << (list == list2) << endl;
    List<int> list3(4); list3.InsertToTail(4); list3.InsertToTail(1); list3.InsertToTail(3);
    cout << "list3 - " << list3 << endl;
    List<int> list4;
    list4 = list3;
    cout << "list4 - " << list4 << endl; // 4 4 1 3
    list3.Clean();
    cout << "Clean list3? - " << list3.isEmpty() << endl;
    list4.InsertToTail(4); list4.InsertToTail(2); list4.InsertToTail(5);
    cout << "list4 - " << list4 << endl; // 4 1 3 4 2 5
    list4.DeleteAll(4);
    cout << "list4 after deleteAll 4 - " << list4 << endl; // 1 3 2 5
    list4.Inverse();
    cout << "list4 after inverse - " << list4 << endl; // 5 2 3 1
    list4.InsertToHead(10);
    cout << "list4 after InsertToHead(10) - " << list4 << endl; //10 5 2 3 1
    List<int> list4copy(list4);
    cout << "list4copy - " << list4copy << endl; // 10 5 2 3 1
    cout << list4copy.ToString() << endl;
    List<int> s = (list4copy.Merge(list4));
    cout << "Merge list4copy and list4 - " << s << endl; // 10 5 2 3 1 10 5 2 3 1
    s.InsertToHead(10); s.InsertToTail(1); // 10 10 5 2 3 1 10 5 2 3 1 1
    s.MadeUnique();
    cout << "Merge list4copy and list4 made unique - " << s << endl; // 10 5 2 3 1
    s.InsertAfter(s.begin(), 100);
    cout << "Insert 100 after 10 - " << s << endl; // 10 100 5 2 3 1
    List<int> l1(1);
    l1.InsertToTail(2);
    l1.InsertToTail(3);
    l1.InsertToTail(4);
    l1.InsertToTail(5);
    cout << "l1 " << l1 << endl;
    List<int> l2(1);
    l2.InsertToTail(5);
    l1.Delete(l1.Search(1), l1.Search(4));
    cout << "Delete from 1 to 4 - " << l1 << endl;
    l1.Clean();
    l1.InsertToTail(1);
    l1.InsertToTail(5);
    l1.InsertToTail(6);
    l2.Clean();
    l2.InsertToTail(2);
    l2.InsertToTail(3);
    l2.InsertToTail(4);
    List<int> l3 = l1.Merge(l1.begin(), l2);
    cout << "Merge l1 and l2 from 1 - " << l3 << endl;
    l1.MergeWith(l1.begin(), l2);
    cout << "Merge l1 and l2 from 1 - " << l1 << endl;
    return 0;
}