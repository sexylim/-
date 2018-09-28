#pragma once
#include "room.h"

class image;
class player;
class enemyManager;

class hallwayRoom1
{

private:
	typedef struct tagMemDCInfo
	{
		HDC		hMemDC;	// ȭ�鿡 ��, ��, ���� ���� �׸� �� �ʿ��� ������ �����ϴ� ��ü
						// �׸��� �׸� �� �ʿ��� �޸� ���� �Ҵ�(��ȭ�� ����)
		HBITMAP	hBitmap;	// �̹������� �ε忡 ���Ǵ� ��ü
		HBITMAP hOldBitmap;
		int		nWidth;		// �̹��� �ʺ�
		int		nHeight;	// �̹��� ����


		tagMemDCInfo()
		{
			hMemDC = NULL;
			hBitmap = NULL;
			hOldBitmap = NULL;
			nWidth = 0;
			nHeight = 0;
		}//

		//void init();

		//~tagImageInfo() {}
	} MEM_INFO, *LPMEM_INFO;

	SYNTHESIZE(enemyManager*, m_pEnemyMgr, EnemyMgr);
	SYNTHESIZE(player*, m_pPlayer, Player);

	SYNTHESIZE(LPMEM_INFO, m_pMemDCInfo, MemDCInfo);

	image* m_imgBg;
	image* m_imgMap;

	SYNTHESIZE(POINT, m_posMap, Map)
	POINT m_posBG;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void colliderMake(int width, int height);

	hallwayRoom1();
	~hallwayRoom1();
};

