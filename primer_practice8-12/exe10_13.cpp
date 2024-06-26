/*标准库定义了名为 partition 的算法，它接受一个谓词，对容器内容进行划分，
使得谓词为true 的值会排在容器的前半部分，而使得谓词为 false 的值会排在后半部分。
算法返回一个迭代器，指向最后一个使谓词为 true 的元素之后的位置。编写函数，接受一个 string，
返回一个 bool 值，指出 string 是否有5个或更多字符。
使用此函数划分 words。打印出长度大于等于5的元素。*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // partition
using namespace std;

bool predicate(const string& s) { // predicate: 谓语
    return s.size() >= 5; // this is the standard
}

int main() {
    vector<string> vec{"a", "as", "aasss", "aaaaassaa", "aaaaaabba", "aaa" };
    auto pivot = partition(vec.begin(), vec.end(), predicate);

    for (auto it = vec.cbegin(); it != pivot; it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
/*
aaaaaabba aaaaassaa aasss */