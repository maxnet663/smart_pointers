#include "shared_ptr_toy.h"

template <typename T>
void ControlBlock<T>::release() {
    if(!--refsCount) { // удаляем объект когда на него уже никто не указывает
        delete ptr;
        delete this;
    }
}

template<typename T>
void ControlBlock<T>::add_ref() {
    refsCount++;
}

template<typename T>
void shared_ptr_toy<T>::add_ref() {
    if (pControlBlock) // проверка, не освобожден ли указатель
        pControlBlock->add_ref();
}

template<typename T>
void shared_ptr_toy<T>::release() {
    if (pControlBlock)
        pControlBlock->release();
    pControlBlock = nullptr; //освобождаем этот указатель, от владения объектом
}

template <typename T>
shared_ptr_toy<T>& shared_ptr_toy<T>::operator=(const shared_ptr_toy<T>& other) {
    if (pControlBlock)
       release(); // освобождаем от предыдущего владения
    pControlBlock = other.pControlBlock;
    add_ref();
    return *this;
}

template<typename T>
shared_ptr_toy<T> make_shared_toy(std::string inName) {
    return shared_ptr_toy<T>(new T(inName));
}

template<typename T>
shared_ptr_toy<T> make_shared_toy(const T& other) {
    return shared_ptr_toy<T>(new T(other));
}
