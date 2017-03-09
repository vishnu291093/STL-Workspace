/***

Lists are sequence containers that allow constant time insert and erase operations anywhere within the sequence, and iteration in both directions.

List containers are implemented as doubly-linked lists; Doubly linked lists can store each of the elements
they contain in different and unrelated storage locations.
The ordering is kept internally by the association to each element of a link to the element preceding it and a link to the element following it.

They are very similar to forward_list: The main difference being that forward_list objects are single-linked lists,
and thus they can only be iterated forwards, in exchange for being somewhat smaller and more efficient.

Compared to other base standard sequence containers (array, vector and deque), lists perform generally better in inserting,
extracting and moving elements in any position within the container for which an iterator has already been obtained,
and therefore also in algorithms that make intensive use of these, like sorting algorithms.

The main drawback of lists and forward_lists compared to these other sequence containers
is that they lack direct access to the elements by their position;
For example, to access the sixth element in a list, one has to iterate from a known position
 (like the beginning or the end) to that position, which takes linear time in the distance between these.
  They also consume some extra memory to keep the linking information associated to each element
  (which may be an important factor for large lists of small-sized elements).



***/
#include <iostream>
#include <list>

int main ()
{
  std::list<int> first;                                // empty list of ints
  std::list<int> second (4,100);                       // four ints with value 100
  std::list<int> third (second.begin(),second.end());  // iterating through second
  std::list<int> fourth (third);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  std::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
    //iterators
    std::list <int>::iterator it = second.begin();
    std::list <int>::iterator it_end = second.end();
    std::list <int>::reverse_iterator rit = second.rbegin();
    std::list <int>::reverse_iterator rit_end = second.rend();
    std::list <int>::const_iterator cit = second.cbegin();
    std::list <int>::const_iterator cit_end = second.cend();
//checking capacity
    std::cout<< second.empty() <<std::endl;
    std::cout<< second.size() <<std::endl;
    std::cout<< second.max_size() <<std::endl;

   // Accessing the elements
    std::cout<< second.front() <<std::endl;
    std::cout<< second.back() <<std::endl;
//The assign() function will reinitialize the vector. We can pass either a valid element range using the [first, last) iterators
//or we can specify the number of elements to be created and the element value.
first.assign(second.begin(), second.end());
//Inserts a new element at the beginning of the list, right before its current first element.
//This new element is constructed in place using args as the arguments for its construction.
 first.emplace_front(10);
//Note that pop_back() does not return the value of the popped element.
first.pop_back();
first.pop_front();
first.push_back(100);
first.push_front(100);


//Inserts a new element at the end of the list, right before its current first element.
//This new element is constructed in place using args as the arguments for its construction.
 first.emplace_back(10);

 //The container is extended by inserting a new element at position.
 //This new element is constructed in place using args as the arguments for its construction.
 first.emplace(first.begin(),100);

//Removes from the list container either a single element (position) or a range of elements ([first,last)).
auto it_newer = first.begin() ;
it_newer++;
first.erase(it_newer,first.end());

//Exchanges the content of the container by the content of x, which is another list of the same type. Sizes may differ.
//After the call to this member function, the elements in this container are those which were in x before the call,
//and the elements of x are those which were in this. All iterators, references and pointers remain valid for the swapped objects.
first.assign(second.begin(),second.end());
first.swap(second);

//reverse list of
first.reverse();

}
