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
    auto sperm = shopManager.findChippestPriceForListProducts(products);
    auto ochko = shopManager.calculateProducts(shop2, 10);
    shopManager.buyProduct(shop2, p1);
    auto ochko1 = shopManager.calculateProducts(shop2, 100);
    return 0;
}
