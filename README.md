# Monkey Resquest


Componente de request, feito com intuito de deixar mais fácil a comunicação via api com o esp32
# Importação

Basta clonar este repositorio para a pasta [esp]/esp-idf/components

` https://github.com/Space-Monkeys/conductivity.git `


# Exemplo

```c++

  Conductivity *conductivity = new Conductivity();
  cout << conductivity->read() << std::endl;

```

#Repositorio de Exemplo

Basta clonar(Lempre-se de importar a biblioteca executando o passo acima) este repositorio para quaquer pasta
` https://github.com/Space-Monkeys/conductivity.git `

#BUGFIX

Ao copiar a biblioteca para a pasta /components, caso já tenha algum projeto que você fez o build
irá precisar apagar a pasta /build do projeto, até então essa foi a solução que achei 😉.
 

```powershell
idf.py -p [PORTA] build flash monitor
```
# adc_read
