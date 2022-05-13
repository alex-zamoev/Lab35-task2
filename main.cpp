#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>

int main()
{
    std::vector<int> inVec{1,2,3,4,5,6,3,4,5,2,1,3,4,5,7};

    auto foo = [](std::vector<int> inVec){
        std::unordered_set<int> t;
        std::vector<int> outVec;
        for(const auto &ptr: inVec)
            t.insert(ptr);
        for(const auto &ptr: t)
            outVec.push_back(ptr);
        auto p1 = std::make_unique<std::vector<int>>(outVec);

        return p1;
    };

    auto p = foo(inVec);

    for(const auto &ptr: *p)
        std::cout << ptr << std::endl;
    return 0;
}
