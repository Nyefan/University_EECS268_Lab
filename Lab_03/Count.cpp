/** 
 * @File:   Count.cpp
 * @Author: Davis St. Aubin
 *
 * Created on September 16, 2013
 */

//#include "Count.h"

template <typename T>
Count<T>::Count(void) {

}

template <typename T>
Count<T>::Count(T t) {
    item = t;
    count = 1;
}

template <typename T>
Count<T>::Count(const Count &orig) {
    item = orig.item;
    count = orig.count;
}

template <typename T>
Count<T>::~Count(void) {

}

template <typename T>
void Count<T>::bumpCount() {
    ++count;
}

//template <typename T>
//bool Count<T>::equals(const T &t) const{
//
//}

template <typename T>
T Count<T>::getItem() const {
    return item;
}

template <typename T>
int Count<T>::getCount() const {
    return count;
}








