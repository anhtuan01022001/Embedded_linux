# #!/bin/bash

# read -p "Enter your age: " age
# if ! [[ "$age" =~ ^[0-9]+$ ]]; then
#     echo "Tuổi không hợp lệ!"
#     exit 1
# fi

# if [[ $age -lt 6 ]]; then
#     echo "Mầm non"
# elif [[ $age -ge 6 && $age -lt 11 ]]; then
#     echo "Tiểu học"
# elif [[ $age -ge 11 && $age -lt 15 ]]; then
#     echo "THCS"
# elif [[ $age -ge 15 && $age -lt 18 ]]; then
#     echo "THPT"
# else
#     echo "Đại học hoặc đã đi làm"
# fi

#!/bin/bash

# read -p "Enter your number: " n
# if ! [[ "$n" =~ ^[0-9]+$ ]] || [[ "$n" -le 0 ]]; then
#     echo "Số khong hợp lệ!"
#     exit 1
# fi

# sum=0
# for ((i = 1; i <= n; i ++ )); do    
#     (( sum += i ))
# done 

# echo "Tổng các số từ 1 đến $n là: $sum"

# for ((i=1; i <= n; i++)); do
#     for((j = 1; j <= i; j++)); do
#         echo -n "* "
#     done
#     echo
# done

#!/bin/bash
read -p "Enter a number: " n
if ! [[ "$n" =~ ^[0-9]+$ ]] || [[ "$n" -le 0 ]]; then
    echo "Số không hợp lệ!"
    exit 1
fi

for ((i = 0; i < n; i++)); do
    read -p "Nhập phần tử thứ $((i + 1)): " arr[i]
    if ! [[ "${arr[i]}" =~ ^-?[0-9]+$ ]]; then
        echo "Giá trị không hợp lệ! Vui lòng nhập một số nguyên."
        exit 1
    fi
done

sum=0
max=0
min=0

for ((i = 0; i < n; i++)); do
    (( sum += arr[i] ))
    if [[ $i -eq 0 ]]; then
        max=${arr[i]}
        min=${arr[i]}
    else
        if [[ ${arr[i]} -gt $max ]]; then
            max=${arr[i]}
        fi
        if [[ ${arr[i]} -lt $min ]]; then
            min=${arr[i]}
        fi
    fi
done

echo "Tổng các phần tử trong mảng là: $sum"
echo "Giá trị lớn nhất trong mảng là: $max"
echo "Giá trị nhỏ nhất trong mảng là: $min"

echo "Mảng theo thứ tự ngược:"
for ((i = n-1; i >= 0; i--)); do
    echo -n "${arr[i]} "
done

echo