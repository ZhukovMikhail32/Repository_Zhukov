/* Custom manipulators.
 * @file
 * @date 2018-08-05
 * @author Anonymous
 */

#ifndef __IOMANIP_HPP__
#define __IOMANIP_HPP__

#include <iostream>

//{ endm manipulator
std::ostream& endm(std::ostream& os) { 
    return os << "[eol]\n"; 
} 
//}

//{ squares manipulator
class SquareStreamManipulator {}; 
inline SquareStreamManipulator squares; 
 
template <class T> 
class SquareWrapper { 
private: 
    T& os; 
public: 
    SquareWrapper(T& os): os(os) {} 
 
    template <class U> 
    T& operator<<(const U& value) { 
        return os << "[" << value << "]"; 
    } 
}; 
 
 
template<class T> 
SquareWrapper<T> operator<<(T& os, const SquareStreamManipulator& manipulator) { 
    return SquareWrapper<T>(os); 
} 
//}

//{ add manipulator
class AddStreamManipulator {}; 
inline AddStreamManipulator add; 
 
template <class T, class U> 
class AddWrapper2 { 
private: 
    const U& value; 
    T& os; 
public: 
    AddWrapper2(T& os, const U& value): os(os), value(value) {} 
     
    std::ostream& operator<<(const U& value) { 
        return os << this->value + value; 
    } 
}; 
 
template <class T> 
class AddWrapper1 { 
private: 
    T& os; 
public: 
    AddWrapper1(T& os): os(os) {} 
 
    template<class U> 
    AddWrapper2<T, U> operator<<(const U& value) { 
        return AddWrapper2<T, U>(os, value); 
         
    } 
}; 
 
template<class T> 
AddWrapper1<T> operator<<(T& os, AddStreamManipulator& manipulator) { 
    return AddWrapper1<T>(os); 
}
//}

#endif // __IOMANIP_HPP__
