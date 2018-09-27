#pragma once
#include <vector>
#include "enemy.h"

class enemyManager
{
private:
	// std::vector ��� ���� : enemy*
	// ������ �˰� �ִ� �迭�� ���� ���·� ����ȴ�
	std::vector<enemy*>	m_vecEnemy;
	// <enemy* �� ���ҷ� ������ vector>�� ������ �ּҰ��� ��� ����
	std::vector<enemy*>::iterator	m_iter;

public:
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void setEnemy(int countX, int countY);
	void setEnemy( player * pTarget, int Phase);
	void setTarget(player* pTarget);

	inline std::vector<enemy*>	getVecEnemy() { return m_vecEnemy; }
	inline std::vector<enemy*>::iterator getIterEnemy() { return m_iter; }

	enemyManager();
	~enemyManager();
};

