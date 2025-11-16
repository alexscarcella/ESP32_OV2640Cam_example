// Board: AI Thinker ESP32-CAM
// https://github.com/yoursunny/esp32cam

// Install ESP32 Arduino core v3.x.
// Clone the github repository under $HOME/Arduino/libraries directory.
// In Tools - Board menu, select AI Thinker ESP32-CAM to enable 4MB external PSRAM.
// Add #include <esp32cam.h> to your sketch.
// Check out the examples for how to use.

#include "WifiCam.hpp"
#include <WiFi.h>
#include "FS.h"
#include "SD_MMC.h"

static const char* WIFI_SSID = "ESP32CAM";
static const char* WIFI_PASS = "1234";

esp32cam::Resolution initialResolution;

// WebServer server(80);



void snapshot() {
  // ---------------------------------------
  // scatta una foto
  auto frame = esp32cam::capture();
  if (frame == nullptr) {
    Serial.println("capture() failure");
    return;
  }
  Serial.printf("capture() success: %dx%d %zub\n", frame->getWidth(), frame->getHeight(),
                frame->size());
  // ---------------------------------------
  // Inizializza la microSD
  if (!SD_MMC.begin()) {
    Serial.println("Errore inizializzazione SD");
    return;
  } else {
    Serial.println("SD inizializzata");
  }
  // ---------------------------------------
  // Salva l'immagine su SD
  File file = SD_MMC.open("/foto.jpg", FILE_WRITE);
  if (!file) {
    Serial.println("Errore apertura file su SD");
  } else {
    file.write(frame->data(), frame->size());
    Serial.println("Foto salvata su SD come /foto.jpg");
  }
  file.close();
  // ---------------------------------------
}




void setup() {
  Serial.begin(115200);
  Serial.println();
  esp32cam::setLogger(Serial);
  delay(1000);

  // WiFi.persistent(false);
  // WiFi.mode(WIFI_STA);
  // WiFi.begin(WIFI_SSID, WIFI_PASS);
  // if (WiFi.waitForConnectResult() != WL_CONNECTED) {
  //   Serial.printf("WiFi failure %d\n", WiFi.status());
  //   delay(5000);
  //   ESP.restart();
  // }
  // Serial.println("WiFi connected");
  // delay(1000);

  {
    using namespace esp32cam;

    initialResolution = Resolution::find(640, 480);

    Config cfg;
    cfg.setPins(pins::AiThinker);
    cfg.setResolution(initialResolution);
    cfg.setJpeg(80);

    bool ok = Camera.begin(cfg);
    if (!ok) {
      Serial.println("camera initialize failure");
      delay(5000);
      ESP.restart();
    }
    Serial.println("camera initialize success");
  }

  Serial.println("camera starting");
  // Serial.print("http://");
  // Serial.println(WiFi.localIP());

  // addRequestHandlers();
  // server.begin();
}

void loop() {
  // server.handleClient();
  //
  snapshot();
  delay(5000);
}