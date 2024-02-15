#include <Novice.h>
#include "MT.h"
#include"Matrix4x4.h"
#include"Vector3.h"
#include"Vector2.h"
#include<cmath>
#include <cassert>
#define _USE_MATH_DEFINES

const char kWindowTitle[] = "LE2C_27_ワタナベアキヒロ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);


	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Quaternion q1 = { 2.0f,3.0f,4.0f,1.0f };
	Quaternion q2 = { 1.0f,3.0f,5.0f,2.0f };
	Quaternion identity = IdentityQuaternion();
	Quaternion conj = Conjugate(q1);
	Quaternion inv = InverseQuaternion(q1);
	Quaternion normal = NormalizeQuaternion(q1);
	Quaternion mul1 = Multiply(q1, q2);
	Quaternion mul2 = Multiply(q2, q1);
	float norm = Norm(q1);


	static const int kWindowWidth = 1280;
	static const int kWindowHeght = 720;
	static const int kRowHeight = 20;
	static const int kColumnWidth = 60;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		Novice::ScreenPrintf(20, 20, "%.2f,%.2f,%.2f,%.2f :Identity", identity.x, identity.y, identity.z, identity.w);
		Novice::ScreenPrintf(20, 40, "%.2f,%.2f,%.2f,%.2f : Conjugate", conj.x, conj.y, conj.z, conj.w);
		Novice::ScreenPrintf(20, 60, "%.2f,%.2f,%.2f,%.2f : Inverse", inv.x, inv.y, inv.z, inv.w);
		Novice::ScreenPrintf(20, 80, "%.2f,%.2f,%.2f,%.2f : Normalize", normal.x, normal.y, normal.z, normal.w);
		Novice::ScreenPrintf(20, 100, "%.2f,%.2f,%.2f,%.2f : Multiply(q1, q2)", mul1.x, mul1.y, mul1.z, mul1.w);
		Novice::ScreenPrintf(20, 120, "%.2f,%.2f,%.2f,%.2f : Multiply(q2, q1)", mul2.x, mul2.y, mul2.z, mul2.w);
		Novice::ScreenPrintf(20, 140, "%.2f : Norm", norm);
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
