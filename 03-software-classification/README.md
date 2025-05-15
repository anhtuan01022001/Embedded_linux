# Phân loại phần mềm nhúng Linux là 2 loại:

## Foreground Process: Là những phần mềm(tiến trình con) chiếm độc quyền thiết bị nhập chuẩn(stdin) của phần mềm chạy nó(tiến trình cha).

- after compile: ./main
- foreground: ./main

## Background Process: Là những phần mềm không chiếm thiết bị nhập chuẩn của phần mềm chạy nó, từ đó người dùng sẽ phải tương tác bằng các phương pháp IPC

- after compile: ./main &
- ./main &: là cách chạy background

## Foreground Process và Background Process có thể được quản lý bằng các lệnh sau:

- fg: chuyển background process về foreground
- bg: chuyển foreground process về background
- Thực hiện chuyển đổi từ foreground sang background bằng cách nhấn Ctrl + Z để chuyểnforeground sang trạng thái stop sau đó sử dụng lệnh bg %id.
    ex: ./main & -> ./main + Ctrl+Z -> bg %id -> fg %id