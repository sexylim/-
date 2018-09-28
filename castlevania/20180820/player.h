#pragma once
class player
{
private:
	// �÷��̾� �̹���
	image *	 m_pImg;
	image *	 m_pImg2;
	
	// �÷��̾� ��Ʈ
	RECT	 m_rc;
	
	// �÷��̾� �Ӽ� ��
	float	 m_Speed;
	float	 m_fX;
	float	 m_fY;

	float	m_JumP;

	// �÷��̾� �����Ӽ��� �Ӽ�
	int		m_nRCurrFrameX;
	int		m_nRCurrFrameY;

	int		m_nLCurrFrameX;
	int		m_nLCurrFrameY;
	int		m_nCount;

	int		m_Gravity;

	// �÷��̾ ���� �ִ� ���� �Ӽ�
	bool	m_PlayerSee;

	// �÷��̾��� ���� ���
	bool	m_PlayerAttack;

	// �÷��̾��� ���� ���
	int		m_PlayerJump;

	// �÷��̾��� �ɱ� ���
	int		m_PlayerDown;

public:
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	player();
	~player();
};

