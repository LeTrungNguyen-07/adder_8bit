#include <iostream>
#include <vector>
using namespace std;

vector<int> decimalToBinary(int num) {
    // 1. Khai báo vector 8 phần tử
    vector<int> bits(8,0);
    // 2. Vòng lặp duyệt từ bit 7 về bit 0
    for (int i = 7; i >= 0; --i) {
    // Chuyển đổi số thập phân (0-255) thành mảng nhị phân 8 bit [MSB -> LSB]
        bits[7 - i] = ( num >> i) & 1;
    }
    return bits;
}
// Hiển thị mảng bit nhị phân
void displayBinary(const vector<int>& bits) {
    for (int bit : bits ) {
        cout << bit;
    }
}
class Adder8Bit {
private:
   int inputA;
   int inputB;
   int result;
   bool overflowFlag;
public:
    // 1. Constructor khởi tạo giá trị ban đầu bằng 0
    Adder8Bit() : inputA(0), inputB(0), result(0), overflowFlag(false) {}
    // 2. Đặt dữ liệu vào
    void setInputs(int a, int b) {
        inputA = a;
        inputB = b;
    }
    // 3. Thực hiện tính toán
    void compute() {
        int rawSum = inputA + inputB;
        if ( rawSum > 255 ) {
            overflowFlag = true; 
            result = rawSum % 256;
        } else {
            overflowFlag = false;
            result = rawSum;
        }
    }
    // 4. Các hàm lấy thông tin (Getter)
    int getResult() const {
        return result;
    }
    bool hasOverflow() const {
        return overflowFlag; 
    }
    // 5. In kết quả hiển thị
    void display() const {
        cout << "A = " << inputA << " (";
        displayBinary(decimalToBinary(inputA));
        cout << ") ";
        cout << "B = " << inputB << " (";
        displayBinary(decimalToBinary(inputB)); 
        cout << " )" << endl;

        cout << "Result" << result << " (";
        displayBinary(decimalToBinary(result));
        cout << ") | Overflow: " << " OverflowFlag: " << (overflowFlag ? "YES" : "NO") << endl;
    }
};
void runTests() {
    Adder8Bit adder;
    cout << " ---- AUTOMATED TEST ---- " << endl;
    
    cout << "[Test 1: 100 + 50]" << endl;
    adder.setInputs(100,50);
    adder.compute();
    adder.display();

    cout << "[Test 2: 200 + 100]" << endl;
    adder.setInputs(200,100);
    adder.compute();
    adder.display();

    cout << "[Test 3: 255 + 1]" << endl;
    adder.setInputs(255,1);
    adder.compute();
    adder.display();

    cout << "[Test 4: 0 + 0]" << endl;
    adder.setInputs(0,0);
    adder.compute();
    adder.display();

    cout << "[Test 5: 200 + 200]" << endl;
    adder.setInputs(200,200);
    adder.compute();
    adder.display();
}

int main() {
    // 1. Chạy danh sách bài test
    runTests();
    // 2. Chế độ tương tác
    Adder8Bit userAdder;
    char choice = 'Y';
    cout << "---- INTERACTIVE MODE ----" << endl;
    do {
        int a,b;
        cout << "Nhập A (0-255): "; cin >> a;
        cout << "Nhập B (0-255): "; cin >> b;
        userAdder.setInputs(a, b);
        userAdder.compute();
        userAdder.display();

        cout << " Muốn test tiếp không? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    cout << "Chương trình đã kết thúc. " << endl;
    
    int testNum = 100;
    // 1. Chuyển đổi số 100 sang dạng nhị phân 8-bit
    vector<int> bits = decimalToBinary(testNum);
    // 2. In kết quả ra màn hình
    cout << " Số " << testNum << " chuyển đổi qua nhị phân 8 bit là: ";
    displayBinary(bits);
    cout << endl;
    // Test thêm vài số biên đặc biệt:
    cout << " Số 0 chuyển đổi qua nhị phân 8 bit là: ";
    displayBinary(decimalToBinary(0));
    cout << endl;
    cout << " Số 255 chuyển đổi qua nhi phân 8 bit là: ";
    displayBinary(decimalToBinary(255));
    cout << endl;
    return 0;
}
