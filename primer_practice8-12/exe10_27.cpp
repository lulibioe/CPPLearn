#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>  // for inserter
#include <list>
using namespace std;

/* 使用unique_copy将vec中连续不重复的元素 copy到list中去. 注意重复但不连续的不会去除 */
/* back_inserter, insert ele in the end of a container (not just vector)*/
void copyNonDup(const vector<int>& vec, list<int>& ls) {
    unique_copy(vec.cbegin(), vec.cend(), back_inserter(ls));
    for (int i : ls) {
        cout << i << " ";
    }
    cout << endl;
}

template <typename Sequence>  // can ignore what data type inside Sequence
void print(const Sequence& seq, const string& msg) {
    cout << "inserted by " << msg << ": ";
    for (auto n : seq) {
        cout << n << " ";
    }
    cout << endl;
}

void compare3inserter(const vector<int>& vec) {
    list<int> ls1, ls2, ls3, ls4;
    unique_copy(vec.cbegin(), vec.cend(), front_inserter(ls1));
    print(ls1, "front_inserter");

    unique_copy(vec.cbegin(), vec.cend(), back_inserter(ls2));
    print(ls2, "back_inserter");

    // 注意 insert 插入到给定iterator的前一个位置
    unique_copy(vec.cbegin(), vec.cend(), inserter(ls3, ls3.begin()));
    print(ls3, "inserter in ls.begin()");

    unique_copy(vec.cbegin(), vec.cend(), inserter(ls4, ls4.end()));
    print(ls4, "inserter in ls.end()");
}

int main() {
    vector<int> vec{1,2,1,1,2,3,3};
    list<int> ls;
    copyNonDup(vec, ls);

    compare3inserter(vec);
    return 0;
}
/*
1 2 1 2 3 
*/