#include "stdafx.h"
#include "roomManager.h"
#include "room.h"


roomManager::roomManager()
{
}


roomManager::~roomManager()
{
}

HRESULT roomManager::init()
{
	return S_OK;
}

void roomManager::release()
{
}

void roomManager::update()
{
}

void roomManager::render(HDC hdc)
{
}

room * roomManager::addRoom(string roomName, room * pRoom)
{
	if (!pRoom)	return NULL;

	m_mapRooms.insert(pair<string, room*>(roomName, pRoom));

	return pRoom;
}

HRESULT roomManager::changeRoom(string sceneName)
{

	// �ʿ��� �ٲٰ����ϴ� ���� ã�´�
	m_iter = m_mapRooms.find(sceneName);
	// �ʿ��� �ٲٰ����ϴ� ���� �� ã����
	if (m_iter == m_mapRooms.end())	return E_FAIL;

	// �ٲٰ����ϴ� ���� ������� ������
	if (m_iter->second == m_pCurrRoom)	return S_OK;

	// �ٲٰ����ϴ� ���� ã������ �ʱ�ȭ
	if (SUCCEEDED(m_iter->second->init()))
	{
		// �ʱ�ȭ ���� ��, ���� ���� release
		if (m_pCurrRoom)
			m_pCurrRoom->release();

		// ���� ���� �ٲٰ����ϴ� ������ ��ü
		m_pCurrRoom = m_iter->second;
		return S_OK;
	}

	return E_FAIL;

}

