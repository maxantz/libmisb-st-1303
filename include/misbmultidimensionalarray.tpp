
#include <iostream>
#include <type_traits>

template<typename... Args>
void MDArray::setValue(double value, Args... args) {
    static_assert((std::is_convertible<typename std::decay<Args>::type, uint32_t>::value && ...),
                  "All arguments must be convertible to uint32_t");
	// verification des bornes
	// attribution de la valeur
}


template<typename... Args>
double MDArray::setValue(Args... args) {
    static_assert((std::is_convertible<typename std::decay<Args>::type, uint32_t>::value && ...),
                  "All arguments must be convertible to uint32_t");
	double l_returnedValue;
	// verification des bornes
	// recuperation de la valeur
	return l_returnedValue;
}


