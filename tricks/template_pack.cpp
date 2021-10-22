

//.h
template<typename ... Vars>
void FixEmptyVar(const Vars& ... vars);

// .cpp
template<typename ... Vars>
void CMyClass::FixEmptyVar(const Vars& ... vars)
{
	// variables vars show empty space instead of zero 
	// only std::string as parameters

	for (auto var : std::initializer_list<std::string>{ vars ... }) //could be std::string_view
	{
		if (!m_map.count(var.c_str()))
			m_map[var.c_str()] = " ";
	}
}

////
//if you have C++17 you can use a fold expression

template<typename... Strings>
std::string space_between(const Strings&... strings)
{
    return ((strings + ' ') + ...);
}

//
template<class...Add>
void space_between(std::string var, Add... add)
{
  for(auto i: std::initializer_list<std::string_view>{add...}) {
    m_map[var] += i + " ";
  }
  m_map[var].pop_back();
}

