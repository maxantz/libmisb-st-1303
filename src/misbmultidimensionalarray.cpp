#include "misbmultidimensionalarray.h"

#include <sstream>

MDArray::MDArray()
{
}

MDArray::MDArray(const std::vector<uint32_t>& dimensions) : m_dimensions(dimensions)
{
	// calcule la taille du vecteur datas
	size_t l_taille = 1;
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
	size_t l_taille = 1;
	for (auto l_iter : m_dimensions)
		l_taille *= l_iter;
	// reservation vecteur datas
	m_datas.resize(l_taille);
}

bool MDArray::FromBytes(const std::vector<uint8_t>& value)
{
	// verification value.size() > 1
	// lecture nb_dimensions
	// verification value.size() > 1 + nb_dimensions * 4
	// iteration nb_dimensions
	//     lecture taille dimension nth
	// verification value.size() > 1 + nb_dimensions * 4 + 1
	// verification type de donnees
	// verification value.size() > 1 + nb_dimensions * 4 + 1 + somme(dimension nth) * sizeof(float64)
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

