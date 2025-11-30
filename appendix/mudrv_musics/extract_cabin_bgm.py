#!/usr/bin/env python3
import sys
import struct
import os

def print_help():
    print("Usage: python extract_cabin_bgm.py <target_file_path> <address> <string> <output_file_path>")
    print("  <target_file_path> : 入力バイナリファイルのパス")
    print("  <address>          : 0x00000000 の形式の 32bit 16進数整数")
    print("  <string>           : 出力ファイル先頭+6 の位置に書き込む文字列（空文字なら上書きしない）")
    print("  <output_file_path> : 出力バイナリファイルのパス")

def main():
    if len(sys.argv) != 5:
        print_help()
        sys.exit(1)

    target_file_path = sys.argv[1]
    address_str = sys.argv[2]
    insert_string = sys.argv[3]
    output_file_path = sys.argv[4]

    # address の形式チェック
    try:
        if not address_str.startswith("0x") or len(address_str) != 10:
            raise ValueError("Address format error")
        address = int(address_str, 16)
    except ValueError:
        print("Error: <address> は 0x00000000 の形式の 32bit 16進数で指定してください")
        sys.exit(1)

    # バイナリファイルを開く
    try:
        with open(target_file_path, "rb") as f:
            data = f.read()
    except IOError as e:
        print(f"Error: 入力ファイルを開けません: {e}")
        sys.exit(1)

    if address + 6 > len(data):
        print("Error: アドレスがファイル範囲外です")
        sys.exit(1)

    # 4バイト識別子チェック
    identifier = data[address:address+4]
    if identifier not in [b"BGM\0", b"bgm\0", b"ONS\0"]:
        print("Error: 識別子が不正です。処理を終了します")
        sys.exit(1)

    # サイズ取得 (address+4 から 2バイト, little endian)
    size_bytes = data[address+4:address+6]
    if len(size_bytes) < 2:
        print("Error: サイズフィールドが不完全です")
        sys.exit(1)
    size = struct.unpack("<H", size_bytes)[0]

    # ブロック抽出
    block = data[address:address+size]
    if len(block) < size:
        print("Error: ブロックサイズがファイル長を超えています")
        sys.exit(1)

    # 出力ファイルに書き込み
    block = bytearray(block)

    # <string> が空文字列でない場合のみ上書き
    if insert_string != "":
        str_bytes = insert_string.encode("utf-8")
        end_pos = 6 + len(str_bytes)
        if end_pos > len(block):
            print("Error: 文字列がブロックに収まりません")
            sys.exit(1)
        block[6:end_pos] = str_bytes

    # 出力先ディレクトリを生成
    if os.path.dirname(output_file_path):
        os.makedirs(os.path.dirname(output_file_path), exist_ok=True)

    try:
        with open(output_file_path, "wb") as out:
            out.write(block)
    except IOError as e:
        print(f"Error: 出力ファイルに書き込めません: {e}")
        sys.exit(1)

    print(f"Extraction complete. 出力先: {output_file_path}")

if __name__ == "__main__":
    main()
