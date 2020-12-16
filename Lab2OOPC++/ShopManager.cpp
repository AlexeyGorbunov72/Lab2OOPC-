
#include <stdio.h>
#include <vector>
#include "Shop.h"
#include <map>
#include <float.h>
using namespace std;
class ShopManager{
    map<int, Shop*> shops;
    int shopsUIDCounter = 0;
    bool validate(int shopUID){
        if(shops.find(shopUID) == shops.end()){
            cout << "this uid unexists" << endl;
            return false;
        }
        return true;
    }
public:
    ShopManager(){}
    int createShop(){ // return uid
        shopsUIDCounter++;
        shops[shopsUIDCounter] = new Shop(shopsUIDCounter);
        return shopsUIDCounter;
    }
    void putGoodsToShopWithUID(int shopUID, vector<Product> products, vector<double> prices){
        if(!validate(shopUID)){
            return;
        }
        shops[shopUID]->deliveryGoods(products, prices);
        
    }
    float buyProducts(int shopUID, vector<Product> products){
        if(!validate(shopUID)){
            return -1;
        }
        return shops[shopUID]->buyProducts(products);
    }
    map<Product, int> calculateProducts(int shopUID, double money){
        if(!validate(shopUID)){
            map<Product, int> emptyResponse;
            return emptyResponse;
        }
        return shops[shopUID]->calculateProducts(money);
    }
    pair<int, double> findChippestPriceForProduct(Product product){
        double minPrice = DBL_MAX;
        double shopUID = 0;
        for (std::map<int, Shop*>::iterator it = shops.begin(); it!=shops.end(); ++it){
            double cost = it->second->getCostOfProduct(product);
            if(minPrice > cost){
                minPrice = cost;
                shopUID = it->first;
            }
        }
        return make_pair(shopUID, minPrice);
    }
    double buyProduct(int shopUID, Product product){
        return shops[shopUID]->buyProduct(product);
    }
    pair<int, double> findChippestPriceForListProducts(vector<Product> products){
        double minPrice = DBL_MAX;
        double shopUID = 0;
        for (std::map<int, Shop*>::iterator it = shops.begin(); it!=shops.end(); ++it){
            double cost = it->second->getCostOfList(products);
            if(minPrice > cost){
                minPrice = cost;
                shopUID = it->first;
            }
        }
        return make_pair(shopUID, minPrice);
    }
    void setPriceOfProduct(int shopUID, Product product, double price){
        if(validate(shopUID)){
            shops[shopUID]->setPriceOfProduct(price, product);
        }
    }
};
