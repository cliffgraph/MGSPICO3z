#!/usr/bin/env python3

import sys
import os

def validate_hex_argument(arg_name, value):
    try:
        if not value.lower().startswith("0x"):
            raise ValueError
        int_value = int(value, 16)
        if int_value < 0 or int_value > 0xFFFFFFFF:
            raise ValueError
        return int_value
    except ValueError:
        print(f"Error: {arg_name} は 0x00000000 ～ 0xFFFFFFFF の範囲の16進数で指定してください。")
        sys.exit(1)

def extract_binary(target_file_path, start_address_hex, binary_size_hex, output_file_path):
    # 引数のバリデーション
    start_address = validate_hex_argument("start_address", start_address_hex)
    binary_size = validate_hex_argument("binary_size", binary_size_hex)

    # 入力ファイルの存在確認
    if not os.path.isfile(target_file_path):
        print(f"Error: ファイルが存在しません: {target_file_path}")
        sys.exit(1)

    # ファイルサイズの取得と範囲チェック
    file_size = os.path.getsize(target_file_path)
    if start_address >= file_size:
        print(f"Error: start_address ({start_address_hex}) がファイルサイズ ({file_size} バイト) を超えています。")
        sys.exit(1)
    if start_address + binary_size > file_size:
        print(f"Error: 指定された範囲 ({start_address_hex} ～ {hex(start_address + binary_size - 1)}) がファイルサイズを超えています。")
        sys.exit(1)

    # バイナリ抽出処理
    try:
        with open(target_file_path, "rb") as f:
            f.seek(start_address)
            data = f.read(binary_size)

        with open(output_file_path, "wb") as out_f:
            out_f.write(data)

        print(f"抽出完了: {output_file_path} に {binary_size} バイトを書き出しました。")
    except Exception as e:
        print(f"Error: 処理中にエラーが発生しました: {e}")
        sys.exit(1)

if __name__ == "__main__":
    if len(sys.argv) != 5:
        print("使用方法: extract_binary.py <target_file_path> <start_address> <binary_size> <output_file_path>")
        sys.exit(1)

    _, target_file_path, start_address_hex, binary_size_hex, output_file_path = sys.argv
    extract_binary(target_file_path, start_address_hex, binary_size_hex, output_file_path)
    