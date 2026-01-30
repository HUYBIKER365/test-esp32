#include <Arduino.h>
#include <DHT.h>

// --- CẤU HÌNH ---
#define DHTPIN 14     // Chân Data nối vào GPIO 14
#define DHTTYPE DHT11 // Loại cảm biến là DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Khởi động Serial Monitor tốc độ 115200
  Serial.begin(115200);
  Serial.println("--- KHOI DONG DHT11 ---");

  // Khởi động cảm biến
  dht.begin();
}

void loop() {
  // Chờ 2 giây giữa các lần đọc (DHT11 rất chậm)
  delay(2000);

  // Đọc độ ẩm (%)
  float h = dht.readHumidity();
  // Đọc nhiệt độ (độ C)
  float t = dht.readTemperature();

  // Kiểm tra lỗi (quan trọng)
  if (isnan(h) || isnan(t)) {
    Serial.println("Lỗi: Không tìm thấy cảm biến DHT11 !");
    Serial.println("-> Kiểm tra lại dây nối hoặc nguồn 3.3V/5V.");
    return;
  }

  // In kết quả ra màn hình
  Serial.print("Nhiet do: ");
  Serial.print(t);
  Serial.print("°C  |  Do am: ");
  Serial.print(h);
  Serial.println("%");
}