#include "AudioTools.h"
#include "BluetoothA2DPSink.h"

// OpenBuds by MistaaB
// 2026 Version 4.1

AnalogAudioStream out;
VolumeStream volume(out);
BluetoothA2DPSink a2dp_sink(volume);

float currentVolume = 0.9f;

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 Bluetooth Headphone starting...");

  auto cfg = out.defaultConfig(TX_MODE);
  cfg.sample_rate     = 44100;
  cfg.channels        = 2;
  cfg.bits_per_sample = 16;
  cfg.buffer_size     = 512;
  cfg.buffer_count    = 8;
  out.begin(cfg);

  auto vcfg = volume.defaultConfig();
  vcfg.volume        = currentVolume;
  volume.begin(vcfg);

  a2dp_sink.set_task_core(1);
  a2dp_sink.set_task_priority(22);
  a2dp_sink.set_mono_downmix(true);
  a2dp_sink.start("OpenBuds");

  Serial.println("Bluetooth ready — pair from your phone!");
  Serial.println("Send 'v0' to 'v100' via Serial to change volume.");
}

void loop() {
  // Serial volume control: type e.g. "v70" and press Enter
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    if (cmd.startsWith("v") || cmd.startsWith("V")) {
      int val = cmd.substring(1).toInt();
      if (val >= 0 && val <= 100) {
        currentVolume = val / 100.0f;
        volume.setVolume(currentVolume);
        Serial.printf("Volume set to %d%%\n", val);
      }
    }
  }

  // Connection status every 5s
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 5000) {
    lastPrint = millis();
    Serial.println(a2dp_sink.is_connected()
      ? "[Connected]"
      : "[Waiting for Bluetooth connection...]");
  }
}
