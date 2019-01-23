#include "Body.h"

/**
	the point of this class is to take the details of the body class so we can define multiple bodies to be used as projectiles
	Our character will be its own body instance that is seperate from the others. Our enemies and boss will have a similar build as a base 
	though we obviously wont be able to control them. 
	Main ideas for character control include: 
	-movement up down left right
	-a way to evade bullets most liking a block function that can only be held for about 0.5 seconds to avoid someone spamming it. 
	-a 1 time use replenish function that can either be used to heal or fill our mana
	-an attacking function that is correlated to the state of the character, the more damage they take the less they can dish out meaning health is even more vital 
**/
class CharacterControlls
{
private:
	//used once for mana or health but not both
	int replenish;
	//will be set at 5
	int health;
	//will be set at 100
	int mana;
	float damage;
	//will be set at 0.5 seconds
	float blockDuration;
	//tbd when game starts taking shape
	float movementSpeed;
	//caps to prevent player from being over powered
	const float maxSpeed = 5.0f;
	const int maxHealth = 10;
	const float damageCap = 15.0f;
	const float fireInterval = 0.33f;
	

public:
	CharacterControlls();
	int ReplenishSystem(int replenish, int health, int mana);
	void Attack(float damage, const float damageCap, const float fireInterval);
	void MoveCharacter(float movementSpeed, const float maxSpeed);
	~CharacterControlls();
};

