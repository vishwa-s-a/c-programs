// list in c++
// list is a bidirectional linear list which shows efficient operations in insertion and deletion 
// of elements in the list when compared to array
// refer list reference materials from cplusplus website
#include<iostream>
#include<list>

using namespace std;
void display(list<int> &l)
{
    list<int>::iterator it;// creating a iterator for accessing elements of a list
    for (it=l.begin();it!=l.end(); it++)// here the end() gives reference of end of the list
    {
       cout<<*it<<" ";
    }
    cout<<endl;

}

int main()
{   
    list<int>list1;// list of 0 length
    list1.push_back(5);
    list1.push_back(7);
    list1.push_back(1);
    list1.push_back(9);
    list1.push_back(12);

    // list<int>::iterator iter;//creation of iterator
    // iter=list1.begin();// here the iterator is pointed to first element
    // cout<<*iter<<endl;
    // iter++;
    // cout<<*iter;

    display(list1);

    /* METHODS TO REMOVE THE ELEMENT FROM THE LIST
    removing elements from the list
    list1.pop_back();// removes the last element
    display(list1);
    list1.pop_front();// removes the first element in the list
    display(list1);
    to remove the element from the middle of the list
    list1.remove(9);// removes the 9 element
    display(list1);
    */

   /*
   // sorting the list 
   list1.sort();
   display(list1);
    */


    list<int>list2(3);//empty list of size 3
    list<int>::iterator iter;
    iter=list2.begin();
    *iter=45;
    iter++;
    *iter=6;
    iter++;
    *iter=9;
    display(list2);

    //merging of list
    list1.merge(list2);
    cout<<"list1 After merging\n";
    list1.sort();
    display(list1);

    //reversing the list
    list1.reverse();
    display(list1); 

    return 0;
}