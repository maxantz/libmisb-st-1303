#ifndef __MISB_MULTIDIMENSIONALARRAY_H__
#define __MISB_MULTIDIMENSIONALARRAY_H__

#include <vector>

class MDArray {
public:
	MDArray();
	MDArray(const std::vector<uint32_t>& dimensions);
	~MDArray();

	template<typename... Args>
	void SetValue(double value, Args... args);

	template<typename... Args>
	double GetValue(Args... args) const;

	void Resize(const std::vector<uint32_t>& dimensions);

	bool FromBytes(const std::vector<uint8_t>& value);
	std::vector<uint8_t> ToBytes() const;

	std::string ToString() const;
private:
	template<typename... Args>
	size_t _getIndex(Args... args) const;
private:
	uint8_t m_dataType{0x03};
	std::vector<uint32_t> m_dimensions;
	std::vector<uint8_t> m_datas;
};

#include "misbmultidimensionalarray.tpp"

#endif // __MISB_MULTIDIMENSIONALARRAY_H__
