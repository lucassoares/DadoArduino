int button = 2;
int ledPins[] = {3,4,5,6,7,8,9};
int numeroDado = 0;


void setup(){
    //Serial.begin(9600);
    randomSeed(analogRead(0));
    pinMode(button, INPUT);

    for(int i = 0; i <= 7; i++){
        pinMode(ledPins[i],OUTPUT );
        digitalWrite(i,LOW);
    }
}

void loop(){
    if(digitalRead(button) == 1){
        numeroDado = random(1,7);  
        //Serial.println(numeroDado);
    }

    NumeroSorteado(numeroDado);
}

void NumeroSorteado(int numero){
    DesligarTodosLeds();
    LigarLedsDado(numero);
}

void DesligarTodosLeds(){
    for(int i = 0; i <= 7; i++){
        digitalWrite(ledPins[i],LOW);
    }
}

void LigarLedsDado(int numeroDado){
    int numeroComparacao = 0;
    if((numeroDado % 2) == 0){
        numeroComparacao = 1;
        numeroDado++;
    }
    else{
        numeroComparacao = 0;
    }

    for(int i = numeroComparacao; i < numeroDado; i++){
        digitalWrite(ledPins[i],HIGH);
    }
}
