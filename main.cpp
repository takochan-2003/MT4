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

	Quaternion rotation =
		MakeRotateAxisAngleQuaternion(Normalize(Vector3{ 1.0f, 0.4f, -0.2f }), 0.45f);
	Vector3 pointY = { 2.1f, -0.9f, 1.3f };
	Matrix4x4 rotateMatrix = MakeQRotateMatrix(rotation);

	Vector3 rotateByQuaternion = RotateVector(pointY, rotation);

	Vector3 rotateByMatrix = Transform(pointY, rotateMatrix);

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
		QuaternionScreenPrintf(20, 0, rotation, "rotatetion");
		MatrixScreenPrintf(0, kRowHeight * 1, rotateMatrix, "rotateMatrix");
		VectorScreenPrintf(0, kRowHeight * 6, rotateByQuaternion, "rotateByQuaternion");
		VectorScreenPrintf(0, kRowHeight * 7, rotateByMatrix, "rotateByMatrix");
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
