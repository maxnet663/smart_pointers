#include "shared_ptr_toy.h"
#include "shared_ptr_toy.cpp"
#include "dogtoy.h"

// шаблоны - мощный интрумент, но приходится делать такие вот штуки

template class shared_ptr_toy<Toy>;
template shared_ptr_toy<Toy> make_shared_toy<Toy>(std::string inName);
template shared_ptr_toy<Toy> make_shared_toy<Toy>(const Toy& other);
