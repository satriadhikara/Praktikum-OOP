#include "Item.hpp"

#include <iostream>
using namespace std;

int Item::totalItems = 0;
int Item::totalRevenue = 0;

Item::Item() : serialNum(totalItems + 1)
{
    this->stock = 0;
    this->price = 0;
    this->sold = 0;
    totalItems += 1;
}

Item::Item(int stock, int price) : serialNum(totalItems + 1)
{
    this->stock = stock;
    this->price = price;
    this->sold = 0;
    totalItems += 1;
}

Item::Item(const Item &other) : serialNum(totalItems + 1)
{
    this->stock = other.stock;
    this->price = other.price;
    this->sold = other.sold;
    totalItems += 1;
}

Item::~Item() {}

int Item::getSerialNum() const
{
    return serialNum;
}

int Item::getSold() const
{
    return sold;
}

int Item::getPrice() const
{
    return price;
}

void Item::addStock(int addedStock)
{
    stock += addedStock;
}

void Item::sell(int soldStock)
{
    if (soldStock > stock)
    {
        totalRevenue += (stock * price);
        sold += stock;
        stock = 0;
    }
    else
    {
        stock -= soldStock;
        totalRevenue += (soldStock * price);
        sold += soldStock;
    }
}

void Item::setPrice(int newPrice)
{
    price = newPrice;
}