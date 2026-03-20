#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

static void printBanner(const std::string &title) {
    std::cout << "\n== " << title << " ==" << std::endl;
}

static void castSpell(ICharacter &caster, int idx, ICharacter &target,
                      const std::string &line) {
    std::cout << line << std::endl;
    caster.use(idx, target);
}

int main() {
    printBanner("Magic Academy");

    IMateriaSource *library = new MateriaSource();
    library->learnMateria(new Ice());
    library->learnMateria(new Cure());

    ICharacter *hero = new Character("Aria");
    ICharacter *cleric = new Character("Borin");
    ICharacter *monster = new Character("Ogre");

    std::cout << hero->getName() << " enters the arena with "
              << cleric->getName() << "." << std::endl;
    std::cout << monster->getName() << " roars from the shadows."
              << std::endl;

    hero->equip(library->createMateria("ice"));
    hero->equip(library->createMateria("ice"));
    cleric->equip(library->createMateria("cure"));
    cleric->equip(library->createMateria("ice"));

    printBanner("Round 1");
    castSpell(*hero, 0, *monster, "Aria hurls a shard of frost.");
    castSpell(*monster, 3, *hero, "The ogre flails wildly, but nothing happens.");
    castSpell(*cleric, 0, *hero, "Borin restores Aria after the counterattack.");

    printBanner("Round 2");
    castSpell(*hero, 1, *monster, "Aria chains a second icy strike.");
    castSpell(*cleric, 1, *monster, "Borin surprises everyone with a frost bolt.");

    printBanner("Backup Plan");
    Character champion(*static_cast<Character *>(hero));
    champion = *static_cast<Character *>(cleric);
    std::cout << "A magical echo named " << champion.getName()
              << " joins the fight." << std::endl;
    champion.use(0, *hero);
    champion.use(1, *monster);

    printBanner("Finale");
    AMateria *unknownSpell = library->createMateria("fire");
    if (!unknownSpell) {
        std::cout << "The library has no scroll for fire." << std::endl;
    }
    hero->unequip(3);
    hero->use(3, *monster);
    std::cout << monster->getName() << " retreats. The arena is safe."
              << std::endl;

    delete monster;
    delete cleric;
    delete hero;
    delete library;
    return 0;
}
