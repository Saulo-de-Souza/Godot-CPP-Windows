# Gogot CPP 4.5 - Windows

## Instruções e detalhes:

- Primeiramente você tem que instalar o Python e o scons.
- Abra a Godot 4.5x e importe o projeto que está na pasta my_game_here.

- Não rode o jogo antes de abrir este projeto no cmd do windows ou no vscode e der "prompts\scons.bat" para o scons construir o codigo c++.

- Caso queira, pode futuramente substituir pastas e variáveis "my_game_here" pelo nom do seu projeto.

- Comandos para windows de como compilar para windows, linux e web estão na pasta "prompts" em arquivos.bat.
- Não esquecer de instalar scons (pip install scons) e alterar o endereço path do scons nos arquivos prompts .bat.
- Seu código cpp e hpp tem que ficar na pasta src.

- Abre o vs code e trabelhe com cpp e hpp nele.
- Durante o trabalho, use o prompt scons.bat.
- A pasta "prompts" possui vários casos de usos como exemplo.
- O arquivo SConstruct.py está completo para compilar para vários SO.
- Para este projeto, use a Godot 4.5
- Use sempre os arquivos.bat na pasta prompts pois ele alem de compilar, faz copias de arquivos, etc.
- Alguns arquivos estão ocultos pelo settings.json dentro da pasta .vscode. Caso queira vêlos, comentar o codigo nele.
- No projeto exemplo junto com este projeto, estou criando um raycast pelo c++ para pegar a posição do impacto no staticbody na cena além de ter criado um node com o nome CameraSpring e colocar movimentação nele. basta mover com joystick ou o teclado.
