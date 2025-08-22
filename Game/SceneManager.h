//--------------------------------------------------------------------------------------
// File: SceneManager.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include <memory>
#include <string>
#include <unordered_map>

// �O���Q��
class Scene;

// �V�[���}�l�[�W���[�N���X
class SceneManager
{

private:

	// �G�C���A�X�錾
	using SceneCollection = std::unordered_map<std::string, std::unique_ptr<Scene>>;

	// �V�[���Q
	SceneCollection m_scenes;

	// ���s���̃V�[��
	Scene* m_pCurrentScene;

	// �v�����ꂽ�V�[��
	Scene* m_pRequestedScene;

public:

	// �R���X�g���N�^
	SceneManager();

	// �f�X�g���N�^
	~SceneManager();

	// �V�[���̓o�^
	void RegisterScene(const std::string& sceneName, std::unique_ptr<Scene> scene);

	// �X�V����
	void Update(float elapsedTime);

	// �`�揈��
	void Render();

	// �J�n�V�[���̐ݒ�
	void SetStartScene(const std::string& startSceneName);

	// �V�[���̕ύX
	void RequestSceneChange(const std::string& requestSceneName);

private:

	// �V�[���̕ύX
	void ChangeScene();

};
