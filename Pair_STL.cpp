#include <utility>      // std::pair
#include <iostream>     // std::cout


int main()
{
  std::pair <std::string,double> product1;                     // default constructor
  std::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
  std::pair <std::string,double> product3 (product2);          // copy constructor

  product1 = std::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

  product2.first = "shoes";                  // the type of first is string
  product2.second = 39.90;

//Exchanges the contents of the pair object with the contents of pr.
product2.swap(product3);
//operators <, >, <= and >= perform a lexicographical comparison on the sequence formed by members
//first and second (in all cases using operator< reflexively for the comparisons).


//Returns a reference to member first if I is 0, or a reference to member second if I is 1.

std::cout << std::get<0>(product2) << " and " << std::get<1>(product2) << '\n';
}
