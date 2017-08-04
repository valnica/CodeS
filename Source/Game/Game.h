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

/////////////////////////////////////////////////////
// Name : Game
//
// Over View : �Q�[���N���X
/////////////////////////////////////////////////////
class Game:public GameBase
{
private:
	GameObject* obj_;

public:
	Game();
	~Game();

	void Initialize() override;
	void Update() override;
	void Render() override;
};

