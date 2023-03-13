#pragma once

#include "game_object.h"

class PrimitiveBuilder;

namespace gef
{
	class InputManager;
}

class Player : public GameObject
{
public:
	Player();
	~Player();

	void Intialise(PrimitiveBuilder* pb, gef::InputManager* im, b2World* wrld);

	void Update(float dt);

	//Getter function for player_body_
	b2Body* GetPlayerBody() { return player_body_; };
private:
	void BuildTransform();
	void GetInput(float dt);

	gef::InputManager* input_manager_;

	//Pointer for physics world
	b2World* world_;

	//Player Variables
	b2Body* player_body_;

	gef::Vector4 scale_, rotation_, position_;
	

	float speed;
	
};

