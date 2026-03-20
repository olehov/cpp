#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <cstddef>
#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
private:
    static const size_t MAX_SIZE = 4;
    AMateria *inventory_[MAX_SIZE];
    std::string name_;

    Character();
    void clearInventory();

public:
    Character(const std::string &name);
    Character(const Character &other);

    Character &operator=(const Character &other);

    const std::string &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);

    ~Character();
};

#endif