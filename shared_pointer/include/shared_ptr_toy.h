#pragma once
#include <iostream>

// класс ControlBlock будет хранить указатель на объект
// и количество указателей на него
// поскольку мы храним указатель и счетчик в одном месте, то они будут
// храниться по соседству в памяти, и память не будет фрагментироваться

template <typename T>
class ControlBlock {
private:
    size_t refsCount; 
public:
    T* ptr; // public для доступа из класса shared_ptr_toy

    ControlBlock() : refsCount(0), ptr(nullptr) { } 

    ControlBlock(T* inPtr) : refsCount(1), ptr(inPtr) { }

    void add_ref();

    void release();

    size_t get_refsCount() { return refsCount; }

};

template <typename T>
class shared_ptr_toy {
private:
    // здесь мы бы могли хранить указатель на объект во владении,
    // а также, указатель на счетчик, но так как у нас есть ControlBlock
    // используем его
    ControlBlock<T>* pControlBlock; 
public:
    shared_ptr_toy() { }

    shared_ptr_toy(T* inPtr) : pControlBlock(new ControlBlock<T>(inPtr)) { }

    shared_ptr_toy(const shared_ptr_toy& other) // конструктор копирования
            : pControlBlock(other.pControlBlock) { add_ref(); }; // так как появился новый указатель ++refsCount

    ~shared_ptr_toy() { release(); }


private:
    void add_ref();

public:
    void release();

    bool is_released() { return pControlBlock; }

    size_t get_refsCount() { return pControlBlock->get_refsCount(); }

    T* get_ptr() const { return pControlBlock->ptr; }

    // без этих перегрузок, умные указатели не указатели
    T& operator*() const { return *(pControlBlock->ptr); }

    T* operator->() const { return pControlBlock->ptr; }

    shared_ptr_toy<T>& operator=(const shared_ptr_toy<T>& other); // перегрузка оператора =

};

template <typename T>
// конструируем объект типа T с параметром string и отдаем его во владение
// нашему умному указателю
shared_ptr_toy<T> make_shared_toy(std::string inName);

// тоже самое, но теперь создаем объект через конструктор копирования
// (компилятор предоставит нам дефолтный конструктор копирования, т.к. 
// на уроке мы его не определили
template<typename T>
shared_ptr_toy<T> make_shared_toy(const T& other);
