import sys
import os
import struct

MAGIC_S_BYTES = b'\x62\x67\x6d\x00'  # bgm
MAGIC_L_BYTES = b'\x42\x47\x4D\x00'  # BGM
MAGIC_O_BYTES = b'\x4F\x4E\x53\x00'  # ONS
BLOCK_SIZE = 512


def extract_blocks(target_path, dest_dir, prefix):
    print(f"[INFO] 開始: {target_path} を解析中…")

    try:
        with open(target_path, 'rb') as f:
            data = f.read()
    except Exception as e:
        print(f"[ERROR] 入力ファイルの読み込みに失敗しました: {e}")
        return

    if not os.path.exists(dest_dir):
        try:
            os.makedirs(dest_dir)
            print(f"[INFO] 出力ディレクトリを作成しました: {dest_dir}")
        except Exception as e:
            print(f"[ERROR] 出力ディレクトリの作成に失敗しました: {e}")
            return

    offset = 0
    count = 0
    data_len = len(data)

    while offset + 6 <= data_len:
        magicval = data[offset:offset+4]
        if magicval == MAGIC_S_BYTES or magicval == MAGIC_L_BYTES or magicval == MAGIC_O_BYTES:
            size_bytes = data[offset+4:offset+6]
            payload_size = struct.unpack('<H', size_bytes)[0]  # block_size = データ部のサイズ
            total_size = 6 + payload_size  # マジック + サイズ情報 + データ部
            block_end = offset + total_size

            if block_end <= data_len:
                file_no = count + 1
                output_filename = f"{prefix}_{file_no:03d}.mud"
                output_path = os.path.join(dest_dir, output_filename)
                try:
                    with open(output_path, 'wb') as out_file:
                        out_file.write(data[offset:block_end])
                    sector = offset // BLOCK_SIZE
                    print(f"[INFO] 抽出: {magicval.decode('ascii').strip()}: {output_filename} ({offset:05X}h, {total_size} bytes, sector {sector:04X}h)")
                    count += 1
                except Exception as e:
                    print(f"[ERROR] ファイル {output_filename} の書き込みに失敗しました: {e}")
            else:
                print(f"[WARN] offset {offset} のブロックサイズ {payload_size} がファイル末尾を超えています。スキップします。")
        offset += BLOCK_SIZE

    print(f"[INFO] 完了: {count} 個のブロックを抽出しました。")

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage: python extract_62676d.py <target_binary_file_path> <dest_dir_path> <prefix>")
        sys.exit(1)

    target_binary_file_path = sys.argv[1]
    dest_dir_path = sys.argv[2]
    prefix = sys.argv[3]

    extract_blocks(target_binary_file_path, dest_dir_path, prefix)