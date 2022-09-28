#include <iostream>
#include <string>
using namespace std;
class Shop
{
    int itemprice[100];
    int itemid[100];
    int counter=0;

public:
    void initcounter(void)
    {
        counter = 0;
    }
    void setPrice(void);
    void displayPrice(void);
};
void Shop::setPrice(void)
{
    cout << "Enter the id of your item number " << counter + 1 << endl;
    cin >> itemid[counter];
    cout << "Enter the price of the item" << endl;
    cin >> itemprice[counter];
    counter++;
}
void Shop::displayPrice(void)
{
    for (int i = 0; i < counter; i++)
    {
        cout << "The price of item with id "<< itemid[i] << " is " << itemprice[i] << endl;
    }
}
int main()
{
    Shop hari;
    //hari.initcounter();
    hari.setPrice();
    hari.setPrice();
    hari.setPrice(); 
    hari.displayPrice();
    return 0;
}