#include <iostream>

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (size_t i = 0; i < MAX_SIZE; i++) {
        inventory_[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    for (size_t i = 0; i < MAX_SIZE; i++) {
        if (other.inventory_[i]) {
            inventory_[i] = other.inventory_[i]->clone();
        } else {
            inventory_[i] = NULL;
        }
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    if (this != &other) {
        clear();
        for (size_t i = 0; i < MAX_SIZE; i++) {
            if (other.inventory_[i]) {
                inventory_[i] = other.inventory_[i]->clone();
            } else {
                inventory_[i] = NULL;
            }
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
    if (!materia)
        return;

    for (size_t i = 0; i < MAX_SIZE; i++) {
        if (inventory_[i] == materia) {
            return;
        }
    }

    for (size_t i = 0; i < MAX_SIZE; i++) {
        if (!inventory_[i]) {
            inventory_[i] = materia;
            return;
        }
    }

    std::cerr << "MateriaSource is full" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (size_t i = 0; i < MAX_SIZE; i++) {
        if (inventory_[i] && inventory_[i]->getType() == type) {
            return inventory_[i]->clone();
        }
    }
    return NULL;
}

void MateriaSource::clear() {
    for (size_t i = 0; i < MAX_SIZE; i++) {
        delete inventory_[i];
        inventory_[i] = NULL;
    }
}

MateriaSource::~MateriaSource() {
    clear();
}
