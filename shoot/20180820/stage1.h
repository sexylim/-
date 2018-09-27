#pragma once

class enemyManager;
class player;
class sanger;

class stage1
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
		}

		//void init();

		//~tagImageInfo() {}
	} MEM_INFO, *LPMEM_INFO;

	image* m_imgBg;

	SYNTHESIZE(enemyManager*, m_pEnemyMgr, EnemyMgr);
	SYNTHESIZE(player*, m_pPlayer, Player);
	SYNTHESIZE(sanger*, m_pSanger, Sanger);

	SYNTHESIZE(LPMEM_INFO, m_pMemDCInfo, MemDCInfo);

	POINT m_posBG;
	SYNTHESIZE(POINT, m_posMap, Map)

	RECT m_colliderRect[3];


	
public:

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	RECT* getColliderRect() { return m_colliderRect; }

	void colliderMake(int width,int height);

	void mapPartRander(HDC hdc);

	void stage1EnemyMaking();

	stage1();
	~stage1();
};

