# ESP32_OV2640Cam_example

Un semplice esempio di utilizzo della **ESP32-CAM** con sensore **OV2640**, pensato per mostrare come catturare immagini e gestire lo streaming video tramite l’ambiente **Arduino IDE** o **PlatformIO**.  

## ✨ Caratteristiche principali
- Supporto al modulo **ESP32-CAM AI Thinker** con sensore OV2640.  
- Configurazione Wi-Fi per accesso remoto.  
- Acquisizione immagini in vari formati (JPEG).  
- Possibilità di avviare un piccolo web server per visualizzare uno snapshot o lo stream della camera.  
- Codice semplice e facilmente estendibile per progetti IoT e di visione artificiale.  

## 📦 Requisiti
- **Hardware**
  - ESP32-CAM (AI Thinker o compatibile) con camera OV2640.
  - Adattatore FTDI o programmatore USB-UART per il flash.
- **Software**
  - [Arduino IDE](https://www.arduino.cc/en/software) (>= 1.8.19) oppure [PlatformIO](https://platformio.org/).
  - ESP32 board support package installato (via Board Manager).
  - Libreria `esp32-camera` (inclusa nel pacchetto ESP32 Arduino).

## ⚙️ Installazione
1. Clona il repository:
   ```bash
   git clone https://github.com/alexscarcella/ESP32_OV2640Cam_example.git
   ```
2. Apri il progetto in Arduino IDE o PlatformIO.  
3. Seleziona la scheda **AI Thinker ESP32-CAM**.  
4. Configura la porta seriale corretta.  
5. Carica lo sketch sul dispositivo.  

## 🚀 Utilizzo
1. Dopo il flash, apri il monitor seriale (baud rate 115200).  
2. Verrà mostrato l’indirizzo IP assegnato via Wi-Fi.  
3. Apri il browser e digita l’IP per accedere alla pagina di streaming.  
4. Puoi catturare immagini singole o visualizzare il flusso video.  

## 📂 Struttura del progetto
- `ESP32_OV2640Cam_example.ino` → Sketch principale.  
- `src/` → Eventuali file di supporto.  
- `README.md` → Documentazione del progetto.  

## 🛠️ Personalizzazione
- Modifica le credenziali Wi-Fi (`ssid` e `password`) nello sketch.  
- Cambia la risoluzione della camera (QVGA, VGA, SVGA, XGA, UXGA).  
- Integra funzioni aggiuntive come salvataggio su SD o invio a server remoto.  

## 🐞 Troubleshooting

Ecco alcuni problemi frequenti e le relative soluzioni:

- **Errore durante il flash ("Failed to connect")**
  - Assicurati che il pin **IO0** sia collegato a **GND** durante il caricamento.  
  - Dopo il flash, scollega IO0 da GND e riavvia la scheda.  
  - Controlla che RX/TX non siano invertiti.

- **Schermo nero o nessuna immagine**
  - Verifica che la camera OV2640 sia ben inserita nel connettore.  
  - Abilita la **PSRAM** selezionando la scheda *AI Thinker ESP32-CAM* in Arduino IDE.  
  - Prova a ridurre la risoluzione (es. QVGA) per testare la stabilità.

- **Reset continuo o crash con errore `Brownout detector was triggered`**
  - Usa un alimentatore stabile da **5V / 2A**.  
  - Evita di alimentare la scheda solo tramite USB se il regolatore non è sufficiente.  

- **Indirizzo IP non assegnato**
  - Controlla che SSID e password Wi-Fi siano corretti.  
  - Assicurati che la rete sia a 2.4 GHz (l’ESP32-CAM non supporta 5 GHz).  
  - Riavvia il router se necessario.

- **Immagini corrotte o incomplete**
  - Riduci la risoluzione o la qualità JPEG.  
  - Evita di aprire più sessioni contemporanee sul web server.  