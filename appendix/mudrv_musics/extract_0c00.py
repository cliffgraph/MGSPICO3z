import sys
import os

def is_start(data, i):
    # 始端条件:
    # - 512の倍数の位置
    # - data[i:i+2] == b'\x0c\x00'
    # - data[i-3:i] == b'\x00\x00\x00'
    return (
        i % 512 == 0 and
        i >= 3 and
        data[i:i+2] == b'\x0c\x00' and
        data[i-3:i] == b'\x00\x00\x00'
    )

def find_end(data, start):
    i = start + 2
    zero_run_start = None
    while i < len(data):
        if data[i] == 0x00:
            if zero_run_start is None:
                zero_run_start = i
        else:
            if zero_run_start is not None:
                run_len = i - zero_run_start
                last_zero_pos = i - 1
                # 終端条件:
                # - 0x00が3バイト以上連続
                # - 最後の0x00が (16の倍数)-1 の位置
                if run_len >= 3 and (last_zero_pos + 1) % 16 == 0:
                    return last_zero_pos + 1  # 終端は最後の0x00の次の位置
                zero_run_start = None
        i += 1
    return None

def find_regions(data):
    regions = []
    i = 0
    while i < len(data) - 4:
        if is_start(data, i):
            start = i
            end = find_end(data, start)
            if end:
                regions.append((start, end))
                i = end  # 次の探索は終端以降から
            else:
                i += 512  # 終端が見つからない場合は次の512バイト境界へ
        else:
            i += 1
    return regions

def save_regions(data, regions, output_path, prefix_str):
    for idx, (start, end) in enumerate(regions):
        fno = idx + 1
        filename = os.path.join(output_path, f"{prefix_str}_{fno:03}.mud")
        with open(filename, "wb") as f:
            f.write(data[start:end])
        print(f"Saved: {filename} ({start:04X}, {end-start} bytes)")

def main():
    if len(sys.argv) != 4:
        print("Usage: python read_0c00.py <target_binary_file> <output_dir_path> <prefix>")
        sys.exit(1)

    input_file = sys.argv[1]
    if not os.path.isfile(input_file):
        print(f"Error: File '{input_file}' not found.")
        sys.exit(1)

    output_path = sys.argv[2]
    os.makedirs(output_path, exist_ok=True)
    if not os.path.isdir(output_path):
        print(f"Error: File '{input_file}' not found.")
        sys.exit(1)

    prefix_str = sys.argv[3]

    with open(input_file, "rb") as f:
        data = f.read()

    regions = find_regions(data)
    if not regions:
        print("No matching regions found.")
    else:
        save_regions(data, regions, output_path, prefix_str)

if __name__ == "__main__":
    main()