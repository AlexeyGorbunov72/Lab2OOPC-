//
//  Shop.cpp
//  Lab2OOPC++
//
//  Created by Alexey on 16.12.2020.
//

#include <stdio.h>
#include "Shop.h"
#include "Product.h"
#include <vector>
#include "ProductInfoInStore.h"
#include <float.h>
using namespace std;
Shop::Shop(int uid) {
    this->uid = uid;
}
void Shop::deliveryGoods(vector<Product> products, vector<double> prices) {
    for(int i = 0; i < products.size(); i++){
        if(!validate(products[i])){
            ProductInfoInStore info;
            info.count = 1;
            info.price = prices[i];
            store[products[i]] = info;
            continue;
        }
        store[products[i]].count++;
    }
}

map<Product, int> Shop::calculateProducts(double money) {
    map<Product, int> totalBill;
    for (std::map<Product, ProductInfoInStore>::iterator it = store.begin(); it!=store.end(); ++it){
        Product product = it->first;
        ProductInfoInStore info = it->second;
        if(info.count > 0){
            if(info.price == 0){
                totalBill[product] = info.count;
                continue;
            }
            int potencialCount = money / info.price;
            if(potencialCount > info.count){
                totalBill[product] = info.count;
            } else {
                totalBill[product] = potencialCount;
            }
        } else {
            totalBill[product] = 0;
        }
    }
    return totalBill;
}

double Shop::buyProducts(vector<Product> products){
    double cost = 0;
    for(int i = 0; i < products.size(); i++){
        Product product = products[i];
        cost += buyProduct(product);
    }
    return cost;
}

double Shop::buyProduct(Product product){
    double cost = 0;
    if(validate(product)){
        if(store[product].count > 0){
            store[product].count--;
            cost += store[product].price;
        }
    }
    return cost;
}

double Shop::getCostOfProduct(Product product){
    if(validate(product)){
        if(store[product].count > 0){
            return store[product].price;
        }
    }
    return DBL_MAX;
}
double Shop::getCostOfList(vector<Product> products){
    double totalBill = 0;
    for(int i = 0; i < products.size(); i++){
        totalBill += getCostOfProduct(products[i]);
    }
    return totalBill;
}
void Shop::setPriceOfProduct(double price, Product product){
    if(validate(product)){
        store[product].price = price;
    }
}
