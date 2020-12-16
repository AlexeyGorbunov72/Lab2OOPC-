#pragma once
#include <string>
using namespace std;
class Product {
    string name;
    int uid;
    int generateUID(){
        static int staticUid = 0;
        return staticUid++;
    }
public:
    Product(string name);
    bool operator <(const Product& rhs) const{
            return uid < rhs.uid;
    }
    int getUID(){
        return uid;
    }
    string getName() const{
        return name;
    }
};
