#include <vector>
#include <iostream>



int main()
{
//initialize a vector
std::vector<int> vec;
//vector of size 10
std::vector<int> vec2(10);
//vector of size 10 and intialized
std::vector<int> vec3(10,5);
//if out of range then throws an instance of std::out of range
//vec.at(11) = 32;
//addding element to the end of the vector
vec.push_back(10);
//Inorder to prevent the copying and increasing the size of the arrray
//you can use the method reserve
//If the vector already has room for the required number of elements,
//reserve() does nothing. In other words, reserve() will grow the allocated storage of the vector,
//if necessary, but will never shrink it.
//vec.reserve(10);
//o find out how many elements would fit in the currently allocated storage of a vector, use the capacity() member function.
// To find out how many elements are currently contained by the vector, use the size() member function:
std::cout<<vec.capacity()<<std::endl;
std::cout<<vec.size()<<std::endl;
//if we dont reserve the size then once it reaches max,The vector will copy it to another memory location of double the initial size

//The correct way of enlarging the number of contained elements is to call vector's member function resize()

//If the new size is larger than the old size of the vector, it will preserve all elements already present in the controlled sequence; t
//he rest will be initialized according to the second parameter. If the new size is smaller than the old size,
//it will preserve only the first new_size elements. The rest is discarded and shouldn't be used any more—consider these elements invalid.
//If the new size is larger than capacity(), it will reallocate storage so all new_size elements fit. resize() will never shrink capacity().

vec.clear();//vec is empty
vec.reserve(4);//capasity is 4
vec.push_back(23);// vec is 23
vec.resize(5); // vec is 23,0,0,0,0
vec.push_back(100);// vec is 23,0,0,0,0,100
vec.resize(2); //vec is 23,0
vec.resize(5,1); //vec is 23,0,1,1,1

//address of the first element of the vector can be got by
//&vec[0]
//we can pass that to function asking for a pointer to int or other type

//we can construct a vector by copying from an array
double p[] = {1, 2, 3, 4, 5};
std::vector<double> a(p, p+5);

//Using pointer to point to an memmory address of a vecotr can be problemamtic as
// the vector might cahange its memory to increase its size and the vecotr will be
// pointing to an deleted memory

//const iterator
std::vector<double>::const_iterator i;

//assign function

//The assign() function will reinitialize the vector. We can pass either a valid element range using the [first, last) iterators
//or we can specify the number of elements to be created and the element value.
vec.assign(a.begin(), a.end());

//pop_back(), that removes the last element in the controlled sequence.
 //The removed element becomes invalid, and size() is decremented.
//Note that pop_back() does not return the value of the popped element.
vec.pop_back();

//reverse iterator
std::vector<int>::reverse_iterator r = vec.rbegin();
// to get a normal iterator out, use base member function
std::vector<int>::iterator i = r.base();

// to access the front element use
vec.front();
//to acess the last element use
vec.back();

//insert and erase
std::vector<int>::iterator it = vec.begin() + 1;
    // insert 33 before the second element:
// it points to the inserted element
it = v.insert(it, 33);


    //insert the contents of q before the second element:
vec.insert(it, p.begin(), p.end());
// insert three time -1 before the fourth element:
 it = vec.begin() + 4;
v.insert(it, 3, -1);
//0 10 11 12 33 1 2 3 4
//after
//0 10 11 -1 -1 12 33 1 2 3 4

   it = v.begin() + 1;
    v.erase(it, it + 4);
    // 0 10 11 -1 -1 12 33 1 2 3 4
    //after
    //v contains 0 12 33 1 2 3 4

}
