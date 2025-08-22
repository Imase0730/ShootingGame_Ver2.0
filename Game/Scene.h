//--------------------------------------------------------------------------------------
// File: Scene.h
//
//--------------------------------------------------------------------------------------
#pragma once

// �O���錾
class SceneManager;

// �V�[���N���X
class Scene
{
private:

	// �V�[���}�l�[�W���[�ւ̃|�C���^
	SceneManager* m_pSceneManager;

public:

	// �R���X�g���N�^
	Scene(SceneManager* pSceneManager);

	// �f�X�g���N�^
	virtual ~Scene();

	// ����������
	virtual void Initialize() = 0;

	// �X�V����
	virtual void Update(float elapsedTime) = 0;

	// �`�揈��
	virtual void Render() = 0;

	// �I������
	virtual void Finalize() = 0;

protected:

	// �V�[���̕ύX
	void ChangeScene(const std::string& nextSceneName);

};
