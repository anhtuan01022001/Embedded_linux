# Linux Fundamentals Learning - GCC & Library Development

## 🧠 Mục tiêu học tập

Đây là repo cá nhân ghi lại quá trình học tập và thực hành các kiến thức nền tảng về **Linux**, tập trung vào:

- Sử dụng **GCC (GNU Compiler Collection)** để biên dịch mã nguồn C/C++.
- Tạo và sử dụng **thư viện tĩnh (Static Library)**.
- Tạo và sử dụng **thư viện chia sẻ (Shared Library)**.
- Hiểu cơ bản về quá trình **linking, compile-time vs runtime linking**, và cách sử dụng `Makefile` để tự động hóa quá trình build.

## 📁 Nội dung

### 1. GCC - Biên dịch mã nguồn
- Các flag cơ bản: `-c`, `-o`, `-Wall`, `-I`, `-L`, `-l`
- Biên dịch từng bước: compile ➝ assemble ➝ link
- Ví dụ thực hành: Biên dịch một chương trình C đơn giản từ dòng lệnh.

### 2. Static Library (`.a`)
- Tạo thư viện tĩnh bằng `ar` và `gcc`
- Link thư viện tĩnh vào chương trình chính
- Ưu nhược điểm của static library

### 3. Shared Library (`.so`)
- Tạo thư viện dùng chung
- Cấu hình `LD_LIBRARY_PATH` và sử dụng `ldconfig`
- Link thư viện động vào chương trình
- So sánh với thư viện tĩnh

### 4. Makefile cơ bản
- Cấu trúc file `Makefile`
- Biến, rule, target, dependency
- Tự động build các thư viện và ứng dụng demo

## 📌 Ví dụ demo

Repo này sẽ bao gồm một số ví dụ cụ thể:

- `src/`: Mã nguồn thư viện và chương trình chính
- `lib/`: Output thư viện `.a` và `.so`
- `build/`: Output chương trình đã biên dịch
- `Makefile`: Tự động hóa quy trình build

## 💡 Kiến thức nền tảng

- Quy trình biên dịch trong Linux
- Cách hoạt động của linker và loader
- Ưu/nhược điểm của static vs shared library
- Cách debug khi gặp lỗi `undefined reference`, `cannot open shared object file`, v.v.

## 🛠️ Công cụ

- **GCC**: Trình biên dịch chính
- **Make**: Dùng để build project

## 📚 Tài liệu tham khảo

- [Create Libraries](https://renenyffenegger.ch/notes/development/languages/C-C-plus-plus/GCC/create-libraries/index)
- [Makefile tutorial - GNU Make](https://www.gnu.org/software/make/manual/make.html)

---

> 🔍 Repo này phù hợp với những bạn mới học lập trình hệ thống, hoặc chuẩn bị học về kernel/module lập trình trong Linux.

