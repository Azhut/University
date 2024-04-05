def head(file_path, num_lines):
    with open(file_path, 'r') as file:
        for i, line in enumerate(file):
            if i >= num_lines:
                break
            yield line.strip()


file_path = 'test_head.txt'
num_lines = 6

lines_generator = head(file_path, num_lines)

for _ in range(num_lines):
    print(next(lines_generator))
