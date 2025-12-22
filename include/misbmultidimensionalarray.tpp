#include <iostream>
#include <iomanip>
#include <type_traits>

template<typename... Args>
void MDArray::SetValue(double value, Args... args) {
	static_assert((std::is_convertible<typename std::decay<Args>::type, uint32_t>::value && ...),
		"All arguments must be convertible to uint32_t");
	// calcul de l'index
	const size_t l_index = _getIndex(args...);

	// verification des bornes
	if (l_index >= m_datas.size())
		throw std::runtime_error("Wrong index");

	// attribution de la valeur
	memcpy(&m_datas[l_index], &value, sizeof(double));
}


template<typename... Args>
double MDArray::GetValue(Args... args) const {
	static_assert((std::is_convertible<typename std::decay<Args>::type, uint32_t>::value && ...),
		"All arguments must be convertible to uint32_t");

	// calcul de l'index
	const size_t l_index = _getIndex(args...);

	// verification des bornes
	if (l_index >= m_datas.size())
		throw std::runtime_error("Wrong index");
	
	// recuperation de la valeur
	double l_returnedValue;
	memcpy(&l_returnedValue, &m_datas[l_index], sizeof(l_returnedValue));

	return l_returnedValue;
}


template<typename... Args>
size_t MDArray::_getIndex(Args... args) const {
	static_assert((std::is_convertible<typename std::decay<Args>::type, uint32_t>::value && ...),
		"All arguments must be convertible to uint32_t");
	if (sizeof...(Args) != m_dimensions.size())
		throw std::runtime_error("Wrong number of dimensions");

	size_t idxArray[] = { static_cast<size_t>(args)... };
	size_t index = 0;
	size_t multiplier = sizeof(double);

	// On part de la dernière dimension vers la première
	for (int d = m_dimensions.size() - 1; d >= 0; --d) {
		index += idxArray[d] * multiplier;
		multiplier *= m_dimensions[d];
}	

	return index;
}

