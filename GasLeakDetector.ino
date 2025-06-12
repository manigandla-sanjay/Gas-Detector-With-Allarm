/* File: GasLeakDetector.ino
   MQ-2 Gas Leak Detector with Alarm
*/

const int MQ2_PIN        = A0;    // Analog output from MQ-2
const int GREEN_LED_PIN  = 7;     // Indicates safe status
const int RED_LED_PIN    = 8;     // Indicates alarm
const int BUZZER_PIN     = 9;     // Active buzzer
const int GAS_THRESHOLD  = 300;   // Analog threshold (0–1023)

const unsigned long ALARM_DURATION  = 10000UL; // 10 seconds
const unsigned long BEEP_INTERVAL   = 200UL;   // 200 ms on/off blink

// State variables
bool     alarmActive       = false;
bool     buzzerState       = false;
unsigned long alarmStart   = 0;
unsigned long lastBeep     = 0;

void setup() {
  // Initialize I/O
  pinMode(MQ2_PIN,        INPUT);
  pinMode(GREEN_LED_PIN,  OUTPUT);
  pinMode(RED_LED_PIN,    OUTPUT);
  pinMode(BUZZER_PIN,     OUTPUT);

  // Start serial for monitoring
  Serial.begin(9600);
  Serial.println("Gas Leak Detector Initializing...");
  
  // Ensure safe indicators
  digitalWrite(RED_LED_PIN,   LOW);
  digitalWrite(BUZZER_PIN,    LOW);
  digitalWrite(GREEN_LED_PIN, HIGH);
}

void loop() {
  int gasValue = analogRead(MQ2_PIN);
  Serial.print("Gas Level: ");
  Serial.println(gasValue);

  // Detect threshold breach
  if (!alarmActive && gasValue > GAS_THRESHOLD) {
    alarmActive     = true;
    alarmStart      = millis();
    lastBeep        = millis();
    buzzerState     = false;
    digitalWrite(GREEN_LED_PIN, LOW);
    Serial.println(">>> ALARM TRIGGERED <<<");
  }

  if (alarmActive) {
    unsigned long now = millis();

    // Blink buzzer and red LED
    if (now - lastBeep >= BEEP_INTERVAL) {
      buzzerState = !buzzerState;
      digitalWrite(BUZZER_PIN,  buzzerState);
      digitalWrite(RED_LED_PIN, buzzerState);
      lastBeep = now;
    }

    // End alarm after duration
    if (now - alarmStart >= ALARM_DURATION) {
      alarmActive = false;
      digitalWrite(BUZZER_PIN,    LOW);
      digitalWrite(RED_LED_PIN,   LOW);
      digitalWrite(GREEN_LED_PIN, HIGH);
      Serial.println(">>> Alarm reset; back to safe <<<");
    }
  }

  delay(500); // sample twice per second
}
