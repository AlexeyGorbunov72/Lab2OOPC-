#include <iostream>
#include "ShopManager.cpp"
int main(int argc, const char * argv[]) {
    ShopManager shopManager;
    int shop = shopManager.createShop("shop21");
    int shop2 = shopManager.createShop("shop90fj");
    vector<Product> products;
    Product p1("some");
    Product p2("shit");
    Product p3("fuck");
    products.push_back(p1);
    products.push_back(p2);
    products.push_back(p3);
    vector<double> prices;
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    shopManager.putGoodsToShopWithUID(shop2, products, prices);
    shopManager.setPriceOfProduct(shop2, p3, 100);
    shopManager.putGoodsToShopWithUID(shop, products, prices);
    cout << shopManager.buyProducts(shop, products);
    auto result1 = shopManager.findChippestPriceForListProducts(products);
    cout << "uid chippest shop is: " << result1.first << endl;
    cout << "price: " << result1.second << endl;
    auto result2 = shopManager.calculateProducts(shop2, 10);
    for(auto &p: result2){
        cout << p.first.getName() << " count: " << p.second << endl;
    }
    shopManager.buyProduct(shop2, p1);
    cout << "- -- - - - - - - - " << endl;
    auto result3 = shopManager.calculateProducts(shop2, 100);
    for(auto &p: result3){
        cout << p.first.getName() << " count: " << p.second << endl;
    }
    return 0;
}
