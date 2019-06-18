//
// Created by Sanfuh on 2019/6/12.
//

#ifndef ALGORITHM_OFFER38_H
#define ALGORITHM_OFFER38_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Offer38 {

public:
    int GetNumberOfK(vector<int> data ,int k) {

        int left, right, mid;
        int first_k, last_k;

        left = 0;
        right = data.size() - 1;
        mid = (left + right)/2;

        first_k = -1;
        while(left <= right) {

            if(data[mid] == k) {
                if(mid == 0) {
                    first_k = 0;
                    break;
                } else if(data[mid - 1] < k) {
                    first_k = mid;
                    break;
                } else {
                    right = mid - 1;
                    mid = (left + right)/2;
                }
            } else if(data[mid] < k) {
                left = mid + 1;
                mid = (left + right)/2;
            } else if(data[mid] > k) {
                right = mid - 1;
                mid = (left + right)/2;
            }
        }

        if(first_k == -1)
            return 0;

        left = 0;
        right = data.size() - 1;
        mid = (left + right)/2;

        last_k = data.size();
        while(left <= right) {

            if(data[mid] == k) {
                if(mid == data.size() - 1) {
                    last_k = data.size() - 1;
                    break;
                } else if(data[mid + 1] > k) {
                    last_k = mid;
                    break;
                } else {
                    left = mid + 1;
                    mid = (left + right)/2;
                }
            } else if(data[mid] < k) {
                left = mid + 1;
                mid = (left + right)/2;
            } else if(data[mid] > k) {
                right = mid - 1;
                mid = (left + right)/2;
            }
        }

        return last_k - first_k + 1;
    }

    void run() {

        vector<int> data1 = {1,2,3,3,3,3};
        vector<int> data = {3};

        cout << GetNumberOfK(data1,3) << endl;
    }

};
#endif //ALGORITHM_OFFER38_H
