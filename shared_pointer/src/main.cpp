#include <iostream>
#include "dogtoy.h"
#include "shared_ptr_toy.h"

int main() {
    shared_ptr_toy<Toy> ball = make_shared_toy<Toy>("Ball");
    shared_ptr_toy<Toy> bone = make_shared_toy<Toy>("Bone");

    std::cout << "Ball has: " << ball.get_refsCount() << " references"
        << std::endl << " and points at " << ball->get_name() << std::endl;
    std::cout << "Bone has: " << bone.get_refsCount() << " references"
        << std::endl << " and points at " << bone->get_name() << std::endl;

    std::cout << "After created some classes:" << std::endl;
    Dog a("Sharik", ball, 1);
    Dog b("Druzhok", ball, 10);
    Dog c("Pushok", ball, 5);
    Dog d("Polkan", bone, 11);
    Dog e("Iriska", bone, 8);

     std::cout << "Ball has: " << ball.get_refsCount() << " references"
        << std::endl << " and points at " << ball->get_name() << std::endl;
     std::cout << "Bone has: " << bone.get_refsCount() << " references"
        << std::endl << " and points at " << bone->get_name() << std::endl;


    ball.release();
    bone.release();

    std::cout << "After release:" << std::endl;
    std::cout << (ball.is_released() ? "Ball hasn't released" : "Ball has released") 
        << std::endl << (bone.is_released() ? "Bone hasn't relesed" :"Bone has released" )
        << std::endl;
    return 0;
}
