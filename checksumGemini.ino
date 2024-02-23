// Función para calcular el checksum
unsigned char FucCheckSum(unsigned char *i, unsigned char ln);

// Lista de lecturas del sensor
unsigned char lecturas[][9] = {
  {0xFF, 0x86, 0x00, 0x44, 0x03, 0x00, 0x00, 0x00, 0x33},
  {0xFF, 0x86, 0x00, 0x43, 0x03, 0x00, 0x00, 0x00, 0x34},
  {0xFF, 0x86, 0x00, 0x43, 0x03, 0x00, 0x00, 0x00, 0x34},
  {0xFF, 0x86, 0x00, 0x44, 0x03, 0x00, 0x00, 0x00, 0x33},
  {0xFF, 0x86, 0x00, 0x43, 0x03, 0x00, 0x00, 0x00, 0x34},
  {0xFF, 0x86, 0x00, 0x44, 0x03, 0x00, 0x00, 0x00, 0x33},
  {0xFF, 0x86, 0x00, 0x43, 0x03, 0x00, 0x00, 0x00, 0x34},
  {0xFF, 0x86, 0x00, 0x44, 0x03, 0x00, 0x00, 0x00, 0x33},
  {0xFF, 0x86, 0x00, 0x44, 0x03, 0x00, 0x00, 0x00, 0x33},
  {0xFF, 0x86, 0x00, 0x44, 0x03, 0x00, 0x00, 0x00, 0x33},
  {0xFF, 0x86, 0x00, 0x44, 0x03, 0x00, 0x00, 0x00, 0x33},
  {0xFF, 0x86, 0x00, 0x44, 0x03, 0x00, 0x00, 0x00, 0x33},
  {0xFF, 0x86, 0x00, 0x44, 0x03, 0x00, 0x00, 0x00, 0x33},
  {0xFF, 0x86, 0x00, 0x43, 0x03, 0x00, 0x00, 0x00, 0x34},
  {0xFF, 0x86, 0x00, 0x44, 0x03, 0x00, 0x00, 0x00, 0x33},
  {0xFF, 0x86, 0x00, 0x44, 0x03, 0x00, 0x00, 0x00, 0x33},
  {0xFF, 0x86, 0x00, 0x44, 0x03, 0x00, 0x00, 0x00, 0x33},
  {0xFF, 0x86, 0x00, 0x44, 0x03, 0x00, 0x00, 0x00, 0x33},
  {0xFF, 0x86, 0x00, 0x43, 0x03, 0x00, 0x00, 0x00, 0x34},
  {0xFF, 0x86, 0x00, 0x44, 0x03, 0x00, 0x00, 0x00, 0x33},
  {0xFF, 0x86, 0x00, 0x43, 0x03, 0x00, 0x00, 0x00, 0x34},
  {0xFF, 0x86, 0x00, 0x43, 0x03, 0x00, 0x00, 0x00, 0x34},
  {0xFF, 0x86, 0x00, 0x44, 0x03, 0x00, 0x00, 0x00, 0x33},
  {0xFF, 0x86, 0x00, 0x44, 0x03, 0x00, 0x00, 0x00, 0x33},
  {0xFF, 0x86, 0x00, 0x44, 0x03, 0x00, 0x00, 0x00, 0x33},
  {0xFF, 0x86, 0x00, 0x44, 0x03, 0x00, 0x00, 0x00, 0x33},
  {0xFF, 0x86, 0x00, 0x44, 0x03, 0x00, 0x00, 0x00, 0x33},
  {0xFF, 0x86, 0x00, 0x44, 0x03, 0x00, 0x00, 0x00, 0x33},
  {0xFF, 0x86, 0x00, 0x43, 0x03, 0x00, 0x00, 0x00, 0x34}
};


void setup() {
  Serial.begin(9600);
}

void loop() {
  // Calcular y verificar el checksum para cada lectura
  for (int i = 0; i < sizeof(lecturas) / sizeof(lecturas[0]); i++) {
    unsigned char checksum = FucCheckSum(lecturas[i], 8);
    Serial.print("Lectura: ");
    for (int j = 0; j < 8; j++) {
      Serial.print(lecturas[i][j], HEX);
      if (j < 7) {
        Serial.print(" ");
      }
    }
    Serial.print(" - Checksum calculado: ");
    Serial.println(checksum, HEX);

    // Verificación del checksum (reemplazar con el valor esperado)
    if (checksum == 0x9D) {
      Serial.println("Checksum correcto!");
    } else {
      Serial.println("Error! Checksum incorrecto.");
    }
  }

  // Esperar un tiempo antes de repetir
  delay(1000);
}

unsigned char FucCheckSum(unsigned char *i, unsigned char ln) {
  unsigned char j, tempq = 0;
  i += 1;
  for (j = 0; j < (ln - 2); j++) {
    tempq += *i;
    i++;
  }
  tempq = (~tempq) + 1;
  return (tempq);
}
