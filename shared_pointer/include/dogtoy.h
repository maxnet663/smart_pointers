#include "shared_ptr_toy.h"

//Классы из видео к уроку
class Toy {
public:
    Toy(std::string _name) : name(_name) {}
    Toy() : name("SomeToy") {}
    std::string get_name() { return name; }
private:
    std::string name;
};

class Dog {
public:
    Dog(std::string _name, shared_ptr_toy<Toy> toy, int _age) : name(_name), lovelyToy(toy) {
        if (_age >= 0 && _age < 30)
            age = _age;
    }
    Dog() : Dog("Snow", make_shared_toy<Toy>("SomeToy"), 0) {}
    Dog(std::string _name) : Dog(_name, make_shared_toy<Toy>("SomeToy"), 0) {}
    Dog(int _age) : Dog("Snow", make_shared_toy<Toy>("SomeToy"), _age) {}

    void copyLoveToy(const Dog& oth) {
        lovelyToy = oth.lovelyToy;
    }

private:
    std::string name;
    int age;
    shared_ptr_toy<Toy> lovelyToy;
};

