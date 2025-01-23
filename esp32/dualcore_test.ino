// Codigo que utiliza do sistema de Tasks da esp32 para ter dois processos rodando ao mesmo tempo

TaskHandle_t Task0;
TaskHandle_t Task1;

void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT); // Led 1
  pinMode(2, OUTPUT); // Led 2
  analogReadResolution(12);
  Serial.begin(115200);

  xTaskCreatePinnedToCore(Task0code, "loop1", 10000, NULL, 1, &Task0, 0); 
  xTaskCreatePinnedToCore(Task1code, "loop2", 10000, NULL, 1, &Task1, 1);
  // O primeiro parametro é o nome da tass, o segundo é o nome humano
  // O terceiro é o numero de bytes maximo da task, o quarto é um pointer que vai ser usado como parametro da task
  // O quinto é a prioridade da task, o sexto é um handle para referenciar a task, e o setimo é o numero da cpu que realizará a task.
}
// Criacao de algo semelhante a dois void loop, sendo void Task0code e void Task1code.
void Task0code(void* pvParameter){
  Serial.printf("Loop1 running on core %d");
  Serial.println(xPortGetCoreID());
  for(;;){
  // Primeiro loop
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
    delay(1000);
  }
}

void Task1code(void* pvParameter){
  Serial.printf("Loop2 running on core %d");
  Serial.println(xPortGetCoreID());
  for(;;){
  // Segundo loop
    digitalWrite(4, HIGH);
    delay(300);
    digitalWrite(4, LOW);
    delay(300);
  }
}


void loop() {
  // put your main code here, to run repeatedly:
}
