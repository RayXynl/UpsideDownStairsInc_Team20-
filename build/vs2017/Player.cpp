#include "Player.h"
#include "primitive_builder.h"
#include "input/input_manager.h"
#include "input/keyboard.h"
#include "maths/matrix33.h"
#include "system/debug_log.h"

Player::Player():
	GameObject(),
	input_manager_(NULL),
	player_body_(NULL)
{

}

Player::~Player()
{

}

void Player::Intialise(PrimitiveBuilder* pb, gef::InputManager* im, b2World* wrld)
{
	input_manager_ = im;
	world_ = wrld;

	// setup the mesh for the player
	set_mesh(pb->GetDefaultCubeMesh());

	// assign type for player
	type_ = objectType::PLAYER;

	// create a physics body for the player
	player_body_def.type = b2_dynamicBody;
	player_body_def.position = b2Vec2(0.0f, 4.0f);
	player_body_def.userData.pointer = reinterpret_cast<uintptr_t>(this);

	player_body_ = world_->CreateBody(&player_body_def);

	// create the shape for the player
	player_shape.SetAsBox(0.5f, 0.5f);

	// create the fixture
	player_fixture_def.shape = &player_shape;
	player_fixture_def.density = 1.0f;

	// create the fixture on the rigid body
	player_body_->CreateFixture(&player_fixture_def);

	position_ = gef::Vector4(player_body_->GetPosition().x, player_body_->GetPosition().y, 0);
	scale_ = gef::Vector4(1, 1, 1);
}

void Player::Update(float dt)
{
	GetInput(dt);
	BuildTransform();
}

void Player::BuildTransform()
{

}

void Player::GetInput(float dt)
{
	auto keyboard_ = input_manager_->keyboard();

	if (keyboard_->IsKeyDown(gef::Keyboard::KC_SPACE))
	{
		player_body_def.position.Set(player_body_->GetPosition().x, player_body_->GetPosition().y + 1.0f);
		gef::DebugOut(" player :%f, %f", player_body_->GetPosition().x, player_body_->GetPosition().y);
	}
}