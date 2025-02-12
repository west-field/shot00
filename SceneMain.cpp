#include "DxLib.h"
#include "SceneMain.h"

#include <cassert>

#include "ShotBound.h"
#include "ShotNormal.h"
#include "ShotSin.h"

namespace
{
	//ショットの発射間隔
	constexpr int kShotInterval = 16;
}

SceneMain::SceneMain()
{
	m_hPlayerGraphic = -1;
	m_hShotGraphic = -1;
	m_hTestSound = -1;
	m_hBgmSound = -1;
}
SceneMain::~SceneMain()
{

}

// 初期化
void SceneMain::init()
{
	m_hPlayerGraphic = LoadGraph("data/player.bmp");
	m_hShotGraphic = LoadGraph("data/shot.bmp");

	m_hTestSound = LoadSoundMem("sound/cursor0.mp3");
	m_hBgmSound = LoadSoundMem("sound/bgm.mp3");

	m_player.setHandle(m_hPlayerGraphic);
	m_player.init();
	m_player.setMain(this);	//自身のポインタを取得する場合 this を使う
	m_player.setShotSe(m_hTestSound);

	PlaySoundMem(m_hBgmSound, DX_PLAYTYPE_LOOP, true);
}

// 終了処理
void SceneMain::end()
{
	//bgm終了
	StopSoundMem(m_hBgmSound);
	//グラフィックアンロード
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hShotGraphic);
	//サウンドアンロード
	DeleteSoundMem(m_hTestSound);
	DeleteSoundMem(m_hBgmSound);

	for (auto& pShot : m_pShotVt)
	{
		assert(pShot);
		delete pShot;		//確保されていたらdelete
		pShot = nullptr;		//中身をnullptrに
	}
}

// 毎フレームの処理
void SceneMain::update()
{
	m_player.update();
	std::vector<ShotBase*>::iterator it = m_pShotVt.begin();
	while (it != m_pShotVt.end())
	{
		auto& pShot = (*it);

		if (!pShot)
		{
			it++;
			continue;//中身があるかどうか　nullptrの時continue
		}
		pShot->update();
		if (!pShot->isExist())
		{
			delete pShot;
			pShot = nullptr;

			//vector要素の削除
			it = m_pShotVt.erase(it);
			continue;
		}

		it++;
	}
}

// 毎フレームの描画
void SceneMain::draw()
{
	m_player.draw();

	for (auto& pShot : m_pShotVt)
	{
		if (!pShot)	continue;
		pShot->draw();
	}

	//現在存在している弾の数を表示
	DrawFormatString(0, 0, GetColor(255, 255, 255), "弾の数:%d", m_pShotVt.size());
}

//弾の生成
bool SceneMain::createShotNormal(Vec2 pos)
{
	ShotNormal* pShot = new ShotNormal;
	pShot->setHandle(m_hShotGraphic);
	pShot->start(pos);
	m_pShotVt.push_back(pShot);

	return true;
}
bool SceneMain::createShotBound(Vec2 pos)
{
	ShotBound* pShot = new ShotBound;
	pShot->setHandle(m_hShotGraphic);
	pShot->start(pos);
	m_pShotVt.push_back(pShot);

	return true;
}
bool SceneMain::createShotSin(Vec2 pos)
{
	ShotSin* pShot = new ShotSin;
	pShot->setHandle(m_hShotGraphic);
	pShot->start(pos);
	m_pShotVt.push_back(pShot);

	return true;
}