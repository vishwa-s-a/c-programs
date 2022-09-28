// array of objects using pointers
#include<iostream>
using namespace std;
class ShopItem
{
    int id;
    float price;
    public:
        void setData(int a , int b)
        {
            id=a;
            price=b;
        }
        void getData()
        {
            cout<<"Code of this item is "<<id<<endl;
            cout<<"The price of this item is "<<price<<endl;
        }
};
int main()
{
    // shop are
    // 1.general store
    // 2.veggies
    // 3.hardware
    int size=3;
    ShopItem *ptr= new ShopItem[size];
    ShopItem *ptrTemp=ptr;
    int p;
    float q;
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter Id and price of item "<<i+1<<endl;
        cin>>p>>q;
        //(*ptr).setData(p,q);
        ptr->setData(p,q);
        ptr++;
    }
    //here ptr is not in the initial position so we need to use another same pointer
    for (int i = 0; i < size; i++)
    {
        cout<<"Item number: "<<i+1<<endl;
        ptrTemp->getData();
        ptrTemp++;
        
    }
    
    
    return 0;
}
