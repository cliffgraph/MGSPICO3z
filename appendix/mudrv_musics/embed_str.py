#!/usr/bin/env python3
import sys
import os

def print_help():
    print("使い方: python enbed_str.py <target_file_path> <address> <\"strings\">")
    print("  <target_file_path> : バイナリファイルのパス")
    print("  <address>          : 32bit 16進数 (例: 0x00000010)")
    print("  <\"strings\">        : 指定位置に上書きする文字列")

def main():
    if len(sys.argv) != 4:
        print_help()
        sys.exit(1)

    target_file_path = sys.argv[1]
    address_str = sys.argv[2]
    embed_string = sys.argv[3]

    # アドレスの形式チェック
    try:
        if not address_str.startswith("0x"):
            raise ValueError("Address must start with 0x")
        address = int(address_str, 16)
    except ValueError:
        print("Error: アドレスの形式が正しくありません。")
        print_help()
        sys.exit(1)

    # ファイル存在チェック
    if not os.path.isfile(target_file_path):
        print(f"Error: ファイル '{target_file_path}' が見つかりません。")
        sys.exit(1)

    try:
        with open(target_file_path, "r+b") as f:
            f.seek(0, os.SEEK_END)
            file_size = f.tell()

            if address >= file_size:
                print("Error: アドレスがファイルサイズを超えています。")
                sys.exit(1)

            f.seek(address)
            f.write(embed_string.encode("utf-8"))
            # 上書きなのでファイルサイズは変えない
    except Exception as e:
        print(f"Error: {e}")
        sys.exit(1)

    print("文字列を正常に埋め込みました。")

if __name__ == "__main__":
    main()


