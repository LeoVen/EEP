/**
 * @file inheritance.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 26/07/2018
 * 
 * Showcase for inheritance in C++
 */
#include <string>
#include <iostream>

class Weapon
{
  protected:
	std::string name;
	double damage;
	unsigned bullets;

  public:
	Weapon(std::string name, double damage, unsigned bullets)
	{
		this->name = name;
		this->damage = damage;
		this->bullets = bullets;
	}

	~Weapon() = default;

	void print(void)
	{
		std::cout << this->name << " [ Damage: " << this->damage << " Bullets: " << this->bullets << " ]" << std::endl;
	}

	bool is_empty(void)
	{
		return this->bullets == 0;
	}

	double shoot()
	{
		if (this->is_empty())
			return 0;

		this->bullets--;

		return this->damage;
	}
};

class Stormtrooper
{
  protected:
	std::string trooper_name;
	unsigned health;

  public:
	Weapon *main_weapon;
	Weapon *secondary_weapon;
	Weapon *active_weapon;

	Stormtrooper(std::string trooper_name, unsigned health, Weapon *main_weapon, Weapon *secondary_weapon)
	{
		this->trooper_name = trooper_name;
		this->health = health;
		this->main_weapon = main_weapon;
		this->secondary_weapon = secondary_weapon;
		this->active_weapon = nullptr;
	}

	~Stormtrooper() = default;

	void print(void)
	{
		std::cout << std::endl;
		std::cout << "Trooper name     : " << this->trooper_name << std::endl;
		std::cout << "Health           : " << this->health << std::endl;
		std::cout << "Primary Weapon   > " << std::endl;
		this->main_weapon->print();
		std::cout << "Secondary Weapon > " << std::endl;
		this->secondary_weapon->print();
		std::cout << std::endl;
	}

	void switch_main(void)
	{
		this->active_weapon = this->main_weapon;
	}

	void switch_secondary(void)
	{
		this->active_weapon = this->secondary_weapon;
	}

	double attack(void)
	{
		if (this->active_weapon == nullptr)
			return 0;

		return this->active_weapon->shoot();
	}

	void defend(Stormtrooper *attacker)
	{
		this->health -= attacker->attack();
	}
};

class HeavyTrooper : public Stormtrooper
{
  protected:
	double armor;

  public:
	Weapon *ternary_weapon;

	HeavyTrooper(std::string trooper_name, unsigned health, unsigned armor,
				 Weapon *main_weapon, Weapon *secondary_weapon, Weapon *ternary_weapon)
		: Stormtrooper(trooper_name, health, main_weapon, secondary_weapon)
	{
		this->armor = armor;
		this->ternary_weapon = ternary_weapon;
	}

	~HeavyTrooper() = default;

	void print(void)
	{
		std::cout << std::endl;
		std::cout << "Trooper name     : " << this->trooper_name << std::endl;
		std::cout << "Health           : " << this->health << std::endl;
		std::cout << "Armor            : " << this->armor << std::endl;
		std::cout << "Primary Weapon   > " << std::endl;
		this->main_weapon->print();
		std::cout << "Secondary Weapon > " << std::endl;
		this->secondary_weapon->print();
		std::cout << "Ternary Weapon   > " << std::endl;
		this->ternary_weapon->print();
		std::cout << std::endl;
	}

	void switch_main(void)
	{
		this->active_weapon = this->main_weapon;
	}

	void switch_secondary(void)
	{
		this->active_weapon = this->secondary_weapon;
	}

	void switch_ternary(void)
	{
		this->active_weapon = this->ternary_weapon;
	}

	void defend(Stormtrooper *attacker)
	{
		this->health -= attacker->attack() - this->armor;
	}

};

main(int argc, char const *argv[])
{

	Weapon blaster_1("Blaster Mk1", 25.3, 20);
	Weapon blaster_2("Blaster Mk2", 25.6, 20);
	Weapon machine_gun_1("Machine Gun Mk1", 20.0, 60);
	Weapon machine_gun_2("Machine Gun Mk2", 10.0, 60);
	Weapon rocket("Rocket Launcher", 200.0, 3);

	Stormtrooper trooper("Udani", 250, &machine_gun_1, &blaster_1);

	HeavyTrooper h_trooper("Bladakadani", 400, 5, &rocket, &machine_gun_2, &blaster_2);

	trooper.print();
	h_trooper.print();

	trooper.switch_main();
	h_trooper.switch_ternary();

	trooper.defend(&h_trooper);
	h_trooper.defend(&trooper);

	trooper.print();
	h_trooper.print();

	return 0;
}
