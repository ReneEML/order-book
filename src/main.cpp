#include <iostream>
#include <map>

int main() {
    std::map<int, int> mymap;
    std::map<int, int>::iterator it;
    mymap[1] = 69;
    mymap[21] = 420;
    mymap[4] = 21;
    mymap[0] = 42;
    mymap[-1] = 99;
//    std::map<int, int>::iterator largest = mymap.find(-1);
//    mymap.erase(largest++);
//    std::cout << largest->first << " => " << largest->second << '\n';
    std::map<int, int>::iterator largest = mymap.find(21);
    std::cout << mymap.size() << std::endl;
    mymap.erase(largest--);
    std::cout << mymap.size() << std::endl;
    std::cout << largest->first << " => " << largest->second << '\n';
    return 0;
}
