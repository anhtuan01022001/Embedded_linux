# #!/bin/bash

# read -p "Nhập chuỗi: " str
# n=${#str}

# echo "Độ dài chuỗi: $n"
# echo "Ký tự đầu tiên: ${str:0:1}"
# echo "Ký tự cuối cùng: ${str: -1}"

# # Đảo chuỗiiếp tbài
# echo -n "Chuỗi đảo ngược: "
# for ((i=n-1; i>=0; i--)); do
#   echo -n "${str:i:1}"
# done
# echo

# # Kiểm tra chứa chữ 'a'
# if [[ "$str" == *a* ]]; then
#     echo "Chuỗi có chứa chữ a"
# fi

# # Nối chuỗi với chính nó nếu dài ≥ 2
# if [ $n -ge 2 ]; then
#     echo "Chuỗi sau khi nối chính nó: ${str}${str}"
# fi

#!/bin/bash

# read -p "Nhập một số nguyên dương: " n
# if [[ ! "$n" =~ ^[0-9]+$ ]] || [ "$n" -le 0 ]; then
#     echo "Vui lòng nhập một số nguyên dương."
#     exit 1
# fi

# is_prime() {
#     local num=$1
#     if [ $num -le 1 ]; then
#         echo "$num không phải là số nguyên tố."
#         return 1
#     fi
#     for ((i=2; i*i<=num; i++)); do
#         if [ $((num % i)) -eq 0 ]; then
#             return 1
#         # else
#         #     echo "$num là số nguyên tố."
#         #     return 0
#         fi
#     done
#     return 0
# }
# if is_prime $n; then
#     echo "$n là số nguyên tố."
# else
#     echo "$n không phải là số nguyên tố."
# fi


# if [ -f "test.txt" ]; then
#     echo "test.txt đã tồn tại."
# else
#     echo "test.txt không tồn tại, tạo mới..."
#     touch test.txt
#     echo "test.txt đã được tạo."
# fi
# # Kiểm tra xem test.txt có phải là tệp hay không
# if [ -f "test.txt" ]; then
#     echo "test.txt là một tệp."
# else
#     echo "test.txt không phải là một tệp."
# fi

# # Đếm số dòng trong tệp
# line_count=$(wc -l < test.txt)
# echo "Số dòng trong test.txt: $line_count"

# # Đếm số từ trong tệp
# word_count=$(wc -w < test.txt)
# echo "Số từ trong test.txt: $word_count"

# # Đếm số ký tự trong tệp
# char_count=$(wc -c < test.txt)
# echo "Số ký tự trong test.txt: $char_count"

# # Đọc nội dung tệp và in ra
# echo "Nội dung của test.txt:"
# cat test.txt
# echo

# for ((i=1; i<=$line_count; i++)); do
#     echo "Dòng $i: $(sed -n "${i}p" test.txt)"
# done < test.txt

# echo "Đã in từng dòng trong test.txt."
# # Thêm nội dung vào tệp test.txt
# echo "Thêm nội dung vào tệp test.txt..."
# echo -n "Nội dung mới" >> test.txt
# echo "Nội dung đã được thêm vào test.txt."
# # Đọc nội dung tệp test.txt
# echo "Nội dung của test.txt sau khi thêm:"
# cat test.txt

# # # Xóa tệp test.txt
# # rm test.txt
# # echo "Tệp test.txt đã được xóa."
# # Kiểm tra lại xem tệp đã bị xóa hay chưa
# if [ ! -f "test.txt" ]; then
#     echo "test.txt đã bị xóa."
# else
#     echo "test.txt vẫn còn tồn tại."
# fi

# Ex 7: File content analysis

# read -p "Nhập tên tệp: " filename
# if [ ! -f "$filename" ]; then
#     echo "Tệp $filename không tồn tại."
#     exit 1
# fi

# cat "$filename"
# line_count=$(wc -l < "$filename")
# echo
# echo "Số dòng trong tệp: $line_count"
# word_count=$(wc -w < "$filename")
# echo "Số từ trong tệp: $word_count"

# now=$(date "+%Y-%m-%d %H:%M:%S")
# echo "# Đã kiểm tra lúc $now" >> "$filename"

# Ex 8: Handing command line Parameters in Bash

