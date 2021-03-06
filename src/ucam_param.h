//*************************************************************************************************//
//* [ucam_param.h]										  *//
//*  ・uCam-iiのパラメータの設定を行う								  *//
//* 											          *//
//* 			   			                   [ 2017/08/26 Renta_Yamamoto ]  *//
//*************************************************************************************************//


//-- [ヘッダファイル二重読み込み防止処理] -----------------------------------------------------//
#ifndef _UCAM_PARAM_											// 条件付きコンパイル
#define _UCAM_PARAM_ 											// 条件定義
//---------------------------------------------------------------------------------------------//  


//-- [置換] -----------------------------------------------------------------------------------//
//- INITAL_PARAM1             : 0x00                                                          -//
//- INITAL_PARAM2             : 0x03                                                          -//
//- INITAL_PARAM3             : 0x01                                                          -//
//- INITAL_PARAM4             : 0x00                                                          -//
//- GETPICTURE_PARAM1         : 0x01                                                          -//
//- GETPICTURE_PARAM2         : 0x00                                                          -//
//- GETPICTURE_PARAM3         : 0x00                                                          -//
//- GETPICTURE_PARAM4         : 0x00                                                          -//
//- SNAPSHOT_PARAM1           : 0x01                                                          -//
//- SNAPSHOT_PARAM2           : 0x00                                                          -//
//- SNAPSHOT_PARAM3           : 0x00                                                          -//
//- SNAPSHOT_PARAM4           : 0x00                                                          -//
//- SETPACKAGESIZE_PARAM1     : 0x00                                                          -//
//- SETPACKAGESIZE_PARAM2     : 0x00                                                          -//
//- SETPACKAGESIZE_PARAM3     : 0x00                                                          -//
//- SETPACKAGESIZE_PARAM4     : 0x00                                                          -//
//- SETBAUDRATE_PARAM1        : 0x00                                                          -//
//- SETBAUDRATE_PARAM2        : 0x00                                                          -//
//- SETBAUDRATE_PARAM3        : 0x00                                                          -//
//- SETBAUDRATE_PARAM4        : 0x00                                                          -//
//- RESET_PARAM1              : 0x00                                                          -//
//- RESET_PARAM2              : 0x00                                                          -//
//- RESET_PARAM3              : 0x00                                                          -//
//- RESET_PARAM4              : 0x00                                                          -//
//- DATA_PARAM1               : 0x00                                                          -//
//- DATA_PARAM2               : 0x00                                                          -//
//- DATA_PARAM3               : 0x00                                                          -//
//- DATA_PARAM4               : 0x00                                                          -//
//- SYNC_PARAM1               : 0x00                                                          -//
//- SYNC_PARAM2               : 0x00                                                          -//
//- SYNC_PARAM3               : 0x00                                                          -//
//- SYNC_PARAM4               : 0x00                                                          -//
//- LIGHT_PARAM1              : 0x00                                                          -//
//- LIGHT_PARAM2              : 0x00                                                          -//
//- LIGHT_PARAM3              : 0x00                                                          -//
//- LIGHT_PARAM4              : 0x00                                                          -//
//---------------------------------------------------------------------------------------------//


//-- [初期化コマンド] ---------------------------------------------------------------------//
//-                                                                                       -//
//-  ---                     [PARAMETER1]                                                 -//
//-     - 0x00                                                                            -//
//-                                                                                       -//
//- Image format             [PARAMETER2]                                                 -//
//-     - 0x03 / 8bit for Y only                                                          -//
//-     - 0x08 / 16bit Color (CrYCbY)                                                     -//
//-     - 0x06 / 16bit Color (RGB565)                                                     -//
//-     - 0x07 / jpeg                                                                     -// 
//-                                                                                       -//
//- RAW Resolutian           [PARAMETER3]                                                 -//
//-     - 0x01 / 80x60                                                                    -//
//-     - 0x03 / 160x120                                                                  -//
//-     - 0x09 / 128x128                                                                  -//
//-     - 0x0B / 128x96                                                                   -//
//-                                                                                       -//
//- JPEG Resolution          [PARAMETER4]                                                 -//
//-     - 0x03 / 160x128                                                                  -//
//-     - 0x05 / 320x240                                                                  -//
//-     - 0x07 / 640x480                                                                  -//
//-                                                                                       -//
//-----------------------------------------------------------------------------------------//
#define INITAL_PARAM1             0x00                                                                  // ...
#define INITAL_PARAM2             0x03                                                                  // イメージフォーマット
#define INITAL_PARAM3             0x01                                                                  // RAW解像度
#define INITAL_PARAM4             0x00                                                                  // JPEG解像度]
//-----------------------------------------------------------------------------------------//


