#include "stdafx.h"
#include "enemyManager.h"
#include "spaceShip.h"


HRESULT enemyManager::init()
{
	m_bisAllClear = false;
	m_bisSetting = false;
	return S_OK;
}

void enemyManager::release()
{
	// vector�� ù ���Һ��� ������ ���ұ��� ��ȸ�ϸ� �� ���Ҹ� delete�Ѵ�
	for (m_iter = m_vecEnemy.begin(); m_iter != m_vecEnemy.end(); m_iter++)
	{
		delete (*m_iter);
	}
	// vector ��ü�� �����Ѵ�
	m_vecEnemy.clear();
}

void enemyManager::update()
{
	m_bisAllClear = true;
	m_bisSetting = false;
	m_bisSetting = false;
	// vector�� ù ���Һ��� ������ ���ұ��� ��ȸ�ϸ� �� ���Ҹ� update�Ѵ�
	for (m_iter = m_vecEnemy.begin(); m_iter != m_vecEnemy.end(); m_iter++)
	{
		if ((*m_iter)->getIsAlive())
		{
			m_bisAllClear = false;
			(*m_iter)->update();

		}

		//m_bisSetting = (*m_iter)->getIsSetting();
		m_bisSetting = m_vecEnemy[m_vecEnemy.size() - 1]->getIsSetting();
		(*m_iter)->setIsAllSetting(m_bisSetting);
	}


}

void enemyManager::render(HDC hdc)
{
	// vector�� ù ���Һ��� ������ ���ұ��� ��ȸ�ϸ� �� ���Ҹ� render�Ѵ�
	for (m_iter = m_vecEnemy.begin(); m_iter != m_vecEnemy.end(); m_iter++)
	{
		if ((*m_iter)->getIsAlive())
			(*m_iter)->render(hdc);


	}
}

void enemyManager::setEnemy(int countX, int countY,int stage ,int baseX,int baseY,int intervalX,int intervalY)
{
	
	for (int i = 0; i < countY; i++)
	{
		for (int j = 0; j < countX; j++)
		{
			enemy* pEnemy;
			switch (stage)
			{
			case 1:
				//130 70 100 60
				pEnemy = new enemy;
				pEnemy->init("image/ufo.bmp", PointMake(-10 - 70 * j, -10 - 60 * i), PointMake(baseX + intervalX * j, baseY + intervalY * i));

				// vector�� ������ ���� �ڿ� ���ο� �����͸� �߰��Ѵ�
				m_vecEnemy.push_back(pEnemy);

				break;
			



			default:
			case 2:
				
				pEnemy = new enemy;
				pEnemy->init("image/ufoGOLD.bmp", PointMake(-10 - 70 * j, -10 - 60 * i), PointMake(baseX + intervalX * j, baseY + intervalY * i));

				// vector�� ������ ���� �ڿ� ���ο� �����͸� �߰��Ѵ�
				m_vecEnemy.push_back(pEnemy);


				break;
			}


		}
	}
}


void enemyManager::setEnemy(vector<int> vec, int stage)
{

	for (int i = 0; i < vec[5]; i++)
	{
		for (int j = 0; j < vec[4]; j++)
		{
			enemy* pEnemy;
			switch (stage)
			{
			case 1:
				//130 70 100 60
				pEnemy = new enemy;
				pEnemy->init("image/ufo.bmp", PointMake(vec[6] - vec[8] * j, vec[7] - vec[8] * i), PointMake(vec[0] + vec[2] * j, vec[1] + vec[3] * i));

				// vector�� ������ ���� �ڿ� ���ο� �����͸� �߰��Ѵ�
				m_vecEnemy.push_back(pEnemy);

				break;




			default:
			case 2:

				pEnemy = new enemy;
				pEnemy->init("image/ufoGOLD.bmp", PointMake(vec[6] - vec[8] * j, vec[7] - vec[8] * i), PointMake(vec[0] + vec[2] * j, vec[1] + vec[3] * i));

				// vector�� ������ ���� �ڿ� ���ο� �����͸� �߰��Ѵ�
				m_vecEnemy.push_back(pEnemy);


				break;
			}


		}
	}
}

void enemyManager::setTarget(spaceShip * pTarget)
{

	for (m_iter = m_vecEnemy.begin(); m_iter != m_vecEnemy.end(); m_iter++)
	{
		if ((*m_iter)->getIsAlive())
		{
			(*m_iter)->setTarget(pTarget);

		}
	}
}

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}
