#ifndef __ITEM__
#define __ITEM__
class Item
{
private:
    int item[3];
    int time;

public:
    Item(int value);
    void resetItem(int value);
    int getX();
    int getY();
    int getValue();
    int getTime();
    void upTime();
};
#endif
