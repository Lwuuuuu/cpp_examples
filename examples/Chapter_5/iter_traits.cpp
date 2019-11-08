#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <string>
using namespace std;

template<typename C>
    using Iterator_type = typename C::iterator; //Iter's type
template<typename Iter>
    using Iterator_category = typename iterator_traits<Iter>::iterator_category; //Iter's category 
template<typename C>
    using Value_type = typename C::value_type; //The type of for elements, in this case it is int 

template<typename Ran>
void sort_helper(Ran beg, Ran end, random_access_iterator_tag) {
    sort(beg, end);
}

template<typename For>
void sort_helper(For beg, For end, forward_iterator_tag) {
    vector<Value_type<For>> v {beg, end};
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), beg);
}

template<typename C>
void sort(C& c) {
    using Iter = Iterator_type<C>; //Will be vector or forward_lsit
    sort_helper(c.begin(), c.end(), Iterator_category<Iter>{}); //Will convert to forward_itertor_tag or random_access_iterator_tag
}

void test(vector<string>& v, forward_list<int>& lst) {
    sort(v);
    sort(lst);
}

int main() {
    vector<string> v1 = {"c", "b", "a"};
    forward_list<int> v2 = {4, 3, 2};
    test(v1, v2);
    cout << v1[0] << " " << v1[1] << " " << v1[2] << endl; 
    for (auto it = v2.begin(); it != v2.end(); ++it)
        cout << ' ' <<  *it;
}