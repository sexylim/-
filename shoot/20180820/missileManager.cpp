#include "stdafx.h"
#include "missileManager.h"

HRESULT missileManager::init()
{

	//m_vecMissile.resize(m_nMaxCount);
	m_vecMissile.reserve(m_nMaxCount);

	// ������ ������ ����
	//int size = m_vecMissile.size();

	return S_OK;
}

HRESULT missileManager::init(const char* szImageName, float range, int maxCount)
{
	m_fRange = range;
	m_nMaxCount = maxCount;
	m_szImageName = szImageName;

	//m_vecMissile.resize(m_nMaxCount);
	m_vecMissile.reserve(m_nMaxCount);

	// ������ ������ ����
	//int size = m_vecMissile.size();

	return S_OK;
}

void missileManager::release()
{
	for (m_iter = m_vecMissile.begin(); 
		m_iter != m_vecMissile.end(); m_iter++)
	{
		delete (*m_iter);
	}
	m_vecMissile.clear();
}

void missileManager::update()
{
	for (m_iter = m_vecMissile.begin(); m_iter != m_vecMissile.end(); m_iter++)
	{
		(*m_iter)->update();
	}
}

void missileManager::render(HDC hdc)
{
	for (m_iter = m_vecMissile.begin(); m_iter != m_vecMissile.end(); m_iter++)
	{
		(*m_iter)->render(hdc);
	}
}

void missileManager::fire(float x, float y, float angle, float speed ,int patton/*=0*/)
{
	//if (m_vecMissile.size() > m_nMaxCount)	return;

	missile* pMissile;
	pMissile = NULL;
	for (m_iter = m_vecMissile.begin(); m_iter != m_vecMissile.end(); m_iter++)
	{
		if ((*m_iter) != NULL)
		{
			if (!(*m_iter)->getIsFire())
			{
				pMissile = (*m_iter);
				pMissile->setTarget(m_pTarget);
				pMissile->init(m_szImageName, speed, x, y, angle, 1000, patton);
			}
		}

	}
	if (pMissile == NULL)
	{
		pMissile = new missile;
		pMissile->setTarget(m_pTarget);
		pMissile->init(m_szImageName, speed, x, y, angle, 1000, patton);
		m_vecMissile.push_back(pMissile);
	}
	//missile* pMissile = new enemyMissile;

	// 1. reserve ���� ��


	// Ÿ���� ������ �ش�

	pMissile->fire(x, y);

	//// 2. resize ���� ��
	//m_vecMissile[0]->init(m_szImageName, speed,
	//	x, y, angle, 100);
}


void missileManager::fire(float x, float y)
{
	//if (m_vecMissile.size() > m_nMaxCount)	return;

	missile* pMissile;
	pMissile = NULL;
	for (m_iter = m_vecMissile.begin(); m_iter != m_vecMissile.end(); m_iter++)
	{
		if ((*m_iter) != NULL)
		{
			if (!(*m_iter)->getIsFire())
			{
				pMissile = (*m_iter);
			}
		}

	}
	if (pMissile == NULL)
	{
		pMissile = new missile;
		pMissile->init();
		m_vecMissile.push_back(pMissile);
	}

	//missile* pMissile = new enemyMissile;

	// 1. reserve ���� ��



	// Ÿ���� ������ �ش�

	pMissile->fire(x, y);

	//// 2. resize ���� ��
	//m_vecMissile[0]->init(m_szImageName, speed,
	//	x, y, angle, 100);
}

void missileManager::move()
{
}

missileManager::missileManager()
{
}


missileManager::~missileManager()
{
}
