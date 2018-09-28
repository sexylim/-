#pragma once
#include "singletonBase.h"
class room;

class roomManager :public singletonBase<roomManager>
{
private:
	map<string, room*>	m_mapScenes;
	map<string, room*>::iterator	m_iter;


	static room*	m_pCurrScene;	// ���� ��
	static room*	m_pNextScene;	// ��ȯ ��� ���� ��


										// ���� ��					�ѹ� ������ �Ǹ� �޸𸮿� �ö󰡼� ���α׷��� ������ ������ �ȳ�����
										// ��ȯ ��� ���� ��		���������� �޸𸮿� �ö������� ��Ȳ�� ��������� ���� ������ �������� ������(static)
										//�ε� ��				�׷��� �ٸ� Ŭ�������� ����ƽ���� ���� �̸����� ����� �� ���� �ȴ�.(���� ����)

public:
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	//�Ϲ� ��
	scene* addScene(string sceneName, room* pScene);
	HRESULT changeScene(string sceneName);


	//friend: ĸ��ȭ �Ѱ��� ���� ����
	roomManager();
	~roomManager();
};

