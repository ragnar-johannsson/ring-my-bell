 

int controlPin = 9;
int ledPin = 13;

int duration = 125;
int wait = 200;

void turn(int times) {
    for (int i = 0; i < times; i++) {
        digitalWrite(controlPin, HIGH);
        digitalWrite(ledPin, HIGH);
        delay(duration);
        digitalWrite(controlPin, LOW);
        digitalWrite(ledPin, LOW);
        delay(wait);
    }
}

void setup() {
    Serial.begin(9600);
    pinMode(controlPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    if (Serial.available() > 0) {
        int incoming = Serial.read();
        if (48 < incoming < 54) {
            turn(incoming-48);
        }
    }
}

