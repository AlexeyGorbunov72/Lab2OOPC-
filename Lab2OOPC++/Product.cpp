//
//  Product.cpp
//  Lab2OOPC++
//
//  Created by Alexey on 16.12.2020.
//
#include <stdio.h>
#include "Product.h"
Product::Product(string name){
    uid = generateUID();
    this->name = name;
}

