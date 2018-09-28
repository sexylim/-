#include "stdafx.h"
#include "effectManager.h"
#include "effect.h"


HRESULT effectManager::init()
{
	return S_OK;
}

void effectManager::release()
{
	m_iter = m_mapEffects.begin();
	for (; m_iter != m_mapEffects.end(); )
	{

		vecEffect::iterator iter;
		vector<effect*> vecE= m_iter->second;

		// m_mapEffects <key,value>
		// key :string / (iterator-> first)
		// value :vector<effect*> /(iterator->second)
		// m_iter : m_mapEffects�� �����ϴ� ����(pair : key,value)�� ����ִ� �޸� �ּ�(������)
		// value�� �޾ƿ´� vecE (���⿡)
		//if(vecE!=NULL)

		// iter : vecE�� �����ϴ� ���Ҹ� ��� �ִ� �޸� �ּ�
		for (iter = vecE.begin(); iter != vecE.end(); iter++)
		{
			// m_iter->second�� �ȵǴ� ������ �ּҰ����� �ȿ� ���� �ƴϱ� ������ 
			
			if ((*iter))
			{
				(*iter)->release();
				SAFE_DELETE((*iter));
				
			}	
		}
		vecE.clear();

		// ���ͷ����� ��ü�� �Ѱܾ� ���ͷ����ͷ� �Ѿ��
		m_iter = m_mapEffects.erase(m_iter);


	}
	m_mapEffects.clear();


}


void effectManager::update()
{
	for (m_iter = m_mapEffects.begin(); m_iter != m_mapEffects.end(); m_iter++)
	{
		vecEffect::iterator iter;
		//����Ʈ�� �����͸� ���ҷ� ���� ����
		for (iter = m_iter->second.begin(); iter != m_iter->second.end(); iter++)
		{
			(*iter)->update();
		}

	}
}

void effectManager::render(HDC hdc)
{
	for (m_iter = m_mapEffects.begin(); m_iter != m_mapEffects.end(); m_iter++)
	{
		vecEffect::iterator iter;
		for (iter = m_iter->second.begin(); iter != m_iter->second.end(); iter++)
		{
			(*iter)->render(hdc);
		}

	}
}


void effectManager::addEffect(string effectName,
	const char * imageName, int imageWidth, int imageHeight,
	int frameWidth, int frameHeight, int fps,
	int bufferCount ,float elapsedTime/*=0.0f */)
{
	image* pImage = IMAGEMANAGER->addImage(effectName, imageName, imageWidth, imageHeight, true, RGB(255, 0, 255));

	vecEffect vecEffects;
	for (int i = 0; i < bufferCount; i++)
	{
		effect* pEffect = new effect;
		pEffect->init(pImage,
			frameWidth, frameHeight, fps, elapsedTime);

		vecEffects.push_back(pEffect);
	}

	m_mapEffects.insert(
		pair<string, vecEffect>(effectName, vecEffects));
}

void effectManager::play(string effectName, int x, int y)
{
	m_iter = m_mapEffects.find(effectName);

	if (m_iter!= m_mapEffects.end())
	{
		vecEffect::iterator iter;
		for (iter = m_iter->second.begin(); iter != m_iter->second.end(); iter++)
		{
			if ((*iter)->getIsAlive()) continue;

			(*iter)->startEffect(x, y);
			return;
		}
		
	}

	

}

effectManager::effectManager()
{
}


effectManager::~effectManager()
{
}