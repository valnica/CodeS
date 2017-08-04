/////////////////////////////////////////////////////
// Name : Game
//
// Author : �R�c ����
//
// Day : 2017/8/3
/////////////////////////////////////////////////////
#pragma once

#include <memory>

#include "../GameBase/GameBase.h"

class GameObject;
class Camera;

/////////////////////////////////////////////////////
// Name : Game
//
// Over View : �Q�[���N���X
/////////////////////////////////////////////////////
class Game:public GameBase
{
private:
	std::shared_ptr<GameObject> obj_;
	std::shared_ptr<GameObject> obj2_;
	std::shared_ptr<GameObject> obj3_;
	std::shared_ptr<Camera> camera_;

public:
	Game();
	~Game();

	void Initialize() override;
	void Update() override;
	void Render() override;
};

