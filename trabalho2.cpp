//Programa base para TRABALHO 2
//PROF.: Glauber Kiss de Souza
//DISC.: Analizar Orient. T�cnicas

    // Defining the int variables
int soma = 13; 
int carryBit = 0; 
int nib1a,nib1b,nib1c,nib1d = 0;
int nib2a,nib2b,nib2c,nib2d = 0;
int res1a,res1b,res1c,res1d = 0;

void setup()
{
    // Configuring pins 0 to 7 as inputs and 8 to 12 as outputs
    pinMode(0, INPUT);
    pinMode(1, INPUT);
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, INPUT);
}

int somaBit(int b1a, int b2a, int cBit)
{
    // Function to add two bits with carryBit
    int bitResult = 0; 
    int aux1, aux2 = 0;
    if ((b1a ^ b2a) ^ cBit)
    {
        bitResult = 1; 1
    }
    else
    {
        bitResult = 0;
    }
    return bitResult;
}

int somaCarryBit(int b1a, int b2a, int cBit)
{
// Function to calculate carryBit
    int aux1, aux2 = 0; 
    if ((b1a && b2a)||(b1a && cBit)||(b2a && cBit))
    {
        cBit = 1;
    }
    else
    {
        cBit = 0;
    }
    return cBit;
}

void loop()
{
    // Main function that runs continuously
    soma = digitalRead(13);
    nib1a = digitalRead(0);
    nib1b = digitalRead(1);
    nib1c = digitalRead(2);
    nib1d = digitalRead(3);
    nib2a = digitalRead(4);
    nib2b = digitalRead(5);
    nib2c = digitalRead(6);
    nib2d = digitalRead(7);
    if (soma == 1)
    {
        carryBit = 0; 
        res1a = somaBit(nib1a,nib2a,carryBit);
        carryBit = somaCarryBit(nib1a,nib2a,carryBit);
        res1b = somaBit(nib1b,nib2b,carryBit);
        carryBit = somaCarryBit(nib1b,nib2b,carryBit);
        res1c = somaBit(nib1c,nib2c,carryBit);
        carryBit = somaCarryBit(nib1c,nib2c,carryBit);
        res1d = somaBit(nib1d,nib2d,carryBit);
        carryBit = somaCarryBit(nib1d,nib2d,carryBit);
    }
    // Write results to the corresponding output pins
    digitalWrite(8,res1a);
    digitalWrite(9,res1b);
    digitalWrite(10,res1c);
    digitalWrite(11,res1d);
    digitalWrite(12,carryBit);
}