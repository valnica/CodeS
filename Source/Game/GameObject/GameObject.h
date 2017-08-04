/////////////////////////////////////////////////////
// Name : GameObject
//
// Author : 山田 聖弥
//
// Day : 2017/8/4
/////////////////////////////////////////////////////
#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include <Model.h>

class Component;
class Transform;

/////////////////////////////////////////////////////
// Name : GameObject
//
// Over View : ゲームのオブジェクトクラス
/////////////////////////////////////////////////////
class GameObject
{
protected:
	std::unordered_map<std::string, std::shared_ptr<Component>> component_;
	Transform* transform_;

	std::unique_ptr<DirectX::Model> model_;

public:
	//コンストラクタ
	GameObject();

	//デストラクタ
	~GameObject();

	//更新処理
	void Update();

	/////////////////////////////////////////////////////
	// Name : AddComponent
	//
	// Over View : コンポネントの追加
	//
	// Argument : コンポネントの名前
	//
	// Return : 無し
	/////////////////////////////////////////////////////
	template <typename T>
	void AddComponent(std::string componentTag)
	{
		if (component_.count(componentTag) <= 0)
		{
			std::shared_ptr<T> component;
			component.reset(new T);
			component_[componentTag] = component;
		}
	}

	/////////////////////////////////////////////////////
	// Name : GetComponent
	//
	// Over View : コンポネントの取得
	//
	// Argument : コンポネントの名前
	//
	// Return : コンポネントのポインタ
	/////////////////////////////////////////////////////
	template <typename T>
	T* GetComponent(std::string componentTag)
	{
		T* component = nullptr;

		if (component_.count(componentTag) >= 0)
		{
			component = (T*)component_[componentTag].get();
		}

		return component;
	}
};