# 8-Bit Adder Simulation in C++

Chương trình mô phỏng bộ cộng 8-bit không dấu bằng C++, hỗ trợ phát hiện tràn số (Overflow Flag) và hiển thị kết quả ở dạng mã nhị phân.

---

## Tính năng chính (Features)

* Cộng 2 số nguyên không dấu trong dải từ $0 \rightarrow 255$.
* Tự động chuyển đổi số thập phân sang chuỗi nhị phân 8-bit.
* Phát hiện và xử lý hiện tượng **Tràn số 8-bit (Overflow Flag)** theo cơ chế xoay vòng modulo $256$.
* Tích hợp bộ kiểm thử tự động `runTests()` với các kịch bản kiểm thử biên.
* Chế độ tương tác cho phép nhập dữ liệu linh hoạt từ bàn phím.

---

## Kiến thức & Công nghệ (Concepts Learned)

* **Ngôn ngữ:** C++ (C++11 trở lên).
* **OOP (Lập trình hướng đối tượng):** Đóng gói thuộc tính (`private`) và phương thức (`public`), khởi tạo Constructor với danh sách gán (Initializer List).
* **Bitwise Manipulation:** Sử dụng phép dịch bit (`>>`) và mặt nạ bit (`& 1`) để trích xuất từng bit nhị phân.
* **Xử lý số học phần cứng:** Mô phỏng cờ tràn và giới hạn dải lưu trữ 8-bit ($2^8 - 1$).

---

## Cách biên dịch và chạy (How to Run)

```bash
# Biên dịch chương trình
g++ -std=c++11 main.cpp -o adder8bit

# Chạy chương trình
./adder8bit
---- AUTOMATED TESTS ----
[Test 2: 200 + 100]
A = 200 (11001000) | B = 100 (01100100)
Result =  44 (00101100) | Overflow: YES
