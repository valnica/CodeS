/////////////////////////////////////////////////////
// Name : ModelRenderer
//
// Author : 山田 聖弥
//
// Day : 2017/8/4
/////////////////////////////////////////////////////
#pragma once

#include <Model.h>
#include <string>
#include "../Renderer.h"

/////////////////////////////////////////////////////
// Name : ModelRenderer
//
// Over View : モデルのレンダラークラス
/////////////////////////////////////////////////////
class ModelRenderer:public Renderer
{
private:
	std::shared_ptr<DirectX::Model> model_;
	
	static std::string tag_;

public:
	ModelRenderer();
	~ModelRenderer();

	void Initialize(Transform* transform, wchar_t* modelPath);
	void Render(Math::Matrix view, Math::Matrix proj) override;
	
	static std::string Tag();
};