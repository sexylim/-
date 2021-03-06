#pragma once
class player
{
private:
	// 플레이어 이미지
	image *	 m_pImg;
	image *	 m_pImg2;
	
	// 플레이어 렉트
	SYNTHESIZE (RECT, m_rc,Rc);
	
	// 플레이어 속성 값


	float	m_JumP;

	float	m_SildeP;

	float	m_BackP;

	int		m_SildeC;

	int		m_BackC;
	float m_Speed;
	SYNTHESIZE( float, m_fX,Fx);
	SYNTHESIZE(float, m_fY,FY);

	// 플레이어 프레임설정 속성
	int		m_nRCurrFrameX;
	int		m_nRCurrFrameY;

	int		m_nLCurrFrameX;
	int		m_nLCurrFrameY;
	int		m_nCount;

	int		m_Gravity;

	// 플레이어가 보고 있는 방향 속성
	bool	m_PlayerSee;

	// 플레이어의 공격 모션
	bool	m_PlayerAttack;

	// 플레이어의 점프 모션
	int		m_PlayerJump;

	// 플레이어의 앉기 모션
	int		m_PlayerDown;

	// 플레이어의 슬라이딩 모션
	bool	m_PlayerSilde;

	// 플레이어의 백대쉬 모션
	bool	m_PlayerBackDash;

	SYNTHESIZE(bool,m_xCameraOn,XCameraOn);
	SYNTHESIZE(bool, m_yCameraOn, YCameraOn);
public:
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void mapMove();

	void mapchackCollision();

	player();
	~player();
};

