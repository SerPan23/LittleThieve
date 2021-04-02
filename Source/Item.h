#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

class Item{
public:
    int x;
    int y;
    int width;
    int height;

    Item(int x, int y, int width, int height){
        x = x;
        y = y;
        width = width;
        height = height;
    }

    virtual void event() = 0;

};


class Candy:public Item{
    void event() override {
        cout << "Candy";
    }
};


#endif // ITEM_H_INCLUDED
