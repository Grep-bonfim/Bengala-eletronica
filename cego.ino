#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10   // SDA/SS do RC522
#define RST_PIN 9   // RST do RC522

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  while (!Serial); // espera porta serial (opcional)
  SPI.begin();     // inicia SPI bus
  mfrc522.PCD_Init(); // inicia o MFRC522
  Serial.println(F("RFID inicializado. Aproxime um cartão/tag..."));
}

void loop() {
  // Verifica se há um novo cartão presente
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  Serial.print(F("UID: "));
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    // imprime em hex, com zero à esquerda
    if (mfrc522.uid.uidByte[i] < 0x10) Serial.print("0");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    if (i != mfrc522.uid.size - 1) Serial.print(":");
  }
  Serial.println();
  
  // Opcional: tipo do cartão
  Serial.print(F("Tipo do PICC: "));
  Serial.println(mfrc522.PICC_GetTypeName(mfrc522.uid.sak));
  
  // Encerra leitura deste cartão
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
  delay(500);
}
