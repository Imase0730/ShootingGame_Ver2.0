//--------------------------------------------------------------------------------------
// File: SceneManager.cpp
//
//--------------------------------------------------------------------------------------
#include "SceneManager.h"
#include "Scene.h"

// �R���X�g���N�^
SceneManager::SceneManager()
	: m_scenes{}
	, m_pCurrentScene{ nullptr }
	, m_pRequestedScene{ nullptr }
{
}

// �f�X�g���N�^
SceneManager::~SceneManager()
{
	// ���s���̃V�[���̏I������
	if (m_pCurrentScene) m_pCurrentScene->Finalize();
}

// �V�[���̓o�^
void SceneManager::RegisterScene(const std::string& sceneName, std::unique_ptr<Scene> scene)
{
	// �V�[���̖��O�ŃV�[����o�^
	m_scenes.emplace(sceneName, std::move(scene));
}

// �X�V����
void SceneManager::Update(float elapsedTime)
{
	// �V�[���̕ύX
	if (m_pRequestedScene) ChangeScene();

	// �V�[���̍X�V
	if (m_pCurrentScene) m_pCurrentScene->Update(elapsedTime);
}

// �`�揈��
void SceneManager::Render()
{
	// �V�[���̕`�揈��
	if (m_pCurrentScene) m_pCurrentScene->Render();
}

// �J�n�V�[���̐ݒ�
void SceneManager::SetStartScene(const std::string& startSceneName)
{
	RequestSceneChange(startSceneName);
}

// �V�[���̕ύX
void SceneManager::RequestSceneChange(const std::string& requestSceneName)
{
	// �V�[�������o�^�H
	if (m_scenes.count(requestSceneName) == 0)
	{
		OutputDebugString(L"%s�͓o�^����Ă��܂���B", requestSceneName.c_str());
		return;
	}

	// �o�^���ꂽ���N�G�X�g�V�[�����擾
	m_pRequestedScene = m_scenes[requestSceneName].get();
}

// �V�[���̕ύX
void SceneManager::ChangeScene()
{
	// �V�[���̃��N�G�X�g�v�����Ȃ��H
	if (!m_pRequestedScene) return;

	// ���s���̃V�[���̏I������
	if (m_pCurrentScene) m_pCurrentScene->Finalize();

	// ���N�G�X�g�v���̃V�[���ֈڍs
	m_pCurrentScene = m_pRequestedScene;
	// �V�[���̏���������
	m_pCurrentScene->Initialize();

	// ���N�G�X�g�v�����N���A
	m_pRequestedScene = nullptr;
}

