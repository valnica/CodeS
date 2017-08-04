/////////////////////////////////////////////////////
// Name : GameObject
//
// Author : �R�c ����
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
// Over View : �Q�[���̃I�u�W�F�N�g�N���X
/////////////////////////////////////////////////////
class GameObject
{
protected:
	std::unordered_map<std::string, std::shared_ptr<Component>> component_;
	Transform* transform_;

	std::unique_ptr<DirectX::Model> model_;

public:
	//�R���X�g���N�^
	GameObject();

	//�f�X�g���N�^
	~GameObject();

	//�X�V����
	void Update();

	/////////////////////////////////////////////////////
	// Name : AddComponent
	//
	// Over View : �R���|�l���g�̒ǉ�
	//
	// Argument : �R���|�l���g�̖��O
	//
	// Return : ����
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
	// Over View : �R���|�l���g�̎擾
	//
	// Argument : �R���|�l���g�̖��O
	//
	// Return : �R���|�l���g�̃|�C���^
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