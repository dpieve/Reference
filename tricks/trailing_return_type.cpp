
// when you dont know the return type and it's based on the parameters

template<class T, class U>
auto multiply(T const& lhs, U const& rhs) -> decltype(lhs * rhs) {
  return lhs * rhs;
}

// when you dont want to use auto as the return type
template<class T, class U>
decltype(std::declval<T>() * std::declval<U>()) multiply(T const& lhs, U const& rhs) {
  return lhs * rhs;
}

// use of declval
decltype(std::declval<NonDefault>().foo()) n2 = n1; // type of n2 is int
