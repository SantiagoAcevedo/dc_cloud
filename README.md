
![Logo](https://user-images.githubusercontent.com/7269314/78952616-93bfb700-7aac-11ea-8c5c-a9ff8fd4bf27.jpg)



# Monitor DC Cloud com Arduino

O sistema off-grid pode ser monitorado remotamente, permitindo a visualização de dados em tempo real e a identificação de falhas à distância. Esse projeto faz uso da plataforma [thingspeak.com](https://thingspeak.com/) para armazenamento de dados, com um limite de atualização de 15 segundos no modo gratuito. Além disso, o sistema é totalmente adaptável e pode ser configurado para enviar dados para qualquer outra URL, usando os métodos POST ou GET.

O hardware utilizado neste projeto é o Arduino UNO, que vem com um módulo ESP 8266 integrado na mesma placa. A comunicação entre os dois é realizada por meio de uma conexão serial.

Com este sistema de monitoramento remoto, é possível ter um acompanhamento em tempo real do funcionamento de um sistema off-grid, incluindo a identificação de eventuais falhas à distância, o que facilita a manutenção e o reparo.

O Step Down foi utilizado pois a tensão de carga neste caso pode chegar a 14v.

[Projeto Funcionando](https://thingspeak.com/channels/1887175)


![UNO R3 + ESP 8266](https://github.com/SantiagoAcevedo/dc_cloud/blob/main/imgonline-com-ua-dexifwdxaiXxSck8o.jpg?raw=true)
## Material Utilizado

- UNO R3 + ESP 8266 [Link](https://pt.aliexpress.com/item/32831857729.html?spm=a2g0o.order_list.order_list_main.10.afbbcaa4pjYSnU&gatewayAdapt=glo2bra)
- ACS 712 [Link](https://pt.aliexpress.com/item/32830307620.html?spm=a2g0o.order_list.order_list_main.72.afbbcaa4pjYSnU&gatewayAdapt=glo2bra)
- Sensor de Tensão [Link](https://pt.aliexpress.com/item/32556523770.html?spm=a2g0o.order_list.order_list_main.71.afbbcaa4pjYSnU&gatewayAdapt=glo2bra)
- Conversor DC/DC - Step Down

