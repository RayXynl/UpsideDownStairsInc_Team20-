#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include <graphics/mesh_instance.h>
#include <box2d/Box2D.h>

enum class objectType
{
	PLAYER,
	GROUND,
	ENEMY
};

class GameObject : public gef::MeshInstance
{
public:
	void UpdateFromSimulation(const b2Body* body);

	objectType type_;
};

#endif // _GAME_OBJECT_H