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

	for (auto& shot : m_shot)
	{
		shot.setHandle(m_hShotGraphic);
	}
}

// 終了処理
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hShotGraphic);
}

// 毎フレームの処理
void SceneMain::update()
{
	m_player.update();
	for (auto& shot : m_shot)
	{
		shot.update();
	}
}

// 毎フレームの描画
void SceneMain::draw()
{
	m_player.draw();

	for (auto& shot : m_shot)
	{
		shot.draw();
	}

	//現在存在している弾の数を表示
	int shotNum = 0;
	for (auto& shot : m_shot)
	{
		if (shot.isExist())	shotNum++;
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "弾の数:%d", shotNum);
}

//弾の生成
bool SceneMain::createShot(Vec2 pos)
{
	for (auto& shot : m_shot)
	{
		if (shot.isExist())	continue;	//既に使われていたら次へ

		shot.start(pos);	//使われていなかったら打つ
		return true;
	}
	return false;
}