//
// Created by lhq46 on 2019/3/29.
//

#include "std.h"

void print_vector(std::vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
