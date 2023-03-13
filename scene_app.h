#ifndef _SCENE_APP_H
#define _SCENE_APP_H

#include <system/application.h>
#include <maths/vector2.h>
#include <string>
#include <graphics/mesh_instance.h>
#include <box2d/Box2D.h>
#include <input/input_manager.h>

#include "game_object.h"
#include "Player.h"
#include "primitive_builder.h"

// FRAMEWORK FORWARD DECLARATIONS
namespace gef
{
	class Platform;
	class SpriteRenderer;
	class Font;
	class InputManager;
	class Renderer3D;
}

class SceneApp : public gef::Application
{
public:
	SceneApp(gef::Platform& platform);
	void Init();
	void CleanUp();
	bool Update(float frame_time);
	void Render();
private:
	void InitPlayer();
	void InitGround();
	void InitEnemy();
	void InitFont();
	void CleanUpFont();
	void DrawHUD();
	void SetupLights();
    
	gef::SpriteRenderer* sprite_renderer_;
	gef::Font* font_;
	gef::Renderer3D* renderer_3d_;
	gef::InputManager* input_manager_;

	PrimitiveBuilder* primitive_builder_;

	// create the physics world
	b2World* world_;
	
	// player variables
	Player player_;

	//Enemy Variables
	GameObject enemy_;
	b2Body* enemy_body_;

	// ground variables
	gef::Mesh* ground_mesh_;
	GameObject ground_;
	b2Body* ground_body_;

	float fps_;
};

#endif // _SCENE_APP_H
