/*
    SIT210 3.3D Particle Buddy System Demo
    code adapted and modified from:
    https://build.particle.io/examples/56214d636666d9ece3000005
*/

int LED = D7;

void myHandler(const char *event, const char *data)
{
    if (strcmp(data,"wave")==0) {
        blink();
    }
    else if (strcmp(data,"pat")==0) {
        fastBlink();
    }
}

void blink() {
    for(int i=0; i<3; i++) {
        digitalWrite(LED, HIGH);
        delay(1000);
        digitalWrite(LED, LOW);
        delay(1000);   
    }
}

void fastBlink() {
    for(int i=0; i<3; i++) {
        digitalWrite(LED, HIGH);
        delay(200);
        digitalWrite(LED, LOW);
        delay(200);    
    }
}

void setup() {
    pinMode(LED, OUTPUT); 
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", myHandler);
}

void loop() {
    delay(10000);
    Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "wave"); // publish the wave event as deakin riot no longer active
    delay(10000);
    Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "pat"); // publish the pat event as deakin riot no longer active
}
