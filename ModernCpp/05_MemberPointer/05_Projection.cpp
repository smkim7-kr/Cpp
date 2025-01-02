// Diverse ways to comparing two stirngs, using std::invoke
#include <iostream>
#include <functional>
#include <string>

// C++20 - std::identity returns unchanged arguments
template<class T, class Proj = std::identity> // default value Proj setting
const T& cmpobj(const T& obj1, const T& obj2, Proj proj = {}) {
    // below option cannot handle if proj is member function pointer
    // return proj(obj1) < proj(obj2) ? obj2 : obj1:

    // std::invoke handles both typical and member functions
    // can also handle if proj is member variable pointer
    // i.e. (obj1.*proj) < (obj2.*proj)
    return std::invoke(proj, obj1) < std::invoke(proj, obj2) ? obj2 : obj1;
}

template<class U, class Comp = std::less<void>, class Proj2 = std::identity>
const U& cmpobj2(const U& obj1, const U& obj2, Comp comp = {}, Proj2 proj = {}) {
    // added compare operator instead of using <
    return std::invoke(comp, std::invoke(proj, obj1), std::invoke(proj, obj2)) ? obj2 : obj1;
}

struct Vec2 {
    int x, y;
};


int main() {
    std::string s1 = "hello";
    std::string s2 = "world";

    // 1) compare variable/object, default identity proj
    auto cmp1 = cmpobj(s1, s2); 
    // 2) compare variable/object, lambda function to compare size/size
    auto cmp2 = cmpobj(s1, s2, [](auto &a) { return a.size(); }); 
    auto cmp3 = cmpobj(s1, s2, [](auto &a) { return a.capacity(); }); 
    // 3) compare variable/object, proj is member function pointer
    auto cmp4 = cmpobj(s1, s2, &std::string::size ); 
    // 4) compare variable/object, proj is member variable pointer
    Vec2 v1{10, 20};
    Vec2 v2{20, 30};
    auto cmp5 = cmpobj(v1, v2, &Vec2::y ); 
    std::cout << cmp5.x << ", " << cmp5.y << std::endl;

    auto _cmp1 = cmpobj2(s1, s2); 
    auto _cmp2 = cmpobj2(s1, s2, std::greater{});
    auto _cmp3 = cmpobj2(s1, s2, {}, &std::string::size);
    auto _cmp4 = cmpobj2(s1, s2, std::greater{}, &std::string::size);
}

