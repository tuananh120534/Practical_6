#include "BigNumCalc.h"
#include<list>
#include<iostream>
#include<string>
#include<vector>

BigNumCalc::BigNumCalc(){};
BigNumCalc::~BigNumCalc(){};
std::list<int> BigNumCalc::buildBigNum(std::string numString){
    int n = numString.size();
    std::vector<int> nums(n,0);
    for(int i = 0; i<n; i++){
        nums[i] = numString[i]-'0';
    }
    std::list<int> listNums(nums.begin(), nums.end());
    while(*listNums.begin()==0&&listNums.size()>1) listNums.pop_front();
    return listNums;
};
std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2){
    std::list<int> ans;
    if(num2.size()>num1.size()){
        std::list<int> hold = num2;
        num2=num1;
        num1=hold;
    }
    int carry = 0;
    auto itr1 = num1.rbegin();
    auto itr2 = num2.rbegin();
    while(carry==true||itr1!=num1.rend()||itr2!=num2.rend()){
        

        int localSum = carry;
        if(itr1!=num1.rend()){
            localSum+=*itr1;
            ++itr1;
        }
        if(itr2!=num2.rend()){
            localSum+=*itr2;
            ++itr2;
        }
        // std::cout<<"localSum: "<<localSum<<std::endl;
        // std::cout<<"localSum%10: "<<localSum%10<<std::endl;
        carry = localSum/10;
        ans.push_front(localSum%10);
        
    }
    return ans;
};
std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2){
    while (num2.size() < num1.size()) {
        num2.push_front(0);
    }
    // std::cout<<"num1: ";
    //     for (int digit : num1) {
    //         std::cout << digit;
    //     }
    // // std::cout<<std::endl;
    // // std::cout<<"num2: ";
    //     for (int digit : num2) {
    //         std::cout << digit;
    //     }
    // std::cout<<std::endl;
    std::list<int> ans;
    if(num2.size()>num1.size()){
        std::list<int> hold = num2;
        num2=num1;
        num1=hold;
    }
    int carry = 0;
    auto itr1 = num1.rbegin();
    auto itr2 = num2.rbegin();
    while(carry==true||itr1!=num1.rend()||itr2!=num2.rend()){
        // std::cout<<"1point: "<<*itr1<<std::endl;
        // std::cout<<"2point: "<<*itr2<<std::endl;
        int localSum = carry;
        if(itr1!=num1.rend()){
            localSum+=*itr1;
            itr1++;
        }
        if(itr2!=num2.rend()){
            localSum-=*itr2;
            itr2++;
        }
        if(localSum<0){
            localSum+=10;
            carry=-1;
        }else{
            carry=0;
        }
        // std::cout<<"carry: "<<carry<<std::endl;
        ans.push_front(localSum);
        
    }
    while(*ans.begin()==0 && ans.size()>1) {
        ans.pop_front();
    }
    // std::cout<<"ans: ";
    // for (int digit : ans) {
    //     std::cout << digit;
    // }
    // std::cout<<std::endl;
    return ans;
};
std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2){
    std::list<int> ans;
    int carry = 0;
    auto itr1 = num1.rbegin();
    auto itr2 = num2.begin();
    while(itr1!=num1.rend()||carry){
        int localSum = carry;
        if(itr1!=num1.rend()){
            localSum=*itr1*(*itr2)+carry;
            itr1++;
        }
        carry = localSum/10;
        ans.push_front(localSum%10);
    }
    while(*ans.begin()==0 && ans.size()>1) {
        ans.pop_front();
    }
    return ans;
};