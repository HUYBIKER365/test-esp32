#include <Arduino.h>

void setup() {
  // Khởi động giao tiếp Serial với máy tính
  // Tốc độ này phải khớp với trong Monitor (thường là 9600 hoặc 115200)
  Serial.begin(9600); 
}

void loop() {
  // In chữ "Anh sang: " ra màn hình
  Serial.print("Anh sang: ");
  
  // Ví dụ in thêm một số (giả sử là giá trị cảm biến)
  Serial.println(123); 

  // Đợi 1 giây trước khi lặp lại
  delay(1000); 
}