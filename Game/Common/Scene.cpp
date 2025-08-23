//--------------------------------------------------------------------------------------
// File: Scene.cpp
//
//--------------------------------------------------------------------------------------
#include "Scene.h"
#include "SceneManager.h"

// �R���X�g���N�^
Scene::Scene(SceneManager* pSceneManager)
	: m_pSceneManager(pSceneManager)
{

}

// �f�X�g���N�^
Scene::~Scene()
{

}

// �V�[���̕ύX
void Scene::ChangeScene(const std::string& nextSceneName)
{
	m_pSceneManager->RequestSceneChange(nextSceneName);
}
