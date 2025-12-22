#include "misbmultidimensionalarray.h"

#include <sstream>

MDArray::MDArray()
{
}

MDArray::MDArray(const std::vector<uint32_t>& dimensions) : m_dimensions(dimensions)
{
	// calcule la taille du vecteur datas
	size_t l_taille = sizeof(double);
	for (auto l_iter : m_dimensions)
		l_taille *= l_iter;
	// reservation vecteur datas
	m_datas.resize(l_taille);
}

MDArray::~MDArray()
{
	// vidage des vecteurs
	m_dimensions.clear();
	m_datas.clear();
}

void MDArray::Resize(const std::vector<uint32_t>& dimensions)
{
	// vidage des vecteurs
	m_dimensions.clear();
	m_datas.clear();
	// affectation vecteur dimensions
	m_dimensions = dimensions;
	// calcule la taille du vecteur datas
	size_t l_taille = sizeof(double);
	for (auto l_iter : m_dimensions)
		l_taille *= l_iter;
	// reservation vecteur datas
	m_datas.resize(l_taille);
}

bool MDArray::FromBytes(const std::vector<uint8_t>& value)
{
	// vidage des vecteurs
	m_dimensions.clear();
	m_datas.clear();

	// verification value.size() > 1
	const size_t l_size = value.size();
	if (l_size < 1) return false;

	size_t l_start = 0;

	// lecture nb_dimensions
	const size_t l_dims = static_cast<const size_t>(value[l_start++]) * sizeof(uint32_t);
	// verification value.size() > 1 + nb_dimensions * sizeof(uint32_t)
	if (l_size < (l_start + l_dims)) return false;

	// iteration nb_dimensions
	for (size_t l_i = 0; l_i < l_dims; l_i += sizeof(uint32_t))
	{
		// lecture taille dimension nth
		m_dimensions.push_back(static_cast<uint32_t>(value[l_i]<<24 | value[l_i+1]<<16 | value[l_i+2]<<8 | value[l_i+3]));
	}

	// verification value.size() > 1 + nb_dimensions * sizeof(uint32_t) + 1
	if (l_size < (1 + l_dims + 1)) return false;

	// verification type de donnees
	if (value[1 + l_dims] != 3u) return false;

	// calcule la taille du vecteur datas
	size_t l_taille = sizeof(double);
	for (auto l_iter : m_dimensions)
		l_taille *= l_iter;

	// verification value.size() > 1 + nb_dimensions * sizeof(uint32_t) + 1 + somme(dimension nth) * sizeof(float64)
	if (l_size < (1 + l_dims + 1 + l_taille * sizeof(double))) return false;

	// reservation vecteur datas
	m_datas.resize(l_taille);
	
	// lecture des n valeurs
	return false;
}

std::vector<uint8_t> MDArray::ToBytes() const
{
	std::vector<uint8_t> l_returnedValue;

	const uint8_t l_numDims = static_cast<const uint8_t>(m_dimensions.size());
	l_returnedValue.push_back(l_numDims);
	for (uint32_t l_dim : m_dimensions)
	{
		l_returnedValue.push_back((l_dim >> 24) & 0xFF);
		l_returnedValue.push_back((l_dim >> 16) & 0xFF);
		l_returnedValue.push_back((l_dim >>  8) & 0xFF);
		l_returnedValue.push_back((l_dim      ) & 0xFF);
	}
	l_returnedValue.push_back(m_dataType);
	l_returnedValue.insert(l_returnedValue.end(), m_datas.begin(), m_datas.end());

	return l_returnedValue;
}

std::string MDArray::ToString() const
{
	std::stringstream l_ss;

	return l_ss.str();
}

