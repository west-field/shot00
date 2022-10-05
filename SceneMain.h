#pragma once

#include "player.h"
#include "ShotBase.h"

class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	// 初期化
	void init();
	// 終了処理
	void end();

	// 毎フレームの処理
	void update();
	// 毎フレームの描画
	void draw();

	//弾の生成
	bool createShotNormal(Vec2 pos);
	bool createShotBound(Vec2 pos);
	bool createShotMeandeling(Vec2 pos);
	
private:
	// ショットの最大数
	static constexpr int kShotMax = 64;

private:

	// プレイヤーのグラフィックハンドル
	int m_hPlayerGraphic;
	//ショットのグラフィックハンドル
	int m_hShotGraphic;
	// プレイヤー
	Player m_player;
	// ショット

	ShotBase* m_pShot[kShotMax];//ベースクラスのポインタに継承先のクラスを入れることができる

//	ShotBound* m_pShotBound[kShotMax];//反射
//	ShotMeandeling* m_pShotMeandeling[kShotMax];//蛇行
//	ShotNormal* m_pShotNormal[kShotMax];//まっすぐ
// ShotSlanting* m_shot[kShotMax];//斜め
//	ShotSin* m_shotSin[kShotMax];
};