#include "Player.h"
#include "primitive_builder.h"
#include "input/input_manager.h"
#include "input/sony_controller_input_manager.h"
#include "maths/matrix33.h"

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
	type_ = objectType::PLAYER;
	// create a physics body for the player
	b2BodyDef player_body_def;
	player_body_def.type = b2_dynamicBody;
	player_body_def.position = b2Vec2(0.0f, 4.0f);
	player_body_def.userData.pointer = reinterpret_cast<uintptr_t>(this);

	player_body_ = world_->CreateBody(&player_body_def);

	// create the shape for the player
	b2PolygonShape player_shape;
	player_shape.SetAsBox(0.5f, 0.5f);

	// create the fixture
	b2FixtureDef player_fixture_def;
	player_fixture_def.shape = &player_shape;
	player_fixture_def.density = 1.0f;

	// create the fixture on the rigid body
	player_body_->CreateFixture(&player_fixture_def);
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
	auto controller = input_manager_->controller_input()->GetController(0);

	float x_axis = controller->left_stick_x_axis();
	float y_axis = controller->left_stick_y_axis();

	gef::Vector4 input_velocity = gef::Vector4(x_axis * speed * dt, y_axis * speed * dt, 0);

	position_ = position_ + input_velocity;

}