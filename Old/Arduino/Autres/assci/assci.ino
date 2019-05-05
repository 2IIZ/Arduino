void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println(65);
  Serial.println('A');
  Serial.println(char(65)); //affiche la lettre A. Grâce à l'instruction char() on force le typage en caractère. l'Arduino affiche donc un caractère grâce à son code.
  Serial.println(int('A')); //affiche 65. l'instruction int() force le typage vers un nombre entier. On transforme donc le caractère en code ASCII.

}

void loop() {
  
}
