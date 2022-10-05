#include "DxLib.h"
#include "SceneMain.h"

namespace
{
	//ショットの発射間隔
	constexpr int kShotInterval = 16;
}

SceneMain::SceneMain()
{
	m_hPlayerGraphic = -1;
	m_hShotGraphic = -1;
}
SceneMain::~SceneMain()
{

}

// 初期化
void SceneMain::init()
{
	m_hPlayerGraphic = LoadGraph("data/player.bmp");
	m_hShotGraphic = LoadGraph("data/shot.bmp");

	m_player.setHandle(m_hPlayerGraphic);
	m_player.init();
	m_player.setMain(this);	//自身のポインタを取得する場合 this を使う

	for (auto& shot : m_pShotNormal)
	{
		shot = nullptr;	//	何も入っていない状態で初期化
	}
	for (auto& shot : m_pShotBound)
	{
		shot = nullptr;
	}
	for (auto& shot : m_pShotMeandeling)
	{
		shot = nullptr;
	}
}

// 終了処理
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hShotGraphic);

	for (auto& shot : m_pShotNormal)
	{
		if (!shot)	continue;//nullptrの時中には何もないからdeleteしない
		delete shot;		//確保されていたらdelete
		shot = nullptr;		//中身をnullptrに
	}
	for (auto& shot : m_pShotBound)
	{
		if (!shot)	continue;
		delete shot;
		shot = nullptr;
	}
	for (auto& shot : m_pShotMeandeling)
	{
		if (!shot)	continue;
		delete shot;
		shot = nullptr;
	}
}

// 毎フレームの処理
void SceneMain::update()
{
	m_player.update();
	for (auto& shot : m_pShotNormal)
	{
		if (!shot)	continue;//中身があるかどうか　nullptrの時continue
		shot->update();
	}
	for (auto& shot : m_pShotBound)
	{
		if (!shot)	continue;
		shot->update();
	}
	for (auto& shot : m_pShotMeandeling)
	{
		if (!shot)	continue;
		shot->update();
	}
}

// 毎フレームの描画
void SceneMain::draw()
{
	m_player.draw();

	for (auto& shot : m_pShotNormal)
	{
		if (!shot)	continue;
		shot->draw();
		if (!shot->isExist())
		{
			delete shot;
			shot = nullptr;
		}
	}
	for (auto& shot : m_pShotBound)
	{
		if (!shot)	continue;
		shot->draw();
		if (!shot->isExist())
		{
			delete shot;
			shot = nullptr;
		}
	}
	for (auto& shot : m_pShotMeandeling)
	{
		if (!shot)	continue;
		shot->draw();
		if (!shot->isExist())
		{
			delete shot;
			shot = nullptr;
		}
	}

	//現在存在している弾の数を表示
	int shotNum = 0;
	for (auto& shot : m_pShotNormal)
	{
		if (!shot)	continue;
		if (shot->isExist())	shotNum++;
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Normal:%d", shotNum);
	
	shotNum = 0;
	for (auto& shot : m_pShotBound)
	{
		if (!shot)	continue;
		if (shot->isExist())	shotNum++;
	}
	DrawFormatString(0, 20, GetColor(255, 255, 255), "Bound:%d", shotNum);

	shotNum = 0;
	for (auto& shot : m_pShotMeandeling)
	{
		if (!shot)	continue;
		if (shot->isExist())	shotNum++;
	}
	DrawFormatString(0, 40, GetColor(255, 255, 255), "Meandeling:%d", shotNum);

}

//弾の生成
bool SceneMain::createShotNormal(Vec2 pos)
{
	for (auto& shot : m_pShotNormal)
	{
		if (shot)	continue;	//すでにある場合は処理しない

		shot = new ShotNormal;
		shot->setHandle(m_hShotGraphic);
		shot->start(pos);
		return true;
	}
	return false;
}
bool SceneMain::createShotBound(Vec2 pos)
{
	for (auto& shot : m_pShotBound)
	{
		if (shot)	continue;

		shot = new ShotBound;				//メモリを確保
		shot->setHandle(m_hShotGraphic);	//確保したメモリに住所を指定
		shot->start(pos);
		return true;
	}
	return false;
}
bool SceneMain::createShotMeandeling(Vec2 pos)
{
	for (auto& shot : m_pShotMeandeling)
	{
		if (shot)	continue;

		shot = new ShotMeandeling;
		shot->setHandle(m_hShotGraphic);
		shot->start(pos);
		return true;
	}
	return false;
}