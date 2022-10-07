#pragma once

#include "Vec2.h"

class SceneMain;	//相互にヘッダーのインクルードが必要な時、後で使う宣言をする

class Player
{
public:
	Player();
	virtual ~Player();

	// グラフィックデータ設定
	void setHandle(int handle) { m_handle = handle; }

	// プレイヤーの初期化
	void init();
	//SceneMainクラスのポインタ
	void setMain(SceneMain* pMain) { m_pMain = pMain; }

	// 処理
	void update();
	// 描画
	void draw();

	// 情報の取得
	Vec2 getPos() const { return m_pos; }

	Vec2 getStartPos() const { return m_startPos; }

	void setShotSe(int shotSe){ m_hShotSe = shotSe; }
private:
	int m_handle;
	int m_hShotSe;
	//SceneMainのポインタ
	SceneMain* m_pMain;

	// 表示位置
	Vec2 m_pos;
	// 移動
	Vec2 m_vec;
	//ショットの発射間隔
	int m_shotInterval;

	//ショットが手の位置から発射
	Vec2 m_startPos;
};