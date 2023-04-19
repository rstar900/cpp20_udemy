#include <list>
#include <iostream>

// Both forward and reverse iterator works for list
// Can insert and pop from front and back
// size() function available
// Insert and Erase happens before and at position, so no before_begin() needed
// Advantage : Fast insertion and deletion of elements in the middle
// Disadvantage  : No random access; need to go through each element

template <typename T>
void print_forward(T& container)
{
  auto it = container.begin();

  std::cout << "[ Size : " << container.size() << ", Items : ";
  while (it != container.end())
  {
    std::cout << *it << ", ";
    ++it;
  }
  std::cout << " ]" << std::endl;
}

template <typename T>
void print_reverse(T& container)
{
  auto it = container.rbegin();

  std::cout << "[ Size : " << container.size() << ", Items : ";
  while (it != container.rend())
  {
    std::cout << *it << ", ";
    ++it;
  }
  std::cout << " ]" << std::endl;
}

int main()
{
  std::list l1 = {1,2,3,4,5,6};

  std::cout << std::endl << "--- Printing in reverse direction ---" << std::endl << std::endl;
  print_reverse(l1);

  std::cout << std::endl << "--- Printing in forward direction ---" << std::endl << std::endl;
  print_forward(l1);

  // find an element (std::find returns an iterator for the found element)

  std::cout << std::boolalpha;
  bool isFound5 = false;
  bool isFound7 = false;
  auto foundElement5It = std::find(l1.begin(), l1.end(), 5);
  auto foundElement7It = std::find(l1.begin(), l1.end(), 7);

  if (foundElement5It != l1.end())
    isFound5 = true;

  if (foundElement7It != l1.end())
    isFound7 = true;
  

  std::cout << std::endl << "Element 5 found : " << isFound5 << std::endl; 
  std::cout << std::endl << "Element 7 found : " << isFound7 << std::endl; 

  //begin() iterator can be useful for insertion or anything else in the beginning
  l1.insert(l1.begin(), 7);
  std::cout << std::endl << "--- After inserting 7 in the beginning ---" << std::endl << std::endl;
  print_forward(l1);

  // Similarily there is emplace for in place creation while insertion
  l1.emplace(foundElement5It, 100);
  std::cout << std::endl << "--- After inserting 100 via emplace() before 5 ---" << std::endl << std::endl;
  print_forward(l1);

  // erase()
  l1.erase(std::find(l1.begin(), l1.end(), 3)); // Need to find 3 to get it's iterator
  std::cout << std::endl << "--- After removing 3 ---" << std::endl << std::endl;
  print_forward(l1);

  // clear() also works
  l1.clear();
  std::cout << std::endl << "--- After clear() ---" << std::endl << std::endl;
  print_forward(l1);

  // Can be reassigned after clear()
  // Then printing before applying unique() and after it
  // Note: It is only removing consecutive duplicates (example, 1's are not removed)
  l1 = {1, 2, 2, 3, 4, 4, 100, 70, 1, 5, 6, 7, 10, 10, 50};
  std::cout << std::endl << "--- Before and after unique() ---" << std::endl << std::endl;
  print_forward(l1);
  l1.unique();
  print_forward(l1);

  // remove() and remove_if()
  std::cout << std::endl << "--- After removing 3 ---" << std::endl << std::endl;
  l1.remove(3);
  print_forward(l1);
  std::cout << std::endl << "--- After removing all elements greater than 10 ---" << std::endl << std::endl;
  l1.remove_if([](int n){return n > 10;});
  print_forward(l1);

  // sort() and reverse()
  std::cout << std::endl << "--- sort() ---" << std::endl << std::endl;
  l1.sort();
  print_forward(l1);
  std::cout << std::endl << "--- reverse() ---" << std::endl << std::endl;
  l1.reverse();
  print_forward(l1);

  // resiszing after reducing does not bring back elements, the remaining places are 0 initialized
  std::cout << std::endl << "--- resize(5) ---" << std::endl << std::endl;
  l1.resize(5);
  print_forward(l1);
  std::cout << std::endl << "--- resize(10) ---" << std::endl << std::endl;
  l1.resize(10);
  print_forward(l1);

  // Other functions like swap(), merge(), pop_front(), push_front(), pop_back(), push_back() are there
  // but here only splice() is given as an example
  std::list l2 {1,2,3,4,5};
  std::list l3 {6,7,8,9,10};
  std::cout << std::endl << "--- Before splice() ---" << std::endl << std::endl;
  std::cout << "l2 : "; print_forward(l2);
  std::cout << "l3 : "; print_forward(l3);
  std::cout << std::endl << "--- After splice() ---" << std::endl << std::endl;
  l2.splice(l2.begin(), l3, l3.begin(), l3.end()); // takes elements after the given starting iterator
  std::cout << "l2 : "; print_forward(l2);
  std::cout << "l3 : "; print_forward(l3);

  return 0;
}
