// QuickSort.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <utility>
#include <cstdlib>
using namespace std;

const int SIZE = 100;

// 配列の中身を表示
void ShowArray(int* pArr, int SIZE)
{
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%2d, ", pArr[i]);
    }
    printf("\n");
}

//// 配列をランダムな値で初期化
void InitRandArray(int* array, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        // １～９９
        array[i] = rand() % 99 + 1;
    }
}

// 配列の右端の数を基準として、それよりも大きい値と小さい値に分ける。
// 最期に基準値の位置を返す pは配列の先頭　endは配列の右端
int Partition(int* pArr, int pivot, int right)
{
    for (int i = pivot; i < right; ++i)
    {
        // 基準値よりも小さい数を左側に入れていく
        if (pArr[i] <= pArr[right])
        {
            // 入れ替えて基準値の位置をずらす
            swap(pArr[pivot], pArr[i]);
            ++pivot;
        }
    }
    // 右端の数(基準値)を基準値の位置に移動
    swap(pArr[right], pArr[pivot]);

    // 基準値の位置を返す
    return pivot;
}

// クイックソート
void QuickSort(int* pArr, int startPos, int endPos)
{
    // 基準値の位置
    int pivot = 0;

    // startPosとendPosが交差するまで繰り返す
    if (startPos < endPos)
    {
        // 配列の右端の数を基準として、それよりも大きい値と小さい値に分ける。
        // 最期に基準値の位置を返す
        pivot = Partition(pArr, startPos, endPos);

        // 再帰呼び出し
        // 先頭から基準値まで
        QuickSort(pArr, startPos, pivot - 1);
        // 基準値から最後まで
        QuickSort(pArr, pivot + 1, endPos);
    }
}

int main()
{
    time_t t;
    srand(time(&t) % RAND_MAX);

    // 配列の動的確保
    int* array = new int[SIZE];

    // メモリが確保できた場合のみ実行
    if (array != NULL)
    {
        InitRandArray(array, SIZE);

        printf("ソート前\n");
        ShowArray(array, SIZE);

        QuickSort(array, 0, SIZE - 1);

        printf("ソート後\n");
        ShowArray(array, SIZE);
    } 

    if (array != NULL)
    {
        // メモリ解放
        delete[] array;
        array = NULL;
    }
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
