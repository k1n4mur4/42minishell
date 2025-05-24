#ifndef EVAL_H
#define EVAL_H

#include <stdio.h>   // 標準入出力
#include <stdlib.h>  // メモリ管理や終了処理
#include <setjmp.h>  // setjmp / longjmp によるエラーハンドリング
#include <signal.h>  // シグナル処理
#include <unistd.h>  // システムコール (read, write, fork など)

// シェルの終了ステータス
#define SUCCESS 0   // コマンドが正常終了
#define FAILURE 1   // コマンドがエラー終了

#include "struct.h"
#include "rl.h"
// シェルのメインループ

#include "parser.h"       // コマンドのパース処理
#include "execute_cmd.h"  // コマンドの実行
#include "builtins.h"     // ビルトインコマンド

// eval.h
int		reader_loop(void);

#endif // EVAL_H