//-- [ゲットピクチャコマンド] -------------------------------------------------------------//
//-                                                                                       -//
//- Picture Type             [PARAMETER1]                                                 -//
//-     - 0x01 / Snapshot Picture Mode                                                    -//
//-     - 0x02 / RAW Picture Mode                                                         -//
//-     - 0x05 / JPEG Picture Mode                                                        -//
//-                                                                                       -//
//- ---                      [PARAMETER2]                                                 -//
//-     - 0x00                                                                            -//
//-                                                                                       -//
//- ---                      [PARAMETER3]                                                 -//
//-     - 0x00                                                                            -//
//-                                                                                       -//
//- ---                      [PARAMETER4]                                                 -//
//-     - 0x00                                                                            -//
//-                                                                                       -//
//-----------------------------------------------------------------------------------------//
#define GETPICTURE_PARAM1         0x01                                                                  // 画像タイプ
#define GETPICTURE_PARAM2         0x00                                                                  // ...
#define GETPICTURE_PARAM3         0x00                                                                  // ...
#define GETPICTURE_PARAM4         0x00                                                                  // ...
//-----------------------------------------------------------------------------------------//


//-- [スナップショットコマンド] -----------------------------------------------------------//
//-                                                                                       -//
//- Snapshot Type            [PARAMETER1]                                                 -//
//-     - 0x00 / Compressed Picture (JPEG)                                                -// 
//-     - 0x01 / Uncompressed Picture (RAW)                                               -// 
//-                                                                                       -//
//- Skip Frame (High Byte)   [PARAMETER2]                                                 -//
//-     - 0x00 / 保持                                                                     -//
//-     - 0x01 / 次のフレームのキャプチャ                                                 -//
//-                                                                                       -//
//- Skip Frame (Low Byte)    [PARAMETER3]                                                 -//
//-     - 0x00 / 保持                                                                     -//
//-     - 0x01 / 次のフレームのキャプチャ                                                 -//
//-                                                                                       -//
//- ---                      [PARAMETER4]                                                 -//
//-     - 0x00                                                                            -//
//-                                                                                       -//
//-----------------------------------------------------------------------------------------//
#define SNAPSHOT_PARAM1           0x00                                                                  // スナップショットタイプ
#define SNAPSHOT_PARAM2           0x00                                                                  // スキップフレーム(LOW_BYTE)
#define SNAPSHOT_PARAM3           0x00                                                                  // スキップフレーム(HIGH_BYTE)
#define SNAPSHOT_PARAM4           0x00                                                                  // ...
//-----------------------------------------------------------------------------------------//


//-- [パッケージサイズ設定コマンド] -------------------------------------------------------//
//-                                                                                       -//
//- ---                      [PARAMETER1]                                                 -//
//-     - 0x00                                                                            -// 
//-                                                                                       -//
//- Package Size (LOW Byte)  [PARAMETER2]                                                 -//
//-     - 任意                                                                            -//
//-                                                                                       -//
//- Package Size (HIGH Byte) [PARAMETER3]                                                 -//
//-     - 任意                                                                            -//
//-                                                                                       -//
//- ---                      [PARAMETER4]                                                 -//
//-     - 0x00                                                                            -//
//-                                                                                       -//
//-----------------------------------------------------------------------------------------//
#define SETPACKAGESIZE_PARAM1     0x08                                                                  // ...
#define SETPACKAGESIZE_PARAM2     0x00                                                                  // パッケージサイズ(LOW_BYTE)
#define SETPACKAGESIZE_PARAM3     0x00                                                                  // パッケージサイズ(HIGH_BYTE)
#define SETPACKAGESIZE_PARAM4     0x00                                                                  // ...
//-----------------------------------------------------------------------------------------//


