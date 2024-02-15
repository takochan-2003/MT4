#include "MT.h"
#include "Matrix4x4.h"
#include "Vector2.h"
#include "Vector3.h"
#include <Novice.h>
#include <cassert>
#include <cmath>
#define _USE_MATH_DEFINES

const char kWindowTitle[] = "LE2C_27_ワタナベアキヒロ";

static const int kRowHeight = 20;
static const int kColumnWidth = 60;

void VectorScreenPrintf(int x, int y, Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%0.2f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%0.2f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%0.2f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);
}

void QuaternionScreenPrintf(int x, int y, Quaternion& Q, const char* label) {
	Novice::ScreenPrintf(x, y, "%0.2f", Q.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%0.2f", Q.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%0.2f", Q.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%0.2f", Q.w);
	Novice::ScreenPrintf(x + kColumnWidth * 4, y, "%s", label);
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Quaternion rotation0 = MakeRotateAxisAngleQuaternion({ 0.71f, 0.71f, 0.0f }, 0.3f);

	Quaternion rotation1 = MakeRotateAxisAngleQuaternion({ 0.71f, 0.0f, 0.71f }, 3.141592f);

	Quaternion interpolate0 = Slerp(rotation0, rotation1, 0.0f);

	Quaternion interpolate1 = Slerp(rotation0, rotation1, 0.3f);

	Quaternion interpolate2 = Slerp(rotation0, rotation1, 0.5f);

	Quaternion interpolate3 = Slerp(rotation0, rotation1, 0.7f);

	Quaternion interpolate4 = Slerp(rotation0, rotation1, 1.0f);

	static const int kWindowWidth = 1280;
	static const int kWindowHeght = 720;

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
		QuaternionScreenPrintf(0, 50, interpolate0, "interpolate0, Slerp(q0, q1, 0.0f)");
		QuaternionScreenPrintf(0, 100, interpolate1, "interpolate1, Slerp(q0, q1, 0.3f)");
		QuaternionScreenPrintf(0, 150, interpolate2, "interpolate2, Slerp(q0, q1, 0.5f)");
		QuaternionScreenPrintf(0, 200, interpolate3, "interpolate3, Slerp(q0, q1, 0.7f)");
		QuaternionScreenPrintf(0, 250, interpolate4, "interpolate4, Slerp(q0, q1, 1.0f)");
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
