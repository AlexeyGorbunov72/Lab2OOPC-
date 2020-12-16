
#pragma once
#include <vector>
#include <iostream>
#include "Product.h"
#include <map>
#include "ProductInfoInStore.h"


class Shop {
    map<Product, ProductInfoInStore > store;
    int uid;
    string name;
public:
    bool validate(Product product){
        if(store.find(product) == store.end()){
            return false;
        }
        return true;
    }
    Shop(int uid, string name);
    void deliveryGoods(vector<Product> products, vector<double> prices);
    map<Product, int> calculateProducts(double money);
    double buyProducts(vector<Product > products);
    double getCostOfList(vector<Product > products);
    double buyProduct(Product product);
    double getCostOfProduct(Product product);
    void setPriceOfProduct(double price, Product product);
};

