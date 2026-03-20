#include "Character.hpp"

Character::Character() : name_("") {
    for (size_t i = 0; i < MAX_SIZE; i++) {
        inventory_[i] = NULL;
    }
}

Character::Character(const std::string &name) : name_(name) {
    for (size_t i = 0; i < MAX_SIZE; i++) {
        inventory_[i] = NULL;
    }
}

void Character::clearInventory() {
    for (size_t i = 0; i < MAX_SIZE; i++) {
        delete inventory_[i];
        inventory_[i] = NULL;
    }
}

Character::Character(const Character &other) : name_(other.name_) {
    for (size_t i = 0; i < MAX_SIZE; i++) {
        if (other.inventory_[i]) {
            inventory_[i] = other.inventory_[i]->clone();
        } else {
            inventory_[i] = NULL;
        }
    }
}

Character &Character::operator=(const Character &other) {
    if (this != &other) {
        clearInventory();
        name_ = other.name_;
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

const std::string &Character::getName() const { return name_; }

void Character::equip(AMateria *m) {
    if (!m) {
        return;
    }

    for (size_t i = 0; i < MAX_SIZE; i++) {
        if (inventory_[i] == m) {
            return;
        }
    }

    for (size_t i = 0; i < MAX_SIZE; i++) {
        if (!inventory_[i]) {
            inventory_[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= static_cast<int>(MAX_SIZE)) {
        return;
    }
    inventory_[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
    if (idx < 0 || idx >= static_cast<int>(MAX_SIZE)) {
        return;
    }
    if (inventory_[idx]) {
        inventory_[idx]->use(target);
    }
}

Character::~Character() { clearInventory(); }
