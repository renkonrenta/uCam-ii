//*************************************************************************************************//
//* [uCam.h]						   					  *//
//*                                                                                               *//
//* 関数：                                                                                        *//
//*      メッセージ表示関数                            -> void message_display(int)               *//
//*      受信ACKコマンド表示関数		       -> void receive_ack_message(unsigned       *//
//*                                                                                char*)         *//
//*      受信コマンド表示関数			       -> void receive_command_message(unsigned   *//
//*                                                                                    char *)    *//
//*      シグナル初期化関数                            -> void signal_init(struct sigaction *)    *//
//*      シグナル処理関数                              -> extern void siganl_handler(int)         *//
//*      シリアルポート初期化関数                      -> int serial_init(struct termios *,       *// 
//*                                                                       struct termios *)       *//
//*      シリアルポート終了関数                        -> int serial_finish(int, struct termios *)*//
//*      uCam-ii 初期化コマンド送信関数                -> int ucam_init_command(int)  	          *//
//*      uCam-ii 写真取得コマンド送信関数              -> int ucam_getpic_command(int)		  *//
//*      uCam-ii スナップショットコマンド送信関数      -> int ucam_snapshot_command(int		  *//
//*      uCam-ii パッケージサイズ設定コマンド送信関数  -> int ucam_pkgsize_command(int)		  *//
//*      uCam-ii ボーレート設定コマンド送信関数        -> int ucam_bandrate_command(int)	  *//
//*      uCam-ii リセットコマンド送信関数	       -> int ucam_reset_command(int)		  *//
//*      uCam-ii 同期コマンド送信関数		       -> int ucam_sync_command(int)		  *//
//*	 uCam-ii ACKコマンド送信関数		       -> int ucam_ack_command(int,int)		  *//	
//*	 uCam-ii LIGHTコマンド送信関数		       -> int ucam_light_command(int)	          *//
//* 												  *//
//*       											  *//
//*                                                            [ (c)2017/08/29 Renta_Yamamoto ]   *//
//*************************************************************************************************//


//-- [ヘッダファイル二重読み込み防止処理] -----------------------------------------------------//
#ifndef _UCAM_II_											// 条件読み込み
#define _UCAM_II_											// 条件定義
//---------------------------------------------------------------------------------------------//


//-- [ヘッダファイル] -------------------------------------------------------------------------//
//- fcntl.h      : ファイル操作								      -//
//- signal.h     : シグナル							              -//
//- string.h     : 文字列操作 								      -//
//- stdio.h      : 標準入出力							              -//
//- termios.h    : ポート設定							              -//
//- unistd.h     : UNIX標準 / システムコール						      -//
//- ucam_param.h : uCam-iiパラメータ							      -//
//---------------------------------------------------------------------------------------------//
#include <sys/time.h>
#include <fcntl.h>
#include <signal.h>                                                                                     // signal.h読み込み
#include <string.h>											// string.h読み込み
#include <stdio.h>											// stdio.h読み込み
#include <termios.h>											// termios.h読み込み
#include <unistd.h>											// unistd.h読み込み
#include "ucam_param.h"											// ucam_param.h読み込み
//---------------------------------------------------------------------------------------------//


//-- [置換] -----------------------------------------------------------------------------------//
//- DEVICE_NAME            : "/dev/ttyUSB0"                                                   -//
//- BAUDRATE               : B115200                                                          -//
//- ON                     : 1                                                                -//
//- OFF                    : 0                                                                -//
//- PROGRAM_START          : 0                                                                -//
//- PROGRAM_FINISH         : 1                                                                -//
//- SERIAL_PORT_OPEN       : 2                                                                -//
//- SERIAL_PORT_OPEN_FALSE : 3                                                                -//
//- SERIAL_PORT_CLOSE      : 4                                                                -//
//- UCAM_SYNC_SEND         : 5                                                                -//
//---------------------------------------------------------------------------------------------//
#define UCAM_DATA_SIZE         10000
#define DEVICE_NAME            "/dev/ttyUSB0"								// デバイス名
#define BAUDRATE               B115200									// ボーレート
#define ON                     1                                                                        // ON
#define OFF                    0                                                                        // OFF
#define PROGRAM_START          0                                                                        // プログラム起動
#define PROGRAM_FINISH         1								        // プログラム終了
#define SERIAL_PORT_OPEN       2									// シリアルポートオープン
#define SERIAL_PORT_OPEN_FALSE 3									// シリアルポートオープン失敗
#define SERIAL_PORT_CLOSE      4									// シリアルポートクローズ
#define UCAM_SYNC_SEND         5									// SYNCコマンド送信
#define UCAM_SYNC_SEND_FALSE   6
#define UCAM_ACK_SEND          7
#define UCAM_ACK_SEND_FALSE    8
#define SLEEP_TIME             100000									//

//---------------------------------------------------------------------------------------------//


//-- [変数宣言] -------------------------------------------------------------------------------//
extern int signal_flag;											// シグナルフラグ格納変数
//---------------------------------------------------------------------------------------------//


//-- [プロトタイプ宣言] -----------------------------------------------------------------------//
void message_display(int);										// メッセージ表示関数
void receive_ack_message(unsigned char *);								// 受信ACKコマンド表示関数
void receive_command_message(unsigned char *);								// 受信コマンド表示関数
void signal_init(struct sigaction *);									// シグナル初期化関数
extern void signal_handler(int);									// シグナル処理関数
int  serial_init(struct termios *, struct termios *);						        // シリアルポート初期化関数
void serial_finish(int, struct termios *);								// シリアルポート終了関数
int  ucam_init_command(int);										// uCam-ii 初期化関数 
int  ucam_getpic_command(int);										// uCam-ii 写真取得関数
int  ucam_snapshot_command(int);									// uCam-ii スナップショット関数
int  ucam_pkgsize_command(int);										// uCam-ii パッケージサイズ設定関数
int  ucam_bandrate_command(int);									// uCam-ii ボーレート設定関数
int  ucam_reset_command(int);										// uCam-ii リセット関数
int  ucam_sync_command(int);										// uCam-ii 同期関数
int  ucam_ack_command(int,int);										// uCam-ii ACK関数
int  ucam_light_command(int);										// uCam-ii LIGHT関数　　　　
//---------------------------------------------------------------------------------------------//　　　　


//-- [終了処理] -------------------------------------------------------------------------------//
#endif
//---------------------------------------------------------------------------------------------//