//-- [ボーレート設定コマンド] -------------------------------------------------------------//
//-                                                                                       -//
//- 1st Divider              [PARAMETER1]                                                 -//
//-     - 任意                                                                            -//
//-                                                                                       -//
//- 2nd Divider              [PARAMETER2]                                                 -//
//-     - 任意                                                                            -//
//-                                                                                       -//
//- ---                      [PARAMETER3]                                                 -//
//-     - 0x00                                                                            -//
//-                                                                                       -//
//- ---                      [PARAMETER4]                                                 -//
//-     - 0x00                                                                            -//
//-                                                                                       -//
//-----------------------------------------------------------------------------------------//
#define SETBAUDRATE_PARAM1        0x00                                                                  // ディバイダ1
#define SETBAUDRATE_PARAM2        0x00                                                                  // ディバイダ2
#define SETBAUDRATE_PARAM3        0x00                                                                  // ...
#define SETBAUDRATE_PARAM4        0x00                                                                  // ...
//-----------------------------------------------------------------------------------------//


//-- [リセットコマンド] -------------------------------------------------------------------//
//-                                                                                       -//
//- Reset Type               [PARAMETER1]                                                 -//
//-     - 0x00 / 全システムのリセット                                                     -//
//-     - 0x01 / ステートマシンのみをリセット                                             -//
//-                                                                                       -//
//- ---                      [PARAMETER2]                                                 -//
//-     - 0x00                                                                            -//
//-                                                                                       -//
//- ---                      [PARAMETER3]                                                 -//
//-     - 0x00                                                                            -//
//-                                                                                       -//
//- ---                      [PARAMETER4]                                                 -//
//-     - 0x00                                                                            -//
//-                                                                                       -//
//-----------------------------------------------------------------------------------------//
#define RESET_PARAM1              0x00                                                                  // リセットタイプ
#define RESET_PARAM2              0x00                                                                  // ...
#define RESET_PARAM3              0x00                                                                  // ...
#define RESET_PARAM4              0x00                                                                  // ...
//-----------------------------------------------------------------------------------------//


//-- [同期コマンド] -----------------------------------------------------------------------//
//-                                                                                       -//
//- ---                      [PARAMETER1]                                                 -//
//-     - 0x00                                                                            -//
//-                                                                                       -//
//- ---                      [PARAMETER2]                                                 -//
//-     - 0x00                                                                            -//
//-                                                                                       -//
//- ---                      [PARAMETER3]                                                 -//
//-     - 0x00                                                                            -//
//-                                                                                       -//
//- ---                      [PARAMETER4]                                                 -//
//-     - 0x00                                                                            -//
//-                                                                                       -//
//-----------------------------------------------------------------------------------------//
#define SYNC_PARAM1               0x00                                                                  // ...
#define SYNC_PARAM2               0x00                                                                  // ...
#define SYNC_PARAM3               0x00                                                                  // ...
#define SYNC_PARAM4               0x00                                                                  // ...
//-----------------------------------------------------------------------------------------//


//-- [光コマンド] -------------------------------------------------------------------------//
//-                                                                                       -//
//- Frequency Type           [PARAMETER1]                                                 -//
//-     - 0x00 / 50hz                                                                     -//
//-     - 0x00 / 60hz                                                                     -//
//-                                                                                       -//
//- ---                      [PARAMETER2]                                                 -//
//-     - 0x00                                                                            -//
//-                                                                                       -//
//- ---                      [PARAMETER3]                                                 -//
//-     - 0x00                                                                            -//
//-                                                                                       -//
//- ---                      [PARAMETER4]                                                 -//
//-     - 0x00                                                                            -//
//-                                                                                       -//
//-----------------------------------------------------------------------------------------//
#define LIGHT_PARAM1              0x00                                                                  // 周波数タイプ
#define LIGHT_PARAM2              0x00                                                                  // ...
#define LIGHT_PARAM3              0x00                                                                  // ...
#define LIGHT_PARAM4              0x00                                                                  // ...
//-----------------------------------------------------------------------------------------//


//-- [終了処理] ---------------------------------------------------------------------------//
#endif
//-----------------------------------------------------------------------------------------//
