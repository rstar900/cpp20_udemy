#include <deque>
#include <iostream>

// Making it like this so that it works with all sequence containers (To restrict, concepts can be added in the future)
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
  std::deque dq {1,2,3,4,5,6};

  std::cout << std::endl << "--- Printing in reverse direction ---" << std::endl << std::endl;
  print_reverse(dq);

  std::cout << std::endl << "--- Printing in forward direction ---" << std::endl << std::endl;
  print_forward(dq);

  std::cout << std::endl << "--- Pop element from the front ---" << std::endl << std::endl;
  dq.pop_front();
  print_forward(dq);

  std::cout << std::endl << "--- Pop element from the back ---" << std::endl << std::endl;
  dq.pop_back();
  print_forward(dq);

  // The iterator points at the new element

  std::cout << std::endl << "--- insert 100, 200 before 4 ---" << std::endl << std::endl;
  auto it = dq.begin() + 2;
  dq.insert(it, {100, 200});
  print_forward(dq);

  // The advantage of emplace is, it does in-place insertion and avoids an unnecessary copy of object. 
  // For primitive data types, it does not matter which one we use. 
  // But for objects, use of emplace() is preferred for efficiency reasons.
  // It only does one element at a time though
  // For emplace iterator stays at the old element
  std::cout << std::endl << "--- insert 400, 500 before 100 using emplace ---" << std::endl << std::endl;
  dq.emplace(it, 400);
  dq.emplace(it, 500);
  print_forward(dq);

  std::cout << std::endl << "--- Clearing ---" << std::endl << std::endl;
  dq.clear();
  print_reverse(dq);

  // You can push and pop at both ends and other functions like swap() are also available to swap 2 deques
}