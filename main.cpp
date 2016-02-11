#include <vector>
#include <algorithm>
#include <iostream>

template <class T>
bool comp(const T& a, const T& b)
{
    return b < a;
}

template < class T >
T sum(std::vector<T>& v)
{
    if (v.empty()) {
        return static_cast<T>(0.0);
    }

    std::make_heap(v.begin(),v.end(), comp<T>);

    while(v.size() > 1u) {
        std::pop_heap( v.begin(), v.end(), comp<T> );
        std::pop_heap( v.begin(), v.end() - 1u, comp<T> );
        v[ v.size() - 2u ] += v.back();
        v.pop_back();
        std::push_heap( v.begin(), v.end(), comp<T> );
    }

    return v.front();
}

int main()
{
    std::vector<double> test_d;
    std::cout << sum( test_d ) << std::endl;

    test_d.push_back(0.0);
    std::cout << sum( test_d ) << std::endl;

    test_d.push_back(0.0);
    std::cout << sum( test_d ) << std::endl;

    std::vector<float> test_f{10.0f, 0.0f, 5.0f, 5.0f};
    std::cout << sum( test_f ) << std::endl;

    return 0;
}

