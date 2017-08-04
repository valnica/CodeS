/////////////////////////////////////////////////////
// Name : Game
//
// Author : 山田 聖弥
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
// Over View : ゲームクラス
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

