#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <cstddef>
#include <string>

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
    static const size_t MAX_SIZE = 4;
    AMateria *inventory_[MAX_SIZE];

    void clear();

public:
    MateriaSource();
    MateriaSource(const MateriaSource &other);

    MateriaSource &operator=(const MateriaSource &other);

    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &type);

    ~MateriaSource();
};

#endif